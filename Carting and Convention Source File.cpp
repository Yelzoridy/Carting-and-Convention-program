/* 
Coder: Yehia Elzoridy
Program Name:  Catering and Convention Services Calculator 
Description : A Program that calculates payment of catering and conventions services. 
The program takes multiple inputs and uses them to calculate the final bills for customers.

*/ 

#include <iostream>
#include <ctype.h>
#include <iomanip> 
#include <string>
using namespace std;
 
 
 
/* 
Function declaration along with parameters. I've made parameters same as arguments on purpose,
that way I don't get confused while adding the arguments in main function using autosuggestion.
*/ 



void userInput(int& childernCount, int& adultCount);



// Group of functions to get user input for the rest of questions. void parameter because they don't take any input. 
char gethallChoice (void);
char getmealType (void);
char getweekend (void);
char getspeedyPayment (void);

// function to count the Speedy Payment Rate. 
float speedyDiscount(float);


// Process Function to proccess  input and caluclates nesessery values for output 

void costCalculations( int childernCount, int adultCount, char hallChoice, char mealType,char weekend,char CspeedyPayment,
float& totalCostAdults,float& totalCostChild, float& FspeedyPayment, float& totalFoodCost,
const float TAX_RATE, const float GRATUITY,float& totalBill,float& balanceDue, float&taxedAmount, float& gratuityAmount, float &childMealCost,string& weekendResult, 
string& mealPlan,string& hallPlan, float& hallCost,float& mealCost,float& weekendCost );



void billGeneration (int childernCount,int   adultCount ,float childMealCost,
float	totalCostAdults, float totalCostChild, float totalFoodCost,
const float TAX_RATE, const float GRATUITY, float totalBill, float balanceDue, float taxedAmount, float gratuityAmount, string weekendResult, string mealPlan,
float FspeedyPayment,float hallCost, string hallPlan, float mealCost,float weekendCost );



//Global Variables Declaration 
const float TAX_RATE = 0.07;
const float GRATUITY = 0.20;

//These are Global Constants because in my code they are used in multiple functions. 
const float DELUXE_MEAL = 25.95;
const float STANDARD_MEAL = 21.75;
const float HALL_A = 100.00;
const float HALL_B = 85.00;
const float HALL_C = 75.00;
const float HALL_D = 65.00;
const float HALL_H = 00.00;

 
int main () {
   	
	int childernCount;
	int adultCount;
	float totalCostAdults;
	float totalCostChild;
	float totalFoodCost;
	float taxedAmount;
	float gratuityAmount;
	float totalBill;
	float balanceDue;
	char hallChoice; 
	char mealType;
	char CspeedyPayment;
	char weekend;
	float FspeedyPayment;
	float childMealCost;
	string weekendResult;
	string mealPlan;
	string hallPlan;
	float hallCost;
	float mealCost;
	float weekendCost;

   	//Getting User Input along with their hall choice, meal type, speed payment, and weekend reservation. 
  	userInput(childernCount,adultCount);
  	
  	hallChoice =  gethallChoice();
  	
  	hallChoice = toupper(hallChoice);
  	
  	mealType = getmealType();
  	mealType = toupper(mealType);
  	
  	weekend = getweekend();
  	weekend = toupper(weekend);
  	
  	CspeedyPayment= getspeedyPayment();
  	CspeedyPayment = toupper (CspeedyPayment);
  	

	costCalculations( childernCount, adultCount,  hallChoice, mealType, weekend, CspeedyPayment,
	 	totalCostAdults, totalCostChild,  FspeedyPayment,  totalFoodCost,
	 	TAX_RATE, GRATUITY,totalBill, balanceDue, taxedAmount, gratuityAmount , 
 		childMealCost,  weekendResult,  mealPlan, hallPlan, hallCost, mealCost, weekendCost);
 

 	billGeneration(childernCount,  adultCount , childMealCost,
		totalCostAdults,  totalCostChild,  totalFoodCost,
		TAX_RATE, GRATUITY,totalBill,balanceDue, taxedAmount,  gratuityAmount, weekendResult, mealPlan, FspeedyPayment,hallCost,hallPlan,mealCost, weekendCost );
	
	

   return 0;
}

// Input functions: 

