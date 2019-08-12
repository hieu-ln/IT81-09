#include< iostream >
#include<stdio.h>
#include<fstream>
using namespace std;

#define MAX 20
int a[MAX][MAX];
int n;
char vertex[MAX];

//dslk su dung cho stack va queue

struct Node
{
	int info;
	Node *link;
};

Node *sp;
Node *front,*rear;
//stack
void InitStack()
{
	sp=NULL;
}

int isEmptyS()
{
	if(sp !=NULL)
		return 1;
	return 0;
}

void PushS(int x)
{
	Node *p=new Node;
	p->info=x;
	p->link=sp;
	sp=p;
}

int PopS( int &x)
{
	if(sp != NULL)
	{
		Node *p=sp;
		x=p->info;
		sp=p->link;
		delete p;
		return 1;
	}
	return 0;
}

//end stack
//queue

void InitQ()
{

	front = NULL;
	rear = NULL;
}

int isEmpty()
{
	if( front == NULL )
		return 1;
	return 0;
}

void PushQ( int x)
{
	Node *p = new Node ;
	p->link = NULL;
	p->info=x;
	if(rear==NULL)front =p;
	else
		rear->link=p;
	rear=p;
}

int PopQ(int &x)
{
	if(front !=NULL)
	{
		Node*p = front;
		front=p->link;
		x=p->info;
		if(front==NULL)
		{
			rear=NULL;
		}

		delete p;
		return 1;
	}
	return 0;
}
///end queue

void InitGraph()
{
	n=0;

}

void inputGraphFromText()
{
	string line;
	ifstream myfile("matranke1.txt");
	if(myfile.is_open())
	{
		myfile >> n;
		for( int i=0 ; i < n ; i++)
			myfile>>vertex[i];
		for(int i=0 ; i <n ;i++ )
		{
			for(int j=0 ; j < n ; j++)
				myfile >>a[i][j] ;
		}
	}
}

// nhap ma tran ke
void inputGraph()
{
	cout<<"nhap so dinh do thi n: ";
	cin >> n;
	for( int i=0 ; i < n ;i++)
	{
		cout<<"nhap ten dinh ";
		cin >> vertex[i];
		cout<<"nhap vao dong thu" << i + 1 << "   " ;
		for(int j=0; j < n ; j++ )
			cin>>a[i][j];
	}
}
//xuat ma tran ke cua do thi
void outputGraph()
{
	for( int i=0 ; i <n ; i++ )
	{
		for( int j=0 ; j < n;j++)
			cout<<a[i][j] <<"  " ;
		cout<<endl;
	}
}
//xuat ma tran ke

void output(int a[] , int n)
{
	for ( int i=0 ; i < n ;i++ )
		cout<<vertex[a[i]] << "  "  ;
}

//duyet do thi tao BFS

int c[100], bfs[100];
int nbfs = 0;

void Initc()
{
	for(int i=0 ; i < n ; i++)
		c[i]=1;
}

void BFS( int v) //v la dinh bat dau
{
	int w,p;
	PushQ(v);
	c[v]=0;
	while(front !=NULL)
	{
		PopQ(p);
		bfs[nbfs]=p;
		nbfs++;
		for(w=0 ; w<n;w++)
			if(c[w] &&a[p][w]==1)
			{
				PushQ(w);
				c[w] = 0;
			}
	}
}
//duey do thi theo chieu sau DFS

int dfs[100];
int ndfs=0;
void DFS(int s)
{
	PushS(s);
	dfs[ndfs]=s;
	ndfs++;
	c[s]=0;
	int v=-1,u=s;
	while(isEmptyS()==0)
	{
		if(v==n)
			PopS(u);
		for(v=0;v<n;v++)
			if(a[u][v] != 0 && c[v] == 1)
			{
				PushS(u);
				PushS(v);
				dfs[ndfs]=v;
				ndfs++;
				c[v]=0;
				u=v;
				break;
			}
	}
}



void Search_by_BFS( int x, int v)//v la dinh bat dau
{

	int w,p;
	PushQ(v);
	c[v]=0;
	while(front !=NULL)
	{
		PopQ(p);
		if(x==p)
		{
			cout<<"tim thay x" << x << endl;
			return ;
		}
		for(w=0 ; w< n ;w++ )
			if(c[w] && a[p][w] == 1)
			{
				PushQ(w);
				c[w]=0;
			}
	}
}
int main()
{

	int a[MAX];
	int b[MAX];
	int choice , sp,x,i;
	system("cls");
	cout<<"(+-+)(+-+)(+-+)baitap(+-+)(+-+)(+-+) " << endl;
	cout<<"1.khoi tao ma tran ke rong " << endl;
	cout<<"2.nhap ma tran ke tu file text " << endl;
	cout<<"3.nhap ma tran ke " << endl;
	cout<<"4 xuat ma tran ke "<<endl;
	cout<<"5.duyet do thi theo chieu rong BFS " << endl;
	cout<<"6.duyet do thi theo chieu sau DFS " << endl;
	cout<<"7.tim dinh co gia tri  x theo BFS" << endl;
	cout<<"8.Thoat " << endl;
	do{
		cout<<"nhap so can thuc hien " ;
		cin >> choice;
		switch(choice)
		{
		case 1:
			InitGraph();
				cout<<" ban vua khoi tao ma tran ke thanh cong : " << endl;
				break;
		case 2:
			inputGraphFromText();
			cout<<" ban vua nhap ma tran ke tu file : " << endl;
			outputGraph();
			break;
		case 3:
			inputGraph();
			break;
		case 4:
			outputGraph();
			break;
		case 5:
			InitQ();
			Initc();
			cout<<"vui long nhap dinh xuat phat: " ;
			cin >> x;
			nbfs=0;
			BFS(x);
			cout<<" thu tu dinh sau khi duyet BFS " << endl;
			output(bfs,n);
			break;
		case 6:
			InitStack();
			Initc();
			cout<<"vui long nhap dinh xuat phat: " ;
			cin >> x;
			ndfs=0;
			DFS(x);
			cout<<" thu tu dinh sau khi duyet DFS"<<endl;
			output(dfs,n);
			break;
		case 7:
			cout<<"vui long nhap gia tri x can tim " ;
			cin >> x;
			Search_by_BFS(x,0);
			break;
		case 8:
			cout<<"good bye" << endl;
			break;
		default:
			break;
		}
		}
		while(choice !=8 );
		system("pause");
		return 0;
}





