#include"Pocupka.h"
#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

void Sale::AddSale(){

	fstream car("Sale.txt", fstream::out | fstream::app);
	cout << "\t��������� ���� �������" << endl;
	cout << "������ ������ ���������: ";
	cin >> model_car;
	cout << "������ ϲ� �������: ";
	cin >>P>>I>>B;
	cout << "������ ����� �������� �������: ";
	cin >> n_password;
	cout << "������ ���� �������: ";
	cin >> date_of_sale;
	cout << "������ �������: ";
	cin >> number;
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "�� ��������� ������� ������� ������� ����� �����\n ������ �� ���:" << endl;
		cin >> number;
	}
	cout << "������ ���� �������: ";
	cin >> purchase_amout;
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "�� ��������� ������� ������� ������� ����� �����\n ������ �� ���:" << endl;
		cin >> purchase_amout;
	}

	car << "� �������� �������: " <<n_password<< endl;
	car << "ϲ� �������:" << P<<" "<<I<<" "<<B << endl;
	car << "���� �������:" << date_of_sale << endl;
	car << "������ ���������� ���������: " << model_car << endl;
	car << "ʳ������:" << number << endl;
	car << "���� �������:" << purchase_amout << endl;
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
	cout <<"\n��������� ���� ����� ���� �������: "<< count/4<<endl;
	system("pause");
	system("cls");
}