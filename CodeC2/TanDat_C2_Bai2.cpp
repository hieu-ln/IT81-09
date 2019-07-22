//Bài 2: Quản lý một danh sách có th ứ t ự  tối đa 100 phần tử, mỗi phần tử trong danh sách có kiểu int. (Danh sách đặc)
#include <iostream>
#include<iomanip>
using namespace std;

//2.1.Khai báo cấu trúc danh sách
#define MAX 100
int a[MAX];
int n =-1;

//2.2.Viết thủ tục them một phần tử vào danh sách(thêm một phần tử vào vị trí phù hợp trong danh sách đã có thứ tự).Lưu ý : Không xếp thứ tự danh sách.
int vtthem(int x)
{
	int i;
	for (i = 0; i <= n; i++)
		if (x <= a[i])
			return i;
	return i;
}
bool thembk(int x,int vt)
{
	if (vt == -1 && n > MAX - 1)
		return false;
	else
	{
		for (int i = n+1; i >= vt; i--)
		{
			a[i] = a[i - 1];
		}
		a[vt] = x;
		n++;
		
		return true;
	}
}
bool themcothutu(int x)
{
	if (n == -1)
	{
		a[0] = x;
		n++;
		return true;
	}
	else
	{
		if (thembk(x, vtthem(x)))
			return true;
		else
			return false;

	}
}

//2.3.Viết thủ tục xuất các phần tử danh sách
void xuat()
{
	if (n == -1)
		cout << "Danh sach rong !!\n";
	else
	{
		for (int i = 0; i <= n; i++)
		{
			cout << a[i] << setw(4);
		}
		cout << endl;
	}
}
//2.4.Viết thủ tục tìm một phần tử trong danh sách(dung phương pháp tìm kiếm tuần tự)
bool timkiemtuantu(int x)
{

	for (int i = 0; i <= n; i++)
	{
		if (a[i] == x)
			return true;
	}
	return false;
}
//2.5.Viết thủ tục tìm một phần tử trong danh sách(dùng phương pháp tìm kiếm nhị phân)
int timkiemnhiphan(int x)
{
	int left = 0;
	int right = n;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] == x)
		{
			
			return mid;
		}
		else
		{
			if (x>a[mid])
			{
				left = mid + 1;
			}
			else
				right = mid - 1;
		}
	}
	return -1;
}

//2.6.Viết thủ tục tìm một phần tử trong danh sách.Nếu tìm thấy, xóa phần tử này. (*)
bool timvaxoa(int x)
{
	int vt = timkiemnhiphan(x);
	if (vt == -1)
		return false;
	else
	{
		for (int i = vt; i <= n; i++)
		{
			a[i] = a[i + 1];
		}
		//truong hop n
		if (x != a[vt])
		{
			n--;
			return true;
		}
		else
			return false;
	}
}

void menu()
{
	cout << "1.Them mot phan tu vao danh sach co thu tu\n";
	cout << "2.Xuat cac phan tu co trong danh sach\n";
	cout << "3.Tim mot phan tu (thuat toan: tim kiem tuan tu)\n";
	cout << "4.Tim mot phan tu (thuat toan: tim kiem nhi phan)\n";
	cout << "5.Tim va xoa mot phan tu\n";
	cout << "Ban Chon: ";
}
int main()
{
	char tt;
	do {
		int x;
		cout << "~-~-~-~-~BTTH CHUONG 2: bai 2~-~-~-~-~\n";
		menu();
		int choice;
		cin >> choice;
		
		switch (choice)
		{
		case 1:
		{
			cout << "Nhap gia tri muon them: ";
			cin >> x;
			if (themcothutu(x))
			{
				cout << "them thanh cong \nDanh sach ban vua them la: ";
				xuat();
			}
			else
				cout << "them khong thanh cong or danh sach da day\n";
			break;
		}
		case 2:
		{
			cout << "Phan tu co trong danh sach\n";
			xuat();
			cout << endl;
			break;
		}
		case 3:
		{
			if (n == -1)
				cout << "danh sach rong khong the tim kiem\n";
			else
			{
				cout << "nhap phan tu can tim: ";
				cin >> x;
				if (timkiemtuantu(x))
					cout << x << " co trong danh sach \n";
				else
					cout << x << " khong ton tai\n";
			}
			break;
		}
		case 4:
		{
			
			if (n == -1)
				cout << "danh sach rong khong the tim kiem\n";
			else
			{
				cout << "nhap phan tu can tim: ";
				cin >> x;
				if (a[timkiemnhiphan(x)]==x)
					cout << x << " co trong danh sach \n";
				else
					cout << x << " khong ton tai\n";
			}
			break;
		}
		case 5:
		{
			if (n == -1)
				cout << "danh sach rong khong the xoa\n";
			else
			{
				cout << "nhap phan tu can xoa: ";
				cin >> x;
				if (timvaxoa(x))
				{
					cout << " xoa phan tu " << x << " thanh cong\n";
					cout << "danh sach sau khi xoa \n";
					xuat();
				}
				else
					cout << " xoa khong thanh cong\n";
			}
			break;
		}
		}


		cout << "Ban muon tiep tuc (y/n): ";
		//cin >> tt;
		tt = 'y';
		system("pause");
		system("cls");
	} while (tt == 'y' || tt == 'Y');

}
