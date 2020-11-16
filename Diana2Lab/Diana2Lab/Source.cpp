/*
Дано:



Автор: Осипова Д. А.
Дата: 23.09.2020
Предмет: Практикум по программированию
*/
#include <iostream>
#include <iomanip>
#include <time.h>
#include <locale.h>

using namespace std;


struct List
{
	int info;
	List * pred, *next;
};

void createRandomList(List * &head, List * &tail, int n)
{
	head = new List;
	tail = new List;

	head->next = tail;
	tail->pred = head;

	List * last = head;
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		List * p = new List;
		int number;
		cin >> number;
		//p->info = rand() % 200 - 100;
		p->info = number;
		p->pred = last;
		p->next = last->next;
		last->next = p;
		p->next->pred = p;
	}

	return;
}


void printList(List * head, List * tail)
{
	List * p = head->next;
	while (p != tail)
	{
		cout << setw(6) << p->info;
		p = p->next;
	}
	cout << endl;
	return;
}

bool searchPal(List *head, List *tail, int n, int b, int e) {
	int i = 0;
	List *begin;
	List *end;
	begin = head->next;
	end = head->next;

	for (int i = 0; i < b; i++) {
		begin = begin->next;
	}
	for (int i = 0; i < e; i++) {
		end = end->next;
	}

	while (begin != end) {


		if (begin->next == end) {
			//сравниваем begin и end
			if (begin->info == end->info) {
				return true;
			}
			else if (begin->info != end->info) {
				return false;
			}
			//если проверка успешна то true иначе false
		}

		if (begin->info == end->info) {
			if (begin->next->info == end->pred->info) {
				return true;
			}
			begin = begin->next;
			end = end->pred;
			continue;
		}

		else if (begin->info != end->info) {
			return false;
		}
	}
}

int main() {
	setlocale(LC_ALL, "RUS");

	cout << "Введите длинну списка: ";
	cout << endl;
	int n;
	cin >> n;

	List *tail = nullptr, *head = nullptr;
	createRandomList(head, tail, n);

	cout << endl << "исходный список " << endl;
	printList(head, tail);


	List *p1 = new List;
	p1 = head->next;
	int count = 0;
	while (p1 != tail) {
		for (int j = 0; j < count; j++) {
			if (searchPal(head, tail, n, j, n - count + j) != false) {
				cout << "самый длинный палиндром: ";
				List *p, *tailP;
				p = head->next;
				tailP = head->next;
				for (int b = 0; b < j; b++) {
					p = p->next;
				}
				for (int e = 0; e < n - count + j; e++) {
					tailP = tailP->next; 
				}

				while (p != tailP->next) {
					cout << p->info << "\t";
					p = p->next;
				}
				system("pause");
				exit(1);

			}
		}

		p1 = p1->next;
		count++;
	}
	
	 
	//for (int i = 0; i < n; i++) {                                                      // List *p1 = new List;
	//	if (n > 1 || i > 0) {                                                          // i do not understand this kind of things, i am so sorry that you have to spend your time like that.     
	//		for (int j = 0; j < i; j++) {
	//			if (searchPal(head, tail, n, j, n - i + j) != false) {
	//				cout << "самый длинный палиндром: ";
	//				List *p, *tailP;
	//				p = head->next;
	//				tailP = head->next;
	//				for (int b = 0; b < j; b++) {
	//					p = p->next;
	//				}
	//				for (int e = 0; e < n - i + j; e++) {
	//					tailP = tailP->next;
	//				}

	//				while (p != tailP->next) {
	//					cout << p->info << "\t";
	//					p = p->next;
	//				}
	//				system("pause");
	//				exit(1);

	//			}
	//		}
	//	}
	//}

	List *a;
	a = head->next;
	cout << "Самый большой палиндром: " << a->info << endl;
	system("pause");
	return 0;
}
