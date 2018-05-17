#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
volatile sig_atomic_t quitflag;

static void sig_int(int signo){
	if(signo == SIGINT)
					printf("\ninterrupt\n");
	else if(signo == SIGQUIT)
			quitflag = 1;
}

int main(void){
	sigset_t newmask,oldmask,zeromask;

	if(signal(SIGINT,sig_int)==SIG_ERR)
			perror("siganl(SIGINT)error");
	if(signal(SIGQUIT,sig_int)==SIG_ERR)
			perror("signal(SIGQUIT)error");

	sigemptyset(&zeromask);
	sigemptyset(&newmask);
	sigaddset(&newmask,SIGQUIT);

	if(sigprocmask(SIG_BLOCK,&newmask,&oldmask)<0)
			perror("SIG_BLOCK error");

	while(quitflag == 0)
			sigsuspend(&zeromask);

	quitflag = 0;
	
	if(sigprocmask(SIG_SETMASK,&oldmask,NULL)<0)
			perror("SUG_SETMASK error");
	abort();
	exit(0);
}
