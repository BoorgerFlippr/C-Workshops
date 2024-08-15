/*
	==================================================
	Workshop #6 (Part-2):
	==================================================
	Name   :
	ID     :
	Email  :
	Section:
*/



// System Libraries
#include <stdio.h>

// User-Defined Libraries
#include "w6p2.h"

// ----------------------------------------------------------------------------
// PART-1

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

	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data analysis.\n", food);
	printf("NOTE: a 'serving' is %dg\n\n", serving);
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


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* weightsLbs, double* weightKg)
{
	const double* num1 = weightsLbs;
	double num2;

	num2 = *num1 / CONVERT;

	if (weightKg != NULL)
	{
		*weightKg = num2;
	}

	return num2;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int  convertLbsG(const double* weightLbs, int* weightsG)
{
	const double* num1 = weightLbs;
	double num2;
	int num3;

	num2 = *num1 / CONVERT;
	num3 = num2 * 1000;

	if (weightsG != NULL)
	{
		*weightsG = num3;
	}

	return num3;

}

// 10. convert lbs: kg and g
void convertLbs(const double* weightsLbs, double* weightKg, int* weightsG)
{
	double numKg = 0.0, numLbs = 0.0;
	int numG = 0;

	numLbs = *weightsLbs;
	numKg = convertLbsKg(&numLbs, &numKg);
	numG = convertLbsG(&numLbs, &numG);

	*weightKg = numKg;
	*weightsG = numG;
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSizeG, const int totalG, double* totalServings)
{
	const int weight = totalG;
	double num1;

	num1 = (double)weight / (double)servingSizeG;

	if (totalServings != NULL)
	{
		*totalServings = num1;
	}

	return num1;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* productPrice, const double* numberOfServings, double* costPerServing)
{
	const double* price = productPrice;
	const double* serving = numberOfServings;
	double num1;

	num1 = *price / *serving;

	if (costPerServing != NULL)
	{
		*costPerServing = num1;
	}

	return num1;

}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* productPrice, const double* totalCal, double* costPerCal)
{
	const double* price = productPrice;
	const double* total = totalCal;
	double num1;

	num1 = *price / (*total * 325);

	if (costPerCal != NULL)
	{
		*costPerCal = num1;
	}

	return num1;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatfoodInfo food)
{
	struct ReportData report;
	report.sku = food.sku;
	report.productWeightLbs = food.productWeightLbs;
	report.calPerServing = food.calPerServing;
	report.productPrice = food.productPrice;
	convertLbs(&food.productWeightLbs, &report.productWeightKg, &report.productWeightG);
	report.totalServing = calculateServings(SUGGESTED_GRAMS, report.productWeightG, &report.totalServing);
	report.costPerServing = calculateCostPerServing(&report.productPrice, &report.totalServing, &report.costPerServing);
	report.costOfCalPerServing = calculateCostPerCal(&report.productPrice, &report.totalServing, &report.costOfCalPerServing);

	return report;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("\nAnalysis Report (Note: Serving = %dg)\n", SUGGESTED_GRAMS);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData r, const int cheapestOption)
{
	if (cheapestOption == 1)
	{
		printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf ***\n", r.sku, r.productPrice, r.productWeightLbs, r.productWeightKg, r.productWeightG, r.calPerServing, r.totalServing, r.costPerServing, r.costOfCalPerServing);
	}
	else
	{
		printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf\n", r.sku, r.productPrice, r.productWeightLbs, r.productWeightKg, r.productWeightG, r.calPerServing, r.totalServing, r.costPerServing, r.costOfCalPerServing);
	}
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatfoodInfo food)
{
	printf("\nFinal Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf\n\n", food.sku, food.productPrice);
	printf("Happy Shopping!");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	struct CatfoodInfo food[MAX_PRODUCTS];
	struct ReportData report[MAX_PRODUCTS];
	int i, cheapestOption;
	double minCostPerServ = 9999;

	openingMessage(MAX_PRODUCTS);

	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		printf("Cat Food Product #%d\n", i + 1);
		printf("--------------------\n");

		food[i] = getCatFoodInfo();
		report[i] = calculateReportData(food[i]);
		printf("\n");
	}

	displayCatFoodHeader();
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		displayCatFoodData(food[i].sku, &food[i].productPrice, food[i].calPerServing, &food[i].productWeightLbs);
	}

	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		if (report[i].costPerServing < minCostPerServ)
			minCostPerServ = report[i].costPerServing;
	}

	displayReportHeader();
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		if (minCostPerServ == report[i].costPerServing)
		{
			displayReportData(report[i], 1);
		}
		else
		{
			displayReportData(report[i], 0);
		}
	}

	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		if (minCostPerServ == report[i].costPerServing)
			displayFinalAnalysis(food[i]);
	}

	return;
}