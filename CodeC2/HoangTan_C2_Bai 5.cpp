 /*  <iostream>
using namespace std;

#define MAX 100
int a[MAX];
int sp;					// dinh Stack
void Menu();

void init(int a[], int &sp)
{
	sp = -1;
}

int isEmpty(int a[], int sp)
{
	if (sp == -1)
		return 1;
	return 0;
}

int isFull(int a[], int sp)
{
	if (sp == MAX - 1)
		return 1;
	return 0;
}

int Push(int a[], int &sp, int x)
{
	if (sp < MAX - 1)
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}

int Pop(int a[], int &sp, int &x)
{
	if (sp != -1) // khi Stack khac rong
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}
void output(int a[], int n)
{
	for (int i = sp; i >= 0; i--)
		cout << a[i] << endl;
}

int main()
{
	char tt;
	int chon;
	do {
		cout << "1. Khoi tao\n2. Kiem tra rong\n3. Kiem tra day\n4. Them 1 phan tu\n5. Xoa 1 phan tu\n6. Xuat stack\nBan chon: \n";
		cin >> chon;
		switch (chon)
		{
		case 1:
			cout << "Khoi tao Stack thanh cong\n";
			break;
		case 2:
			if (isEmpty(a, sp))
				cout << "Stack rong\n";
			else
				cout << "Stack khong rong\n";
			break;
		case 3:
			if (isFull(a, sp))
				cout << "Stack day\n";
			else
				cout << "Stack chua day\n";
			break;
		case 4:
			int x;
			cout << "Nhap gia tri can them vao Stack: ";
			cin >> x;
			if (Push(a, sp, x))
				cout << "Them thanh cong\n";
			else
				cout << "Them khong thanh cong\n";
			break;
		case 5:
			int y;
			if (Pop(a, sp, y))
				cout << "Xoa thanh cong. Phan tu xoa duoc la: " << y << endl;
			else
				cout << "Xoa khong thanh cong\n";
		case 6:
			cout << "Stack hien tai: " << endl;
			output(a, sp);
			break;
		}
		cout << "Ban co muon tiep tuc hay khong (y/n): ";
		cin >> tt;
	} while (tt == 'y' || tt == 'Y');
}*/