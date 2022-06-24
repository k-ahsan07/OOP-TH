#include<iostream>

using namespace std;
template<typename M>
M Max(M *a)
	{
	M max=a[0];
	for(int i=0;i<4;i++)
	{
		if(a[i]>max)
			max=a[i];
	} 
	return max;
	}
int main()
{
	int a[]={4,5,2,9};
	char b[]={'a','v','c','p'};
	float c[]={4.3,5.5,2.0,2.9};
	cout<<"THE MAXIMUM VALUES ARE\t"<<endl;
	cout<<"MAXIMUM VALUE IN INT   :\t";
	cout<<Max<int>(a)<<endl;;
	cout<<"MAXIMUM VALUE IN CHAR  :\t";
	cout<<Max<char>(b)<<endl;
	cout<<"MAXIMUM VALUE IN DOUBLE:\t";
	cout<<Max<float>(c)<<endl;
}
