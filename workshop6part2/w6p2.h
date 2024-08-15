/*
	==================================================
	Workshop #6 (Part-2):
	==================================================
	Name   :
	ID     :
	Email  :
	Section:
*/

// ----------------------------------------------------------------------------
// defines/macros
#define MAX_PRODUCTS 3
#define SUGGESTED_GRAMS 64
#define CONVERT 2.20462

// ----------------------------------------------------------------------------
// structures
struct CatfoodInfo
{
	int sku;
	double productPrice;
	int calPerServing;
	double productWeightLbs;
};

struct ReportData
{
	int sku;
	double productPrice;
	int calPerServing;
	double productWeightLbs;
	double productWeightKg;
	int productWeightG;
	double totalServing;
	double costPerServing;
	double costOfCalPerServing;
};

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* number);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* number);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numOfProducts);

// 4. Get user input for the details of cat food product
struct CatfoodInfo getCatFoodInfo();

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(int sku, double* productPrice, int calPerServing, double* productWeightPounds);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* weightsLbs, double* weightKg);

// 9. convert lbs: g
int  convertLbsG(const double* weightLbs, int* weightsG);

// 10. convert lbs: kg / g
void convertLbs(const double* weightsLbs, double* weightKg, int* weightsG);

// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSizeG, const int totalG, double* totalServings);

// 12. calculate: cost per serving
double calculateCostPerServing(const double* productPrice, const double* numberOfServings, double* costPerServing);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* productPrice, const double* totalCal, double* costPerCal);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatfoodInfo food);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData r, const int cheapestOption);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatfoodInfo food);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start(void);