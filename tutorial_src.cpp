#include "tutorial_src/tutorial.h"

// Transpose using extra copy
void transpose(double* A, double* AT, int local_n, int global_n)
{
    int rank, num_procs;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    double* send_buffer = new double[local_n*global_n];
    double* recv_buffer = new double[local_n*global_n];
    MPI_Request* send_requests = new MPI_Request[num_procs];
    MPI_Request* recv_requests = new MPI_Request[num_procs];
    int tag = 1234;

    int msg_size = local_n*local_n; // size of each msg
    for (int i = 0; i < num_procs; i++)
    {
        MPI_Irecv(&(recv_buffer[i*msg_size]), msg_size, MPI_DOUBLE, i, tag, MPI_COMM_WORLD,
                &(recv_requests[i]));
    }

    int ctr = 0;
    for (int i = 0; i < num_procs; i++)
    {
        for (int j = 0; j < local_n; j++)
        {
            for (int k = 0; k < local_n; k++)
            {
                send_buffer[ctr++] = A[k*global_n + i*local_n + j];
            }
        }
        MPI_Isend(&(send_buffer[i*msg_size]), msg_size, MPI_DOUBLE, i, tag, MPI_COMM_WORLD,
                &(send_requests[i]));
    }
    
    MPI_Waitall(num_procs, send_requests, MPI_STATUSES_IGNORE);
    MPI_Waitall(num_procs, recv_requests, MPI_STATUSES_IGNORE);

    ctr = 0;
    for (int i = 0; i < num_procs; i++)
    {
        for (int j = 0; j < local_n; j++)
        {
            for (int k = 0; k < local_n; k++)
            {
                AT[j*global_n + i*local_n + k] = recv_buffer[ctr++];
            }
        }

    }

    delete[] send_buffer;
    delete[] recv_buffer;
}
