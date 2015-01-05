//- quick.cpp - implement quicksort

#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

template <class Comparable>
void quicksort(vector<Comparable> & arr);

template <class Comparable>
const Comparable & median3( vector<Comparable> & arr, int left, int right);

template <class Comparable>
void fillVector(vector<Comparable> & arr);

template <class T>
void printVector(vector<T> & arr);

template <class Comparable>
void quicksort(vector<Comparable> & arr, int left, int right);

template <class Comparable>
void insertionSort(vector<Comparable> & arr, int left, int right);

// pick an element v in the set s
    // find first, middle & last elements in s
    // find the median, v
// partition s into two groups s1 <= v & s2 >= v
// return quicksort on both s1 & s2

// driver:
template <class Comparable>
void quicksort(vector<Comparable> & arr)
{
    quicksort(arr, 0, arr.size() -1);
}

// find & return median of left, center & right.
//  order these and remove the pivot.
template <class Comparable>
const Comparable & median3( vector<Comparable> & arr, int left, int right)
{
    int center = (left+right)/2;
    if( arr[center] < arr[left])
    {
        swap( arr[left], arr[center]);
    }
    if( arr[right] < arr[left])
    {
        swap( arr[left], arr[right]);
    }
    if( arr[right] < arr[center])
    {
        swap( arr[center], arr[right]);
    }

    // place pivot at position right - 1
    swap( arr[center], arr[right -1]);
    return arr[right - 1];
}

template <class Comparable>
void fillVector(vector<Comparable> & arr)
{
    srand(time(NULL));
    for(typename vector<Comparable>::iterator it = arr.begin(); it!=arr.end(); ++it)
    {
        *it = rand() % 100;
    }
}

template <class T>
void printVector(vector<T> & arr)
{
    for(typename vector<T>::iterator it = arr.begin(); it!=arr.end(); ++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

template <class Comparable>
void quicksort(vector<Comparable> & arr, int left, int right)
{
    if(left + 10 <= right) //cutoff of 10
    {
        Comparable pivot = median3(arr, left, right);
        //start partitioning
        int i = left, j = right;
        for(; ;)
        {
            while( arr[++i] < pivot) {}
            while(pivot < arr[--j]) {}
            if(i < j)
            {
                swap(arr[i], arr[j]);
            } else {
                break;
            }
        }
        swap( arr[i], arr[right-1]);    // Restore pivot
        quicksort(arr, left, i-1);    // Sort small elements
        quicksort(arr, i + 1, right); // Sort large elements
    }
    else // do insertion sort on the subarray
    {
        insertionSort(arr, left, right);
    }
}

template <class Comparable>
void insertionSort(vector<Comparable> & arr, int left, int right)
{
    int j;
    for(int p = left; p < right; p++)
    {
        Comparable tmp = arr[p];
        for(j = p; j > 0 && tmp < arr[j - 1]; j--)
        {
            arr[j] = arr[j-1];
        }
        arr[j] = tmp;
    }
}

int main()
{
    vector<int> foo(100);
    fillVector(foo);
    printVector(foo);
    quicksort(foo);
    printVector(foo);
    return 0;
}
