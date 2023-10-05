/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>

time_t stop, start;
bool a = false;

void handler(int signum)
{ //signal handler
  stop = time(NULL);
  printf("Hello World!\n");
  a = true;
  //exit(1); //exit after printing
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  alarm(1); //Schedule a SIGALRM for 1 second
  start = time(NULL);
  while(a == false){
    printf("Turing was right!\n");
    sleep(1)
  }; //busy wait for signal to be delivered
  //exit(1);
  return 0; //never reached
}