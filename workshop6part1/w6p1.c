/*
	==================================================
	Workshop #6 (Part-1):
	==================================================
	Name   :
	ID     :
	Email  :
	Section:
*/

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>

// User Libraries
#include "w6p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* number)
{
	int num = 0;
	do
	{
		scanf("%d", &num);
		if (num < 1)
			printf("ERROR: Enter a positive value: ");
	} while (num < 1);

	if (number != NULL)
		*number = num;

	return num;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* number)
{
	double num = 0.0;
	do
	{
		scanf("%lf", &num);
		if (num < 1)
			printf("ERROR: Enter a positive value: ");
	} while (num < 1);

	if (number != NULL)
		*number = num;

	return num;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numOfProducts)
{
	const int food = MAX_PRODUCTS;
	const int serving = SUGGESTED_GRAMS;

	printf("===========================\n");
	printf("Starting Main Program Logic\n");
	printf("===========================\n\n");
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data analysis.\n", food);
	printf("Note a 'serving' is %dg\n\n", serving);
	return;
}

// 4. Get user input for the details of cat food product
struct CatfoodInfo getCatFoodInfo()
{
	struct CatfoodInfo food;
	
	int sku = 0;
	printf("SKU           : ");
	while (sku <= 0)
		sku = getIntPositive(NULL);
	food.sku = sku;

	double productPrice = 0;
	printf("PRICE         : $");
	while (productPrice <= 0)
		productPrice = getDoublePositive(NULL);
	food.productPrice = productPrice;

	double productWeightLbs = 0;
	printf("WEIGHT (LBS)  : ");
	while (productWeightLbs <= 0)
		productWeightLbs = getDoublePositive(NULL);
	food.productWeightLbs = productWeightLbs;

	int calPerServing = 0;
	printf("CALORIES/SERV.: ");
	while (calPerServing <= 0)
		calPerServing = getIntPositive(NULL);
	food.calPerServing = calPerServing;

	return food;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(int sku, double* productPrice, int calPerServing, double* productWeightPounds)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *productPrice, *productWeightPounds, calPerServing);
}

// 7. Logic entry point
void start(void)
{
	struct CatfoodInfo food[MAX_PRODUCTS];
	openingMessage(MAX_PRODUCTS);

	int i;
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		printf("Cat Food Product #%d\n", i + 1);
		printf("--------------------\n");

		food[i] = getCatFoodInfo();
		printf("\n");
	}
	
	displayCatFoodHeader();
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		displayCatFoodData(food[i].sku, &food[i].productPrice, food[i].calPerServing, &food[i].productWeightLbs);
	}
	return;
}