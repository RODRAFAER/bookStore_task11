#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using std::cin;
using std::cout;
using std::vector;
using std::ofstream;
using std::ifstream;
using std::endl;
using std::get;
using std::string;
using std::getline;
using std::ios_base;
using std::abs;

int newStringProverka(int a) {
	while (cin.fail() || a < 0 || a > 1) {
		cout << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Ошибка ввода данных, введите значение заново: ";
		cin >> a;
	}

	return a;
}

int proverka1(int a)
{
	while (cin.fail() || a < 0 || a > 3)
	{
		cout << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Ошибка ввода данных, введите значение заново: ";
		cin >> a;
	}

	return a;
}

int priceCheck(long int a) {
	while (cin.fail() || a < 0) {
		cout << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Ошибка ввода данных, введите значение заново: ";
		cin >> a;
	}

	return a;
}

string nameCheck(string a) {
	while (cin.fail()) {
		cout << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Ошибка ввода данных. Попробуйте ещё раз: ";
		cin >> a;
	}

	return a;
}


int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string source;


	//string head[5] = {"Название", "Автор", "Издательство", "Год", "Цена (руб.)"};
	int count = 0;

	//Заносим все слова в массивы
	cout << "Укажите расположение файла: ";
	cin >> source;
opFile:
	system("cls");

	string record;
	vector <string> name{ "Название" };
	vector <string> author{ "Автор" };
	vector <string> publish{ "Издательство" };
	vector <string> year{ "Год" };
	vector <string> price{ "Цена (руб.)" };

	ifstream openFile(source);
	if (!openFile.is_open()) {
		cout << "Не удалось открыть файл." << endl;
		goto opFile;

	}
	else {
		string proverka;
		getline(openFile, proverka);
		if (proverka.empty()) {
			cout << "В файле нет значений.";
			system("pause");
			return 0;
		}
		else {
			while (openFile >> record) {
				if (count == 0) {
					name.push_back(record);
				}
				else if (count == 1) {
					author.push_back(record);
				}
				else if (count == 2) {
					publish.push_back(record);
				}
				else if (count == 3) {
					year.push_back(record);
				}
				else if (count == 4) {
					price.push_back(record);
				}
				count++;
				if (count == 5) {
					count = 0;
				}

			}
		}
	}
	record.clear();
	openFile.close();

	//Вычисление размеров самых длинных слов в файле
	int maxName = 0;
	int maxAuthor = 0;
	int maxPublish = 0;
	int maxYear = 0;
	int maxPrice = 0;
	if (name.size() == 1) {
		maxName = name[0].length();
	}
	else {
		for (int i = 0; i < name.size(); i++) {
			if (maxName < name[i].length()) {
				maxName = name[i].length();
			}
			else {
				maxName = maxName;
			}
		}
	}

	if (author.size() == 1) {
		maxAuthor = author[0].length();
	}
	else {
		for (int i = 0; i < author.size(); i++) {
			if (maxAuthor <= author[i].length()) {
				maxAuthor = author[i].length();
			}
			else {
				maxAuthor = maxAuthor;
			}
		}
	}

	if (publish.size() == 1) {
		maxPublish = publish[0].length();
	}
	else {
		for (int i = 0; i < publish.size(); i++) {
			if (maxPublish <= publish[i].length()) {
				maxPublish = publish[i].length();
			}
			else {
				maxPublish = maxPublish;
			}
		}
	}

	if (year.size() == 1) {
		maxYear = year[0].length();
	}
	else {
		for (int i = 0; i < year.size(); i++) {
			if (maxYear <= year[i].length()) {
				maxYear = year[i].length();
			}
			else {
				maxYear = maxYear;
			}
		}
	}

	if (price.size() == 1) {
		maxPrice = price[0].length();
	}
	else {
		for (int i = 0; i < price.size(); i++) {
			if (maxPrice <= price[i].length()) {
				maxPrice = price[i].length();
			}
			else {
				maxPrice = maxPrice;
			}
		}
	}



	////Вывод верхней строки на экран
	//string spaceName(abs(int(maxName) - int(head[0].length())) + 2, ' ');
	//string spaceAuthor(abs(int(maxAuthor) - int(head[1].length())) + 2, ' ');
	//string spacePublish(abs(int(maxPublish) - int(head[2].length())) + 2, ' ');
	//string spaceYear(abs(int(maxYear) - int(head[3].length())) + 2, ' ');
	//string spacePrice(abs(int(maxPrice) - int(head[4].length())) + 2, ' ');
	//if (maxName > head[0].length()) {
	//	cout << head[0] << spaceName;
	//}
	//else {
	//	cout << head[0] << "  ";
	//}

	//if (maxAuthor > head[1].length()) {
	//	cout << head[1] << spaceAuthor;
	//}
	//else {
	//	cout << head[1] << "  ";
	//}

	//if (maxPublish > head[2].length()) {
	//	cout << head[2] << spacePublish;
	//}
	//else {
	//	cout << head[2] << "  ";
	//}
	//
	//if (maxYear > head[3].length()) {
	//	cout << head[3] << spaceYear;
	//}
	//else {
	//	cout << head[3] << "  ";
	//}

	//if (maxPrice > head[4].length()) {
	//	cout << head[4] << spacePrice;
	//}
	//else {
	//	cout << head[4] << "  ";
	//}
	//cout << endl;

	//spaceName.clear();
	//spaceAuthor.clear();
	//spacePublish.clear();
	//spaceYear.clear();
	//spacePrice.clear();

	int allNames = name.size();
	// Вывод всех слов 
	for (int i = 0; i < allNames; i++) {
		string spaceName(maxName - name[i].length() + 2, ' ');
		cout << name[i] << spaceName;
		string spaceAuthor(maxAuthor - author[i].length() + 2, ' ');
		cout << author[i] << spaceAuthor;
		string spacePublish(maxPublish - publish[i].length() + 2, ' ');
		cout << publish[i] << spacePublish;
		string spaceYear(maxYear - year[i].length() + 2, ' ');
		cout << year[i] << spaceYear;
		string spacePrice(maxPrice - price[i].length() + 2, ' ');
		cout << price[i] << spacePrice;

		cout << endl;
	}
	cout << endl;


	int select = 0;
	cout << "Что вы хотите сделать дальше? (1 - выбрать книги из диапазона цен, 2 - добавить новые строки, 3 - удалить последнюю строку)" << endl;
	cin >> select;
	select = proverka1(select);
	if (select == 3) {
		int doYouWantToWatch = 0;
		cout << "Последняя строка: " << name[name.size() - 1] << " " << author[author.size() - 1] << " " << publish[publish.size() - 1] << " " << year[year.size() - 1] << " " << price[price.size() - 1] << " была удалена. Хотите ли вы посмотреть текущий результат? (0 - да, 1 - нет)" << endl;
		cin >> doYouWantToWatch;
		doYouWantToWatch = newStringProverka(doYouWantToWatch);
		name.pop_back();
		author.pop_back();
		publish.pop_back();
		year.pop_back();
		price.pop_back();
		system("cls");
		ofstream out(source, ios_base::out);
		for (int i = 0; i < name.size(); i++) {
			if (i == name.size() - 1) {
				out << name[i] << " " << author[i] << " " << publish[i] << " " << year[i] << " " << price[i];
			}
			else {
				out << name[i] << " " << author[i] << " " << publish[i] << " " << year[i] << " " << price[i] << endl;
			}
		}
		if (doYouWantToWatch == 0) {
			out.close();
			goto opFile;
		}
		else {
			system("pause");
			return 0;
		}
		name.clear();
		author.clear();
		publish.clear();
		year.clear();
		price.clear();
	}
	else if (select == 1) {
		system("cls");
		int minPrice = 0, maxPrice;
		cout << "Укажите минимальную цену: ";
		cin >> minPrice;
		minPrice = priceCheck(minPrice);
		cout << "Укажите максимальную цену: ";
		cin >> maxPrice;
		maxPrice = priceCheck(maxPrice);
		cout << endl << "-------------------------------------------------------------------" << endl;
		for (int i = 1; i < price.size(); i++) {
			if (stoi(price[i]) >= minPrice && stoi(price[i]) <= maxPrice) {
				cout << name[i] << " " << author[i] << " " << publish[i] << " " << year[i] << " " << price[i] << endl << "-------------------------------------------------------------------" << endl;
			}
		}
	}
	else if (select == 2) {
		int newStringSelect = 0;
		vector <string> vecName, vecAuthor, vecPublish;
		vector <int> vecYear, vecPrice;
		string name, author, publish;
		int year, price;
		ofstream out(source, ios_base::app);
		do {
			system("cls");
			cout << "Введите название книги: ";
			cin >> name;
			name = nameCheck(name);
			vecName.push_back(name);
			cout << "Введите автора книги: ";
			cin >> author;
			author = nameCheck(author);
			vecAuthor.push_back(author);
			cout << "Введите название издательтсва: ";
			cin >> publish;
			publish = nameCheck(publish);
			vecPublish.push_back(publish);
			cout << "Введите год издания: ";
			cin >> year;
			year = priceCheck(year);
			vecYear.push_back(year);
			cout << "Введите цену книги: ";
			cin >> price;
			price = priceCheck(price);
			vecPrice.push_back(price);
			cout << "Хотите ли вы ещё добавить строку? (0 - да, 1 - нет)" << endl;
			cin >> newStringSelect;
			newStringSelect = newStringProverka(newStringSelect);
		} while (newStringSelect == 0);
		int count = vecName.size();
		for (int i = 0; i < count; i++) {
			out << '\n' << vecName[i] << " " << vecAuthor[i] << " " << vecPublish[i] << " " << vecYear[i] << " " << vecPrice[i];
		}
		vecName.clear();
		vecAuthor.clear();
		vecPublish.clear();
		vecYear.clear();
		vecPrice.clear();
		out.close();
		goto opFile;	
	}


	system("pause");
	return 0;
}	