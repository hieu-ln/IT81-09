#include <iostream>
#include<conio.h>
#include <iomanip>
using namespace std;
#define MAX 100
int a[MAX];
int n;
void input()
{
	do
	{
		cout << "Nhap so luong phan tu: ";
		cin >> n;
		if (n > MAX - 1)
		{
			cout << "\nSo luong phan tu vua nhap vuot qua muc toi da 100 phan tu!. Nhan Enter Nhap lai\n";
			_getch();
		}
		if (n <= 0)
		{
			cout << "\nSo luong phan tu phai lon hon 0!. Nhan Enter Nhap lai\n";
			_getch();
		}
	} while (n > MAX - 1 || n <= 0);

	for (int i = 0; i < n; i++)
	{
		cout << "Gia tri phan tu thu " << i + 1 <<" = " ;
		cin >> a[i];
	}
	cout << endl;
}
void output()
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "    ";
	}
	cout << endl;
}
void InsertionSort(int a[] , int n)
{
	int x, j;
	for (int i = 1; i<n; i++)
	{
		x = a[i];
		j = i - 1;
		while (0 <= j && x <a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
//1.5
void SelectionSort(int a[], int n)
{
	int  min_pos, i, j;
	for (i = 0; i < n - 1; i++)
	{
		min_pos = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min_pos])
				min_pos = j;
		swap(a[min_pos], a[i]);
	}
}
//1.6
void InterchangeSort(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[i])
				swap(a[i], a[j]);
		}
	}
}
//1.7
void BubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j - 1] > a[j])
				swap(a[j], a[j - 1]); 
}
//1.8
void QuickSort(int a[], int left, int right)
	{
		int x = a[(left + right) / 2];
		int i = left;
		int j = right;
		while (i<j)
		{
			while (a[i]<x) i++;
			while (a[j]>x) j--;
			if (i <= j) 
			{
				swap(a[i], a[j]);
				i++;
				j--;
			}
		}
		if (left<j) QuickSort(a, left, j);
		if (i<right) QuickSort(a, i, right);
}
void shift(int a[], int i, int n)
{
	int j = 2 * i + 1;
	if (j >= n) 
		return;
	if (j + 1 <n)
		if (a[j]<a[j + 1])
			j++;

	if (a[i] >= a[j])
		return;
	else {
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift(a, j, n);
	}
}
void HeapSort(int a[], int n)
{
	int i = n / 2;
	while (i >= 0)
	{
		shift(a, i, n - 1);	
		i--;
	}
	int right = n - 1;
	while (right>0)
	{
		swap(a[0], a[right]);
		right--;
		if (right > 0) 
			shift(a, 0, right);
	}
}

int Search_tuantu(int x)
{
	for (int i = 0; i < n; i++)
		if (a[i] == x)
			return 1;
	return 0;

}

int Search_binary(int x,int a[],int n)
{
	int left = 0, right = n - 1;
	int mid;
	QuickSort(a, 0, n - 1);
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] == x)
			return 1;
		if (x > a[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	return 0;
}

void menu()
{
	cout << "1.Nhap danh sach\n";
	cout << "2.Xuat danh sach\n";
	cout << "3.Insertion Sort\n";
	cout << "4.Seletion Sort\n";
	cout << "5.Interchange Sort\n";
	cout << "6.Bubble Sort\n";
	cout << "7.Quick Sort\n";
	cout << "8.Heap Sort\n";
	cout << "9.Search Tuan Tu\n";
	cout << "10.Search Binary\n";
	cout << "Ban chon: ";

}
//main
int main()
{
	int tt;
	do {
		int choose;
		menu();
		cin >> choose;

		switch (choose)
		{
		case 1:
		{
			input();
			cout << "Danh sach vua nhap la: ";
			output();
			cout << "Nhap danh sach thanh cong!!\n";
			break;
		}
		case 2:
		{
			cout << "Danh sach cac phan tu: ";
			output();
			break;
		}
		case 3:
		{
			if (n != 0)
			{
				InsertionSort(a, n);
				cout << "Danh sach sau khi sap xep la: ";
				output();
			}
			else
			{
				cout << "Danh sach rong. Khong the sap xep!\n";
			}
			break;
		}
		case 4:
		{
			if (n != 0)
			{
				SelectionSort(a, n);
				cout << "Danh sach sau khi sap xep la: ";
				output();
			}
			else
			{
				cout << "Danh sach rong. Khong the sap xep!\n";
			}
			break;
		}
	
		case 5:
		{
			if (n != 0)
			{
				InterchangeSort(a, n);
				cout << "Danh sach sau khi sap xep la: ";
				output();
			}
			else
			{
				cout << "Danh sach rong. Khong the sap xep!\n";
			}
			break;
		}
		case 6:
		{
			if (n != 0)
			{
				BubbleSort(a, n);
				cout << "Danh sach sau khi sap xep la: ";
				output();
			}
			else
			{
				cout << "Danh sach rong. Khong the sap xep!\n";
			}
			break;
		}
		case 7:
		{

			if (n != 0)
			{
				QuickSort(a, 0, n);
				cout << "Danh sach sau khi sap xep la: ";
				output();
			}
			else
			{
				cout << "Danh sach rong. Khong the sap xep!\n";
			}
			break;
		}
		case 8: 
		{

			if (n != 0)
			{
				HeapSort(a, n);
				cout << "Danh sach sau khi sap xep la: ";
				output();
			}
			else
			{
				cout << "Danh sach rong. Khong the sap xep!\n";
			}
			break;
		}
		case 9: 
		{
			int x;
			cout << "Nhap gia tri can tim: ";
			cin >> x;
			if (Search_tuantu(x))
				cout << x << " co trong danh sach \n";
			else
				cout << "Khong tim thay " << x << " trong danh sach\n";
			break;

		}
		case 10:
		{
			int x;
			cout << "Nhap gia tri can tin: ";
			cin >> x;
			if (Search_binary(x, a, n))
				cout << x << " co trong danh sach \n";
			else
				cout << "Khong tim thay " << x << " trong danh sach\n";
			break;
		}
		}


		cout << "Ban muon tiep tuc khong (y/n): \n";
		cin >> tt;
		system("cls");
	} while (tt == 'y' || tt == 'Y');
