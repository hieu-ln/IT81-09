/*#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 100
int a[MAX];
int n; // so luong phan tu thuc te cua danh sach
void nhap(int a[], int n);
void xuat(int a[], int n);
int timkiem(int a[], int n, int x);
int themcuoi(int a[], int &n, int x);
int xoacuoi(int a[], int &n);
int xoa(int a[], int &n);

void nhap(int a[], int n)
{
	cout << "Nhap sluong ptu: ";
	do {
		cin >> n;
		if (n <= 0 || n > MAX)
			cout << "Nhap lai n!";
	} while (n <= 0 || n > MAX);
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap a[" << i << "] = ";
		cin >> a[i];
	}
}

void xuat(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

int timkiem(int a[], int n, int x)
{
	int i = 0;
	while ((i < n) && (a[i] != x))
		i++;
	if (i == n)
		return i;
	return -1;
}

int themcuoi(int a[], int &n, int x)
{
	if (n >= 0 && n < MAX - 1)	
	{
		a[n] = x;
		n++;
		return 1;
	}
	return 0;
}

int xoacuoi(int a[], int &n)
{
	if (n > 0)
	{
		n--;
		return 1;
	}
	return 0;
}

int xoa(int a[], int &n, int vti)
{
	if ( vti >= 0 && vti < n)
	{
	//xoa
		for (int j = vti; j < n -1; j++)
			a[j] = a[j + 1];
		n--;
		return 1;
	}
		return 0;
}

int timxoa(int a[], int &n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
			xoa(a, n, i);
		return 1;
	}
	return -1;
}
void menu()
{
	cout << "----BTH1-CHUONG2----" << endl;
	cout << "1. Nhap danh sach" << endl;
	cout << "2. Xuat danh sach" << endl;
	cout << "3. Tim 1 ptu trong danh sach" << endl;
	cout << "4. Them 1 ptu vao cuoi danh sach" << endl;
	cout << "5. Xoa 1 ptu cuoi danh sach" << endl;
	cout << "6. Xoa ptu tai vi tri i trong danh sach" << endl;
	cout << "7. Tim va xoa 1 ptu (neu tim thay) trong danh sach" << endl;
	cout << "8. Thoat" << endl;
}

int main()
{
	int chon = 0;
	int x;
	int kq;
	menu();
	do {
		cout << "Chon so de thuc hien: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
		{
			nhap(a, n);
			break;
		}
		case 2:
		{
			cout << "Danh sach la: ";
			if (n != 0)
				xuat(a, n);
			else
				cout << "Dach sach khong con phan tu nao!" << endl;
			break;
		}
		case 3:
		{
			cout << "Nhap gtri can tim: ";
			cin >> x;
			kq = timkiem(a, n, x);
			if (kq != -1)
				cout << "Gtri x = " << x << " co trong danh sach tai vi tri i = " << kq << endl;
			else
				cout << "Gtri x = " << x << " khong co trong danh sach" << endl;
			break;
		}
		case 4:
		{
			cout << "Nhap gia tri phan tu muon them: ";
			cin >> x;
			cout << "Danh sach sau khi them cuoi la: ";
			xuat(a, n);
			break;
		}
		case 5:
		{
			xoacuoi(a, n);
			if (n != 0)
			{
				cout << "Danh sach sau khi xoa cuoi la: ";
				xuat(a, n);
			}
			else
				cout << "Dach sach khong con ptu nao!" << endl;
			break;
		}
		case 6:
		{
			cout << "Nhap vi tri muon xoa: ";
			cin >> x;
			xoa(a, n, x);
			if (n != 0)
			{
				cout << "Danh sach sau khi xoa tai vi tri " << x << " la: ";
				xuat(a, n);
			}
			else
				cout << "Dach sach khong con phan tu nao!" << endl;
			break;
		}
		case 7:
		{
			cout << "Nhap phan tu muon tim kiem va xoa: ";
			cin >> x;
			kq = timxoa(a, n, x);
			if (kq != -1 && n != 0)
			{
				cout << "Danh sach sau khi xoa la: ";
				xuat(a, n);
			}
			else
				cout << "Khong co gtri " << x << " trong danh sach" << endl;
			break;
		}
		}
	} while (chon != 8);
}
*/