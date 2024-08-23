#include<stdio.h>
#include<unistd.h>
int main(){
 char *argv[] = {
  "ls", 
  "-l",
  NULL
 };
execv("/bin/ls", argv);
perror("execv");
return 1;
}
