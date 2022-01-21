//REVERSE A STRING USING FOR LOOP
//This is more efficient actually, and simple
#include "common.h"

int Stack4(void){
    char C[10];
    printf("Enter a string:\n");
    scanf("%s", C);
    int length=strlen(C);
    printf("Entered string and length: %s (%d)\n",C,length);
    //printf("%lu\n",strlen(C));
    int i=0; //first element
    int j=length-1; //last element
    char temp;
    while (i<j){
        temp=C[i];
        C[i]=C[j];
        C[j]=temp;
        i++;
        j--;
    }
    printf("Output = %s\n",C);
    return 0;
}


