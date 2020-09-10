#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(){
  printf("Signal handler called\n");
}

int main(){
  //signal(SIGINT, sig_handler);
  while(1){
	  printf("Hello\n");
	  sleep(300000);
  }
  return 0;
}
