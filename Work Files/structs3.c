#include <stdio.h>
#include <stdlib.h>


struct Date {
	int Month;			/* Members */
	int Day;
	int Year;
};

struct Date AddDecade(struct Date);

int main(int argc, char *argv[])
{
	struct Date BDay;

	char buffer[50];

	printf("What month were you born? ");
	BDay.Month = atoi(gets_s(buffer, 50));	

	printf("What day were you born? ");
	BDay.Day = atoi(gets_s(buffer, 50));

	printf("What year were you born? ");
	BDay.Year = atoi(gets_s(buffer, 50));

	printf("You were born on %d, %d, %d?\n", BDay.Month, BDay.Day, BDay.Year);

	BDay = AddDecade(BDay);
	
	printf("You will be 10 years older on %d, %d, %d\n", BDay.Month, BDay.Day, BDay.Year);

}

struct Date AddDecade(struct Date Target) {

	Target.Year += 10;
	return Target;

}
