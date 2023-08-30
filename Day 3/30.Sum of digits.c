#include<stdio.h>
int main(){
   int number,remainder,total=0,temp;
   printf("enter the number=");
   scanf("%d",&number);
   temp=number;
   while(number>0){
      remainder=number%10;
      total=total+remainder;
      number=number/10;
   }
   printf("Sum  of digits:%d",total);
   return 0;
}
