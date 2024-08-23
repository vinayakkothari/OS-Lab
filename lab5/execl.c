#include<stdio.h>
#include<unistd.h>
int main(){
 printf("Demo of execl\n");
 execl("bin/ls", "ls", "-l", NULL);
 perror("execl");
 return 1;
}

