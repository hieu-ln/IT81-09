#include < iostream>
#include <stdio.h>
#include<fstream>
#include<sstream>
#include<iomanip>

using namespace std;

#define MAX 20
int a[MAX][MAX];
int n;
char vertex[MAX];

void InitGraph()
{
	n=0;
}

void inputGraphFromText()
{
	string line;
	ifstream myfile("matrantrongso1.txt");
	if(myfile.is_open())
	{
		myfile>>n;
		for(int i=0;i<n;i++)
			myfile>>vertex[i];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				myfile>>a[i][j];
		}
	}
}

void inputGraph()
{
	cout<<"nhap so dinh do thi n" << endl;
	cin >> n;
	cout<<"nhap ten dinh" << endl;
	for( int i=0;i<n;i++)
		cin>>vertex[i];
	for( int i=0;i<n;i++)
	{
		cout<<"nhap dong thu" <<i+1<< " : " ;
		for( int j=0;j<n;j++)
			cin>>a[i][j];
	}
}
int outputGraph()
{
	cout<< setw(6)<<left;
	for(int i=0;i<n;i++)
	{
		for( int j=0;j<n;j++)
			cout<<a[i][j]<<setw(6)<<left;
		cout<<endl;
	}
}
//khai bao tap E
int E1[MAX];
int E2[MAX];
int E3[MAX];
int wE[MAX];
int nE=0;//so phan tu tap
//khai bao tap T
int T1[MAX];
int T2[MAX];
int wT[MAX];
int nT=0;




int TonTai(int d, int D[], int nD)
{
	for( int i=0;i<nD;i++)
		if(D[i]==d)
			return 1;
	return 0;
}

void XoaViTriE(int i)
{

	for(int j=i;j<nE;j++)
	{
		E1[j]=E1[j+1];
		E2[j]=E2[j+1];
		wE[j]=wE[j+1];
	}

	nE--;
}

void XoaCanhE(int u, int v)
{
	for( int i=0;i<nE;i++)
		if(E1[i]==u&&E2[i]==v)
		{
			XoaViTriE(i);
			break;
		}
}

void prim(int s)//s la ding bat dau
{int u=s,min,i,d1,d2;
while(nT<n-1)
{
	for(int v=0;v<n;v++)
		if(a[u][v]!=0)
			if(TonTai(v,T2,nT)==0)
			{
				E1[nE]=u;
				E2[nE]=v;
				wE[nE]=a[u][v];
				nE++;
			}
		for(i=0;i<nE;i++)
			if(TonTai(E2[i],T2,nT)==0)
			{
				min=wE[i];
				d1=E1[i];
				d2=E2[i];
				break;
			}

			for(i=0;i<nE;i++)
				if(TonTai(E2[i],T2,nT)==0)
					if(min>wE[i])
					{
						min=wE[i];
						d1=E1[i];
						d2=E2[i];
					}

			T1[nT]=d1;
			T2[nT]=d2;
			wT[nT]=a[d1][d2];
			a[d1][d2]=0;
			a[d2][d1]=0;
			nT++;
			XoaCanhE(d1,d2);
			u=d2;
	}
}

void output(bool VertexName)
{
	int tong=0;
	for(int i=0;i<nT;i++)
	{
		if((VertexName))
			cout<<endl<<"("<<vertex[T1[i]]<<","<<vertex[T2[i]]<<")"<<wT[i];
		else
			cout<<endl<<"("<<T1[i]<<","<<T2[i]<<")"<<wT[i];
		tong+=wT[i];
	}
	cout<<"\n Tong = " << tong;
}

int main()
{
	int choice,x,i;
	cout<<"1.khai tao ma tran ke rong " << endl;
	cout<<"2.nhap ma tran ke tu file " << endl;
	cout<<"3.nhap  ma tran ke  " << endl;
	cout<<"4.xuat ma tran ke " << endl;
	cout<<"5.tim cay khung toi thieu" << endl;
	cout<<"6.thoay " << endl;

	do{
		cout<<"vui long chon so thuc hien";
		cin>>choice;
		switch(choice)
		{

		case 1:
			InitGraph();
			cout<<"khooi tao thanh cong " << endl;
			break;

		case 2:
			inputGraphFromText();
			cout<<"ban vua nhap ma tran ke thanh cong"<< endl;
			outputGraph();
			break;
		case 3:
			inputGraph();
			break;

		case 4:
			outputGraph();
			break;
		case 5:

			cout<<"nhap dinh xuat phat";
			cin>>x;
			prim(x);
			cout<<"cay khung toi thieu";
				output(true);
			break;
		case 6:

			cout<<"goodbye";
		}
	}while(choice!=6);
	return 0;
}