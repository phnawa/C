#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int sum=0;
int partition(int a[],int low,int high)
{
	int pos=a[low];
	while(low<high) 
	{
		while(low<high&&a[high]>=pos)
		{
			--high;
			cnt++;
		}
		a[low]=a[high];
		while(low<high&&a[low]<=pos) 
		{
			++low;
			cnt++;
		}
		a[high]=a[low];
	}
	a[low]=pos;
	return low;
}

void QuickSort(int a[],int low,int high)
{
	if(low<high)
	{
		int set_pos=partition(a,low,high);
		QuickSort(a,low,set_pos-1);
		QuickSort(a,set_pos+1,high);
	}
} 
void Merge(int arr[],int L,int M,int R)
{
    int Left_Size=M-L;
    int Right_Size=R-M+1;
	int Left[Left_Size];
	int Right[Right_Size];
	for(int s=L;s<M;s++)
	{
		Left[s-L]=arr[s];
	}
	for(int t=M;t<=R;t++)
	{
		Right[t-M]=arr[t];
	}
	int i=0;
	int j=0;
	int k=L;//注意此时的k=L并不等于0 
	while(i<Left_Size&&j<Right_Size)
	{
		if(Left[i]<Right[j])
		{
			arr[k++]=Left[i++];
			cnt++;
		}
		else
		{
			arr[k++]=Right[j++];
			cnt++;
		}
	}
	while(i<Left_Size)
	{
		arr[k++]=Left[i++];
	}
	while(j<Right_Size)
	{
		arr[k++]=Right[j++];
	}
}
void MergeSort(int arr[],int left,int right)
{
	if(left==right)  return;
	else
	{
		int M=(left+right)/2;
		MergeSort(arr,left,M);
		MergeSort(arr,M+1,right);
		Merge(arr,left,M+1,right);
	}
}
void Display(int a[],int n)
{
	cout<<"排序后的序列为：";
	for(int i=0;i<n;i++)
	{
		if(sum==10)
		{
			cout<<endl<<"                ";
			sum=0;
		}
		sum++;
		cout<<setw(8)<<a[i];
	}
	cout<<endl<<endl;
}
int main()
{
	int n;
	cout<<"请输入随机数的个数：";
	cin>>n;
	int a[n],b[n],c[n];
	cout<<"随机数为: ";
	for(int i=0;i<n;i++)
	{
		if(sum==10)
		{   
			cout<<endl<<"          ";
			sum=0;
		}
		sum++;
		a[i]=rand();
		b[i]=a[i];
		c[i]=a[i];
		cout<<setw(8)<<a[i];
	}
	cout<<endl<<endl;
	sum=0;
	QuickSort(b,0,n-1);
	cout<<"快速排序比较了 "<<cnt<<" 次" <<endl;
	Display(b,n);
	cnt=0;
	sum=0;
	MergeSort(c,0,n-1);
	cout<<"归并排序比较了 "<<cnt<<" 次" <<endl;
	Display(c,n);
	return 0;
	
} 
