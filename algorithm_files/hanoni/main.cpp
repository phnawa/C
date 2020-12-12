//
//  main.cpp
//  hanoni
//
//  Created by 彭浩南 on 2020/12/3.
//
#include<iostream>
using namespace std;
int cnt=0;
void move(char a,int n,char c)
{
    cnt++;
    cout<<a<<"->"<<c<<endl;
}

void hanoi(int n,char a,char b,char c)
{
    
    if(n==1)
    move(a,1,c);
    else
    {
        hanoi(n-1,a,c,b);
        move(a,n,c);
        hanoi(n-1,b,a,c);
    }
}


int main(void)
{
    int n;
    cin>>n;
    hanoi(n,'a','b','c');
    cout<<cnt<<endl;
    return 0;
}
