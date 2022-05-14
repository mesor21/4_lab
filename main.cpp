#include <iostream>
#include <cstring> 
#include <string>
#include <cmath>
using namespace std;

class Array{
protected:
    int const count_input = 10;
    unsigned char summ[10];
public:
    unsigned char d_class[10];
    unsigned char o_class[10];
    Array(Array * arr=0):arr(arr){
        for(int i=0; i<count_input;i++){
            d_class[i]=0;
            o_class[i]=0;
        }
    }
    Array *arr;

    unsigned char DecimalFromeOctal[10];
    void OctalToDesimal(){ 
        for(int i=0; i<count_input;i++){
            DecimalFromeOctal[i]='0';
        }
        int summ=0;
        for(int i=count_input-1; i!=-1; i--){
            int x=o_class[i]+'0';
            if(x!=0){
                summ=pow(8, i)*x+summ;
            }
        }
        for(int i=count_input-1; i!=-1; i--){
            if(summ/pow(10, i)){
                DecimalFromeOctal[i]=(summ/pow(10, i))-'0';
                summ=summ-(DecimalFromeOctal[i]+'0')*pow(10, i);
            }
        }
    }
    void test(){
        for(int i=0; i<count_input; i++){
            cout<<d_class[i];
        }
        cout<<" "<<endl;
        for(int i=0; i<count_input; i++){
            cout<<o_class[i];
        }
        cout<<" "<<endl;
    }
    virtual void test2(){
        for(int i=0; i<count_input; i++){
            cout<<DecimalFromeOctal[i];
        }
        cout<<" "<<endl;
    }
    virtual void summ_of_element_arr(){
        for(int i; i<count_input; i++){
            summ[i]=d_class[i]+DecimalFromeOctal[i];
        }
    }
    void out(){
        for(int i=0; i<count_input; i++){
            cout<<summ[i]<<endl;
        }
    }
};

class Decimal:public Array
{
private:
    unsigned char sing;
    int decimal_count_input;
public:
    Decimal(Array *arr):Array(arr){
    };
    void set_decimal(string q){
        for(int i=0; i<count_input;i++){
            arr->d_class[i]='0';
        }
        decimal_count_input= q.length();
        if(q[0]=='-'){
            sing='-';
            decimal_count_input--;
            for(int i=decimal_count_input; i>0; i--){
                arr->d_class[i-1]=q[decimal_count_input-i+1];
            }
        }
        else{
            for (int i = decimal_count_input; i>0; i--) {
                arr->d_class[i-1] = q[decimal_count_input-i];
            }
        }
    }
};

class Octal:public Array
{
private:    
    int octal_count_input;
public:
    Octal(Array *arr):Array(arr){
    };
    void set_octal(string q){
        for(int i=0; i<count_input;i++){
            arr->o_class[i]='0';
        }
        octal_count_input= q.length();
        for(int i=octal_count_input; i>0; i--){
            arr->o_class[i-1]=q[octal_count_input-i];
        }
    }
};


int main(){
    Array *arr=new Array;
    Decimal *x=new Decimal(arr);
    Octal *y=new Octal(arr);
    x->arr;
    y->arr;
    x->set_decimal("13452");
    y->set_octal("1234");
    arr->test();
    arr->OctalToDesimal();  
    arr->test2();
    delete y;
    delete x;
    delete arr;
}