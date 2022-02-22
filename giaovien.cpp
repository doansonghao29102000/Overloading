#include<iostream.h>
using namespace std;
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
          bool operator <(long x);
          bool operator ==(string s);
          string getName(){
          	   return ht;
          }
        
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
bool giao_vien::operator<(long x)
{
	return this->bl*610 < x;
}
bool giao_vien::operator ==(string s)
{
	return this->ht == s;
}
int main(){
	int n;
	cout<<"Nhap vao so luong giao vien:";
	cin>>n;
	cin.ignore();
	giao_vien x[100];
	for(int i=0;i<n;i++){
		cout<<"\nnhap thong tin cho giao vien thu "<<i+1<<endl;
		cin>>x[i];
	}
	cout<<"\n---danh sach giao vien co luong nho hon 2000 ---"<<endl;
	for(int i=0;i<n;i++){
		if(x[i] < 2000){
			cout<<x[i];
		}
	}
	giao_vien gv;
	cout<<"\nnhap thong tin cho 1 giao vien tu ban phim "<<endl;
	cin >> gv;
	int cnt = 0;
	for(int i=0;i<n;i++){
		if(x[i] == gv.getName()){
			cnt++;
			cout<<"\nluong cua giao vien do la:"<<x[i].lcb()<<endl;
			break;
		}
	}
	if(cnt == 0){
		n++;
		x[n-1] = gv;
		
	}
	for(int i=0;i<n;i++){
			cout<<x[i];
	}
	return 0;
}