#include<iostream>
#include<iomanip>
using namespace std;

#define MAX 9
int a[MAX];
int front, rear;

void init()
{
	front = -1;
	rear = -1;
}
bool isEmpty()
{
	if (rear == -1)
		return true;
	return false;
}
bool isFull()
{
	if (rear - front == MAX - 1)
		return true;
	return false;
}

int Pust(int x)
{
	if ((rear - front == MAX - 1) || (rear - front == -1))
		return 0;
	else
	{
		if (front == -1)
		
			front = 0;

		if (rear == MAX) 
			rear = -1; 
		
		a[++rear] = x; 
		
		return 1;
	}
}
int Pop( int &x)
{
	if (front != -1)
	{
		x = a[front];
		if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		else {
			front++;
			if (front > MAX - 1) front = 0;
		} return 1;
	} return 0;

}
void output()
{
	int tang = front;
	do 
	{
		cout << a[tang] << setw(4);
		tang++;
		if (tang == MAX)
		{
			tang = 0;
		}
	} while (tang != rear+1);
	cout <<  endl;
}
void menu()
{
	cout << "1.Khoi tao Queue rong\n";
	cout << "2.Kiem tra Queue rong\n";
	cout << "3.Kiem tra Queue day\n";
	cout << "4.Them mot phan tu vao Queue\n";
	cout << "5.Xoa mot phan tu Queue \n";
	cout << "6.Xuat danh sach queue \n";
	cout << "Ban chon: ";

}

int main()
{
	char tt;
	do
	{
		int choice;
		int x;
		cout << "~-~-~-~-~BTTH CHUONG 2: bai 7~-~-~-~-~\n";
		menu();
		output();
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			init();
			cout << "khoi tao thanh cong\n";
			break;
	
		}
		case 2:
			if (isEmpty())
				cout << "Queue rong\n";
			else
				cout << "Queue có phan tu\n";
			break;
		case 3:
			isFull()?cout << "Danh sach queue da day\n" : cout << "Danh sach queue chua day\n";
			break;
		case 4:
		{
			cout << "Nhap phan tu muon them: ";
			cin >> x;
			if (Pust(x))
			{
				cout << "them thanh cong\n";
				cout << "Danh sach sau khi tang la: ";
				output();
			
			}
			else
				cout << "Them khong thanh cong\n";
			break;
		}
		
		case 5:
		{
			if (Pop(x)) {
				cout << "xoa thanh cong\n";
				cout << "danh sach sau khi xoa la: ";
				output();

			}
			else
				cout << "xoa khong thang cong\n";
			break;
		}
		case 6:
		{
			cout << "danh sach queue: ";
			output();
			cout << endl;
			break;
		}
		}
		cout << "Ban muon tiep khong (y/n): ";
		cin >> tt;
		system("cls");
	} while (tt == 'y' || tt == 'Y');
}
