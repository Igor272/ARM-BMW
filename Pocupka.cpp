#include"Pocupka.h"
#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

void Sale::AddSale(){

	fstream car("Sale.txt", fstream::out | fstream::app);
	cout << "\tДодавання нової покупки" << endl;
	cout << "Введіть модель автомобіля: ";
	cin >> model_car;
	cout << "Введіть ПІБ покупця: ";
	cin >>P>>I>>B;
	cout << "Введіть номер паспорта покупця: ";
	cin >> n_password;
	cout << "Введіть дату покупки: ";
	cin >> date_of_sale;
	cout << "Введіть кількість: ";
	cin >> number;
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Не правильно введено потрібно вводити тільки цифри\n Введіть ще раз:" << endl;
		cin >> number;
	}
	cout << "Введіть суму покупки: ";
	cin >> purchase_amout;
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Не правильно введено потрібно вводити тільки цифри\n Введіть ще раз:" << endl;
		cin >> purchase_amout;
	}

	car << "№ паспорта покупця: " <<n_password<< endl;
	car << "ПІБ покупця:" << P<<" "<<I<<" "<<B << endl;
	car << "Дата покупки:" << date_of_sale << endl;
	car << "Модель придбаного автомобіля: " << model_car << endl;
	car << "Кількість:" << number << endl;
	car << "Сума покупки:" << purchase_amout << endl;
	car << "_________________________________________" << endl;
}
void Sale::Print() {
	string line;
	fstream car;
	car.open("Sale.txt", fstream::in);
	while (getline(car, line))
	{
		cout << line << endl;
	}
	car.close();
	system("pause");
};

void Sale::SearchSale(string model) {
	fstream car;
	car.open("Sale.txt", fstream::in);
	vector<string>sale;
	string line;
	int a = 0,count = 0;
	while (getline(car, line))
	{
		sale.push_back(line);
		size_t foundIndex = line.find(model);
		a++;
		if (foundIndex != string::npos)
		{
			for (int i = a - 4; i < a; i++) {
				cout << sale[i] << endl;
				count++;
			}
		}
	}
	cout <<"\nАвтомобілів цієї моделі було продано: "<< count/4<<endl;
	system("pause");
	system("cls");
}