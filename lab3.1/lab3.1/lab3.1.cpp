#include "stdafx.h"
#include <iostream>

struct node
{
	char inf[256];
	int P;
	struct node* prev;
};

struct node* head = NULL, * last = NULL;

void push(const char* str, int P);

void pop();

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	char com[10], data[256];
	int pr;
	while (1) {
		if (head != NULL) {
			node* tmp = head;
			cout << "�������: ";
			while (1) {
				cout << tmp->inf << " ";
				if (tmp == last) {
					cout << endl << endl;
					break;
				}
				tmp = tmp->prev;
			}
		}
		cout << "������� ������� push ��� pop ��� ������ � ��������. ����� ����� ������� exit: ";
		cin >> com;
		cout << endl;
		if (!strcmp(com, "push")) {
			cout << "������� ������ ��� ��������� � �������: ";
			cin >> data;
			cout << "������� ����� ��� ���������� � �������: ";
			cin >> pr;
			cout << endl;
			push(data, pr);
		}
		else if (!strcmp(com, "pop")) {
			pop();
		}
		else if (!strcmp(com, "exit")) {
			exit(0);
		}
		else {
			cout << "�� ����� ������� �������" << endl << endl;
		}
	}
}

void push(const char* str, int P) {
	node* tmp = (node*)malloc(sizeof(node));
	if (head == NULL) {
		head = tmp;
		last = tmp;
		tmp->P = P;
		strcpy_s(tmp->inf, str);
	}
	else {
		char flag = 0;
		tmp->P = P;
		strcpy_s(tmp->inf, str);
		node* sravn = head, * sravnprev = head;
		while (flag == 0) {
			while (1) {
				if (sravn->P == tmp->P) {
					if (sravn == last) {
						last = tmp;
						sravn->prev = tmp;
						flag = 1;
						break;
					}
					else {
						tmp->prev = sravn->prev;
						sravn->prev = tmp;
						flag = 1;
						break;
					}
				}
				else if (sravn->P < tmp->P) {
					if (sravn == last) {
						last = tmp;
						sravn->prev = tmp;
						flag = 1;
						break;
					}
					else {
						sravnprev = sravn;
						sravn = sravn->prev;
						break;
					}
				}
				else if (sravn->P > tmp->P) {
					if (sravn == head) {
						tmp->prev = head;
						head = tmp;
						flag = 1;
						break;
					}
					else {
						tmp->prev = sravn;
						sravnprev->prev = tmp;
						flag = 1;
						break;
					}
				}
			}
		}
	}
}

void pop() {
	if (head == NULL) {
		cout << "������� ������" << endl << endl;
		return;
	}
	else if (head == last) {
		cout << "����������� �������: " << head->inf << endl << endl;
		free(head);
		head = NULL;
		last = NULL;
	}
	else {
		cout << "����������� �������: " << head->inf << endl;
		node* tmp = head;
		head = head->prev;
		free(tmp);
	}
}
