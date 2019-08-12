//BAI 4 CHUONG 5
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

#define MAX 20
int a[MAX][MAX]; //mang ma tran ke
int n; //so dinh cua do thi
char vertex[MAX]; //mang ten dinh

//Cac ham cua Stack va Queue
//cau truc
struct node{
	int info;
	node *link;
};
node *sp;
node *front, *rear;

//STACK
void initStack()
{
	sp = NULL;
}
int isEmptyS()
{
	if (sp == NULL)
		return 1;
	return 0;
}
void pushS(int x)
{
	node *p = new node;
	p->info = x;
	p->link = sp;
	sp = p;
}
int popS(int &x)
{
	if (sp != NULL)
	{
		node *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}

//QUEUE
void initQueue()
{
	front = NULL;
	rear = NULL;
}
int isEmptyQ()
{
	if (front == NULL)
		return 1;
	return 0;
}
void pushQ(int x)
{
	node *p = new node;
	p->info = x;
	p->link =NULL;
	if (front == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}
int popQ(int &x)
{
	if (front != NULL)
	{
		node *p = front;
		front = p->link;
		x = p->info;
		if (front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}

//do thi
void initGraph()
{
	n = 0;
}
//lay du lieu tu file text
void inputGraphFromText()
{
	string line;
	ifstream myfile ("matranke1.txt");
	if (myfile.is_open())
	{
		myfile >> n;
		for (int i = 0; i < n; i++)
			myfile >> vertex[i];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				myfile >> a[i][j];
	}
}
//4.1: Nhap ma tran ke cua do thi
void inputGraph()
{
	cout << "Nhap so dinh cua do thi: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap ten dinh: ";
		cin >> vertex[i];
		cout << "Nhap vao dong thu " << i + 1 << ": ";
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}
}
//4.2: Xuat ma tran ke cua do thi
void outputGraph()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " ";
	cout << endl;
	}
}
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << vertex[a[i]] << " ";
}
//4.3: Duyet do thi theo thu chieu rong BFS
int C[100];
int bfs[100];
int nbfs = 0;
void initC()
{
	for (int i = 0; i < n; i++)
		C[i] = 1;
}
void BFS(int v)
{
	int w, p;
	pushQ(v);
	C[v] = 0;
	while (front != NULL)
	{
		popQ(p);
		bfs[nbfs] = p;
		nbfs++;
		for (w = 0; w < n; w++)
			if (C[w] && a[p][w] == 1)
			{
				pushQ(w);
				C[w] = 0;
			}
	}
}
//4.4: Duyet do thi theo chieu sau DFS
int dfs[100];
int ndfs = 0;
void DFS(int s)
{
	pushS(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int v = -1, u = s;
	while (isEmptyS() == 0)
	{
		if (v == n)
			popS(u);
		for (v = 0; v < n; v++)
			if (a[u][v] != 0 && C[v] == 1)
			{
				pushS(u);
				pushS(v);
				dfs[ndfs] = v;
				ndfs++;
				C[v] = 0;
				u = v;
				break;
			}
	}
}
//4.5: Dung BFS tim x trong do thi
void searchByBFS(int x, int v)
{
	int w, p;
	pushQ(v);
	C[v] = 0;
	while (front != NULL)
	{
		popQ(p);
		if (x == p)
		{
			cout << "Tim thay gia tri x = " << x << endl;
			return;
		}
		for (w = 0; w < n; w++)
			if (C[w] && a[p][w] == 1)
			{
				pushQ(w);
				C[w] = 0;
			}
	}
}

//xuat menu
void menu()
{
	cout << "----- BAI 4 - CHUONG 5 ------" << endl;
	cout << "1. Khoi tao MA TRAN KE rong" << endl;
	cout << "2. Nhap MA TRAN KE tu file text" << endl;
	cout << "3. Nhap MA TRAN KE" << endl;
	cout << "4. Xuat MA TRAN KE" << endl;
	cout << "5. Duyet do thi theo chieu rong BFS" << endl;
	cout << "6. Duyet do thi theo chieu sau DFS" << endl;
	cout << "7. Tim dinh co gia tri x theo chieu rong BFS" << endl;
	cout << "0. Thoat" << endl;
}

void main()
{
	int a[MAX], b[MAX];
	int choice, sp, sp_b, x, i;
	menu();

	do{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			initGraph();
			cout << "Ban vua khoi tao MA TRAN KE rong thanh cong" << endl;
			break;
		case 2:
			inputGraphFromText();
			cout << "Ban vua nhap MA TRAN KE tu file:" << endl;
			outputGraph();
			break;
		case 3:
			inputGraph();
			break;
		case 4:
			outputGraph();
			break;
		case 5:
			initQueue();
			initC();
			cout << "Vui long nhap dinh xuat phat: ";
			cin >> x;
			nbfs = 0;
			BFS(x);
			cout << "Thu tu dinh sau khi duyet BFS:" << endl;
			output(bfs, n);
			cout << endl;
			break;
		case 6:
			initStack();
			initC();
			cout << "Vui long nhap dinh xuat phat: ";
			cin >> x;
			ndfs = 0;
			DFS(x);
			cout << "Thu tu dinh sau khi duyet DFS:" << endl;
			output(dfs, n);
			cout << endl;
			break;
		case 7:
			initQueue();
			initC();
			nbfs = 0;
			cout << "Vui long nhap gia tri can tim: ";
			cin >> x;
			searchByBFS(x, 0);
			break;
		default:
			cout <<"...GOODBEY...." << endl;
		}
	} while(choice >= 1 && choice <= 7);
}