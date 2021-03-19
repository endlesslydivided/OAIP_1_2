#include <iostream>  
#include <io.h>
#include <windows.h>
# define str_len 30                               
# define size 30  
using namespace std;

#define size 30

void input();
void output();
void del();
void find(char lastName[15]);


typedef struct Car
{
	char mark[10];
	char color[10];
	char dateOut[11];
	char number[7];
	char dateInspection[11];
	char ownerLastName[15];
}CAR;
FILE* f; errno_t err; 
int currentSize = 0, choice, numberOfNotes;
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	char ownerLastName[15];
	do
	{
		cout << "\n1.Ввод данных с клавиатуры и запись в файл\n";
		cout << "2.Вывод данных из файла\n";
		cout << "3.Удаление записей\n";
		cout << "4.Поиск необходимой записи\n";
		cout << "0.Выход из программы\n";
		cout << "Введите номер неоходимой операции: ";	cin >> choice;
		switch (choice)
		{
		case 1:input(); break;
		case 2: output(); break;
		case 3: del(); break;
		case 4:
			cout << "Введите фамилию: ";
			cin >> ownerLastName;
			find(ownerLastName); break;
		case 0: del(); exit(0); break;
		}
	  
	} while (choice != 0);
}
void input()
{
		Car buf = { ' ', ' ', ' ', ' ', ' ', ' '};
		if (!fopen_s(&f, "carbase.bin", "ab"))	
		{
			cout << "Текущая строка:"; cout << currentSize + 1;
			cout << endl << "Марка машины:"; cin >> buf.mark;
			cout << endl << "Цвет машины:"; cin >> buf.color;
			cout << endl << "Дата выпуска машины:"; cin >> buf.dateOut;
			cout << endl << "Номер машины:"; cin >> buf.number;
			cout << endl << "Дата последней проверки машины:"; cin >> buf.dateInspection;
			cout << endl << "Фамилия владельца машины:"; cin >> buf.ownerLastName;
			fwrite(&buf, sizeof(buf), 1, f);
			currentSize++;
		}
		else {
			cout << "Ошибка открытия файла";
			return;
		}
		fclose(f);
		cout << "Что дальше?" << endl;
}
void output()
{
	CAR buf;
	if (!fopen_s(&f, "carbase.bin", "rb"))
	{
		cout << "\nМарка        Цвет           Дата выпуска          Номер машины    Дата последней проверки    Фамилия владельца\n";
		fread(&buf, sizeof(buf), 1, f); 
		while (!feof(f))
		{
			cout << buf.mark << "\t     " << buf.color << "\t    " << buf.dateOut << "\t            " << buf.number << "\t        " << buf.dateInspection << "\t         " << buf.ownerLastName << endl;
			fread(&buf, sizeof(buf), 1, f);
		}
		cout << endl;
		fclose(f);
	}
	else
	{
		cout << "Ошибка открытия файла";
		return;
	}

	cout << "Что дальше?" << endl;
}

void del()
{
	int d;
	if (!fopen_s(&f, "carbase.bin", "wb"))
	{
		cout << "Файл очищен.";
	}
	else {
		cout << "Ошибка открытия файла";
		return;
	}
	fclose(f);
	currentSize = 0;
}

void find(char lastName[15])
{
	bool flag = false;  CAR buf;
	if (!fopen_s(&f, "carbase.bin", "rb"))
	{
		while (!feof(f))
		{
			fread(&buf, sizeof(buf), 1, f);
			if (strcmp(lastName, buf.ownerLastName) == 0)   //сравнение строк
			{
				cout << "\nМарка   Цвет   Дата выпуска   Номер машины    Дата последней проверки    Фамилия владельца\n";
				cout << buf.mark << "\t     " << buf.color << "\t    " << buf.dateOut << "\t            " << buf.number << "\t        " << buf.dateInspection << "\t         " << buf.ownerLastName << endl;
				flag = true; break;
			}
		}
		fclose(f);
		if (!flag) 
			cout << "Ничего не найдено\n";
	}
	else
	{
		cout << "Ошибка открытия файла";
		return;
	}

	cout << "Что дальше?" << endl;
}

//cout << endl << "Марка машины:"; buf.mark = *(t + p)->mark;
//cout << endl << "Цвет машины:"; cout << listOfCars[i].color << endl;
//cout << endl << "Дата выпуска машины:"; cout << listOfCars[i].dateOut << endl;
//cout << endl << "Номер машины:"; cout << listOfCars[i].number << endl;
//cout << endl << "Дата последней проверки машины:"; cout << listOfCars[i].dateInspection << endl;
//cout << endl << "Фамилия владельца машины:"; cout << listOfCars[i].ownerLastName << endl;
//cout << "Фамилия: "; 	cin >> buf.fio;
//cout << "Группа: "; 	cin >> buf.group;
//fwrite(&buf, sizeof(buf), 1, f);