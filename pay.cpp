// Finn Nguyen
// CPSC 301-01 
// Tues-Thurs: 10-12:50pm 

#include <iostream>
#include <iomanip>
#include <fstream>
#include "person.h"
using namespace std;

void readData(Person a[], int &n);
void writeData(Person a[], int n);

int main()
{
	Person a[20];
	int n;

	readData(a, n);
	writeData(a, n);

	return 0;
}

void readData(Person a[], int &n)
{
	ifstream fin;
	string first, last;
	float hours, rate;

	n = 0;

	fin.open("input.txt");

	if (!fin)
	{
		cout << "Error: could not open file 'input.txt'" << endl;
		return;
	}

	while (fin >> first >> last >> hours >> rate)
	{
		a[n].setFirstName(first);
		a[n].setLastName(last);
		a[n].setHoursWorked(hours);
		a[n].setPayRate(rate);
		n++;
	}

	fin.close();
}

void writeData(Person a[], int n)
{
	ofstream fout;

	fout.open("output.txt");

	if (!fout)
	{
		cout << "Error: could not open file 'output.txt'" << endl;
		return;
	}

	fout << fixed << showpoint << setprecision(2);

	for (int i = 0; i < n; i++)
	{
		fout << a[i].fullName() << " " << a[i].totalPay() << endl;
	}

	fout.close();
}
