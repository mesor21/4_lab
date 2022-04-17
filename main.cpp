#include <iostream>
using namespace std;

class Array{
private:
    unsigned char frome_array[4];
public:
    unsigned char& operator[](const int index);
};
unsigned char& Array:: operator[](const int index){
    return frome_array[index];
};
/*
class Decimal
{
private:
    char sing;
    unsigned char d_class[100];
public:
    Decimal();
    ~Decimal();

};

class Octal
{
private:
    unsigned char o_class[100];
public:
    Octal();
    ~Octal();

};
*/  
int main(){
    Array x;
    x[2]=1;
}