//Glenn Parreno
//115 814 196
//geparreno@myseneca.ca
//IPC144 NDD

#include <stdio.h>

int main(void)
{
	double convertToCoins, serviceFee;
	int toonies, loonies, quarters, dimes, nickels, pennies;

	printf("Change Maker Machine\n");
	printf("====================\n");
	printf("Enter dollars and cents amount to convert to coins: $");
	scanf("%lf", &convertToCoins);
	serviceFee = convertToCoins * 0.05;
	printf("Service fee (5.0 percent): %0.2lf\n", serviceFee);
	convertToCoins -= serviceFee;
	printf("Balance to dispense: $%0.2lf\n\n", convertToCoins);
	
	toonies = ((int)convertToCoins / 2) % 200;
	convertToCoins = convertToCoins - (toonies * 2);
	printf("$2.00 Toonies  X %d (remaining: $%0.2f)\n", toonies, convertToCoins);

	loonies = ((int)convertToCoins / 1) % 100;
	convertToCoins -= loonies;
	printf("$1.00 Loonies  X %d (remaining: $%0.2f)\n", loonies, convertToCoins);

	quarters = convertToCoins / 0.25;
	quarters %= 25;
	convertToCoins = convertToCoins - (quarters * 0.25);
	printf("$0.25 Quarters X %d (remaining: $%0.2f)\n", quarters, convertToCoins);

	dimes = convertToCoins / 0.10;
	dimes %= 10;
	convertToCoins = convertToCoins - (dimes * 0.10);
	printf("$0.10 Dimes    X %d (remaining: $%0.2f)\n", dimes, convertToCoins);

	nickels = convertToCoins / 0.05;
	nickels %= 10;
	convertToCoins = convertToCoins - (nickels * 0.05);
	printf("$0.05 Nickels  X %d (remaining: $%0.2f)\n", nickels, convertToCoins);

	pennies = convertToCoins / 0.01;
	convertToCoins = convertToCoins - (pennies * 0.01);
	printf("$0.01 Pennies  X %d (remaining: $%0.2f)\n", pennies, convertToCoins);

	printf("\nAll coins dispensed!\n");



	printf("================================================================\n");

	printf("10.10 = %.15lf\n", 10.10);
	printf("10.12 = %.2lf\n", 10.12);
	printf("10.15 = %.15lf\n", 10.15);

	
}