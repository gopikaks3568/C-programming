//the program to demostrate Cp linux command in C
#include<stdio.h>
int main(int argc,char* argv[]){
        FILE f1,f2;
        f1=fopen(argv[1],"r");
        f2=fopen(argv[2],"w");
        if (!f1 &&!f2 &&  argc!=3 ){
                printf("Error");
        }
        char c;
        while (c=fgetc(f1)!=EOF){

                fputc(c,f2);
        }
        fclose(f1);
        fclose(f2);
}