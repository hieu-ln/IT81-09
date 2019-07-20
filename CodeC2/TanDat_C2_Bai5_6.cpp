#include <iostream>
#include <iomanip>
using namespace std; 
#define MAX 100 
int a[MAX];
int sp; 
void init() 
{ sp = -1; } 
bool isEmpty() 
{ 
	if (sp == -1) 		
		return true; 	
	return false;
}
bool isFull() 
{
	if (sp == MAX - 1)
		return true;
	return false;
}
int push(int x)
{
	if (!isFull())
	{
		a[++sp] = x; 
		return 1;
	}
	return 0;
}
int pull(int &x)
{
	if (!isEmpty())
	{
		x = a[sp--]; 
		return 1;
	}
	return 0;
}
void output()
{
	for (int i = 0; i <= sp; i++)
		cout << a[i] << setw(4);
	cout << endl;
}
long long tp_to_np(int x)
{
	init();
	long long np = 0;
	
	int so;
	while (x > 0)
	{
		so = x % 2;
		if (push(so))
		{
			x = x / 2;
		}
		
		else
			return -1;
		
	}
	while (!isEmpty())
	{
		if (pull(so))
		{
			np = np * 10 + so;
			
		}
	}
	return np;
}
void menu()
{
	cout << "1.khoi tao stack rong\n";
	cout << "2.kiem tra stack rong\n";
	cout << "3.kiem tra stack day\n";
	cout << "4.them mot phan tu vao stack \n";
	cout << "5.xoa mot phan tu trong stack \n";
	cout << "6.chuyen doi nhi phan sang thap phan\n";
	cout << "Ban Chon: ";
}
int main()
{
	char tt;
	do
	{
		int choice;
		int x;
		cout << "~-~-~-~-~BTTH CHUONG 2: bai 5~-~-~-~-~\n";
		menu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			cout << "khoi tao thanh cong ";
			break;
		case 2:
		{
			if (isEmpty())
				cout << "Stack rong\n";
			else
				cout << "Stack khong rong\n";
			break;
		}
		case 3:
		{
			if (isFull())
				cout << "Stack day\n";
			else
				cout << "Stack chua day\n";
			break;
		}
		case 4:
		{
			cout << "nhap gia tri phan tu stack: ";
			cin >> x;
			if (push(x))
			{
				cout << "them thanh cong\n";
				cout << "danh sach vua them: ";
				output();
			}
			else
				cout << "them khong thanh cong\n";
			break;
		case 5:
		{
			if (pull(x))
			{
				cout << "xoa thanh cong\n";
				output();
			}
			else
				cout << "xoa khong thanh cong\n";
			break;
		}
		case 6:
			int tp;
			cout << "chuyen doi so thap sang nhi phan: ";
			cin >> tp;
			if (tp < 0 || tp_to_np(x) == -1)
				cout << "Loi khong the chuyen doi\n";
			else
				cout << "Nhi phan cua " << tp << " la: " << tp_to_np(tp) << endl;
			init();
			break;
			
		}
		}
		cout << "ban muon tiep tuc khong (y/n): ";
		cin >> tt;
		system("cls");

	} while (tt == 'y' || tt == 'Y');
}