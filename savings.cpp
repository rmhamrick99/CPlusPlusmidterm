#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <fstream>
using namespace std;

//Heading
char PT1[] = "SAVINGS PLAN GENERATOR";

class Savings
{
public:
	void mainLine(void);
private:
	double dPayRate;
	int week;
	double dTotalHrs;
	double dHrsWorked;
	double dGrossPay;
	double dNetPay;
	double dClothesSavings;
	double dSuppliesSavings;
	double dSavingsBonds;
	double dParentsBonds;

	void accumulate();
	void calculate(double dGrossPay);
	void output(double dGrossPay, double dNetPay, double dClothesSavings, double dSuppliesSavings, double dSavingsBonds, double dParentsBonds);
	void PrnHeadings(void);
};
void main(void)
{
	Savings rl;
	rl.mainLine();
	
	system("pause");
	return;
}

void Savings::mainLine()
{
	PrnHeadings();
	accumulate();
	
}

void Savings::accumulate()
{
	dTotalHrs = 0;
	cout << "What is your payrate per hour?" << endl;
	cin >> dPayRate;
	for (week = 1; week <= 5; week++)
	{
		cout << "Enter your hours for week #" << week << endl;
		cin >> dHrsWorked;
		dTotalHrs = dTotalHrs + dHrsWorked;
	}
	dGrossPay = dTotalHrs * dPayRate;
	calculate(dGrossPay);
}

void Savings::calculate(double dGrossPay)
{
	dNetPay = dGrossPay - dGrossPay * 0.14;
	dClothesSavings = dNetPay * 0.1;
	dSuppliesSavings = dNetPay * 0.01;
	dSavingsBonds = (dNetPay - dSuppliesSavings - dClothesSavings) * 0.25;
	dParentsBonds = dSavingsBonds * 0.5;
	output(dGrossPay, dNetPay, dClothesSavings, dSuppliesSavings, dSavingsBonds, dParentsBonds);
}

void Savings::output(double dGrossPay, double dNetPay, double dClothesSavings, double dSuppliesSavings, double dSavingsBonds, double dParentsBonds)
{	
	cout << endl;
	cout << "Gross Pay: " << dGrossPay << endl;
	cout << "Net Pay: " << dNetPay << endl;
	cout << "Savings for Clothes: " << dClothesSavings << endl;
	cout << "Savings for School Supplies: " << dSuppliesSavings << endl;
	cout << "Savings to Purchase Bonds: " << dSavingsBonds << endl;
	cout << "Parents will match you in savings to purchase bonds: " << dParentsBonds << endl<<endl;
}
void Savings::PrnHeadings(void)
{
	cout << PT1 << endl;
	cout << endl << endl;
	return;
}