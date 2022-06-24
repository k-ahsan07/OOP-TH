#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class Cities{
    private:
    int peopleCount;
    float budget;
    float expenses;
    public:
    int get_PeopleCount(){return peopleCount;}
    float get_Budget(){return budget;}
    float get_Expenses(){return expenses;}
    void set_PeopleCount(int a){peopleCount=a;}
    void set_Budget(float b){budget=b;}
    void set_Expenses(float c){expenses=c;}
    Cities(int a=0, float b=0, float c=0){
        set_PeopleCount(a);
        set_Budget(b);
        set_Expenses(c);
    }
    ~Cities(){
       
    }
};
class Provinces: public Cities{
    private:
    int citiesCount;
    public:
    Cities citiesinProvinces[20];
    void set_CitiesCount(int d){citiesCount=d;}
    int get_CitiesCount(){return citiesCount;}
    Provinces(int a=0):Cities(){
        set_CitiesCount(a);
    }
    ~Provinces(){
        cout<<"Provinces destroyed";
    }
};
class Country: public Provinces{
    private:
    int provincesCount;
    public:
    void set_provincesCount(int a){provincesCount=a;}
    int get_ProvincesCount(){return provincesCount;}
    Provinces provincesinCountry[5];  
    Country(int a=0):Provinces(){
        provincesCount=a;
    }
    ~Country(){
        cout<<"Country destroyed";
    }

};
void totalExpenses(Cities c[], int ID){
    int temp, servicecost;
    servicecost=ID%100;
    cout<<"\n\n THE service cost is : "<<servicecost<<endl;
    for(int i=0;i<20;i++){
        cout<<"\nEnter the amount of people in City "<<i+1<<">>";
        cin>>temp;
        c[i].set_PeopleCount(temp);
        c[i].set_Expenses(c[i].get_PeopleCount()*servicecost);
        cout<<"\nThe expenses for city "<<i+1<<" are "<<c[i].get_Expenses();
    }
}
void totalExpenses2(Provinces p[], Cities c[]){
    int temp=0,j,temp2=4;
    for(int i=0;i<5;i++){
        for(j=(temp2-4);j<temp2;j++){
            temp+=c[j].get_Expenses();
        }
        p[i].set_Expenses(temp);
        temp2+=4;
        temp=0;
    }
    cout<<"\n\nprinting Provice expenses";
    int tot=0;
    for(int k=0;k<5;k++){
        cout<<"\nProvince "<<k+1<<":"<<p[k].get_Expenses();
        tot+=p[k].get_Expenses();
    }
    cout<<"\nTOTAL EXPENSE OF THE COUNTRY: "<<tot<<" RUPEES"<<endl;
}
void highestExpensesP(Provinces p[]){
    int maxpos;
    float max=0;
    for(int i=0;i<5;i++){
        if(p[i].get_Expenses()>max){
            max=p[i].get_Expenses();
            maxpos=i;
        }
    }
    cout<<"The Province with the highest expense is Province "<<maxpos+1<<" with "<<p[maxpos].get_Expenses()<<" Rupees "<<endl;
}
void finalFunction(Country Pak, Provinces p[]){
    cout<<"\nBudget:\tExpenses  Status:"<<endl;
    for(int i=0;i<5;i++){
        if((Pak.provincesinCountry[i].get_Budget()-p[i].get_Expenses())>0){
            cout<<Pak.provincesinCountry[i].get_Budget()<<"\t"<<p[i].get_Expenses()<<"\t"<<"Profit"<<endl;
        }
        else{cout<<Pak.provincesinCountry[i].get_Budget()<<"\t"<<p[i].get_Expenses()<<"\t"<<"Loss"<<endl; }
    }
}
main(){
	Country Pak;
	Pak.provincesinCountry[5];
	Pak.set_provincesCount(5);
	Pak.citiesinProvinces[20];
	Pak.set_CitiesCount(20);
	int ID;
	cout<<"Enter your roll no : ";
	cin>>ID;
	cout<<"\nYour budget is "<<ID<<" million"<<endl;
	unsigned long totbudget=ID*1000000;
	for(int i=0;i<5;i++){
		Pak.provincesinCountry[i].set_Budget(totbudget/4);
	}
	unsigned long citybudget;
    citybudget=Pak.provincesinCountry[0].get_Budget();
	for(int i=0;i<20;i++){
		Pak.citiesinProvinces[i].set_Budget(citybudget/20);
	}
    cout<<"Provinces Budget: \n";
    for (int i = 0; i < 5; i++)
    {
        cout<<"  Province "<<i+1<<": ";
        cout<<fixed<<setprecision(2)<<Pak.provincesinCountry[i].get_Budget()<<"\t";
    }
    cout<<"\nCities Budget: \n";
    for (int i = 0; i < 20; i++)
    {
        cout<<"  City: "<<i+1<<": ";
        cout<<fixed<<setprecision(2)<<"\n"<<Pak.citiesinProvinces[i].get_Budget()<<endl;
    }
    Cities c[20];
    totalExpenses(c,ID);
    Provinces p[5];
    totalExpenses2(p,c);
    highestExpensesP(p);
    finalFunction(Pak,p);
}
