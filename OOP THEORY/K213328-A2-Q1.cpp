#include<iostream>
using namespace std;

class Matrix2;

class Matrix3;
    
class Matrix {
    float var11,var12,var21,var22;
public:
    virtual void display(){ cout<<"K213328 KHUZAIMA AHSAN"<<endl; }
    Matrix(float var11=0, float var12=0, float var21=0, float var22=0){
        cout<<"K213328 KHUZAIMA AHSAN"<<endl;
        this->var11=var11;
        this->var12=var12;
        this->var21=var21;
        this->var22=var22;
        }
    float getvar11() const { 
	return var11;
	}
    float getvar12() const { 
	return var12;
	}
    float getvar21() const {
	 return var21; 
	}
    float getvar22() const { 
	return var22; 
	}
    void setvar11(float var11){ 
	this->var11=var11; 
	}
    void setvar12(float var12){ 
	this->var12=var12; 
	}
    void setvar21(float var21){ 
	this->var21=var21; 
	}
    void setvar22(float var22){ 
	this->var22=var22; 
	}
    friend void myFun2(Matrix2 &m);
    friend void myFun3(Matrix3 &m);
};

class Matrix2 : public Matrix{
public:
    virtual void display(Matrix2 &m1, Matrix2 &m2){ 
	cout<<"K213328 KHUZAIMA AHSAN"<<endl; 
	cout<<"FIRST MATRIX:"<<endl;
	cout<<m1.getvar11()<<"\t"<<m1.getvar12()<<endl;
	cout<<m1.getvar21()<<"\t"<<m1.getvar22()<<endl;
	cout<<"SECOND MATRIX:"<<endl;
	cout<<m2.getvar11()<<"\t"<<m2.getvar12()<<endl;
	cout<<m2.getvar21()<<"\t"<<m2.getvar22()<<endl;
	cout<<"RESULTANT MATRIX:"<<endl;
	cout<<getvar11()<<"\t"<<getvar12()<<endl;
	cout<<getvar21()<<"\t"<<getvar22()<<endl;
	}
    Matrix2(float var11=0, float var12=0, float var21=0, float var22=0) : Matrix(var11,var12,var21,var22){ cout<<"K213328 KHUZAIMA AHSAN"<<endl; }
    void add(Matrix2 m1, Matrix2 m2){
        setvar11(m1.getvar11()+m2.getvar11());
        setvar12(m1.getvar12()+m2.getvar12());
        setvar21(m1.getvar21()+m2.getvar21());
        setvar22(m1.getvar22()+m2.getvar22());
    }
    void subract(Matrix2 m1, Matrix2 m2){
    	setvar11(m1.getvar11()-m2.getvar11());
        setvar12(m1.getvar12()-m2.getvar12());
        setvar21(m1.getvar21()-m2.getvar21());
        setvar22(m1.getvar22()-m2.getvar22());
	}
	void multiply(Matrix2 m1, Matrix2 m2){
    	setvar11((m1.getvar11()*m2.getvar11())+(m1.getvar12()*m2.getvar21()));	
    	setvar12((m1.getvar11()*m2.getvar12())+(m1.getvar12()*m2.getvar22()));
    	setvar21((m1.getvar21()*m2.getvar11())+(m1.getvar22()*m2.getvar21()));
    	setvar22((m1.getvar21()*m2.getvar12())+(m1.getvar22()*m2.getvar22()));
    }
};

