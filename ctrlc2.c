#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void ouch(int sig){
	printf("OUCH! - I got signal %d\n",sig);
}

int main(){
	struct sigaction act,oldact;
	act.sa_handler = ouch;
	sigemptyset(&act.sa_mask);
	act.sa_flags=0;

	oldact.sa_handler = ouch;
	sigemptyset(&act.sa_mask);
	oldact.sa_flags=0;
	//sigaction(SIGINT,&act,0);
	sigaction(SIGINT,&act,&oldact);
	while(1){
		printf("Hello world!\n");
		sleep(1);
	}
	return 0;
}
