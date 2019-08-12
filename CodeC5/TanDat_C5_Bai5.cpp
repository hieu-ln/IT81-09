//Bai 4, Chuong 5: Do Thi
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#define MAX 20
///DSLK su dung cho STACK va QUEUE
struct Node{
	int info;
	Node *link;
};

Node *First[MAX];		//DS cac DSK
int n;					//so dinh cua do thi
char vertex[MAX];		//ten dinh

Node *sp;
Node* front, *rear;

//STACK
void InitStack()
{
	sp = NULL;
}

int isEmptyS()
{
	if (sp == NULL)
		return 1;
	return 0;
}

void PushS(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}

int PopS(int &x)
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

//End STACK

//QUEUE
void InitQueue()
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
void PushQ(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = NULL;
	if(rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}
int PopQ(int &x)
{
	if(front != NULL)
	{
		Node *p = front;
		front = p->link;
		x = p->info;
		if(front == NULL)
		{
			rear = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}
///End QUEUE

void InitGraph()
{
	n = 0;
}

void InsertLast(Node *&first, Node *p)
{
	if(first == NULL)
		first = p;
	else
	{
		Node * q = first;
		while(q->link != NULL)
		{
			q = q->link;
		}
		q->link = p;
	}
}

void inputGraphFromText()
{
	string line;
	ifstream myfile("danhsachke1.txt");
	if (myfile.is_open())
	{
		myfile >> n;
		for( int i = 0; i < n; i++)
			myfile >> vertex[i];
		string str;
		int i = 0;
		while(getline(myfile, str))
		{
			istringstream ss(str);
			int u;
			while(ss >> u)
			{
				//Dinh u
				Node *p = new Node;
				p->info = u;
				p->link = NULL;
				InsertLast(First[i-1], p);
			}
			i++;
		}
		cout << i;
	}
}

//Cau 5.1: Nhap DANH SACH KE cua do thi
void inputGraph()
{
	cout << "Nhap so dinh do thi n: ";
	cin >> n;
	cout << "Nhap ten dinh: ";
	for(int i = 0; i < n; i++)
		cin >> vertex[i];
	for(int i = 0; i < n+1; i++)
	{
		if(i > 0)
			cout << "Nhap DSK cua dinh thu "<<i-1<<" ("<<vertex[i-1]<<"): ";
		int u;
		string str;
		while(getline(cin,str))
		{
			istringstream ss(str);
			while(ss >> u)
			{
				Node *p = new Node;
				p->info = u;
				p->link = NULL;
				InsertLast(First[i-1], p);
			}
			break;
		}
	}
}

//Cau 5.2 Xuat DANH SACH KE cua do thi
void outputGraph()
{
	for(int i = 0; i < n; i++)
	{
		cout << "Dinh "<<i<<" ( "<<vertex[i]<<"): ";
		Node *p = First[i];
		while(p!=NULL)
		{
			cout << p->info << " ";
			p = p->link;
		}
		cout << endl;
	}
}

void output(int a[], int n)
{
	for(int i = 0; i < n; i++)
		cout << vertex[a[i]] << "  ";
}

//Cau 5.3 Duyet do thi theo chieu rong BFS (Dung Queue...)
int C[100], bfs[100];
int nbfs = 0;
void InitC()
{
	for(int i = 0; i < n; i++)				// n la so dinh cua do thi
		C[i] = 1;
}
void BFS(int v)							// v la dinh bat dau
{
	int p;
	Node *w;
	PushQ(v);
	C[v] = 0;
	while( front != NULL)
	{
		PopQ(p);
		bfs[nbfs] = p;
		w = First[p];
		nbfs ++;
		while(w!=NULL)
		{
			if(C[w->info])
			{
				PushQ(w->info);
				C[w->info] = 0;
			}
			w = w->link;
		}
	}
}

//Cau 5.4 Duyet do thi theo chieu DFS (Dung STACK)
int dfs[100];
int ndfs = 0;
void DFS(int s)
{
	PushS(s);
	dfs[ndfs] = s;
	ndfs++;
	int u = s;
	C[s] = 0;
	Node *v = NULL;
	while (isEmptyS() == 0)
	{
		if(v == NULL)
			PopS(u);
		v = First[u];
		while(v!=NULL)
		{
			if(C[v->info]==1)
			{
				PushS(u);
				PushS(v->info);
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

//Cau 5.5 Dung BFS tim x tren do thi
void Search_by_BFS(int x, int v)
{
	int w, p;
	PushQ(v);
	C[v] = 0;
	while(front != NULL)
	{
		PopQ(p);
		if (x == p)
		{
			cout << "Tim thay x ="<<x<< endl;
			return;
		}
		for(int w = 0; w < n; w++)
			if(C[w])
			{
				PushQ(w);
				C[w] = 0;
			}
	}
}

int main()
{
	int choice, x, i;
	system("cls");
	cout << "--------- BAI TAP 4 , CHUONG 5 , DO THI ---------" << endl;
	cout << "1. Khoi tao DANH SACH KE rong" << endl;
	cout << "2. Nhap DANH SACH KE tu file text" << endl;
	cout << "3. Nhap DANH SACH KE " << endl;
	cout << "4. Xuat DANH SACH KE " << endl;
	cout << "5. Duyet do thi theo chieu rong BFS - DSLK" << endl;
	cout << "6. Duyet do thi theo chieu sau DFS - DSLK" << endl;
	cout << "7. Tim dinh co gia tri x theo BFS" << endl;
	cout << "8. Thoat" << endl;
	do
	{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			InitGraph();
			cout << "Ban vua khoi tao DANH SACH KE rong thanh cong!\n";
			break;
		case 2:
			inputGraphFromText();
			cout << "Ban vua nhap DANH SACH KE tu file: \n";
			outputGraph();
			break;
		case 3:
			inputGraph();
			break;
		case 4:
			outputGraph();
			break;
		case 5:
			InitQueue();
			InitC();
			cout << "Vui long nhap dinh xuat phat: ";
			cin >> x;
			nbfs = 0;
			BFS(x);
			cout << "Thu tu dinh sau khi duyet BFS: "<< endl;
			output(bfs,n);
			break;
		case 6:
			InitStack();
			InitC();
			cout << "Vui long nhap dinh xuat phat: ";
			cin >> x;
			ndfs = 0;
			DFS(x);
			cout << "Thu tu dinh sau khi duyet DFS: "<< endl;
			output(dfs,n);
			break;
		case 7:
			InitQueue();
			InitC();
			nbfs = 0;
			cout << "Vui long nhap gia tri x can tim: ";
			cin >> x;
			Search_by_BFS(x,0);
			break;
		case 8:
			cout << "Goodbye.....!" << endl;
			break;
		default:
			break;
		}
	} while(choice != 8);
	system("pause");
	return 0;
}