// void function to get count for both adults and childern then pass them by reference.
void userInput (int& childernCount, int& adultCount) 
{
		cout<<"\n\nWelcome to Passaic County Catering and Convention Services"<<endl;
		cout<<"\nPlease fill out this form, so we can get your bill.\n"<< endl;
	
	
		cout<< "\nCan we please get the number of Childern with you\n"<<endl;;
		cin >> childernCount;
		
		cout<< "\nPlease enter the number of adults: \n"<<endl;;
		cin >> adultCount;
			
}
// char function to get hallchoice from user. 
char gethallChoice (void)
{

	char answer;
	
	cout<< "\nPlease Choose one of the following Halls:"<< endl;
	
	
	cout<< "\n Hall -A\t\t$100.00"<<endl;
	cout<< "\n Hall -B\t\t$85.00"<<endl;
	cout<< "\n Hall -C\t\t$75.00"<< endl;
	cout<< "\n Hall -D\t\t$65.00"<<endl;
	cout<< "\n Hall -H\t\tis home"<<endl;
	
	//I've used this since using answer[] for somereason breaks the program. 	
	cout<< "\nPlease enter only the letter with the hall."<< endl;
	
	cin >> answer; 
	return answer;
}
// char function to get meal choice from user. 
char getmealType (void){
	char answer;
	cout<< "\nPlease Choose one of the following meals:"<< endl;
	
	
	cout<< "\n Deluxe Meal -A\t\t$"<< DELUXE_MEAL<<endl;
	cout<< "\n Standad Meal -B\t$"<< STANDARD_MEAL<<endl;

	
	//I've used this since using answer[] for somereason breaks the program. 	
	cout<< "\nPlease enter only the letter with the meal."<< endl;
	
	cin >> answer; 
	return answer;
}
// Function to get Weekend Answer from user.
char getweekend (void){
	
	char answer;
	
	cout<< "\nIs Services Done on Weekend?: "<< endl;
	cout<< "\n(Y/N)"<< endl;
	
	cin >> answer; 
	return answer;
	
}
// Function to get Speedy Payment from user.
char getspeedyPayment (void){
	char answer;
	
	cout<< "\nWould you Like to Enroll in Speedy Payment: "<< endl;
	cout<< "\n(Y/N)"<< endl;
	
	cin >> answer; 
	return answer;
}




// Process Function to procces the total cost of adult & child meal, hall cost, weekend charge if any, and taxes.

void costCalculations(int childernCount, int adultCount, char hallChoice, char mealType,char weekend,char CspeedyPayment,
float& totalCostAdults,float& totalCostChild, float& FspeedyPayment, float& totalFoodCost,
const float TAX_RATE, const float GRATUITY,float& totalBill,float& balanceDue, float&taxedAmount, float& gratuityAmount , 
float& childMealCost, string& weekendResult, string& mealPlan,string& hallPlan,float& hallCost,float& mealCost,float& weekendCost)
{
	//Defining local constants and variables. 

	const float CHILD_RATE = 0.60;
	const float weekendRate = 0.10;
	
	float hallCosts;
	float totalBillPreTax;
	float speedyPaymentRate;

	
	
	// Switch Statement to  get Meal Type
	switch (mealType){
		case 'A': 
			mealCost =  DELUXE_MEAL;
			mealPlan = "DELUXE MEAL";
			break;
		case 'B':
			mealCost = STANDARD_MEAL;
			mealPlan = "STANDARD MEAL";
			break;
		// No Default needed for that case
	}	
	
	// Calculating The costs for bill generation
	totalCostAdults =  mealCost * adultCount;
	
	childMealCost = CHILD_RATE * mealCost; 
	
	totalCostChild = childMealCost * childernCount;
	
	totalFoodCost = totalCostChild + totalCostAdults;
	
	gratuityAmount = totalFoodCost * GRATUITY; 
	
	// Switch Statement to  get Hall Type
	
	switch (hallChoice){
		
		case 'A':
			hallCost = HALL_A;
			hallPlan = "Hall A";
			break;
			
		case 'B':
			hallCost = HALL_B;
			hallPlan = "Hall B";
			break;
			
		case 'C':
			hallCost = HALL_C;
			hallPlan = "Hall C";
			break;
		case 'D':
			hallCost = HALL_D;
			hallPlan = "Hall D";
			break;
		case 'H':
			hallCost = HALL_H;
			hallPlan = "Hall H";
			break;
			// No Default needed for that case
	}
	
	
	
	switch (weekend) {
		case 'Y':
			weekendCost = weekendRate * (totalFoodCost + gratuityAmount + hallCost);
			weekendResult= "YES";
			break;
		case 'N':
			weekendCost = 0;
			weekendResult= "NO";
			break;
				// No Default needed for that case
	}
	
	totalBillPreTax = totalFoodCost  + hallCost + weekendCost; 
	
	taxedAmount = TAX_RATE * totalBillPreTax; 
	
	totalBill = totalBillPreTax + taxedAmount + gratuityAmount; 
	
	switch (CspeedyPayment) {
		case 'Y':
			speedyPaymentRate = speedyDiscount(totalBill );
			break;
		case 'N':
			speedyPaymentRate = 0;
			break;
	}
		
	
	FspeedyPayment = speedyPaymentRate * totalBill ; 

	
	
	
	balanceDue = totalBill - FspeedyPayment; // should be total bill only if FspeedyPayment = 0 ( a - 0 = a )

}



