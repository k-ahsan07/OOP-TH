#include <iostream>
using namespace std;
class laptop{
private:
   int m_num;
   string nameOfProduct;
   double s_price;
   double p_price;
public:
   laptop() {
   m_num=0;
   nameOfProduct="abc";
   s_price=0;
   p_price=0;
}
//setter
void setl1(int a ) {
   m_num=a;
}
void setl2(string b) {
   nameOfProduct=b;
}
void setl3(double c) {
   s_price=c;
}
void setl4(double d) {
   p_price=d;
}
//getter
int getl1() {
   return m_num;
}
string getl2() {
   return nameOfProduct;
}
double getl3() {
   return s_price;
}
double getl4() {
   return p_price;
}
};
class mobile{
private:
   int m_num;
   string nameOfProduct;
   double s_price;
   int p_price;
public:
mobile() {
   m_num=0;
   nameOfProduct="abc";
   s_price=0;
   p_price=0;
}
void setm1(int a ) {
    m_num=a;
}
int getm1() {
    return m_num;}
void setm2(string b) {
    nameOfProduct=b;
}
string getm2() {
    return nameOfProduct;
}
void setm3(double c) {
    s_price=c;
}
double getm3() {
    return s_price;
}
void setm4(double d) {
    p_price=d;
}
double getm4() {
    return p_price;
}
};
int main () {
	laptop l1;
    int rollnum,l2,f2,i,j;
    string n,d,name;
    int a,b,c,m,h;
    double p,e;
    cout<<"Enter your name: ";
    cin>>name;
    cout<<"Enter your roll number: ";
    cin>>rollnum;
    l2=rollnum%100;
    f2=rollnum/100;
    double sum=0.0,sum1=0.0,f;
    laptop obj1[l2];
    mobile obj2[f2];
    cout<<"Taking Information of laptop"<<endl;
    for (i=0;i<l2;i++) {
    	cout<<"Enter model number of laptop ";
    	cin>>m;
    	obj1[i].setl1(m);
        cout<<"Enter name of laptop ";
		cin>>n;
		obj1[i].setl2(n);	}
	cout<<"Enter purchase price of laptop "<<endl;
    for(j=0;j<l2;j++) {
    	cout<<"Model number of laptop ";
		cout<<obj1[j].getl1()<<endl;
    	cout<<"Name of laptop ";
		cout<<obj1[j].getl2();
    	cout<<"Enter purchase price ";
    	cin>>p;
    	obj1[j].setl4(p);}
	cout<<"Taking information of mobiles"<<endl;
	for (a=0;a<f2;a++) {
    	cout<<"Enter model number of mobile ";
    	cin>>c;
    	obj2[i].setm1(c);
        cout<<"Enter name of mobile ";
		cin>>d;
		obj2[a].setm2(d);	}
	cout<<"Enter purchase price of mobile "<<endl;
    for(b=0;b<f2;b++) {
    	cout<<"Model number of mobile ";
		cout<<obj2[b].getm1()<<endl;
    	cout<<"Name of mobile ";
		cout<<obj2[b].getm2();
    	cout<<"Enter purchase price ";
    	cin>>e;
    	obj2[b].setm4(e); }
	 for(h=0;h<l2;h++) {
	 	 f=obj1[h].getl4()*(l2/100.0);
	 	 obj1[h].setl3(f+obj1[h].getl4());
	 	 sum+=f;	 }
	 for(h=0;h<f2;h++) {
	 	 f=obj2[h].getm4()*(l2/100.0);
	 	 obj2[h].setm3(f+obj2[h].getm4());
	 	 sum1+=f;
	 }
	 cout<<"Name: "<<name<<endl;
     cout<< "Profit: "<<sum+sum1<<endl;
     cout<<"Number of objects in mobile: "<<l2<<endl;
	 cout<<"Number of objects in laptop"<<f2<<endl;      
}
