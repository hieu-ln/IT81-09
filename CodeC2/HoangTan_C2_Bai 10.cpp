/* #include <iostream>
using namespace std;
struct Node
{
	int info;
	Node *link;
};
Node *sp;			//luu dia chi phan tu dau tien cua Stack

void init()
{
	sp = NULL;
}

int isEmpty()
{
	if (sp == NULL)
		return 1;
	return 0;
}
void Push(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}

int Pop(int &x)
{
	if (sp != NULL)
	{
		Node *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}

void output()
{
	Node *p = new Node;
	p = sp;
	while (p != NULL)
	{
		cout << p->info << endl;
		p = p->link;
	}
	cout << endl;
}

int Convert(int tp)
{
	init();
	while (tp != 0)
	{
		int d = tp % 2;
		Push(d);
		tp /= 2;
	}
	int np = 0;
	while (!isEmpty())
	{
		int so;
		if (Pop(so))
			np = np * 10 + so;
	}
	return np;
}

void menu()
{
	cout << "\t-----BAI 10 - CHUONG 2-----" << endl;
	cout << "1. Tao danh sach rong" << endl;
	cout << "2. Kiem tra danh sach rong" << endl;
	cout << "3. Chen 1 phan tu vao danh sach" << endl;
	cout << "4. Xoa 1 phan tu ra khoi danh sach" << endl;
	cout << "5. Doi thap phan sang nhi phan" << endl;
	cout << "6. Thoat" << endl;
}

int main()
{
	int choice;
	int x;
	int tp;

	menu();
	do{
		cout << "Chon so de thuc hien: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			init();
			cout << "Tao danh sach rong thanh cong" << endl;
			break;
		case 2:
			x = isEmpty();
			if (x == 1)
				cout << "Kiem tra thanh cong. Danh sach dang rong" << endl;
			else
				cout << "Kiem tra khong thanh cong." << endl;
			break;
		case 3:
			cout << "Nhap gia tri muon them: ";
			cin >> x;
			Push(x);
			cout << "Them gia tri vao danh sach thanh cong" << endl;
			break;
		case 4:
			x = Pop(x);
			if (x != 0)
			{
				cout << "Xoa 1 phan tu thanh cong" << endl;
				cout << "Phan tu co gia tri la: " << x << endl;
			}
			else
				cout << "Xoa khong thanh cong" << endl;
			break;
		case 5:
			break;
		}
	} while(choice != 6);
} */