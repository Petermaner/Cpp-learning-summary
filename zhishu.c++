#include<iostream>
using namespace std;
void zhishu(int n);
int main()
{
	int n;
	cout<<"请输入一个整数。"<<endl;
	cin>>n;
	zhishu(n);
	return 0;
 }
void zhishu(int n){
	int i;
	for(i=2;i<n;i++)
	{
		if(n%i==0)
			break;
	}
	if(n==1||i==n)
		cout<<"这个数是质数。"<<endl;
	if(i<n)
		cout<<"这个数不是质数。"<<endl;	
}
