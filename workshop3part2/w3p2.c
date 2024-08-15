/*Glenn Parreno
  115 814 196
  geparreno@myseneca.ca
  IPC 144 NDD
*/

#include <stdio.h>
#define MIN_YEAR 2010
#define MAX_YEAR 2021
#define LOG_DAYS 3

main() {

	const int jan = 1, dec = 12;
	int month = 0, year = 0, i, day;
	double mRating, eRating,
		totalMRating = 0, totalERating = 0;

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

	for (i = 0; i < LOG_DAYS; i++)
	{
		day = i;

		switch (month)
		{

		case 1: printf("%d-JAN-%02d\n", year, day + 1); break;
		case 2: printf("%d-FEB-%02d\n", year, day + 1); break;
		case 3: printf("%d-MAR-%02d\n", year, day + 1); break;
		case 4: printf("%d-APR-%02d\n", year, day + 1); break;
		case 5: printf("%d-MAY-%02d\n", year, day + 1); break;
		case 6: printf("%d-JUN-%02d\n", year, day + 1); break;
		case 7: printf("%d-JUL-%02d\n", year, day + 1); break;
		case 8: printf("%d-AUG-%02d\n", year, day + 1); break;
		case 9: printf("%d-SEP-%02d\n", year, day + 1); break;
		case 10: printf("%d-OCT-%02d\n", year, day + 1); break;
		case 11: printf("%d-NOV-%02d\n", year, day + 1); break;
		case 12: printf("%d-DEC-%02d\n", year, day + 1); break;

		}

		do
		{
			printf("   Morning rating (0.0-5.0): ");
			scanf("%lf", &mRating);

			if (mRating < 0.0 || mRating > 5.0)
				printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");

		} while (mRating < 0.0 || mRating > 5.0);

		do
		{
			printf("   Evening rating (0.0-5.0): ");
			scanf("%lf", &eRating);

			if (eRating < 0.0 || eRating > 5.0)
				printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");

		} while (eRating < 0.0 || eRating > 5.0);

		totalMRating += mRating;
		totalERating += eRating;

		printf("\n");
	}

	printf("Summary\n");
	printf("=======\n");
	printf("Morning total rating: %0.3lf\n", totalMRating);
	printf("Evening total rating: %0.3lf\n", totalERating);
	printf("----------------------------\n");
	printf("Overall total rating: %0.3lf\n\n", totalMRating + totalERating);
	printf("Average morning rating:  %0.1lf\n", totalMRating / LOG_DAYS);
	printf("Average evening rating:  %0.1lf\n", totalERating / LOG_DAYS);
	printf("----------------------------\n");
	printf("Average overall rating:  %0.1lf", 
		(totalMRating + totalERating) / (LOG_DAYS * 2));

	return 0;
}