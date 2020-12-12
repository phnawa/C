//
//最大子数组
//

#include<iostream>
//设置一个无限大值
#define inf 999999
using namespace std;

typedef struct mid_message{
    //最大子数组的左边界，右边界，最大子数组的总值
    int max_left;
    int max_right;
    int sum;
}midk;

//自己写的一个求3个数中最大值的函数
int Max(int a, int b, int c)
{
    int max = a;
    if(b > max)
        max = b;
    if(c > max)
        max = c;
    return max;
}

//求经过中点的最大子数组，返回结构体
mid_message find_mid(int A[], int low, int mid, int high)
{
    mid_message midx;
    
    //初始化中点左边的子数组值
    int left_sum = -inf;
    int sum = 0;
    
    //通过循环不断向左加，然后一直与left_sum比较
    for(int i = mid ; i >= low ; i--)
    {
        sum = sum + A[i];
        if (sum > left_sum)
        {
            left_sum = sum;
            midx.max_left = i;
        }
            
    }
    
    //与左边的操作相同
    int right_sum = -inf;
    sum = 0;
    for(int j = mid + 1 ; j <= high ; j++)
    {
        sum = sum + A[j];
        if (sum > right_sum)
        {
            right_sum = sum;
            midx.max_right = j;
        }
    }
       
    midx.sum = left_sum + right_sum;
    return midx;
}

mid_message find_max(int A[], int low, int high)
{
    mid_message midx;
    
    //递归出口
    if (high == low)
    {
        midx.max_left = low;
        midx.max_right = high;
        midx.sum = A[low];
        
        return midx;
    }
    else
    {
        int mid = (low+high) / 2;
        //左右中，左右用递归，中用 find_mid
        mid_message midxl = find_max(A, low, mid);
        mid_message midxr = find_max(A, mid+1, high);
        mid_message midxm = find_mid(A, low, mid, high);
        
        int max = Max(midxr.sum, midxl.sum, midxm.sum);
        
        //返回最大的子数组
        if(midxl.sum == max)
            return midxl;
        else if(midxr.sum == max)
            return midxr;
        else
            return midxm;
    }
}

int main()
{
    //测试数据（从别人那复制来的）
    cout<<"请输入随机数的个数：";
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
    {
        A[i]=rand()%2001-1000;
        cout<<A[i]<<" ";
    }
    cout<<endl;
    mid_message max = find_max(A, 0, n);
    cout<<max.max_left<<endl;
    cout<<max.max_right<<endl;
    cout<<max.sum<<endl;
}

