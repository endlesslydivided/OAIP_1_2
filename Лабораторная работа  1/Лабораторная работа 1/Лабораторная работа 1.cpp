#include <iostream>   
#include <windows.h>
# define str_len 50                             
# define size 30  
using namespace std;
void enter_new();
void del();
void analize();
void out();
struct Student
{
	char name[str_len];
	int numberOfExams;
	int Exam1;
	int Exam2;
	int Exam3;
	int Exam4;
};
struct Student listOfStudent[size];
struct Student bad;
int current_size = 0; int choice;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	cout << "Введите:" << endl;
	cout << "1-для удаления записи" << endl;
	cout << "2-для ввода новой записи" << endl;
	cout << "3-для вывода записи(ей)" << endl;
	cout << "4-анализ успеваемости студентов" << endl;
	cout << "0-для выхода" << endl;
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 1:  del();	break;
		case 2:  enter_new();  break;
		case 3:  out();	break;
	    case 4:  analize(); break;
		}
	} while (choice != 0);
}

void enter_new()
{
	cout << "Ввод информации" << endl;
	if (current_size < size)
	{
		cout << "Строка номер ";
		cout << current_size + 1;
		cout << endl << "ФИО: ";
		cin.ignore();
		cin.getline(listOfStudent[current_size].name, 50);
		cout << "Кол-во экзаменов: ";
		cin >> listOfStudent[current_size].numberOfExams;
		if (listOfStudent[current_size].numberOfExams >= 1)
		{
			cout << "Оценка - экзамен №1: " << endl;
			cin >> listOfStudent[current_size].Exam1;
		}
		if (listOfStudent[current_size].numberOfExams >= 2)
		{
			cout << "Оценка - экзамен №2: " << endl;
			cin >> listOfStudent[current_size].Exam2;
		}
		if (listOfStudent[current_size].numberOfExams >= 3)
		{
			cout << "Оценка - экзамен №3: " << endl;
			cin >> listOfStudent[current_size].Exam3;
		}
		if (listOfStudent[current_size].numberOfExams == 4)
		{
			cout << "Оценка - экзамен №4: " << endl;
			cin >> listOfStudent[current_size].Exam4;
		}
		current_size++;
	}
	else
		cout << "Введено максимальное кол-во строк";
	cout << "Что дальше?" << endl;
	cin >> choice;
}
void del()
{
	int d;
	cout << "\nНомер строки, которую надо удалить (для удаления всех строк нажать 99)" << endl;  cin >> d;
	if (d != 99)
	{
		for (int de1 = (d - 1); de1 < current_size; de1++)
			listOfStudent[de1] = listOfStudent[de1 + 1];
		current_size = current_size - 1;
	}
	if (d == 99)
		for (int i = 0; i < size; i++)
			listOfStudent[i] = bad;
	cout << "Что дальше?" << endl;
	cin >> choice;
}
void out()
{
	int sw, n;
	cout << "1-вывод 1 строки" << endl;
	cout << "2-вывод всех строк" << endl;
	cin >> sw;
	if (sw == 1)
	{

		cout << "Номер выводимой строки " << endl;   cin >> n;  cout << endl;
		cout << endl << "ФИО: ";
		cout << listOfStudent[n - 1].name << endl;
		cout << "Кол-во экзаменов: ";
		cout << listOfStudent[n - 1].numberOfExams << endl;
		if (listOfStudent[n - 1].numberOfExams >= 1)
		{
			cout << "Оценка - экзамен №1: ";
			cout << listOfStudent[n - 1].Exam1 << endl;
		}
		if (listOfStudent[n - 1].numberOfExams >= 2)
		{
			cout << "Оценка - экзамен №2: ";
			cout << listOfStudent[n - 1].Exam2 << endl;
		}
		if (listOfStudent[n - 1].numberOfExams >= 3)
		{
			cout << "Оценка - экзамен №3: " ;
			cout << listOfStudent[n - 1].Exam3 << endl;
		}
		if (listOfStudent[n - 1].numberOfExams == 4)
		{
			cout << "Оценка - экзамен №4: " ;
			cout << listOfStudent[n - 1].Exam4 << endl;
		}
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			cout << endl << "ФИО: ";
			cout << listOfStudent[i].name << endl;
			cout << "Кол-во экзаменов: ";
			cout << listOfStudent[i].numberOfExams << endl;
			if (listOfStudent[i].numberOfExams >= 1)
			{
				cout << "Оценка - экзамен №1: ";
				cout << listOfStudent[i].Exam1 << endl;
			}
			if (listOfStudent[i].numberOfExams >= 2)
			{
				cout << "Оценка - экзамен №2: ";
				cout << listOfStudent[i].Exam2 << endl;
			}
			if (listOfStudent[i].numberOfExams >= 3)
			{
				cout << "Оценка - экзамен №3: ";
				cout << listOfStudent[i].Exam3 << endl;
			}
			if (listOfStudent[i].numberOfExams == 4)
			{
				cout << "Оценка - экзамен №4: ";
				cout << listOfStudent[i].Exam4 << endl;
			}
		}
	}
	cout << "Что дальше?" << endl;
	cin >> choice;
}
void analize()
{
	int i;
	int analize = 0; int best = 0; float percent = 0;

	for (i = 0; i < current_size; i++)
	{
		analize = 0;
		if (listOfStudent[i].numberOfExams >= 1)
		{
			if (listOfStudent[i].Exam1 >= 4)
			{
				analize++;
			}
		}
		if (listOfStudent[i].numberOfExams >= 2)
		{
			if (listOfStudent[i].Exam2 >= 4)
			{
				analize++;
			}
		}
		if (listOfStudent[i].numberOfExams >= 3)
		{
			if (listOfStudent[i].Exam3 >= 4)
			{
				analize++;
			}
		}
		if (listOfStudent[i].numberOfExams == 4)
		{
			if (listOfStudent[i].Exam4 >= 4)
			{
				analize++;
			}
		}
		if (listOfStudent[i].numberOfExams == analize)
		{
			best++;
		}
	}
	if (current_size != 0)
	{
		percent = ((best * 1.0) / current_size) * 100;
		printf("Число студентов, сдавших экзамен на 4 и 5, равно: %.2f%%", percent);
	}
	else
	{
		printf("База студентов пуста!\n");
	}
	cout << "Что дальше?" << endl;
	cin >> choice;
}