#include<stdio.h>
int main()
{
    long long a,b,c;

    while (scanf("%lld%lld",&a,&b) != -1) {
    if (a>b){
            c=a-b;
            printf("%lld\n",c);

        }
        else if (a<b){
            c=b-a;
            printf("%lld\n",c);


        }
        else{
        printf("0\n");
        }




    }
    return 0;


}

