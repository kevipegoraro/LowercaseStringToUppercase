//A program that reads a lowercase string of any size and prints its uppercase equivalent for each letter. Using the "do while" command to scan the string to the end.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
// Function that reads a string of any length, dynamically reallocating the string size
char *inputString(FILE* fp, size_t size){
    char *str;
    int ch;
    size_t len = 0;
    str = realloc(NULL, sizeof(char)*size);//size is start size
    if(!str)return str;
    while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
        str[len++]=ch;
        if(len==size){
            str = realloc(str, sizeof(char)*(size+=16));
            if(!str)return str;
        }
    }
    str[len++]='\0';

    return realloc(str, sizeof(char)*len);
}
// Driver function
int main(void){
    char *m;
    int t;
    printf("input string : ");
    m = inputString(stdin, 10);
    t=sizeof(m)+16;
    // For it goes through all the letters and converts them to capital letters if necessary
    int i=0;  
    do   
    {
   	if (m[i]>='a' && m[i]<='z') 
   	{
   	   printf("%c", toupper(m[i]));
   	} else { printf("%c", m[i]); }
   	i++;
    } while(i<=t);
    printf("\n");
    free(m); 
    return 0;
}
