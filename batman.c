#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

static void sighandler(int signo){
  //to intercept signals
  if (signo==SIGINT){

    printf("CAUGHT SIGINT");

    int f = open("sig.txt",O_CREAT | O_WRONLY | O_APPEND, 0644);
    write(f, "Catch SIGINT\n", 15);
    close(f);

    exit(1);
  }
  else
    printf("Parent PID: %d\n", getppid());
}

int main(){
  signal(SIGINT, sighandler);
  
  while(1){  
    printf("PID: %d\n", getpid());
    sleep(1);
  }
  return 0;
}
