#include<iostream.h>
using namespace std;
class vector
{
	private:
	    int a;
	    int b;
	    int c;
      public:
          vector(int a, int b, int c);
          ~vector();
          friend istream& operator >>(istream &in, vector &v);
          friend ostream& operator <<(ostream &out, vector v);
          vector operator +(vector v2);
	    vector operator -(vector v2);         
};
vector::vector(int a=0, int b=0, int c=0)
{
	this->a = a;
	this->b = b;
	this->c = c;
}
vector::~vector()
{
	
}
istream& operator >>(istream &in, vector &v)
{
	cout<<"nhap toa do ox:";
	in >> v.a;
	cout<<"nhap toa do oy:";
	in >> v.b;
	cout<<"nhap toa do oz:";
	in >> v.c;
	return in;
}
ostream& operator <<(ostream &out, vector v)
{
	cout<<"V("<<v.a<<","<<v.b<<","<<v.c<<")"<<endl;
	return out;
}
vector vector::operator +(vector v2)
{
	vector vsum(0,0,0);
	vsum.a = a + v2.a;
	vsum.b = b + v2.b;
	vsum.c = b + v2.c;
	return vsum;
}
vector vector::operator -(vector v2)
{
	vector vsub(0,0,0);
	vsub.a = a - v2.a;
	vsub.b = b - v2.b;
	vsub.c = b - v2.c;
	return vsub;
}
int main(){
	vector vsum, vsub, v1, v2;
	cout<<"nhap thong tin cho vector thu nhat:"<<endl;
	cin>>v1;
	cout<<"nhap thong tin cho vector thu hai:"<<endl;
	cin>>v2;
	vsum=v1+v2;
	cout<<"tong hai vector la: "<<vsum<<endl;
	vsub=v1-v2;
	cout<<"hieu hai vector la: "<<vsub<<endl;
	return 0;
}