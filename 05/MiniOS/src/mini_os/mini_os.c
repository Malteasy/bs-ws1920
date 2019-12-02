#include <stdio.h>
#include <stdlib.h>
#include "mini_os.h"

int
main(void)
{

	int setT,sig;



	if (create_process("init", init, NULL) == -1){
		perror("Creating init process failed");
		return EXIT_FAILURE;
	}

	//Zeitgebersignal anfordern
	struct itimerval tVal, oVal;
	tVal.it_interval.tv_sec = 0.5
	oVal.it_value = 0;

	setT = settimer(2, &tVal, &oVal);
	//Kontrolle ob läuft?

	//sig = sigaction()

	if (start_scheduler()){
		perror("Scheduling failed");
		return EXIT_FAILURE;
	}
	schedule();
	
	puts("Scheduler returned, all processes done");
	return EXIT_SUCCESS;
}
