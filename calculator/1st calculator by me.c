#include<stdio.h>
int main()

{
    int a,b,c;
    char x;
    printf("enter your operation (+,-,*,/)\n");

    scanf("%c",&x);

    if(x=='+'){
    printf("enter 1st number for plus:\n");
    scanf ("%d",&a);
    printf("enter 2nd number : ");
    scanf("%d",&b);

    c=a+b;
    printf("the sum is= %d",c);

    }
    else if(x=='-'){
        printf("enter 1st number for minus:");
    scanf ("%d",&a);

    printf("enter 2nd number for minus: ");
    scanf("%d",&b);

    c=a-b;
    printf("the ans= %d",c);

    }
    else if(x=='*'){
    printf("enter the 1st number for multiply: ");
    scanf("%d",&a);

    printf("enter the 2nd number for multiply: ");
    scanf("%d",&b);

    c=a*b;

    printf("the ans is = %d",c);

    }

    else if(x=='/'){
    printf("enter the 1st number for devide:");
    scanf("%d",&a);

    printf("enter the 2nd number for devide:");
    scanf("%d",&b);

    c=a/b;
    printf("the ans is= %d",c);

    }


    return 0;



}
