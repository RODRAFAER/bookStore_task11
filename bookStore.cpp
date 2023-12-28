#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

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
using std::sort;

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
	while (cin.fail() || a < 0 || a > 7)
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

select:
	int select = 0;
	cout << "Что вы хотите сделать дальше?\n"
		<< "1 - выбрать книги из диапазона цен\n"
		<< "2 - добавить новые строки\n"
		<< "3 - удалить последнюю строку\n"
		<< "4 - сортировать по названиям\n"
		<< "5 - сортировать по авторам\n"
		<< "6 - сортировать по издательству\n"
		<< "7 - сортировать по году\n";

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
	else if (select == 4) {
	kniga:
		string name1;
		cout << "Введите название: ";
		cin >> name1;
		name1 = nameCheck(name1);
		int count = 0;

		system("cls");
		cout << endl << "Ваша(-и) книга(-и)" << "\n" << "-------------------------------------------------------------------\n";
		for (int i = 0; i < name.size(); i++) {
			if (name1 == name[i]) {
				cout << name[i] << " " << author[i] << " " << publish[i] << " " << year[i] << " " << price[i] << endl << "-------------------------------------------------------------------" << endl;
				count++;
			}
		}
		if (count == 0) {
			cout << "Нет такой книги\n" << "-------------------------------------------------------------------\n";
			name1.clear();
			goto kniga;
		}
		goto select;


		//	vector <string> name2;
		//	vector <string> name1;
		//	name2 = name;
		//	name2.erase(name2.begin());
		//	name1 = name2;
		//	sort(name1.begin(), name1.end());
		//	name1.insert(name1.begin(), "Название");

		//	int count = 0;
		//	int allNames = name.size();
		//	// Вывод всех слов
		//	for (int i = 0; i < allNames; i++) {
		//		for (int j = 0; j < allNames; j++) {
		//			if (name1[i] == name[j]) {
		//				count++;
		//				if (count == 1) {
		//					string spaceName(maxName - name1[i].length() + 2, ' ');
		//					cout << name1[i] << spaceName;
		//					string spaceAuthor(maxAuthor - author[j].length() + 2, ' ');
		//					cout << author[j] << spaceAuthor;
		//					string spacePublish(maxPublish - publish[j].length() + 2, ' ');
		//					cout << publish[j] << spacePublish;
		//					string spaceYear(maxYear - year[j].length() + 2, ' ');
		//					cout << year[j] << spaceYear;
		//					string spacePrice(maxPrice - price[j].length() + 2, ' ');
		//					cout << price[j] << spacePrice;

		//					cout << endl;
		//					break;
		//				}
		//				else {
		//					count = 0;
		//				}
		//			}
		//			count = 0;
		//		}
		//	}
		//	cout << endl;

	}
	else if (select == 5) {
	avtor:
		string name1;
		cout << "Введите автора: ";
		cin >> name1;
		name1 = nameCheck(name1);
		int count = 0;

		system("cls");
		cout << endl << "Книга(-и) по вашему автору" << "\n" << "-------------------------------------------------------------------\n";
		for (int i = 0; i < name.size(); i++) {
			if (name1 == author[i]) {
				cout << name[i] << " " << author[i] << " " << publish[i] << " " << year[i] << " " << price[i] << endl << "-------------------------------------------------------------------" << endl;
				count++;
			}
		}
		if (count == 0) {
			cout << "Нет такого автора\n" << "-------------------------------------------------------------------\n";
			name1.clear();
			goto avtor;
		}
		goto select;

		//vector <string> name2;
		//vector <string> name1;
		//name2 = author;
		//name2.erase(name2.begin());
		//name1 = name2;
		//sort(name1.begin(), name1.end());
		//name1.insert(name1.begin(), "Автор");

		//int count = 0;
		//int allNames = name.size();
		// Вывод всех слов
		//for (int i = 0; i < allNames; i++) {
		//	for (int j = 0; j < allNames; j++) {
		//		if (name1[i] == author[j]) {
		//			count++;
		//			if (count == 1) {
		//				string spaceName(maxName - name[j].length() + 2, ' ');
		//				cout << name[j] << spaceName;
		//				string spaceAuthor(maxName - name1[i].length() + 2, ' ');
		//				cout << name1[i] << spaceAuthor;
		//				string spacePublish(maxPublish - publish[j].length() + 2, ' ');
		//				cout << publish[j] << spacePublish;
		//				string spaceYear(maxYear - year[j].length() + 2, ' ');
		//				cout << year[j] << spaceYear;
		//				string spacePrice(maxPrice - price[j].length() + 2, ' ');
		//				cout << price[j] << spacePrice;

		//				cout << endl;
		//				break;
		//			}
		//			else {
		//				count = 0;
		//			}
		//		}
		//		count = 0;
		//	}
		//}
		//cout << endl;
	}
	else if (select == 6) {
	publish:
		string name1;
		cout << "Введите издательство: ";
		cin >> name1;
		name1 = nameCheck(name1);
		int count = 0;

		system("cls");
		cout << endl << "Книга(-и) по вашему издательству" << "\n" << "-------------------------------------------------------------------\n";
		for (int i = 0; i < name.size(); i++) {
			if (name1 == publish[i]) {
				cout << name[i] << " " << author[i] << " " << publish[i] << " " << year[i] << " " << price[i] << endl << "-------------------------------------------------------------------" << endl;
				count++;
			}
		}
		if (count == 0) {
			cout << "Нет такого издательства\n" << "-------------------------------------------------------------------\n";
			name1.clear();
			goto publish;
		}
		goto select;
	}
	else if (select == 7) {
	year:
		string name1;
		cout << "Введите год: ";
		cin >> name1;
		name1 = nameCheck(name1);
		int count = 0;

		system("cls");
		cout << endl << "Книга(-и) по вашему году" << "\n" << "-------------------------------------------------------------------\n";
		for (int i = 0; i < name.size(); i++) {
			if (name1 == year[i]) {
				cout << name[i] << " " << author[i] << " " << publish[i] << " " << year[i] << " " << price[i] << endl << "-------------------------------------------------------------------" << endl;
				count++;
			}
		}
		if (count == 0) {
			cout << "Нет такого года\n" << "-------------------------------------------------------------------\n";
			name1.clear();
			goto year;
		}
		goto select;
	}


	system("pause");
	return 0;
}