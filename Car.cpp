#include"Car.h"
#include<iostream>
#include<vector>
#include<fstream>
#include<Windows.h>

using namespace std;

void Car::AddCar()
{
	fstream car("Car.txt", fstream::out | fstream::app);//�������� ����� car
	cout << "\t��������� ���� �����" << endl;
	cout << "������ ������: ";
	cin >> model;
	cout<< "������ ��� ������: ";
	cin >> typef;
	cout << "������ �� �������: ";
	cin >> year;
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "�� ��������� ������� ������� ������� ����� �����\n ������ �� ���:" << endl;
		cin >> year;
	}
	cout << "������ ��'�� �������: ";
	cin >> eng;
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "�� ��������� ������� ������� ������� ����� �����\n ������ �� ���:" << endl;
		cin >> eng;
	}
	cout << "������ ����� �� 100 ��������: ";
	cin >> acel;
	cout <<"������ ������ ������: ";
	cin >> ros;
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "�� ��������� ������� ������� ������� ����� �����\n ������ �� ���:" << endl;
		cin >> ros;
	}
	cout << "������ ��� ������: ";
	cin >> btype;
	cout << "������ �����������: ";
	cin >> comp;
	cout << "������ ������� ������� ���: ";
	cin >> kilkn;
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "�� ��������� ������� ������� ������� ����� �����\n ������ �� ���:" << endl;
		cin >> kilkn;
	}
	cout << "������ ����: ";
	cin >> color;
	cout << "������ ����: ";
	cin >> price;
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "�� ��������� ������� ������� ������� ����� �����\n ������ �� ���:" << endl;
		cin >> price;
	}
	cout << "������ VIN ���: ";
	cin >> vin;
	//���� � ���� Car.txt
	car << "\tBMW " << model << endl;
	car << "��� ������:" << typef << endl;
	car << "г� �������:" << year <<"�."<< endl;
	car << "��'�� �������:" << eng<<"��3"<< endl;
	car << "����� �� 100 ��������:" << acel<<"c."<< endl;
	car << "������ ������:" << ros <<"�."<<endl;
	car << "��� ������:" << btype << endl;
	car << "�����������:" << comp << endl;
	car << "ʳ������ ������� ���:" << kilkn << endl;
	car << "����:" << color << endl;
	car << "ֳ��:" << price <<"$"<< endl;
	car << "VIN ���:" << vin << endl;
	car << "_________________________________________" << endl;

}
void Car::Print(){
	string line;
	fstream car;
	car.open("Car.txt", fstream::in);//�������� ����� car
while (getline(car, line))
	{
		cout<<line<<endl;
	}
	car.close();
	system("pause");
};
void Car::SearchCar(string m){
	int a=0;
	char* str = new char[1024];
	string line,s;
	fstream car("Car.txt", fstream::in|fstream::out|fstream::app);//�������� ����� car

	while (car >> s) {//����� �������� � ���� car
		if (s == m)
		{
			car.getline(str, 1024, '\n');//��������� ������� �����
			a++;
			cout << "\t\tBMW " << m<< endl;
			for (int i = a + 11; i >= a; i--) {
				car.getline(str, 1024);
				cout << str << endl;
			}
			car.close();
		}
	}
	system("pause");
}
int Car::SearchCars(string model){
	string line;
	int a = 0, b=0;
	char* str = new char[1024];
	fstream car("Car.txt", ios::in);
	fstream fs("Bufer.txt", ios::out, ios::trunc);
	while (car >> line) {
		a++;
		if (line == model)
		{
			car.getline(str, 1024, '\n');
			b++;
			fs << "\tBMW: " << model << " " << endl;
			for (int i = b + 9; i >= b; i--) {
				car.getline(str, 1024);
				fs << str << endl;
			}
		
			car.close();
			fs.close();
			return a;
		}
	}
}
void Car::DeleteCar() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string line, model;
	int a = 0, b = 0,i;
	char* str = new char[1024];
	
	//���������� ����� � ����� � ������
	fstream car("Car.txt", ios::in);
	vector<string>cars;
	cars.clear();
	while (getline(car, line))
	{
		cars.push_back(line);
	}
	car.close();
	//��� �������� �����
	cout << "������ ������: ";
	cin >> model;
	a = SearchCars(model);
	fstream fs("Bufer.txt", ios::out, ios::trunc);
	if (a == 0) { cout << "����� " <<model<<" �� ������� ������ �������� �� ��������� ������� �����"<< endl; }
	else if (a == 2)//��������� ��� 1 ��������
	{
		a=0;
		i = a + 13;
		cars.erase(cars.begin(), cars.begin() + i);
		cout << "������ ��������\n";
	}
	else {
		a /= 2;
		a += 13;
		i = a - 13;
		cars.erase(cars.begin() + i, cars.begin() + a);
		cout << "������ ��������\n";
	}
	//���� ������� � ����
	ofstream carout("Car.txt", ios::out, ios::trunc);
	for (int i = 0; i < cars.size(); i++)
	{
		carout << cars[i] << endl;
	}
	carout.close();
	system("pause");


}