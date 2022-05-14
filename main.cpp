#include <iostream>
#include <cstring> 
#include <string>
#include <cmath>
using namespace std;

class Array{
protected:
    int const count_input = 100;
    unsigned char summ[100];
public:
    unsigned char d_class[100];
    unsigned char o_class[100];
    Array(Array * arr=0):arr(arr){
        for(int i=0; i<count_input;i++){
            d_class[i]=0;
            o_class[i]=0;
        }
    }
    Array *arr;

    unsigned char DecimalFromeOctal[100];
    void OctalToDesimal(){ 
        for(int i=0; i<count_input;i++){
            DecimalFromeOctal[i]=0;
        }
        int summ=0;
        for(int i=count_input-1; i!=-1; i--){
            long long int x=(int)o_class[i];
            if(x!=0){
                summ=pow(8, i)*(x-48)+summ;
            }
        }
        for(int i=count_input-1; i!=-1; i--){
            long long int t = summ/pow(10, i);
            if(t!=0){
                DecimalFromeOctal[i]=t+'0';
                summ=summ-t*pow(10,i);
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
        for(int i=0; i<count_input-1; i++){
            int dec;
            int DFO;
            int sum;
            if(d_class[i]!=0){
                dec=(int)d_class[i]-48;
            }
            else{dec=0;}
            if(DecimalFromeOctal[i]!=0){
                DFO=(int)DecimalFromeOctal[i]-48;
            }
            else{DFO=0;}
            if(summ[i]!=0){
                sum=(int)summ[i]-48;
            }
            else{sum=0;}
            if((dec+DFO+sum)<10){
                summ[i]=(dec+DFO+sum)+'0';
            }
            else{
                summ[i]=(((dec+DFO)%10)+sum)+'0';
                summ[i+1]=((dec+DFO)/10)+'0';
            }
        }
    }
    void out(){
        cout<<"Decimal:\t";
        for(int i=0; i<count_input; i++){
            cout<<d_class[i];
        }
        cout<<" "<<endl;
        cout<<"Octal:\t";
        for(int i=0; i<count_input; i++){
            cout<<o_class[i];   
        }
        cout<<" "<<endl;
        cout<<"Decimal From Octal:\t ";
        for(int i=0; i<count_input; i++){
            cout<<DecimalFromeOctal[i];
        }
        cout<<" "<<endl;
        cout<<"Summ:\t";
        for(int i=count_input-1; i>-1; i--){
            cout<<summ[i];
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
            arr->d_class[i]=0;
        }
        decimal_count_input= q.length();
        if(q[0]=='-'){
            sing='-';
            decimal_count_input--;
            for(int i=decimal_count_input; i>0; i--){
                arr->d_class[i-1]=(int)q[decimal_count_input-i+1];
            }
        }
        else{
            for (int i = decimal_count_input; i>0; i--) {
                arr->d_class[i-1] = (int)q[decimal_count_input-i];
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
            arr->o_class[i]=0;
        }
        octal_count_input= q.length();
        for(int i=octal_count_input; i>0; i--){
            arr->o_class[i-1]=(int)q[octal_count_input-i];
        }
    }
};


int main(){
    Array *arr=new Array;
    Decimal *x=new Decimal(arr);
    Octal *y=new Octal(arr);
    x->set_decimal("13452");
    y->set_octal("2123");
    arr->OctalToDesimal();
    arr->summ_of_element_arr();
    arr->out();
    delete y;
    delete x;
    delete arr;
}