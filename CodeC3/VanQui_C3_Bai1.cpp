#include < iostream >
#include <stdio.h>
#include<ctime>
using namespace std;

#define MAX=5000
//1.1
int a[MAX];
int n;

//1.2 nhap danh sach
void init(int a[],int &n)
{
	cout<<"nhap so luong phan tu cua danh sach";
	cin>>n;
	for(int i =0;i<n;i++)
	{
		a[i]=rand()%10000+1;
	}
	cout<<"Danh sach da nhap ngau nhien nhu sau " << endl;
		for(int i=0 ; i <n;i++)
		{
			cout<<a[i] <<" " ;
		}
	cout<< endl;
}

//nhap danh sach
void input(int a[] , int &n )
{
	cout<<"nhap vao so luong phan tu cua danh sach " << endl;
	for( int i=0;i<n;i++)
	{
		cout<<"a[" <<i<<"]" ;
		cin >> a[i];
	}
}
//xuat danh sach
void output(int a[] , int&n )
{
	for( int i=0 ; i < n ; i++)
	{
		cout<<a[i]<<"  " ;
	}
	cout<< endl;
}

void copyarray(int a[] , int b[] , int n )
{
	for ( int i = 0 ; i < n ; i ++)
	{
		b[i]=a[i];
	}
}
//insertion sort
void insertionsort(int a[] ,int n)
{
	int i,key,j;
	for(int i=1;i<n;i++)
	{
		key=a[i];
		j=i-1;
	
	while(j>=0 &&a[i]>key)
	{
		a[j+1]=a[j];
		j=j-1;
	}
	a[j+1]=key;
	}
}
//hoa doi cho 2 so nguyen
void swap(int &a , int &b )
{
	int t=a;
	a=b;
	b=t;
}
//selection sort
void selectionsort(int a[],int n)
{
	int i,j ,min_idx;
	for( int i=0;i<n-1;i++)
	{
		min_idx=i;
		for(j=i+1;j<n;j++)
			if(a[i] < a[min_idx])
				min_idx=j;
		swap(a[min_idx],a[i]);
	}
}
//1.6
void interchangesort(int a[] , int n)
{
	for(int i=0 ; i < n - 1;i++)
		for(int j=i+1;j<n;j++)
			if(a[i]>a[j])
				swap(a[i],a[j]);
}
//bubble sort
void bubblesort(int arr[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
	bool haveswap=false;
	for(i=0;i<n-i-1;i++)
	{
		if(arr[j] >arr[j+1])
		{
			swap(arr[j],arr[j+1]);
			haveswap=true;
		}
	}
	if(haveswap==false)
	{
		break;
	}
	}
}
//partition
void partition(int a[],int low,int high)
{
	int pivot=a[high];
	int left=low;
	int right=high - 1;
	while(true)
	{
		while(left<right&&a[left]<pivot) left++;
		while(right>=left&&a[left]>pivot) right--;
		if(left >=right)
			break;
		swap(a[left],a[right]);
		left++;
		right--;
	}
	swap(a[left],a[high]);
	return left;
}
//thuc hien giai thuat quick sort
void quicksort(int a[] , int low, int high)
{
	if(low<high)
	{
		int pi= partition(a,low,high);
		quicksort(a,low,high);
		quicksort(a,pi+1,high);
	}
}

void heapify(int a[],int n,int i)
{
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n &&a[l]>a[largest])
		largest=r;
	if(largest!=i)
	{
		swap(a[i],a[largest]);
		heapify(a,n,largest);
	}
}

void heapsort(int a[], int n)
{
	for(int i=n/2-1;i>=0;i--)
		heapify(a,n,i);
	for(int i=n-1;i>=0;i--)
	{
		swap(a[0],a[i]);
		heapify(a,i,0);
	}
}

//1.10
void searchsequence(int a[],int n,int x)
{
	int i=0;
	while(i<n && a[i] != x)
	{
		i++;
	}
	if(i==n)
	{
		cout<<"khong tim thay" << endl;
	}
	else
		cout<<"tim thay tai vi tri " << i;
}
//1.11
int searchbinary(int a[], int l, int r,int x)
{
	if(r>l)
	{
		int mid=l+(r-l)/2;
		if(a[mid]==x)
			return mid;
		if(a[mid] >x)
			return searchbinary(a,mid+1,x);
		return searchbinary(a,mid+1,r,x);
	}
	return -1;
}

