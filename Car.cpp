#include"Car.h"
#include<iostream>
#include<vector>
#include<fstream>
#include<Windows.h>

using namespace std;

void Car::AddCar()
{
	fstream car("Car.txt", fstream::out | fstream::app);//відкриття файлу car
	cout << "\tДодавання нової моделі" << endl;
	cout << "Введіть модель: ";
	cin >> model;
	cout<< "Введіть тип палива: ";
	cin >> typef;
	cout << "Введіть рік випуску: ";
	cin >> year;
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Не правильно введено потрібно вводити тільки цифри\n Введіть ще раз:" << endl;
		cin >> year;
	}
	cout << "Введіть об'єм двигуна: ";
	cin >> eng;
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Не правильно введено потрібно вводити тільки цифри\n Введіть ще раз:" << endl;
		cin >> eng;
	}
	cout << "Введіть розгін до 100 кілометрів: ";
	cin >> acel;
	cout <<"Введіть розхід палива: ";
	cin >> ros;
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Не правильно введено потрібно вводити тільки цифри\n Введіть ще раз:" << endl;
		cin >> ros;
	}
	cout << "Введіть тип кузова: ";
	cin >> btype;
	cout << "Введіть комлектація: ";
	cin >> comp;
	cout << "Введіть кількість кінських сил: ";
	cin >> kilkn;
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Не правильно введено потрібно вводити тільки цифри\n Введіть ще раз:" << endl;
		cin >> kilkn;
	}
	cout << "Введіть колір: ";
	cin >> color;
	cout << "Введіть ціну: ";
	cin >> price;
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Не правильно введено потрібно вводити тільки цифри\n Введіть ще раз:" << endl;
		cin >> price;
	}
	cout << "Введіть VIN код: ";
	cin >> vin;
	//вивід у файл Car.txt
	car << "\tBMW " << model << endl;
	car << "Тип палива:" << typef << endl;
	car << "Рік випуску:" << year <<"р."<< endl;
	car << "Об'єм двигуна:" << eng<<"см3"<< endl;
	car << "Розгін до 100 кілометрів:" << acel<<"c."<< endl;
	car << "Розхід палива:" << ros <<"л."<<endl;
	car << "Тип кузова:" << btype << endl;
	car << "Комлектація:" << comp << endl;
	car << "Кількість кінських сил:" << kilkn << endl;
	car << "Колір:" << color << endl;
	car << "Ціна:" << price <<"$"<< endl;
	car << "VIN код:" << vin << endl;
	car << "_________________________________________" << endl;

}
void Car::Print(){
	string line;
	fstream car;
	car.open("Car.txt", fstream::in);//відкриття файлу car
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
	fstream car("Car.txt", fstream::in|fstream::out|fstream::app);//відкриття файлу car

	while (car >> s) {//пошук значення в файлі car
		if (s == m)
		{
			car.getline(str, 1024, '\n');//підраховка кількості строк
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
	
	//Зчитування даних з файлу у вектор
	fstream car("Car.txt", ios::in);
	vector<string>cars;
	cars.clear();
	while (getline(car, line))
	{
		cars.push_back(line);
	}
	car.close();
	//Ввід потрібних даних
	cout << "Введіть модель: ";
	cin >> model;
	a = SearchCars(model);
	fstream fs("Bufer.txt", ios::out, ios::trunc);
	if (a == 0) { cout << "Моделі " <<model<<" не вдалось знайти перевірте чи правильно введено назву"<< endl; }
	else if (a == 2)//видалення для 1 елемента
	{
		a=0;
		i = a + 13;
		cars.erase(cars.begin(), cars.begin() + i);
		cout << "Успішно видалено\n";
	}
	else {
		a /= 2;
		a += 13;
		i = a - 13;
		cars.erase(cars.begin() + i, cars.begin() + a);
		cout << "Успішно видалено\n";
	}
	//Вивід вектора у файл
	ofstream carout("Car.txt", ios::out, ios::trunc);
	for (int i = 0; i < cars.size(); i++)
	{
		carout << cars[i] << endl;
	}
	carout.close();
	system("pause");


}