// Float Function that calculated speedy payment discount rate. 

float speedyDiscount(float totalBill){
	//Discount Rates Defined as instructed in Project Paper. 
	const float DISCOUNT_RATE_A = 0.01;
	const float DISCOUNT_RATE_B = 0.02;		
	const float DISCOUNT_RATE_C = 0.04;		
	const float DISCOUNT_RATE_D = 0.05;		
	const float DISCOUNT_RATE_E = 0.07;		
	float DiscountRate; 
	
	if ( totalBill < 500.00){
			DiscountRate = DISCOUNT_RATE_A; 
				
		}
	else 
		if (500.00  < totalBill && totalBill < 999.0 ){ 
			DiscountRate = DISCOUNT_RATE_B;	
		}
	else
		if (1000.00 < totalBill && totalBill < 4999.00){
			DiscountRate = DISCOUNT_RATE_C;
		}
	else 
		if ( 5000 < totalBill && totalBill < 9999) {
			DiscountRate = DISCOUNT_RATE_D;
		}
	else 
		if (totalBill > 10000) { 
			DiscountRate = DISCOUNT_RATE_E;
		}
	
	return DiscountRate;
}

// Bill function that generate bill from inputs from the above functions.

void billGeneration(int childernCount,int   adultCount ,float childMealCost,
float	totalCostAdults, float totalCostChild, float totalFoodCost,
const float	TAX_RATE, const float GRATUITY, float totalBill, float balanceDue, float taxedAmount, 
float gratuityAmount, string weekendResult, string mealPlan, float FspeedyPayment, float hallCost,string hallPlan,float mealCost,float weekendCost )
{
	
	//TaxRate
	float taxPercentage = GRATUITY * 100; 
	
	// outputing results to a File
	cout << fixed << showpoint<< setprecision(2);	
	system ("CLS");
	cout <<"/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/" << endl;
	cout <<"\tCaswell Cartering and Convention Services"<<endl;
	cout <<"\t\t\tFinal Bill "<<endl;
	cout <<"/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/" << endl;
		
	cout << "\nNumber of Adults:\t" << adultCount<< endl;
	cout << "Number of Childern:\t" << childernCount <<endl;
	cout << "Gratuity:\t\t"<< taxPercentage<<"%" <<endl;
	cout << "Weekend:\t\t "<< weekendResult <<endl;
	
	cout<< "Cost for "<< mealPlan <<" for adult:\t$"<< mealCost<<endl;
	cout<< "Cost for "<< mealPlan <<" for Child:\t$"<< childMealCost<<endl;
	
	cout << "---------------------------------------------------------"<<endl;
	
	cout<<"\nTotal cost for adult meals:\t\t$"<< totalCostAdults<< endl;
	cout<<"Total cost for child meals:\t\t$"<< totalCostChild << endl;
	
	
	cout<<"\nTotal food cost:\t$"<< totalFoodCost << endl;
	cout << "---------------------------------------------------------"<<endl;
	
	cout <<"\nGratuity:\t$"<< gratuityAmount <<endl;
	
	cout<<hallPlan << "Room Fee\t\t"<<hallCost<<endl;
	cout<<"Weekend Cost:\t\t " << weekendCost<< endl;
	
	// WeekendCharge 
	
	cout<<"Taxes:\t\t"<< taxedAmount <<endl;
	cout << "---------------------------------------------------------"<<endl;
	
	cout << "Subtotal:\t" << totalBill << endl;
	
	
	cout << "\nless Speedy Payment\t\t" << FspeedyPayment << endl;
	
	cout << "\nBalance Due:\t\t " << balanceDue << endl;
	
	cout <<"/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/" << endl;	
}
















































