int main()
{
	int b[max];
	clock_t start;
	int choice ,x,i;
	system("cls");
		cout<<"-----------bai tap 1,chương 3----------------" << endl;
		cout<<"0.khoi tao danh sach ngau nhien " << endl;
		cout<<"1.nhap danh sach " << endl;
		cout<<"2.xuat danh sach" << endl;
		cout<<"3.xuat thu tu danh sach bang selection sort" << endl;
		cout<<"4..xuat thu tu danh sach bang insertion sort " << endl;
		cout<<"5..xuat thu tu danh sach bang bubble sort "<< endl;
		cout<<"6..xuat thu tu danh sach bang interchage sort "<< endl;
		cout<<"7..xuat thu tu danh sach bang quick sort "<< endl;
		cout<<"8..xuat thu tu danh sach bang heap sort "<< endl;
		cout<<"9.tim kiem phan tu x bang tim kiem tuan tu "<< endl;
		cout<<"10.tim kiem phan tu x bang tim kiem nhi phan  "<< endl;
		cout<<"11.thoat" << endl;
		do{
			cout<<"vui long chon so thuc hien" << endl;
			cin >> choice;
			switch(choice)
			{
				case 0:
					init(a,n);
					break;
				case 1:
					input(a,n);
					break;
				case 2:
					cout<<"danh sach la: " <<endl;
					output(a,n);
					break;
				case 3:
					copyarray(a,b,n);
					start=clock();
					selectionsort(b,n);
					duration=(clock()-start)/(double);
					if(n<100)
					{
						cout<<"danh sach sau khi xep thu tu voi selecton sort " << endl;
						output(a,n);
					}
					if(duration > 0 )
						cout<<"thoi gian selectionsort" <<duration *1000000<<"microseconds" << endl;
					break;
				case 4:
					copyarray(a,b,n);
					start=clock();
					insertionsort(b,n);
					duration=(clock()-start)/(double);
					if(n<100)
					{
						cout<<"danh sach sau khi xep thu tu voi selecton sort " << endl;
						output(a,n);
					}
					if(duration > 0 )
						cout<<"thoi gian selectionsort" <<duration *1000000<<"microseconds" << endl;
					break;
				case 5:
					copyarray(a,b,n);
					start=clock();
					bubblesort(b,n);
					duration=(clock()-start)/(double);
					if(n<100)
					{
						cout<<"danh sach sau khi xep thu tu voi selecton sort " << endl;
						output(a,n);
					}
					if(duration > 0 )
						cout<<"thoi gian selectionsort" <<duration *1000000<<"microseconds" << endl;
					break;
				case 6:
					copyarray(a,b,n);
					start=clock();
					interchangesort(b,n);
					duration=(clock()-start)/(double);
					if(n<100)
					{
						cout<<"danh sach sau khi xep thu tu voi selecton sort " << endl;
						output(a,n);
					}
					if(duration > 0 )
						cout<<"thoi gian selectionsort" <<duration *1000000<<"microseconds" << endl;
					break;
				case 7:
					copyarray(a,b,n);
					start=clock();
					quicksort(b,n);
					duration=(clock()-start)/(double);
					if(n<100)
					{
						cout<<"danh sach sau khi xep thu tu voi selecton sort " << endl;
						output(a,n);
					}
					if(duration > 0 )
						cout<<"thoi gian selectionsort" <<duration *1000000<<"microseconds" << endl;
					break;
					copyarray(a,b,n);
					start=clock();
					quicksort(b,n);
					duration=(clock()-start)/(double);
					if(n<100)
					{
						cout<<"danh sach sau khi xep thu tu voi selecton sort " << endl;
						output(a,n);
					}
					if(duration > 0 )
						cout<<"thoi gian selectionsort" <<duration *1000000<<"microseconds" << endl;
					break;
				case 9:
					cout<<"vui long nhap gia tri x" << endl;
					cin>>x;
					start=clock();
					searchsequence(a,x,n);
					duration=(clock()-start)/(double);
					break;
				case 10:
					cout<<"vui long nhap gia tri x" << endl;
					cin >>X;
					start=clock();
					i=searchbinary(b,0,n,x);
					duration=(clock()-start)/(double);
					break;
				case 11:
					cout<<"goodbye" <<endl;
					break;
				default:
					break;
					}
			}while(choice!=11);
					return 0;
	}









		
		








