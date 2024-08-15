/*Glenn Parreno
  115 814 196
  geparreno@myseneca.ca
  IPC 144 NDD
*/

#include <stdio.h>
#define MIN_YEAR 2010
#define MAX_YEAR 2021

int main(void) {

	const int jan = 1, dec = 12;
	int month = 0, year = 0;

	printf("General Well-being Log\n");
	printf("======================\n");

	do
	{

		printf("Set the year and month for the well-being log (YYYY MM): ");
		scanf("%d %d", &year, &month);

		if (year > MAX_YEAR || year < MIN_YEAR)
		{
			printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
		}

		if (month > dec || month < jan)
		{
			printf("   ERROR: Jan.(%d) - Dec.(%d)\n", jan, dec);
		}

	} while ((month > dec || month < jan) || (year > MAX_YEAR || year < MIN_YEAR));

	printf("\n*** Log date set! ***\n\n");

	switch (month) {

	case 1: printf("Log starting date: %d-JAN-01\n", year); break;
	case 2: printf("Log starting date: %d-FEB-01\n", year); break;
	case 3: printf("Log starting date: %d-MAR-01\n", year); break;
	case 4: printf("Log starting date: %d-APR-01\n", year); break;
	case 5: printf("Log starting date: %d-MAY-01\n", year); break;
	case 6: printf("Log starting date: %d-JUN-01\n", year); break;
	case 7: printf("Log starting date: %d-JUL-01\n", year); break;
	case 8: printf("Log starting date: %d-AUG-01\n", year); break;
	case 9: printf("Log starting date: %d-SEP-01\n", year); break;
	case 10: printf("Log starting date: %d-OCT-01\n", year); break;
	case 11: printf("Log starting date: %d-NOV-01\n", year); break;
	case 12: printf("Log starting date: %d-DEC-01\n", year); break;
	}

	return 0;
}
