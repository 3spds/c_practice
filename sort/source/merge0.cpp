//- merge0.cpp implement merge sort

#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

//- declaration

// this is the "driver" for the sort.
//    it will declare the temporary vector and call the overloaded mergeSort method.
template<class Comparable>
void mergeSort(vector<Comparable> &arr);

// this is the overloaded mergeSort method.
//    it will find the middle index based on the length of the array,
//    act recursively on either half, and finally call merge()
template<class Comparable>
void mergeSort(vector<Comparable> &arr, vector<Comparable> &tmp, int left, int right);

// this is the merge method.
//    it compares items on the left with items on the right, copying the smaller into tmp.
//    then it copies the remaining items in left and right (in that order) into tmp
//    finally, it copies tmp into arr
template<class Comparable>
void merge(vector<Comparable> &arr, vector<Comparable> &tmp, int left, int middle, int right);

// this fills vectors with randomness
template<class Comparable>
void fillArray(vector<Comparable> &arr);

// this prints vector contents
template<class Comparable>
void printArray(vector<Comparable> &arr);

//- implementation

// this is the "driver" for the sort.
//    it will declare the temporary vector and call the overloaded mergeSort method.
template<class Comparable>
void mergeSort(vector<Comparable> &arr)
{
    vector<Comparable> tmp(arr.size());
    mergeSort(arr, tmp, 0, arr.size()-1);
}

// this is the overloaded mergeSort method.
//    it will find the middle index based on the length of the array,
//    act recursively on either half, and finally call merge()
template<class Comparable>
void mergeSort(vector<Comparable> &arr, vector<Comparable> &tmp, int left, int right)
{
    if(left<right)
    {
        int middle = (left+right) / 2;
        mergeSort(arr, tmp, left, middle);
        mergeSort(arr, tmp, middle+1, right);
        merge(arr, tmp, left, middle+1, right);
    }
}

// this is the merge method.
//    it compares items on the left with items on the right, copying the smaller into tmp.
//    then it copies the remaining items in left and right (in that order) into tmp
//    finally, it copies tmp into arr
template<class Comparable>
void merge(vector<Comparable> &arr, vector<Comparable> &tmp, int leftPos, int rightPos, int rightEnd)
{
    // find leftEnd
    int leftEnd = rightPos -1;
    // find numElements
    int numElements = rightEnd - leftPos + 1;
    // find tmpPos
    int tmpPos = leftPos;
    // compare items on left with items on right
    while(leftPos <= leftEnd && rightPos <= rightEnd)
    {
        if(arr[leftPos] <= arr[rightPos])
        {
        // copy item on left into tmp, incrementing both
            tmp[tmpPos++] = arr[leftPos++];
        } else {
        // copy item on right into tmp, incrementing both
            tmp[tmpPos++] = arr[rightPos++];
        }
    }
    // copy remaining left items
    while(leftPos <= leftEnd)
    {
        tmp[tmpPos++] = arr[leftPos++];
    }
    // copy remaining right items
    while(rightPos <= rightEnd)
    {
        tmp[tmpPos++] = arr[rightPos++];
    }
    // copy entire tmp into arr
    for(int i=0; i<numElements; i++, rightEnd--)
    {
        arr[rightEnd] = tmp[rightEnd];
    }
    // profit
}

template<class Comparable>
void fillArray(vector<Comparable> &arr)
{
    srand(time(NULL));
    for(int i=0; i<arr.size(); i++)
    {
        arr[i] = rand() % 10;
    }
}

template<class Comparable>
void printArray(vector<Comparable> &arr)
{
    for(int i=0; i<arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> test(1000);
    fillArray<int>(test);
    printArray(test);
    mergeSort(test);
    printArray(test);
    return 0;
}
