#include <iostream>

using namespace std;

void swap( int a, int b );
void bubble_sort( int *begin, int *end );

int main( int argc, char *argv[] )
{
    int arr[] = { 13, 34, 67, 78, 86, 43, 35, 67, 88, 90, 192, 35, 90 };

    bubble_sort( arr, arr + sizeof(arr) / sizeof(int) );

    for( auto x : arr )
        cout << x << endl;

    return 0;
}

void swap( int *a, int *b ){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// 借助 sorted，可提前判断有序退出
void bubble_sort( int *begin, int *end )
{
    bool sorted = false; // 假定尚未排序

    while( ! sorted )
    {
        sorted = true; // 假定已经有序

        for( int *i = begin; i != end; i++ ) // 依次检查相邻元素是否有序
        {
            if( *i > *( i + 1 ) ) // 一旦逆序，则交换之
            {
                swap( i, i + 1 );
                sorted = false; // 不能保证整体有序，故设置false
            }
        }
        end--;
    }
}