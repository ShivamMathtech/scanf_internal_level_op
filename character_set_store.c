#include<stdio.h>
int main(int argc,char * vargs[]){
char word[10];
printf("Enter the alphabets\n");
scanf("%[a-zA-Z]",&word); // Skips the month string entirel
printf("the word is %s\n",word);

return 0;
}