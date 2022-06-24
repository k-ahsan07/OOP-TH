#include<iostream>
using namespace std;
class newdate{
	int date;
	int month;
	int year;
	public:
		newdate(){
			date=0;
			month=0;
			year=0;
		}
		newdate(int a, int b, int c){
			date=a;
			month=b;
			year=c;
		}
		int getdate(){ 
			return date;
				}
		int getmonth(){ 
			return month; 
			}
		int getyear(){ 
			return year;
			}
		void setdate(int a){ 
			date=a;
			}
		void setmonth(int a){ 
			month=a;
			}
		void setyear(int a){
			year=a;
			}
		void display(){
			cout<<"DATE IS "<<date<<"/"<<month<<"/"<<year<<endl;
		}
		int operator == (newdate n2){
			if(year<n2.year)
				return 1;
			else if(year>n2.year)
				return -1;
			else {
				if(month<n2.month)
				return 1;
			else if(month>n2.month)
				return -1;
			else {
				if(date<n2.date)
				return 1;
			else if(date>n2.date)
				return -1;
			else 
				return 0;
				}			
			}
		}
	
};
class employee;
class newdatewords : public newdate{
	string datew;
	string monthw;
	string yearw;
	public:
		newdatewords() : newdate(){
			datew='0';
			monthw='0';
			yearw='0';
		}
		newdatewords(int a, int b, int c) : newdate(a,b,c){
			datew='0';
			monthw='0';
			yearw='0';
		}
		newdatewords(string a, string b, string c) : newdate(){
			datew=a;
			monthw=b;
			yearw=c;
		}
		string getdatew(){
			 return datew;
			 	}
		string getmonthw(){
			 return monthw; 
			 }
		string getyearw(){
			 return yearw;	
			 }
		void setdatew(string a){ 
			datew=a;
			}
		void setmonthw(string a){
			 monthw=a;
			}
		void setyearw(string a){ 
			yearw=a; 
			}
		void display(){
			cout<<"DATE : "<<datew<<"/"<<monthw<<"/"<<yearw<<endl;
		}
		
		friend class employee;
};

string numtowords(int n);

class employee{
	newdate joiningdate;
	newdatewords joiningdatew;
	string name;
	int id;
	int salary;
	static unsigned int count;
	public:
		employee() : name("KHUZAIMA AHSAN") , id(3328) , salary(210000) , joiningdate(20,6,2021){ count++;}
		employee(newdate m, string d, int i, int s) : name(d) , id(i) , salary(s) , joiningdate(m) { count++; }
		void setjoiningdate(newdate n){
			joiningdate.setdate(n.getdate());
			joiningdate.setmonth(n.getmonth());
			joiningdate.setyear(n.getyear());
		}
		void setjoiningdatew(newdatewords n){
			joiningdatew.setdatew(n.getdatew());
			joiningdatew.setmonthw(n.getmonthw());
			joiningdatew.setyearw(n.getyearw());
		}
		void setname(string a){
			name=a;
		}
		void setid(int a){
			id=a;
		}
		void setsalary(int a){
			salary=a;
		}
		string getname(){
			return name;
		}
		int getid(){
			return id;
		}
		int getsalary(){
			return salary;
		}
		newdate getjoiningdate(){
			return joiningdate;
		}
		newdatewords getjoiningdatew(){
			return joiningdatew;
		}
		void displayjoining(){
			joiningdatew.display();
		}
		void sync(){
			joiningdatew.setdatew(numtowords(joiningdate.getdate()));
			joiningdatew.setmonthw(numtowords(joiningdate.getmonth()));
			int fm=joiningdate.getyear();
			if(fm>=100){			
				string str=numtowords(fm/100);
				string st=numtowords(fm%100);
				str+="-"+st;
				joiningdatew.setyearw(str);
			}
			else 
				joiningdatew.setyearw(numtowords(joiningdate.getyear()));		
			
		}
		
		void operator ++ (){
			joiningdate.setdate(joiningdate.getdate()+1);
			sync();
		}
		
		void operator -- (){
			joiningdate.setdate(joiningdate.getdate()-1);
			sync();
		}
		
		void operator ++ (int a){
			joiningdate.setdate(joiningdate.getdate()+1);
			sync();
		}
		
		void operator -- (int a){
			joiningdate.setdate(joiningdate.getdate()-1);
			sync();
		}
		
		bool operator > (employee e){
			int a = joiningdate == e.joiningdate; 
			if((salary > e.salary) && a==1 )
				return 1;
			else 
				return 0;  
		}
		
		bool operator < (employee e){
			int a = joiningdate == e.joiningdate; 
			if((salary < e.salary) && a==-1 )
				return 1;
			else 
				return 0;  
		}
};
string s[]= {"","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","forteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
string s10[]= {"","","twenty ", "thirty ", "forty ","fifty ", "sixty ", "seventy ", "eighty ","ninety " };
string numtowords(int n){
	string fish;
	if(n>19)
		fish += s10[n/10] + s[n%10];
	else 
		fish+= s[n];
	return fish;
}
unsigned int employee::count=0;
int main(){
	employee e1;
	int a,b,c;
	cout<<"Enter DATE : MONTH : YEAR"<<endl;
	cin>>a>>b>>c;
	newdate n(a,b,c);
	string d;
	cout<<"Enter name, ID and salary"<<endl;
	cin>>d>>a>>b;
	employee e2(n,d,a,b);
	bool z = e2 > e1;
	if(z==1)
		cout<<"\nEMPLOYEE2 > EMPLOYEE1 : TRUE "<<endl;
	else 
		cout<<"\nEMPLOYEE2 > EMPLOYEE1 : FALSE "<<endl;
	z = e2 < e1;
	if(z==1)
		cout<<"\nEMPLOYEE2 < EMPLOYEE1 : TRUE "<<endl;
	else 
		cout<<"\nEMPLOYEE2 < EMPLOYEE1 : FALSE "<<endl;
		
	cout<<"\nFOR EMPLOYEE 1 : "<<endl;
	cout<<"NAME : "<<e1.getname()<<endl;
	cout<<"ID : "<<e1.getid()<<endl;
	cout<<"SALARY : "<<e1.getsalary()<<endl;
	newdate p=e1.getjoiningdate();
	p.display();
	e1.sync();
	e1.displayjoining();
	cout<<"\nPOST-FIX INCREMENT OF DATE\n"<<endl;
	e1++;
	e1.displayjoining();
	
	cout<<"\nFOR EMPLOYEE 2 : "<<endl;
	cout<<"NAME : "<<e2.getname()<<endl;
	cout<<"ID : " <<e2.getid()<<endl;
	cout<<"SALARY : "<<e2.getsalary()<<endl;
	newdate q=e1.getjoiningdate();
	q.display();
	e2.sync();
	e2.displayjoining();
	cout<<"\nPOST-FIX DICREMENT OF DATE\n"<<endl;
	e2--;
	e2.displayjoining();
}
