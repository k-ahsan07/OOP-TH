#include<iostream>
#include<fstream>

using namespace std;
class Competition
{
public:
    int a;
    float b;
    double c;
    char d;
    string z;
    string y;
    string x;
    string w;
    string v;
    Competition(int a, float b, double c, char d, string z, string y, string x, string w, string v)
	{
        this->a=a;
        this->z=z;
        this->b=b;
        this->c=c;
        this->d=d;
        this->y=y;
        this->x=x;
        this->w=w;
        this->v=v;
    }
    Competition(){a=0;b=0;c=0;d='\0';z='\0';y='\0';x='\0';w='\0';v='\0';}
};
class ProgCompetition : public Competition{
public:
     ProgCompetition(int e, float f, double g, char h, int a, float b, double c, char d, string z, string y, string x, string w, string v) : Competition(a,b,c,d,z,y,x,w,v)
	 {
        this->e=e;
        this->f=f;
        this->g=g;
        this->h=h;
    }
    ProgCompetition(){e=0;f=0;g=0;h='\0';}
    int e;
    float f;
    double g;
    char h;
};
class DebuggingCompetition : public Competition{
public:
    DebuggingCompetition( char i,  double j, float k, int l, int a, float b, double c, char d, string z, string y, string x, string w, string v) : Competition(a,b,c,d,z,y,x,w,v
	){
        this->i=i;
        this->j=j;
        this->k=k;
        this->l=l;
    }
    DebuggingCompetition(){l=0;j=0;k=0;i='\0';}
    char i;
    double j;
    float k;
    int l;
};
template <class T>

T itsyours (int a){
    ifstream fin;
    fin.open("File.txt",ios::in);
    fin.seekg(a, ios::beg);
    T ob1;
    fin.read((char*)&ob1,sizeof(ob1));
    fin.close();
    return ob1;
}
int main(){
    int t;
    cout<<"CLICK 0 IF YOU WANT 1 FLIE || CLICK 1 IF YOU WANT 3 FILES"<<endl;
    cin>>t;
    if(t==1){
        Competition c(1,1.9,1.99,'A',"KHUZAIMA","AHSAN","K213328","PAKISTAN","ZINDABAD");
        ofstream fout;
        fout.open("File1.txt",ios::trunc | ios::out);
        cout<<"FILE 1 CREATED\t\t";
        fout.write((char*)&c,sizeof(c));
        fout.close();
        
        ProgCompetition p(2,2.9,2.99,'B',1,1.9,1.99,'A',"KHUZAIMA","AHSAN","K213328","PAKISTAN","ZINDABAD");
        fout.open("File2.txt",ios::trunc | ios::out);
        cout<<"FILE 2 CREATED\t\t";
        fout.write((char*)&p,sizeof(p));
        fout.close();
        
        DebuggingCompetition d('C',3.99,3.9,3,1,1.9,1.99,'A',"KHUZAIMA","AHSAN","K213328","PAKISTAN","ZINDABAD");
        fout.open("File3.txt",ios::trunc | ios::out);
        cout<<"FILE 3 CREATED"<<endl;
        fout.write((char*)&d,sizeof(d));
        fout.close();
        }
    else if(t==0){
       ofstream fout;
       Competition c(1,1.9,1.99,'A',"KHUZAIMA","AHSAN","K213328","PAKISTAN","ZINDABAD");
       fout.open("File.txt",ios::trunc | ios::out);
       cout<<"FILE CREATED"<<endl;
       fout.write((char*)&c,sizeof(c));
       
       ProgCompetition p(2,2.9,2.99,'B',1,1.9,1.99,'A',"KHUZAIMA","AHSAN","K213328","PAKISTAN","ZINDABAD");
       fout.write((char*)&p,sizeof(p));
       
       DebuggingCompetition d('C',3.99,3.9,3,1,1.9,1.99,'A',"KHUZAIMA","AHSAN","K213328","PAKISTAN","ZINDABAD");
       fout.write((char*)&d,sizeof(d));
       fout.close();
       
       {cout<<endl<<endl<<"COMPETITION CLASS:"<<endl<<endl;
       Competition comp=itsyours<Competition>(0);
       cout<<comp.a<<endl<<comp.b<<endl<<comp.c<<endl<<comp.d<<endl<<comp.z<<endl<<comp.y<<endl<<comp.x<<endl<<comp.w<<endl<<comp.v<<endl;
       }
       
       {cout<<endl<<endl<<"PROGCOMPETITION CLASS"<<endl<<endl;
        ProgCompetition comp=itsyours<ProgCompetition>(sizeof(Competition)+1);
       cout<<comp.e<<endl<<comp.f<<endl<<comp.g<<endl<<comp.h<<endl<<comp.a<<endl<<comp.b<<endl<<comp.c<<endl<<comp.d<<endl<<comp.z<<endl<<comp.y<<endl<<comp.x<<endl<<comp.w<<endl<<comp.v<<endl;
       }
       
       {cout<<endl<<endl<<"DEBUGGING COMPETITION CLASS"<<endl<<endl;
        DebuggingCompetition comp=itsyours<DebuggingCompetition>(sizeof(Competition)+sizeof(ProgCompetition)+2);
       cout<<comp.i<<endl<<comp.j<<endl<<comp.k<<endl<<comp.l<<endl<<comp.a<<endl<<comp.b<<endl<<comp.c<<endl<<comp.d<<endl<<comp.z<<endl<<comp.y<<endl<<comp.x<<endl<<comp.w<<endl<<comp.v<<endl;
       }
    }

}
