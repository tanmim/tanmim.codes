#include<cmath>
#include<iostream>
using namespace std;
int main(void){
    long long l,r,k;
    cin>>l>>r>>k;

    if(k>r) {cout<<-1<<endl; return 0;}

    //int i=0;
    long long out=1;
    //for(int i=0;i<xx;i++){out*=k;}
    while(1){
//        if(out<l){
//            out*=k;
//            continue;
//        }
//        cout<<out<<' ';
//        out*=k;
            if(out>=l && out<=r) cout<<out<<" ";
            if(k<=r/out) out*=k;
            else break;
    }
    cout<<endl;
}