class Matrix3 : public Matrix{
    float var13,var23,var31,var32,var33;
public:
    virtual void display(Matrix3 &m1, Matrix3 &m2){ 
	cout<<"K213328 KHUZAIMA AHSAN"<<endl; 
	cout<<"FIRST MATRIX:"<<endl;
	cout<<m1.getvar11()<<"\t"<<m1.getvar12()<<"\t"<<m1.var13<<endl;
	cout<<m1.getvar21()<<"\t"<<m1.getvar22()<<"\t"<<m1.var23<<endl;
	cout<<m1.var31<<"\t"<<m1.var32<<"\t"<<m1.var33<<endl;
	cout<<"SECOND MATRIX:"<<endl;
	cout<<m2.getvar11()<<"\t"<<m2.getvar12()<<"\t"<<m2.var13<<endl;
	cout<<m2.getvar21()<<"\t"<<m2.getvar22()<<"\t"<<m2.var23<<endl;
	cout<<m2.var31<<"\t"<<m2.var32<<"\t"<<m2.var33<<endl;
	cout<<"RESULTANT MATRIX:"<<endl;
	cout<<getvar11()<<"\t"<<getvar12()<<"\t"<<var13<<endl;
	cout<<getvar21()<<"\t"<<getvar22()<<"\t"<<var23<<endl;
	cout<<var31<<"\t"<<var32<<"\t"<<var33<<endl;
	}
    Matrix3( float var11=0, float var12=0, float var13=0, float var21=0, float var22=0,  float var23=0, float var31=0, float var32=0, float var33=0) : Matrix(var11,var12,var21,var22)
    {   this->var13=var13;
        this->var23=var23;
        this->var31=var31;
        this->var32=var32;
        this->var33=var33;
        cout<<"K213328 KHUZAIMA AHSAN"<<endl;
    }
    float getvar13() const { 
	return var13; 
	}
    float getvar23() const { 
	return var23; 
	}
    float getvar31() const { 
	return var31; 
	}
    float getvar32() const { 
	return var32; 
	}
    float getvar33() const { 
	return var33; 
	}
    void setvar33(float var33){ 
	this->var33=var33; 
	}
    void setvar13(float var13){ 
	this->var13=var13; 
	}
    void setvar23(float var23){ 
	this->var23=var23; 
	}
    void setvar31(float var31){ 
	this->var31=var31; 
	}
    void setvar32(float var32){ 
	this->var32=var32; 
	}
    void add(Matrix3 m1, Matrix3 m2){
        setvar11(m1.getvar11()+m2.getvar11());
        setvar12(m1.getvar12()+m2.getvar12());
        var13=m1.var13+m2.var13;
        setvar21(m1.getvar21()+m2.getvar21());
        setvar22(m1.getvar22()+m2.getvar22());
        var23=m1.var23+m2.var23;
        var31=m1.var31+m2.var31;
        var32=m1.var31+m2.var32;
        var33=m1.var33+m2.var33;        
    }
    void subract(Matrix3 m1, Matrix3 m2){
    	setvar11(m1.getvar11()-m2.getvar11());
        setvar12(m1.getvar12()-m2.getvar12());
        var13=m1.var13-m2.var13;
        setvar21(m1.getvar21()-m2.getvar21());
        setvar22(m1.getvar22()-m2.getvar22());
        var23=m1.var23-m2.var23;
        var31=m1.var31-m2.var31;
        var32=m1.var31-m2.var32;
        var33=m1.var33-m2.var33;        
	}
	void multiply(Matrix3 m1, Matrix3 m2){
    	setvar11((m1.getvar11()*m2.getvar11())+(m1.getvar12()*m2.getvar21())+(m1.var13*m2.var31));
        setvar12((m1.getvar11()*m2.getvar12())+(m1.getvar12()*m2.getvar22())+(m1.var13*m2.var32));
		var13=(m1.getvar11()*m2.getvar13())+(m1.getvar12()*m2.getvar23())+(m1.var13*m2.var33);
		setvar21((m1.getvar21()*m2.getvar11())+(m1.getvar22()*m2.getvar21())+(m1.var23*m2.var31));
		setvar22((m1.getvar21()*m2.getvar12())+(m1.getvar22()*m2.getvar22())+(m1.var23*m2.var32));
		var23=(m1.getvar21()*m2.getvar13())+(m1.getvar22()*m2.getvar23())+(m1.var23*m2.var33);
		var31=(m1.getvar31()*m2.getvar11())+(m1.getvar32()*m2.getvar21())+(m1.var33*m2.var31);
		var32=(m1.getvar31()*m2.getvar12())+(m1.getvar32()*m2.getvar22())+(m1.var33*m2.var32);
		var33=(m1.getvar31()*m2.getvar13())+(m1.getvar32()*m2.getvar23())+(m1.var33*m2.var33);              
	}
};

void myFun2(Matrix2& m){
	m.var11=4;
    m.var12=5;
    m.var21=4;
    m.var22=9;
}

void myFun3(Matrix3& m){
	m.var11=4;
    m.var12=5;
    m.var21=4;
    m.var22=9;
    m.setvar13(0);
    m.setvar23(0);
    m.setvar31(0);
    m.setvar32(0);
    m.setvar33(0);
}



int main(){
	cout<<"ENTER TYPE OF MATRIX \n PRESS 0 FOR 2*2 \n PRESS 1 FOR 3*3"<<endl;
	bool a;
	cin>>a;
	if(a==0){
		float a,b,c,d;
		cout<<"ENTER FOR FIRST MATRIX:"<<endl;
		cout<<"ENTER ELEMENTS"<<endl;
		cin>>a>>b>>c>>d;
		static Matrix2 m1(a,b,c,d);
		cout<<"ENTER FOR SECOND MATRIX:"<<endl;
		cout<<"ENTER ELEMENTS"<<endl;
		cin>>a>>b>>c>>d;
		static Matrix2 m2(a,b,c,d);
		cout<<"ENTER WHICH OPERATION TO PERFORM\n PRESS 0 FOR ADDITION \n PRESS 1 FOR SUBTRACTION \n PRESS 2 FOR MULTIPLICATION"<<endl;
		int z;
		cin>>z;
		Matrix2 m3;
		if(z==0)
			m3.add(m1,m2);	
		else if(z==1)
			m3.subract(m1,m2);
		else if(z==2)
			m3.multiply(m1,m2);	
		myFun2(m3);	
		m3.display(m1,m2);
		}
	else if(a==1){
		float a,b,c,d,e,f,g,h,i;
		cout<<"ENTER FOR FIRST MATRIX:"<<endl;
		cout<<"ENTER ELEMENTS"<<endl;
		cin>>a>>b>>c>>d>>e>>f>>g>>h>>i;
		static Matrix3 m1(a,b,c,d,e,f,g,h,i);
		cout<<"ENTER FOR SECOND MATRIX:"<<endl;
		cout<<"ENTER ELEMENTS"<<endl;
		cin>>a>>b>>c>>d>>e>>f>>g>>h>>i;
		static Matrix3 m2(a,b,c,d,e,f,g,h,i);
		cout<<"ENTER WHICH OPERATION TO PERFORM\n PRESS 0 FOR ADDITION \n PRESS 1 FOR SUBTRACTION \n PRESS 2 FOR MULTIPLICATION"<<endl;
		int z;
		cin>>z;
		Matrix3 m3;
		if(z==0)
			m3.add(m1,m2);	
		else if(z==1)
			m3.subract(m1,m2);
		else if(z==2)
			m3.multiply(m1,m2);	
		myFun3(m3);
		m3.display(m1,m2);		
		}
}
