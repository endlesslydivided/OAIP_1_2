#include <iostream> 
#include <fstream>
#include <stdio.h>
using namespace std;
extern int choose = 0, access = 0, access_1 = 0;
#define MAX 100
struct Text
{
	char info[MAX];
	Text* next;
};

struct Numbers
{
	char one ;
	char two ;
	char three ;
	char four ;
	char five ;
	char six ;
	char seven ;
	char eight ;
	char nine ;
	char zero ;
	friend bool operator == (const Numbers c1, char l)
	{
		return c1.one == l|| c1.two == l || c1.three == l || c1.four == l || c1.five == l || c1.six == l || c1.seven == l || c1.eight == l || c1.nine == l || c1.zero == l;
	}

};
Numbers c1{'1','2','3','4','5','6','7','8','9','0'};
void create(Text** begin, Text** end,ifstream &ifile);
void view_queue(Text* begin);
void minElem(Text* begin, ofstream& ofile);
void DelONE(Text** begin);
void DelALL(Text** begin);
void show_file(ifstream& ifile);

int main()
{
	setlocale(LC_ALL, "Russian");
	Text* begin = NULL, * end, * t;
	ifstream ifile;
	ofstream ofile;
	float p; int size = 0;
	do
	{
		printf("\n1.Формирование очереди из строк в файле.\n2.Вывести элементы очереди.\n3.Совершить сдвиг числе в конец строк и запись в файл.\n4.Удаление элемента очереди.\n5.Удаление очереди.\n6.Вывести элементы нового файла.\n7.Выход.");
		cout << "\nВведите необходимый пункт меню: "; cin >> choose;
		switch (choose)
		{
		case 1: if (access == 0)
		{
			access = 1;
			create(&begin, &end, ifile);
		}
			  else
		{
			cout << "\nСначала необходимо очистить очередь!";
		}break;
		case 2:
			if (begin == NULL)
			{
				cout << "Очередь пуста!\n" << endl;
			}
			else
			{
				view_queue(begin);
			}break;
		case 3:minElem(begin, ofile); break;
		case 4: DelONE(&begin); break;
		case 5: DelALL(&begin); break;
		case 6:
			cout << "\nНовый файл:\n";
			show_file(ifile);
			  break;
		case 7: break;
		default:break;
		}
	} while (choose != 7);
	return 0;
}

void create(Text** begin, Text** end, ifstream& ifile)
{
	char buf[MAX];
	ifile.open("file1.txt");
	if (ifile.fail())  
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	ifile.getline(buf, MAX);
	do
	{
		Text* t = new Text;
		t->next = NULL;
		if (*begin == NULL)
			*begin = *end = t;
			strcpy_s(t->info,buf);
			(*end)->next = t;
			*end = t;
		ifile.getline(buf, MAX);
	}while (buf[0] != '\0');
	ifile.close();
}
void view_queue(Text* begin)
{
	Text* t = begin;
	if (t == NULL)
	{
		cout << "Очередь пуста\n";
		return;
	}
	else
		while (t != NULL)
		{
			cout << t->info << endl;
			t = t->next;
		}
}
void minElem(Text* begin,ofstream &ofile)
{
	ofile.open("result.txt");
	char clear[MAX];
	char number_buf[MAX];
	int number_buf_count = 0;
	char fullText_buf[MAX];
	char result[MAX];
	int result_count = 0;
	Text* t = begin;
	if (t == NULL)
	{
		cout << "Очередь пуста\n";
		return;
	}
	else
	{
		while (t != NULL)
		{
			strcpy_s(fullText_buf, t->info);

			for (int i = 0; fullText_buf[i] != '\0'; i++)
			{
				if (c1 == fullText_buf[i])
					number_buf[number_buf_count++] = fullText_buf[i];
				else
					result[result_count++] = fullText_buf[i];
			}
			for (int i = 0; i < number_buf_count; i++)
			{
				result[result_count++] = number_buf[i];
			}
			result[result_count++] = '\n\0';
			result[result_count] = '\0';
			ofile << result;

			for (int i = 0; i < MAX; i++)
			{
				number_buf[i] = {0};
				fullText_buf[i] = {0};
				result[i] = {0};
			}
			number_buf_count = 0;
			result_count = 0;
			t = t->next;
		}
	}
	ofile.close();
}
void DelONE(Text** begin)
{
	Text* t;
	t = new Text;
	t = *begin;
	*begin = (*begin)->next;
	delete t;
	if (*begin == NULL)
	{
		access = 0;
	}
}
void DelALL(Text** begin)
{
	Text* t;
	t = new Text;
	while (*begin != NULL)
	{
		t = *begin;
		*begin = (*begin)->next;
		delete t;
	}
	access = 0;
}
void show_file(ifstream& ifile)
{
	char buf[MAX];
	ifile.open("result.txt");
	while (buf[0] != '\0')
	{
		ifile.getline(buf, MAX);
		cout << buf << endl;
	}
}
