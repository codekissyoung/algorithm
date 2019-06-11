#include <iostream>

using namespace std;

int fib( int n )
{
    if( n <= 2 )
        return 1;

    int fn;         // n 项
    int fn_1 = 1;   // n - 1 项
    int fn_2 = 1;   // n - 2 项

    for( int i = 2; i < n; i++ )
    {
        fn = fn_1 + fn_2;
        fn_2 = fn_1;
        fn_1 = fn;
    }

    return fn;
}

int main( int argc, char *argv[] )
{
    cout << fib( 10 ) << endl;

    return 0;
}

