#include "tutorial_src/tutorial.h"

// Transpose using extra copy
double transpose(double* A, double* AT, int local_n, int global_n, int first_n)
{
    int rank, num_procs;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    double* buffer = new double[local_n*global_n];
    MPI_Request* send_requests = new MPI_Request[num_procs];
    MPI_Request* recv_requests = new MPI_Request[num_procs];

    int msg_size = local_n*local_n; // size of each msg
    for (int i = 0; i < num_procs; i++)
    {
        MPI_Irecv(&(AT[i*msg_size]), msg_size, MPI_DOUBLE, i, tag, MPI_COMM_WORLD,
                &(recv_requests[i]));
    }

    int ctr = 0;
    for (int i = 0; i < num_procs; i++)
    {
        for (int j = i*local_n; j < (i+1)*local_n; j++)
        {
            for (int k = 0; k < local_n; k++)
            {
                buffer[ctr++] = A[j*local_n+k];
            }
        }
        MPI_Isend(&(buffer[i*msg_size]), msg_size, MPI_DOUBLE, i, tag, MPI_COMM_WORLD,
                &(send_requests[i]));
    }
    
    MPI_Waitall(num_procs, send_requests, MPI_STATUSES_IGNORE);
    MPI_Waitall(num_procs, recv_requests, MPI_STATUSES_IGNORE);
}
