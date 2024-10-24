#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

int main(){
	pid_t pid;
	printf("Insert the PID: ");
	scanf("%d", &pid);

	printf("\nSending the signal to process with PID '%d'..\n", pid);

	
	short send_sig_result = kill(pid, 0);
	if (send_sig_result != 0){
		fprintf(stderr, "ERROR: there was an error sending the 0 signal to PID '%d'\n",pid);
		fprintf(stderr, "\tError code: '%s'\n\tError message: '%s'\n", strerrorname_np(errno), strerror(errno));
	} else {
		printf("NULL signal correctly delivered to process with PID '%d'.\n", pid);
	}
	return 0;
}
