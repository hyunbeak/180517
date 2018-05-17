#include<stdio.h>
#include<signal.h>
#include<unistd.h>
//SIGINT
void ouch(int sig){
	printf("OUCH! - I got signal %d\n",sig);
}
//SIGQUIT
void ouch2(int sig){
	printf("OUCH2\n");
}
int main(){
	struct sigaction act;
	sigset_t newmask,oldmask,pendmask;
	act.sa_handler = ouch;
	sigemptyset(&act.sa_mask);
	act.sa_flags=0;

	if(signal(SIGQUIT,ouch,0)==-1)
			perror("can't catch SIGQUIT");
	if(signal(SIGINT,sigHandler,0)==-1)
			perror("can't catch SIGQUIT\n");
	sigemptyset(&)

		return 0;
}
