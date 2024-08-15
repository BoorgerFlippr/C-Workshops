/*
	==================================================
	Workshop #6 (Part-1):
	==================================================
	Name   :
	ID     :
	Email  :
	Section:
*/

#define MAX_PRODUCTS 3
#define SUGGESTED_GRAMS 64
// ----------------------------------------------------------------------------
// structures
struct CatfoodInfo
{
	int sku;
	double productPrice;
	int calPerServing;
	double productWeightLbs;
};



// ----------------------------------------------------------------------------
// function prototypes

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

// 7. Logic entry point
void start(void);

