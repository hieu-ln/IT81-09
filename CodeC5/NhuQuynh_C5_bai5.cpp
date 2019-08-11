#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#define MAX 20

struct Node{
	int info;
	Node *link;
};

Node *first[MAX];
int n;
char vertex[MAX];

Node *sp;
Node *front, *rear;

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
	Node *p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}
int popS(int &x)
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
	Node *p = new Node;
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
		Node *p = front;
		front = p->link;
		x = p->info;
		if (front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}
void initGraph(int &n)
{
	for (int i = 0; i < n; i++)
		first[i] = NULL;
	n = 0;
}
void insertLast(Node *&first, Node *p)
{
	if (first == NULL)
		first = p;
	else
	{
		Node *q = first;
		while (q->link != NULL)
			q = q->link;
		q->link = p;
	}
}

void inputGraphFromText()
{
	string line;
	ifstream myfile ("danhsachke1.txt");
	if (myfile.is_open())
	{
		myfile >> n;
		for (int i = 0; i < n ; i++)
			myfile >> vertex[i];
		string str;
		int i = 0;
		while (getline(myfile, str))
		{
			istringstream ss(str);
			int u;
			while (ss >> u)
			{
				Node *p = new Node;
				p->info = u;
				p->link = NULL;
				insertLast(first[i - 1], p);
			}
			i++;
		}
	}
}

void inputGraph()
{
	cout << "Nhap so dinh cua do thi: ";
	cin >> n;
	cout << "Nhap ten dinh: ";
	for (int i = 0; i < n; i++)
		cin >> vertex[i];
	for (int i = 0; i < n; i++)
	{
		if (i > 0)
			cout << "Nhap DSK cua dinh thu " << i - 1<< " (" << vertex[i - 1] << "): ";
		int u;
		string str;
		while (getline(cin, str))
		{
			istringstream ss(str);
			while (ss >> u)
			{
				Node *p = new Node;
				p->info = u;
				p->link = NULL;
				insertLast(first[i - 1], p);
			}
			break;
		}
	}
}
//5.2
void outputGraph()
{
	for (int i = 0; i < n; i++)
	{
		cout << "Dinh " << i << " (" << vertex[i] << "): ";
		Node *p = first[i];
		while (p != NULL)
		{
			cout << p->info << " ";
			p = p->link;
		}
		cout << endl;
	}
}
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << vertex[a[i]] << " ";
	cout << endl;
}

//BFS
int C[100], bfs[100];
int nbfs = 0;
void initC()
{
	for (int i = 0; i < n; i++)
		C[i] = 1;
}
void BFS(int v)
{
	int p;
	Node *w;
	pushQ(v);
	C[v] = 0;
	while (front != NULL)
	{
		popQ(p);
		bfs[nbfs] = p;
		w = first[p];
		nbfs++;
		while (w != NULL)
		{
			if (C[w->info])
			{
				pushQ(w->info);
				C[w->info] = 0;
			}
			w = w->link;
		}
	}
}

//DFS
int dfs[100];
int ndfs = 0;
void DFS(int s)
{
	pushS(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int u = s;
	Node *v = NULL;
	while (isEmptyS() == 0)
	{
		if (v == NULL)
			popS(u);
		v = first[u];
		while (v != NULL)
		{
			if (C[v->info] == 1)
			{
				pushS(u);
				pushS(v->info);
				dfs[ndfs] = v->info;
				ndfs++;
				C[v->info] = 0;
				u = v->info;
				break;
			}
			v = v->link;
		}
	}
}

void searchByBFS(int x, int v)
{
	int p;
	Node *w;
	pushQ(v);
	C[v] = 0;
	while (front != NULL)
	{
		popQ(p);
		if (x == p)
		{
			cout << "Tim thay x = " << x << endl;
			return;
		}
		w = first[p];
		while (w != NULL)
		{
			if (C[w->info])
			{
				pushQ(w->info);
				C[w->info] = 0;
			}
			w = w->link;
		}
	}
}
void main()
{
	int choice, x, i;
	system("cls");
	cout << "------BAI 5- CHUONG 5------" << endl;
	cout << "1. Khoi tao DSK rong" << endl;
	cout << "2. Nhap DSK tu file text" << endl;
	cout << "3. Nhap DSK" << endl;
	cout << "4. Xuat DSK" << endl;
	cout << "5. Duyet do thi theo chieu rong BFS - DSLK" << endl;
	cout << "6. Duyet do thi theo chieu sau DFS - DSLK" << endl;
	cout << "7. Tim dinh co gia tri x theo BFS" << endl;
	cout << "0. Thoat" << endl;

	do{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			n = 10;
			initGraph(n);
			cout << "Ban vua khoi tao DSK trong thanh cong" << endl;
			break;
		case 2:
			inputGraphFromText();
			cout << "Ban vua nhap DSK tu file" << endl;
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
			cout << "Vui long nhap dinh de xuat phat: ";
			cin >> x;
			nbfs = 0;
			BFS(x);
			cout << "Thu tu dinh sau khi duyet BFS: ";
			output(bfs, n);
			break;
		case 6:
			initStack();
			initC();
			cout << "Vui long nhap dinh de xuat phat: ";
			cin >> x;
			ndfs = 0;
			DFS(x);
			cout << "Thu tu dinh sau khi duyet DFS: " << endl;
			output(dfs, n);
			break;
		case 7:
			initQueue();
			initC();
			nbfs = 0;
			cout << "Vui long nhap dinh de tim kiem: ";
			cin >> x;
			searchByBFS(x, 0);
			break;
		default:
			cout << "GOODBEY!...." << endl;
		}
	} while(choice >= 1 && choice <= 7);
}


















