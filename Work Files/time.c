#include <stdio.h>
#include <time.h>

main(){


	time_t time_val;
	struct tm *tp;
	char buffer[100];
	
	time_val = time(NULL);
	printf("Time_Value: %li\n",time_val);

	tp = localtime(&time_val);

	printf("Hours:%d, Minutes:%d, Seconds:%d\n",
	        tp->tm_hour, tp->tm_min, tp->tm_sec);

	printf("asctime()==%s\n",asctime(tp));

	strftime(buffer, 99, "%A %B %d %Y at %I:%M:%S%p", tp);
	printf("%s\n",buffer);

}