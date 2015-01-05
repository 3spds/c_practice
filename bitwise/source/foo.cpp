#include <iostream>

bool getBit(int number, int bit)
{
    return ((1<<bit)&number) != 0;
}

int setBit(int number, int bit, bool value)
{
    return ~(1<<bit)&number | (value<<bit);
}

int clearLeftBit(int number, int bit)
{
    return (-1<<bit)& number;
}

int clearRightBit(int number, int bit)
{
    return (1<<(bit+1))-1 & number;
}

void printBits(int number)
{
    using ::std::cout;
    using ::std::endl;
    for(int bit = 0; bit < 32; bit++)
    {
        cout<<getBit(number, bit)<<" ";
    }
    cout<<endl;
}

int main()
{
    using ::std::cout;
    using ::std::cin;
    using ::std::endl;

    int number=0;
    int bit_to_set=0;
    int value_to_set=0;
    cout<<"Gimme a number."<<endl;
    cin>>number;
    cout<<"Your number, in binary:"<<endl;
    printBits(number);
    cout<<"Set a bit in the number. Which one?"<<endl;
    cin>>bit_to_set;
    cout<<"And to what value?"<<endl;
    cin>>value_to_set;
    number = setBit(number, bit_to_set, value_to_set);
    cout<<"Your new number:"<<endl;
    printBits(number);
    cout<<"Clear right of which bit?"<<endl;
    cin>>bit_to_set;
    number = clearRightBit(number, bit_to_set);
    cout<<"Your new number:"<<endl;
    printBits(number);
    cout<<"Clear left of which bit?"<<endl;
    cin>>bit_to_set;
    number = clearLeftBit(number, bit_to_set);
    cout<<"Your new number:"<<endl;
    printBits(number);
    return 0;
}
