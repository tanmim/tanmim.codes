#include<cmath>
#include<iostream>
using namespace std;
int main(void){
    int n;
    cin>>n;
    long long vital=-1;int zero=0;
    int countofzero=0;
    for(int i=0;i<n;i++){
        long long x;
        cin>>x;
        if(x==0){zero = 1;}
        else if(x%10==0){
            countofzero+=log(double(x))/log(double(10));
        }
        else if(x==1) {}
        else vital=x;
    }
    if(zero){
        cout<<0<<endl; return 0;
    }
    if(vital == -1) {cout<<1; }
    else
        cout<<vital;
    for(int i=0;i<countofzero;i++){cout<<0;}
    cout<<endl;

    return 0;
}
