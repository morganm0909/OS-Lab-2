#include  <stdio.h>
#include  <string.h>
#include  <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>

#define   MAX_COUNT  200

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

void  main(void)
{
     pid_t pid_1;
     pid_t pid_2;
     int status;
     pid_1 = fork();
     if (pid_1 == 0){
          ChildProcess();
     }
     else {
          pid_2 = fork();
          if (pid_1 == 0){
               ChildProcess();}
          else
               wait(&status);
               printf("Child Pid: %d has completed", pid_1);
               wait(&status);
               printf(" Child Pid: %d has completed", pid_2);
     }
}

void  ChildProcess(void)
{
     int   i;
     srand(time(NULL));
     int rand_num = (rand() % 30);
     for (i = 1; i < rand_num; i++){
          int rand_t = (rand() % 10);
     printf("Child Pid: is awake!\nWhere is my Parent: %d?\n", getpid());
     sleep(rand_t);
     }
     exit(1);
}

void  ParentProcess(void)
{
     int   i;

     printf("*** Parent is done ***\n");
}