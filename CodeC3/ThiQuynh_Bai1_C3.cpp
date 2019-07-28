// Bai 1, chuong 3: Xep thu tu , tim kiem
#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

#define Max 5000
// Cau 1.1
int a[Max];
int n;
// Cau 1.2: Nhap danh sach
void init(int a[], int& n)
{
	cout << "Nhap so luong phan tu cua danh sach: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 10000 + 1;
	}
	cout << "danh sach da duoc nhap ngau nhien la: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a [i] << " ";

	}
	cout << endl;
}
// Cau 1.2: Nhap danh sach
void input(int a[], int& n)
{
	cout << "Nhap so luong phan tu cua danh sach: ";
	cin >> n;
	cout << "Nhap vao cac phan tu cua danh sach: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]: ";
		cin >> a[i];
	}
}
// Cau 1.3: Xuat danh sach
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";

	}
	cout << endl;
}
void CopyArray(int a[], int b[], int n)
{
	for (int i = 0; i < n; i++)
	{
		b[i] = a[i];
	}
}
// Cau 1.4: insertion Sort
void insertionsort(int a[], int n)
{
	int i, key, j;
	for (i = 0; i < n; i++)
	{
		key = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}
//ham hoan doi hai so nguyen
void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}
// Cau 1.5: selection sort
void selectionsort(int a[], int n)
{
	int i, j, min_idx;
	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min_idx])
				min_idx = j;
		swap(a[min_idx], a[i]);
	}
}
// Cau 1.6
void interchangesort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);

}
// Cau 1.7 Ham sap xep Bubble sort
void bubblesort(int arr[], int n)
{
	int i, j;
	bool haveSwap = false;
	for ( i = 0; i < n - 1; i++)
	{
		if (arr[j] > arr[j + 1])
		{
			swap(arr[j], arr[j + 1]);
			haveSwap = true;
		}
	}
	if (haveSwap == false)
	{
		return;
	}
}
// Cau 1.8
int partition(int a[], int low, int high)
{
	int pivot = a[high];
	int left = low;
	int right = high - 1;
	while (true)
	{
		while (left <= right && a[left] < pivot) left++;
		while (right >= left && a[right] > pivot) right--;
		if (left >= right) break;
		swap(a[left], a[high]);
		return left;

	}
}
// Ham thuc hien giai thuat Quick sort
void quicksort(int a[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(a, low, high);
		quicksort(a, low, pi - 1);
		quicksort(a, pi + 1, high);
	}
}
//Cau 1.9
void heapify(int a[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && a[l] > a[largest])
		largest = l;
	if (r < n && a[r] > a[largest])
		largest = r;
	if (largest != i)
	{
		swap(a[i], a[largest]);
		heapify(a, n, largest);
	}
}void heapsort(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(a, n, i);
	for (int i = n - 1; i >= 0; i--)
		heapify(a, n, 0);
}
//Cau 1.10
void searchSequence(int a[], int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
	{
		i++;
	}
	if (i == n)
	{
		cout << "Khong tim thay";
	}
	else
	{
		cout << "Tim thay tai vi tri " << i;
	}
	cout << endl;
}
//Cau 1.11
int searchbinary(int a[], int l, int r, int x)
{
	if (r >= l)
	{
		int mid = l + (r - l) / 2;
		if (a[mid] == x)
			return mid;
		if (a[mid] > x)
			return searchbinary(a, l, mid - 1, x);
		else
			return searchbinary(a, l, mid + 1, x);
	}
	return -1;
}
int main()
{
	int b[Max];
	clock_t start;
	double duration;
	int choice, x, i;
	system("cls");
	cout << "-------------Bai tap 1, Chuong 3, Xep thu tu va Tim kiem--------------" << endl;
	cout << "0. Khoi tao danh sach ngau nhien" << endl;
	cout << "1. Nhap danh scah " << endl;
	cout << "2. Xuat danh sach " << endl;
	cout << "3. Xep thu tu danh sach bang Selection Sort " << endl;
	cout << "4. Xep thu tu danh sach bang Insertion Sort " << endl;
	cout << "5. Xep thu tu danh sach bang Bubble Sort " << endl;
	cout << "6. Xep thu tu danh sach bang Interchange Sort " << endl;
	cout << "7. Xep thu tu danh sach bang Quick Sort " << endl;
	cout << "8. Xep thu tu danh sach bang  Heap Sort " << endl;
	cout << "9. Tim kiem phan tu x bang Tim kiem tuan tu " << endl;
	cout << "10. Tim kiem phan tu x bang Tim kiem nhi phan " << endl;
	cout << "11. Thoat " << endl;
	do
	{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
			case 0:
				init(a, n);
				break;
			case 1:
				input(a, n);
				break;
			case 2:
				cout << "Danh sach la: " << endl;
				output(a, n);
				break;
			case 3:
				CopyArray(a, b, n);
				start = clock();
				selectionsort(b, n);
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				if (n < 100)
				{
					cout << "Danh sach sau khi xep  thu tu voi Selection Sort la: " << endl;
					output(b, n);
				}
				if (duration > 0)
					cout << "Thoi gian Selection sort la: " << duration * 100000 << " Microsecond " << endl;
				break;
			case 4 :
				CopyArray(a, b, n);
				start = clock();
				insertionsort(b, n);
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				if (n < 100)
				{
					cout << "Danh sach sau khi xep  thu tu voi Insertion Sort la: " << endl;
					output(b, n);
				}
				if (duration > 0)
					cout << "Thoi gian Insertion sort la: " << duration * 100000 << " Microsecond " << endl;
				break;
			case 5:
				CopyArray(a, b, n);
				start = clock();
				bubblesort(b, n);
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				if (n < 100)
				{
					cout << "Danh sach sau khi xep  thu tu voi Bubble Sort la: " << endl;
					output(b, n);
				}
				if (duration > 0)
					cout << "Thoi gian Bubble sort la: " << duration * 100000 << " Microsecond " << endl;
				break;
			case 6:
				CopyArray(a, b, n);
				start = clock();
				interchangesort(b, n);
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				if (n < 100)
				{
					cout << "Danh sach sau khi xep  thu tu voi Interchange Sort la: " << endl;
					output(b, n);
				}
				if (duration > 0)
					cout << "Thoi gian Interchange sort la: " << duration * 100000 << " Microsecond " << endl;
				break;
			case 7:
				CopyArray(a, b, n);
				start = clock();
				quicksort(b,0, n);
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				if (n < 100)
				{
					cout << "Danh sach sau khi xep  thu tu voi Quick Sort la: " << endl;
					output(b, n);
				}
				if (duration > 0)
					cout << "Thoi gian Quick sort la: " << duration * 100000 << " Microsecond " << endl;
				break;
			case 8:
				CopyArray(a, b, n);
				start = clock();
				heapsort(b, n);
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				if (n < 100)
				{
					cout << "Danh sach sau khi xep  thu tu voi Heap Sort la: " << endl;
					output(b, n);
				}
				if (duration > 0)
					cout << "Thoi gian Heap sort la: " << duration * 100000 << " Microsecond " << endl;
				break;
			case 9:
				cout << "Vui long nhap gia tri x: ";
				cin >> x;
				start = clock();
				searchSequence(a, n, x);
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				if (duration > 0)
					cout << "\n Thoi gian tim kiem tuan tu la: " << duration * 100000 << " microsecond " << endl;
				break;
			case 10:
				cout << "Vui long nhap gia tri x: ";
				cin >> x;
				start = clock();
				i = searchbinary(b, 0, n, x);
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				if (i == -1)
					cout << "Khong tim thay x " << x << " trong day " << endl;
				else
					cout << "Tim thay x " << x << " tai vi tri i = " << i << endl;
				if (duration > 0)
					cout << "\n Thoi gian tim kiem nhi phan la: " << duration * 100000 << " microsecond " << endl;
				break;
			case 11:
				cout << "Bye " << endl;
			default:
				break;
		}
			
	}while (choice != 11);
	system("pause");
	return 0;
		
}