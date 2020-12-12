#include<iostream>
#include<iomanip>
#define inf 1000 //�����
#define n 11 //������
using namespace std;
int C[n][n];//���۾���
int S[n];//��ռ�
int x[n];//��
int bestX[n],bestC=inf;//���·������С���� 
//��S��ʼ��
void init()
{
	for(int i=0;i<n;i++)
		S[i]=i;
}
//����C 
void Read()
{
	int tmp;
	FILE *fp;//�����ļ�ָ��
	fp=fopen("d:/cost.txt","rt");//�Զ��뷽ʽ��d:\cost.txt 
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			fscanf(fp,"%d",&tmp);
			C[i][j]=tmp;
		}
	}
	fclose(fp);
} 
//��ʾ���۾���
void Display()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j)
				cout<<setw(4)<<"inf";
			else
				cout<<setw(4)<<C[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
}
//����֦������
void DFS(int k,int cc,int vis[n])
{
	if(k==n)//���k����Ҷ�ӽڵ��
	{
		if(cc+C[x[n-1]][x[0]]<=bestC)
		{
			cc+=C[x[n-1]][x[0]];
			//�������·������С����
			for(int i=0;i<n;i++)
				bestX[i]=x[i];
			bestC=cc;
			return;
		}
	}
	for(int i=0;i<n;i++)//���ظ��ر�����ռ�
	{	if(vis[i]==0)//���S[i]δ������
		{
			x[k]=S[i];
			vis[i]=1;//��S[i]������
			//�����ǰ����+��(x[k-1],x[k])����С����Ѵ���
			if(cc+C[x[k-1]][x[k]]<bestC)
			{	cc+=C[x[k-1]][x[k]];//���µ�ǰ����
				DFS(k+1,cc,vis);//����
				vis[i]=0;//�ָ�S[i]δ������
				cc-=C[x[k-1]][x[k]];//�ָ���ǰ����
			}
			else//�����ǰ����+��(x[k-1],x[k])���۴��ڻ������Ѵ���
			{
				vis[i]=0;//�ָ�S[i]δ������,����֦
			}
		}
	}
}
//������·������С����
void Output(int i)
{	cout<<"���·�� ";
	for(int j=0;j<n;j++)
		cout<<bestX[j]<<" ";
	cout<<bestX[0]<<endl;
	cout<<"��С���� "<<bestC<<endl;
}
//������
int main()
{
	Read();//������۾���
	Display();//��ʾ���۾���
	init();//��S��ʼ��
	int cc,vis[n]={0};
	x[0]=0;vis[0]=1;cc=0;//����0����,�ó���0������,��ǰ����Ϊ0 
	DFS(1,cc,vis);//���� 
	Output(0);//����ӳ���0���������·������С���� 
	return 0;
}
