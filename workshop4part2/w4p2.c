/*
Glenn Parreno
115 814 196
geparreno@myseneca.ca
IPC 144 NDD
*/

#include <stdio.h>
#define MAX_WL 10
#define MIN_WL 1

int main(void)
{
	const double maxIncome = 400000.00, minIncome = 500.00, minCost = 100.00;
	int priority[MAX_WL], wlItems, i, choice, year, month, filter, note, f;
	double cost[MAX_WL], income, tCost = 0, fCost = 0;
	char options[MAX_WL];

	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n\n");

	do
	{
		printf("Enter your monthly NET income: $");
		scanf("%lf", &income);

		if (income > maxIncome)
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $%0.2lf\n", maxIncome);
		else if (income < minIncome)
			printf("ERROR: You must have a consistent monthly income of at least $%0.2lf\n", minIncome);
		printf("\n");
	} while (income > maxIncome || income < minIncome);

	do
	{
		printf("How many items do you want to forecast?: ");
		scanf("%d", &wlItems);

		if (wlItems > MAX_WL || wlItems < MIN_WL)
			printf("ERROR: List is restricted to between %d and %d items.\n", MIN_WL, MAX_WL);
		printf("\n");
	} while (wlItems > MAX_WL || wlItems < MIN_WL);

	for (i = 0; i < wlItems; i++)
	{
		printf("Item-%d Details:\n", i + 1);
		do
		{
			printf("   Item cost: $");
			scanf("%lf", &cost[i]);
			if (cost[i] < minCost)
				printf("      ERROR: Cost must be at least $%0.2lf\n", minCost);
		} while (cost[i] < minCost);

		tCost += cost[i];

		do
		{
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d", &priority[i]);
			if (priority[i] > 3 || priority[i] < 1)
				printf("      ERROR: Value must be between 1 and 3\n");
		} while (priority[i] > 3 || priority[i] < 1);

		do
		{
			printf("   Does this item have financing options? [y/n]: ");
			scanf(" %c", &options[i]);
			if (options[i] != 'y' && options[i] != 'n')
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
		} while (options[i] != 'y' && options[i] != 'n');

		printf("\n");
	}

	printf("Item Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");

	for (i = 0; i < wlItems; i++)
	{
		printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], options[i], cost[i]);
	}

	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n\n", tCost);
	
	do
	{
		note = 0;
		printf("How do you want to forecast your wish list?\n");
		printf(" 1. All items (no filter)\n");
		printf(" 2. By priority\n");
		printf(" 0. Quit/Exit\n");
		printf("Selection: ");
		scanf("%d", &choice);

		if (choice > 2 || choice < 0)
			printf("\nERROR: Invalid menu selection.\n");

		switch (choice)
		{
		case 1:
			for (i = 0; i < wlItems; i++)
			{
				if (options[i] == 'y')
					note = 1;
			}
			year = (tCost / income) / 12;
			month = ((int)tCost / (int)income) % 12;
			printf("\n====================================================\n");
			printf("Filter:   All items\n");
			printf("Amount:   $%1.2lf\n", tCost);
			printf("Forecast: %d years, %d months\n", year, month + 1);
			if (note == 1)
			{
				printf("NOTE:  Financing options are available on some items.\n");
				printf("       You can likely reduce the estimated months.\n");
			}
			printf("====================================================\n");
			break;
		case 2:
			fCost = 0;
			printf("\nWhat priority do you want to filter by? [1-3]: ");
			scanf("%d", &filter);
			for (i = 0; i < wlItems; i++)
			{
				if (priority[i] == filter)
				{
					fCost += cost[i];

					if (options[i] == 'y')
					{
						note = 1;
					}
				}
			}
			year = (fCost / income) / 12;
			month = ((int)fCost / (int)income) % 12;
			printf("\n====================================================\n");
			printf("Filter:   by priority (%d)\n", filter);
			printf("Amount:   $%1.2lf\n", fCost);
			printf("Forecast: %d years, %d months\n", year, month + 1);
			if (note == 1)
			{
				printf("NOTE: Financing options are available on some items.\n");
				printf("      You can likely reduce the estimated months.\n");
			}
			printf("====================================================\n");
			break;
		}

		printf("\n");
	} while (choice != 0);
	
	printf("Best of luck in all your future endeavors!\n");
	return 0;
}