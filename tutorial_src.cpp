// Serial power method
// Returns eigenvalue
double power_method_seq(int n, double* A, double* x, double* tmp, int n_iter)
{
    double sum, max, lambda;
    for (int iter = 0; iter < n_iter; iter++)
    {
        lambda = 0;
        for (int i = 0; i < n; i++)
        {
            sum = 0;
            max = 0;
            for (int j = 0; j < n; j++)
            {
                sum += A[i*n+j]*x[j];
            }
            tmp[i] = sum;
            if (fabs(sum) > max) 
                max = fabs(sum);
            lambda += fabs(tmp[i] - x[i]);
        }
        lambda /= n;

        for (int i = 1; i < n; i++)
            x[i] = tmp[i] / max;
    }
    return lambda;
}
