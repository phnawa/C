#include<iostream>
#include<iomanip>
#define inf 1000 //无穷大
#define n 11 //城市数
using namespace std;
int C[n][n];//代价矩阵
int S[n];//解空间
int x[n];//解
int bestX[n],bestC=inf;//最佳路径与最小代价 
//对S初始化
void init()
{
	for(int i=0;i<n;i++)
		S[i]=i;
}
//读入C 
void Read()
{
	int tmp;
	FILE *fp;//定义文件指针
	fp=fopen("d:/cost.txt","rt");//以读入方式打开d:\cost.txt 
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
//显示代价矩阵
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
//带剪枝的深搜
void DFS(int k,int cc,int vis[n])
{
	if(k==n)//如果k到达叶子节点层
	{
		if(cc+C[x[n-1]][x[0]]<=bestC)
		{
			cc+=C[x[n-1]][x[0]];
			//更新最佳路径与最小代价
			for(int i=0;i<n;i++)
				bestX[i]=x[i];
			bestC=cc;
			return;
		}
	}
	for(int i=0;i<n;i++)//不重复地遍历解空间
	{	if(vis[i]==0)//如果S[i]未被访问
		{
			x[k]=S[i];
			vis[i]=1;//置S[i]被访问
			//如果当前代价+边(x[k-1],x[k])代价小于最佳代价
			if(cc+C[x[k-1]][x[k]]<bestC)
			{	cc+=C[x[k-1]][x[k]];//更新当前代价
				DFS(k+1,cc,vis);//深搜
				vis[i]=0;//恢复S[i]未被访问
				cc-=C[x[k-1]][x[k]];//恢复当前代价
			}
			else//如果当前代价+边(x[k-1],x[k])代价大于或等于最佳代价
			{
				vis[i]=0;//恢复S[i]未被访问,即剪枝
			}
		}
	}
}
//输出最佳路径与最小代价
void Output(int i)
{	cout<<"最佳路径 ";
	for(int j=0;j<n;j++)
		cout<<bestX[j]<<" ";
	cout<<bestX[0]<<endl;
	cout<<"最小代价 "<<bestC<<endl;
}
//主函数
int main()
{
	Read();//读入代价矩阵
	Display();//显示代价矩阵
	init();//对S初始化
	int cc,vis[n]={0};
	x[0]=0;vis[0]=1;cc=0;//城市0出发,置城市0被访问,当前代价为0 
	DFS(1,cc,vis);//深搜 
	Output(0);//输出从城市0出发的最佳路径与最小代价 
	return 0;
}
