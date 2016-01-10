#include<stdio.h>

int main()

{
    int a;
    scanf("%d",&a);


    if(a%7==1){
        printf("saturday");

    }
    else if(a%7==2) {
        printf("sunday");
}
     else if(a%7==3) {
        printf("monday");
}
     else if(a%7==4) {
        printf("tuesday");
}
     else if(a%7==5) {
        printf("wednesday");
}
     else if(a%7==6) {
        printf("thursday");
}
     else if(a%7==0) {
        printf("friday");
}


    return 0;



}
