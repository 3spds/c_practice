// merge.cpp- merge sort - implement a merge sort on a random array of ints

#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

template <class Comparable>
void mergeSort(vector<Comparable> & arr);

template <class Comparable>
void mergeSort(vector<Comparable> &arr, vector<Comparable> &helper, int left, int right);

template <class Comparable>
void merge(vector<Comparable> &arr, vector<Comparable> &helper, int leftPos, int rightPos, int rightEnd);

template<class Comparable>
void fillRandom(vector<Comparable> &arr);

template<class Comparable>
void printArray(vector<Comparable> &arr);

template <class Comparable>
void mergeSort(vector<Comparable> & arr)
{   //- the driver of the sort.
    vector<Comparable> helper( arr.size());
    mergeSort(arr, helper, 0, arr.size()-1);
}

template <class Comparable>
void mergeSort(vector<Comparable> &arr, vector<Comparable> &helper, int left, int right)
{   //- internal method. makes recursive calls.
    // helper contains the merged result.
    // left is lowest index
    // right is highest index
    if(left < right)
    {
        int center = (left+right)/2;
        mergeSort(arr, helper, left, center);
        mergeSort(arr, helper, center+1, right);
        merge(arr, helper, left, center+1, right);
    }
}

template <class Comparable>
void merge(vector<Comparable> &arr, vector<Comparable> &helper, int leftPos, int rightPos, int rightEnd)
{
    int leftEnd = rightPos -1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    //- Main Loop
    // compare each item in left half w item in right half, copying the smaller of the two to the next place in helper
    while(leftPos <= leftEnd && rightPos <=rightEnd)
    {
        if( arr[leftPos] <= arr[rightPos] )
        {
            helper[tmpPos++] = arr[leftPos++];
        } else {
            helper[tmpPos++] = arr[rightPos++];
        }
    }

    // if items remain in left half, copy them to next place in helper
    while(leftPos <= leftEnd)
    {
        helper[tmpPos++] = arr[leftPos++];
    }
    // if items remain in right half, copy them to next place in helper
    while(rightPos <= rightEnd)
    {
        helper[tmpPos++] = arr[rightPos++];
    }
    // copy helper to arr
    for(int i = 0; i<numElements; i++, rightEnd--)
    {
        arr[rightEnd] = helper[rightEnd];
    }
}

template<class Comparable>
void fillRandom(vector<Comparable> &arr)
{
    srand(time(NULL));
    for(int i=0; i<(arr.size()); i++)
    {
        arr[i] = rand() % 10;
    }
}

template<class Comparable>
void printArray(vector<Comparable> &arr)
{
    for(int i=0; i<(arr.size()); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    cout<<"sort an array. here's a random one:"<<endl;
    vector<int> arr(11);
    fillRandom<int>(arr);
    printArray(arr);
    mergeSort(arr);
    cout<<"sorted:"<<endl;
    printArray(arr);
    return 0;
}
