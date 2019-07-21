#include <iostream>
using namespace std;

//11.1
struct node
{
	int info;
	node *link;
};
node *front, *rear;
//11.2
void init()
{
	front =  NULL;
	rear = NULL;
}
//11.3
int isEmpty()
{
	if (front == NULL && rear == NULL)
		return 1;
	return 0;
}
//1.4
void push(int x)
{
	node *p = new node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
		front = p;
	else
		rear->link = p;

	rear = p;
}
//11.5
	//tu code
int pop(int &x)
{
	if (isEmpty())
		return 0;
	else
	{
		node *p = front;
		x = p->info;
		front = front->link;
		if (front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
}
void menu()
{
	cout << "------CHUONG 2 - BAI 11------" << endl;
	cout << "1. Tao Queue rong" << endl;
	cout << "2. Kiem tra Queue rong" << endl;
	cout << "3. Them 1 phan tu vao Queue" << endl;
	cout << "4. Lay 1 phan tu ra khoi Queue (tu code)" << endl;
	cout << "5. Lay 1 phan tu ra khoi Queue (code sgk)" << endl;
	cout << "0. Thoat" << endl;
}

void main()
{
	int choice, x, kq;

	menu();
	do{
		cout << "Chon 1 so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			init();
			cout << "Tao Queue rong thanh cong" << endl;
			break;
		case 2:
			kq = isEmpty();
			if (kq == 1)
				cout << "Kiem tra thanh cong! Queue dang rong" << endl;
			else
				cout << "Kiem tra khong thanh cong!" << endl;
			break;
		case 3:
			cout << "Nhap gtri can them: ";
			cin >> x;
			push(x);
			cout << "Them ptu x = " << x << " thanh cong" << endl;
			break;
		case 4:
			kq = pop(x);
			if (kq == 1)
				cout << "Lay 1 ptu thanh cong! Gtri x = " << x << endl;
			else
				cout << "Lay 1 ptu khong thanh cong!" << endl;
			break;
		case 5:
			kq = popGT(x);
			if (kq == 1)
				cout << "Lay 1 ptu thanh cong! Gtri x = " << x << endl;
			else
				cout << "Lay 1 ptu khong thanh cong!" << endl;
			break;
		default:
			cout << "GoodBey" << endl;
		}
	} while(choice != 0);
}