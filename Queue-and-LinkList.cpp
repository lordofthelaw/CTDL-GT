/**
*Chương trình đơn giản sử dụng danh sách liên kết đơn và Queue kết hợp nhau.
*Sử dụng queue để sử lý chuôi và mảng các số nguyên.
*Xác định mảng và chuỗi có đối xứng nhau hay không.
*@Author : Trần Quốc Khánh
*/



#include <iostream>
#include <string.h>
using namespace std;

struct Node {
	int n;
	char *s;
	Node *next;
};

struct Queue {
	Node *head;
	Node *tail;
};

void createQueue(Queue &q) {
	q.head = q.tail = NULL;
}

bool isEmpty(Queue q) {
	return q.head == NULL;
}

int enQueue(Queue &q, int x) { // enQueue cho số nguyên
	Node *p = new Node;
	if (p!=NULL) {
		p->n = x;
		p->s = NULL;
		p->next = NULL;
		if (q.head == NULL)
			q.head = q.tail = p;
		else {
			q.tail->next = p;
			q.tail = p;
		}
		return 1;
	}
	else return 0;
}


int enQueue(Queue &q, char *x) { // enQueue cho mảng ký tự
	Node *p = new Node;
	if (p != NULL) {
		int i = 0;
		p->n = 0;
		while (x[i] != NULL) {
			i++;
		}
		p->s = new char[i];
		strcpy(p->s, x);
		p->next = NULL;
		if (q.head == NULL)
			q.head = q.tail = p;
		else {
			q.tail->next = p;
			q.tail = p;
		}
		return 1;
	}
	else return 0;
}


Node deQueue(Queue &q) {
	Node *p , temp;
	if (!isEmpty(q)) {
		p = q.head;
		temp = *p;
		q.head = q.head->next;
		delete p;
		return temp;
	}
	else {
		cout << "Queue rong!" << endl;
	}
}

Node* getNode(Queue q, Node p) {
	if (!isEmpty(q)) {
		for (Node *p = q.head; p != NULL; p = p->next)
		{
			if (p == p->next)
				return p;
		}
	}
	return NULL;
}

bool mangDoiXung(int a[], int n) { //Kiểm tra đối xứng của mảng số nguyên
	Queue q , p;
	Node f, l;
	createQueue(q);
	createQueue(p);
	int len = n / 2;
	for (int i = 0; i < len; i++)
	{
		enQueue(q, a[i]);		//lấy phần tử nửa đầu mảng(từ 0 -> (n/2)-1)
	}
	for (int i = n-1; i >= len; i--)
	{
		enQueue(p, a[i]);		//lấy phần tử nửa sau mảng theo chiều (n-1 -> n/2)
	}
	for (int i = 0; i < len; i++)
	{
		f = deQueue(q);
		l = deQueue(p);
		if (f.n == l.n)			// so sánh cặp nửa đầu nửa cuối với nhau
			continue;
		else
			return false;
	}
	return true;
}

bool chuoiDoiXung(char *s) {
	Queue q, p;
	Node f, l;
	char *s1, *s2;
	createQueue(q);
	createQueue(p);
	int n = strlen(s);
	int len = n / 2;
	s1 = new char[len];
	for (int i = 0; i < len; i++)
		s1[i] = s[i];
	s2 = new char[len];
	for (int i = 0; i < len; i++)
		s2[i] = NULL;
	for (int i = 0; i < len; i++)
		s2[i] = s[n-1-i];
	enQueue(q, s1);		//lấy phần tử nửa đầu mảng(từ 0 -> (n/2)-1)
	enQueue(p, s2);		//lấy phần tử nửa sau mảng theo chiều (n-1 -> n/2)
	f = deQueue(q);
	l = deQueue(p);
	for (int i = 0; i < len; i++)
	{
		
		if (f.s[i] == l.s[i])			// so sánh nửa đầu nửa cuối với nhau
			continue;
		else
			return false;
	}
	return true;

}


/**
*Test Input
*/
int main() {
	int a[10] = { 5,4,3,2,1,1,2,3,4,5 };
	int n = 10;
	char *s = ("khanh hnahk");
	if (mangDoiXung(a, n)) {
		cout << "Mang doi xung" << endl;
	}
	else cout << "Mang khong doi xung" << endl;
	if (chuoiDoiXung(s))
		cout << "Chuoi doi xung !" << endl;
	else
		cout << "Chuoi khong doi xung !" << endl;
	system("pause");
}
