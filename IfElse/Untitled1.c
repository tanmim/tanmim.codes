#include<stdio.h>

int main()

{
    int a;
    scanf("%d",&a);

    if(a%400==0){
        printf("this is leap year");

    }
    else if(a%100==0){
    printf("this is not ly");
    }

    else if(a%4==0){
        printf("this is leap year");

    }
    else {
        printf("this is not leap year");

    }

    return 0;

}
