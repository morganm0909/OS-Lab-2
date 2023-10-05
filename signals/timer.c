/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>

int handled = 0;
int alarm_count = 0;
int t = 1;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  handled = 1;
  //exit(1); //exit after printing
}

void handler2(int signum)
{ //signal handler
  printf("\nAlarms: %d\n", alarm_count);
  printf("Total time executed: %d\n", alarm_count);
  t = 0;
  //exit(1); //exit after printing
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  signal(SIGINT,handler2);

  while(t){
    alarm(1); //Schedule a SIGALRM for 1 second
    pause();
    if (1){
      printf("Turing was right!\n");
      handled = 0;
      alarm_count = alarm_count + 1;
    }
    // printf("Turing was right!\n");
    // sleep(1);
  }; //busy wait for signal to be delivered
  //exit(1);
  return 0; //never reached
}
