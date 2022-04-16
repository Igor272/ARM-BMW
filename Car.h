#pragma once
#include<string>

using namespace std;

class Car {
	int year, eng, kilkn, price;
	double acel, ros;
	string model, typef, btype, comp, color, vin;
public:
	string getModel(string model) { return model; };
	string getTypef(string typef) { return typef; };
	string getBtype(string btype) { return btype; };
	string getComp(string comp) { return comp; };
	string getColor(string color) { return color; };
	string getVin(string vin) { return vin; };
	int getYear(int year){ return year; };
	int getEng(int eng) { return eng; };
	int getKilkn(int kilkn) { return kilkn; };
	int getPice(int price) { return price; };
	double getAcel(double acel) { return acel; };
	double getRos(double ros) { return ros; };
	//Car();
	void AddCar();
	void Print();
	void SearchCar(string m);
	int SearchCars(string model);
	void DeleteCar();
	

};