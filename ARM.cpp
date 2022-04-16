#include <iostream>
#include<Windows.h>
#include<fstream>
#include"Car.h"
#include"Pocupka.h"
#include<vector>


using namespace std;

int main()
{
    system("chcp 1251 > null");
    Car car;
    Sale sale;
    int n=100,v=100;
    while (n != 0) {
        cout << "\t\tДилерський центр BMW\n";
        cout << "------------------------------------------------" << endl;
        cout << "(1)Автомобілі\n(2)Покупки\n(3)Ослуговання та ремонт" << endl;
        cout << "------------------------------------------------" << endl;
        cout << "Оберіть дію: ";
        cin >> n;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Не правильно введено потрібно вводити тільки цифри\n Введіть ще раз:" << endl;
            cin >> n;
        }
        switch (n) {
        case 1: {
                system("cls");
                cout << "\t\tАвтомобілі" << endl;
                cout << "(1)Додати нову модель" << endl;
                cout << "(2)Видалити модель" << endl;
                cout << "(3)Пошук моделі" << endl;
                cout << "(4)Вивести всі моделі" << endl;
                cout << "Оберіть дію: ";
                cin >> v;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore();
                    cout << "Не правильно введено потрібно вводити тільки цифри\n Введіть ще раз:" << endl;
                    cin >> v;
                }
                switch (v)
                {
                case 1: {
                    system("cls");
                    car.AddCar();
                    system("cls"); }break;
                case 2: {
                    system("cls");
                    car.DeleteCar();
                    system("cls"); }break;          
                case 3: {
                    system("cls");
                    string m;
                    cout << "Введіть модель: ";
                    cin >> m;
                    car.SearchCar(m);
                    system("cls"); }break;
                case 4: {
                    system("cls");
                    car.Print();
                    system("cls"); }break;
                
                default:cout << "Введіть правильне значення\n";
                    break;
            }break; }
        case 2: {
            system("cls");
            cout << "\t\tПокупки" << endl;
            cout << "(1)Додати покупку" << endl;
            cout << "(2)Вивести покупки" << endl;
            cout << "(3)Пошук покупки" << endl;
            cout << "Оберіть дію: ";
            cin >> n;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                cout << "Не правильно введено потрібно вводити тільки цифри\n Введіть ще раз:" << endl;
                cin >> n;
            }
            switch (n)
            {
            case 1: {
                system("cls");
                sale.AddSale();
                system("cls"); }break;
            case 2: {
                system("cls");
                sale.Print();
                system("cls"); }break;
            case 3: {
                system("cls");
                string model;
                cout << "Введіть модель автомобіля: ";
                cin >> model;
                sale.SearchSale(model); }break;
                system("cls");
            }break; }
        case 3: {
            SetConsoleCP(1251);
            SetConsoleOutputCP(1251);
            system("cls");
            cout << "\tОбслуговання та ремонт\n";
            cout << "(1)Додати послуги\n(2)Вивести послуги\n(3)Знайти послуги\n";
            cin >> v;
        switch (v) { 
        case 1: {
            system("cls");
            string posluga,posluga1, price;
            fstream service("Service.txt", fstream::out|fstream::app);
           getline(cin,posluga1); 
           cout << "\tДодавання нової послуги\n";
           cout << "Послугa: "; 
            getline(cin,posluga);
            cout << "Ціна: ";
            cin>>price;
            service << posluga << " : " << price<<"$"<< endl;
            break; }
        case 2: {
            system("cls");
            string line;
            fstream service("Service.txt", fstream::in);
            while (getline(service, line))
            {
                cout << line << endl;
            }
            service.close();
            break; }
        case 3: {
            system("cls");
            fstream service("Service.txt", fstream::in);
            vector<string>servi;
            string line,services;
            int a=0;
            getline(cin, services);
            cout << "Послуга яку потрібно знайти: ";
            getline(cin,services);
            while (getline(service, line))
            {
                servi.push_back(line);
                size_t foundIndex = line.find(services);
                a++;
                if (foundIndex != string::npos)
                {
                    for (int i = a - 1; i < a; i++) {
                        cout << servi[i] << endl;
                    }
                }
            }break; }
        
        default:break; }
            
            system("pause");
            system("cls");
       break; }
        default:cout << "Введіть правильне значення" << endl; system("cls");
            }
        }
    }

