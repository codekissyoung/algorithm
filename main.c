#include <stdio.h>
#include <time.h>
#include <math.h>

double polynomial_sum_1( int n, const double a[], double x );
double polynomial_sum_2( int n, const double a[], double x );
int main( int argc, char *argv[] )
{
    clock_t start = clock();
    // ----------------------- test code start ------------------------ //

    double a[] = { 3, 5, 0, 3, 8, 8, 9, 18, 89, 1, 23, 45, 87, 21, 89, 23, 34, 90, 11, 10 };
    double x = 3.43;

    double sum_1= polynomial_sum_1( sizeof(a) / sizeof(double), a, x );
    double sum_2 = polynomial_sum_2( sizeof(a) / sizeof(double), a, x );

    printf("sum_1:%f,sum_2:%f\n", sum_1, sum_2 );

    // ----------------------- test code end   ------------------------ //
    clock_t stop = clock();
    double duration = (double)( stop - start ) / CLOCKS_PER_SEC; // 单位: s
    printf("run time:%fs\n", duration);

    return 0;
}

// 多项式求和 方法1:
double polynomial_sum_1( int n, const double a[], double x )
{
    double sum = a[0];
    for( int i = 1; i < n; ++i )
        sum = sum + a[i] * pow( x, i );
    return sum;
}

// 多项式求和 方法2:
double polynomial_sum_2( int n, const double a[], double x )
{
    double sum = 0;
    for( int i = n - 1; i >= 0; --i )
        sum = a[i] + x * sum;
    return sum;
}