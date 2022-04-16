#pragma once
#include<string>

using namespace std;

class Sale{
	string P, I, B, date_of_sale,model_car,n_password;
	int number,purchase_amout;
public:
	string getP(string P) { return P; };
	string getI(string I) { return I; };
	string getB(string B) { return B; };
	string getDate_of_sale(string date_of_sale) { return date_of_sale; };
	string getModel_car(string model_car) { return model_car; };
	string getN_password(string n_password) { return n_password; };
	int getNumber(int number) { return number; };
	int getPurchase_amout(int purchase_amout) { return purchase_amout; };
	
	void AddSale();
	void Print();
	void SearchSale(string model);
};
