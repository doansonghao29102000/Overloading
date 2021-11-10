#include<iostream.h>
using namespace std;
void swap(int &xp , int &yp)
{
    int temp = xp;
    xp = yp;
    yp = temp;
}
class  giao_vien
{
	private:
	    string ht;
	    int t;
	    string bc;
	    string cn;
	    int bl;
      public:
          friend istream& operator >>(istream &in, giao_vien &a);
          friend ostream& operator <<(ostream &out, giao_vien a);
          long lcb();
          bool operator ==(giao_vien a);
          friend bool operator >(giao_vien a, giao_vien b);
};
istream& operator >>(istream &in, giao_vien &a){
	cout<<"Nhap ho ten:";
	getline(in, a.ht);
	cout<<"Nhap tuoi:";
	in>>a.t;
	in.ignore();
	cout<<"Nhap bang cap:";
	getline(in , a.bc);
	cout<<"Nhap chuyen nganh:";
	getline(in , a.cn);
	cout<<"Nhap bac luong:";
	in>>a.bl;
	in.ignore();
	return in;
}
ostream& operator <<(ostream &out, giao_vien a){
	out<<a.ht<<"   "<<a.t<<"   "<<a.bc<<"   "<<a.cn<<"   "<<a.bl<<"  "<<a.lcb()<<endl;
	return out;
}
long giao_vien::lcb(){
	return this->bl*610;
}
bool giao_vien::operator==(giao_vien a){
	return this->bc==a.bc;
}
bool operator >(giao_vien a, giao_vien b){
	return a.bc > b.bc;
}
int main(){
	int n;
	cout<<"Nhap vao so luong giao vien:";
	cin>>n;
	cin.ignore();
	giao_vien x[n];
	for(int i=0;i<n;i++){
		cout<<"\nnhap thong tin cho giao vien thu "<<i+1<<endl;
		cin>>x[i];
	}
	for(int i=0;i<n-1;i++){
		for(int j=i;j<n;j++){
			if(x[i]>x[j]) swap(x[i],x[j]);
		}
	}
	cout<<"\n---danh sach sinh vien duoc sap xep theo bang cap---"<<endl;
	for(int i=0;i<n;i++){
		cout<<x[i]<<endl;
	}
	return 0;
}