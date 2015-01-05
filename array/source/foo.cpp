#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

void randArray(int* vec, int length){
    srand(time(NULL));
    for(int i=0; i<length; i++){
        vec[i] = rand() % 10;
    }
}

void printArray(int* vec, int length){
    for(int i=0; i<length; i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

void addItem(int* vec, int length, int index, int value){
    vec[index&(length-1)] = value;
}

int main(){
    int length;
    cout<<"Specify length. (Should be 2^n):"<<endl;
    cin>>length;
    int* vec = new int[length]();
    int index = 0;
    int value;
    for(index; index<length*2; index++){
        cout<<"Next entry?:"<<endl;
        cin>>value;
        addItem(vec, length, index, value);
        printArray(vec, length);
    }
    cout<<"Well, that was fun. Thank you!"<<endl;
    delete[] vec;
    return 0;
}
