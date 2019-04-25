#include<stdio.h>
#include<time.h>
#include<unistd.h>

void wait(float duration){
	time_t start, end;
	double elapsed;  // seconds
	start = time(NULL);
	int terminate = 1;
	while (terminate) {
		end = time(NULL);
		elapsed = difftime(end, start);
		if (elapsed >= duration /* seconds */)
			terminate = 0;
		else  // No need to sleep when 90.0 seconds elapsed.
			usleep(duration*1000000);
	}
}

/*int main(){
	wait(4.00);
	printf("Hello: Soryy I forgot.\n");
}*/
