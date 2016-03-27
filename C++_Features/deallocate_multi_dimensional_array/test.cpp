#include <iostream>

int main()
{
    double** x = new double*[5];
    for(int i = 0; i < 5; i++)
        x[i] = new double[5];

    for(int i = 0; i < 5; i++)
        delete[] x[i];

    delete[] x;
    return 0;
}
