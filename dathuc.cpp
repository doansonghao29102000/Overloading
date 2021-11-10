#include<iostream.h>
using namespace std;
class da_thuc
{
	private:
	    int a,b,c,d;
      public:
          da_thuc(int a, int b, int c, int d);
          ~da_thuc();
          friend istream& operator >>(istream &in, da_thuc &dt);
          friend ostream& operator <<(ostream &out, da_thuc dt);
          da_thuc operator +(da_thuc dt2);
	    da_thuc operator -(da_thuc dt2); 
};
da_thuc::da_thuc(int a=0, int b=0, int c=0, int d=0)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
}
da_thuc::~da_thuc()
{ 
//cout<<doi tuong se duoc huy tai day<<endl;
}
istream& operator >>(istream &in, da_thuc &dt)
{
	cout<<"nhap he so bac 3:";
	in >> dt.a;
	cout<<"nhap he so bac 2:";
	in >> dt.b;
	cout<<"nhap he so bac 1:";
	in >> dt.c;
	cout<<"nhap he so bac 0:";
	in >> dt.d;
	return in;
}
ostream& operator <<(ostream &out, da_thuc dt)
{
	out<<dt.a<<"x^3 + "<<dt.b<<"x^2 + "<<dt.c<<"x + "<<dt.d<<endl;
	return out;
}
da_thuc da_thuc::operator +(da_thuc dt2)
{
	da_thuc dt(0,0,0,0);
	dt.a = a + dt2.a;
	dt.b = b + dt2.b;
	dt.c = c + dt2.c;
	dt.d = d + dt2.d;
	return dt;
}
da_thuc da_thuc::operator -(da_thuc dt2)
{
	da_thuc dt(0,0,0,0);
	dt.a = a - dt2.a;
	dt.b = b - dt2.b;
	dt.c = c - dt2.c;
	dt.d = d - dt2.d;
	return dt;
}
int main(){
	da_thuc dtsum, dtsub, dt1, dt2;
	cout<<"nhap thong tin da thuc 1 "<<endl;
	cin>>dt1;
	cout<<"nhap thong tin da thuc 2 "<<endl;
	cin>>dt2;
	dtsum = dt1 + dt2;
	cout<<"tong hai da thuc la q(x) = "<<dtsum;
	dtsub = dt1 - dt2;
	cout<<"hieu hai da thuc la g(x) = "<<dtsub;
	return 0;
}