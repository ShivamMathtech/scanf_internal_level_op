#include<stdio.h>
int main(int argc,char * vargs[]){
char sentence[100];
printf("Enter the Sentance\n");
scanf("%[^.]", sentence); // Reads until '.' is found
printf("the sentence is %s",sentence);
return 0;
}