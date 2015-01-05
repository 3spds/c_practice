// - write a method to compute the maximum length "tower" of carnies
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int hits(string guess, string solution);
int phits(string guess, string solution);
string insertion(string bar);
int* play(string guess, string solution, int* response);

int hits(string guess, string solution)
{
    int num = 0;
    //loop through both simultaneously, counting matches
    for(int i=0; i < guess.length(); i++)
    {
        if(guess.at(i) == solution.at(i))
        {
            num ++;
        }
    }
    return num;
}

int phits(string guess, string solution)
{
    int num = 0;
    //sort both strings
    string sguess = insertion(guess);
    string ssolution = insertion(solution);
    num = hits(sguess, ssolution);
    //apply hits(guess, solution);
    return num;
}

string insertion(string bar)
{
    //perform n-1 passes on string
    string foo = bar;
    int j;
    for(int p = 1; p < foo.length(); p++)
    {
        char tmp = foo.at(p);
        for(j = p; j > 0 && tmp < foo.at(j-1); j--)
        { // if item at j-1 is in the wrong place...
            foo.at(j) = foo.at(j-1); // swap item at j-1 with item at j
        }
        foo.at(j) = tmp;
    }
    return foo;
}

int* play(string guess, string solution, int* response)
{
    response[0] = hits(guess, solution);
    response[1] = response[0] - phits(guess, solution);
    return response; // hits: component 0, pseudo-hits: component 1
}

void printArray(int* arr, int length)
{
    for(int i = 0; i < length; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int response[2];
    cout<<"Guess the colors..."<<endl;
    string input;
    string solution = "GGGG";
    cin>>input;
    play(input, solution, response);
    printArray(response, 2);
    return 0;
}
