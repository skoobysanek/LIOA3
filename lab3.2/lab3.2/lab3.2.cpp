#include "stdafx.h"
#include <iostream>

struct node
{
	char inf[256];
	struct node* prev;
};

struct node* head = NULL, * last = NULL;

void push(const char* str);

void pop();

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	char com[10], data[256];
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
			cout << endl;
			push(data);
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

void push(const char* str) {
	node* tmp = (node*)malloc(sizeof(node));
	if (head == NULL) {
		head = tmp;
		last = tmp;
		strcpy_s(last->inf, str);
	}
	else {
		last->prev = tmp;
		strcpy_s(tmp->inf, str);
		last = tmp;
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
