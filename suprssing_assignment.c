#include<stdio.h>
int main(int argc,char * vargs[]){
int day, year;
char month[20]="";
printf("Enter the value of day , year ,month\n");
scanf("%d %*s %d", &day, &year); // Skips the month string entirel
printf("the value of day is %d, year is %d, and month is %s\n",day,year,month);

return 0;
}