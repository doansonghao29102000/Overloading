#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;
void swap(int &xp, int &yp)
{
    int temp = xp;
    xp = yp;
    yp = temp;
}
struct Ngay_Sinh
{
	int Ngay;
	int Thang;
	int Nam;
};
class Khach_Hang
{
	private:
	    string Ho_Ten;
	    Ngay_Sinh Birth_Date;
	    string So_CMT;
	    string Ho_Khau;
	    int Tuoi;
      public:
          friend istream& operator>>(istream &is, Khach_Hang &a);
          friend ostream& operator<<(ostream &os, Khach_Hang a);
          bool operator < (Khach_Hang a);
          string getHo_Khau();	
};
istream& operator>>(istream &is, Khach_Hang &a){
	cout<<"Nhap Ho Ten Cua Khac Hang:";
	getline(cin,a.Ho_Ten);
	cout<<"Nhap Ngay Sinh Cua Khac Hang:";
	cin>>a.Birth_Date.Ngay>>a.Birth_Date.Thang>>a.Birth_Date.Nam;
	cout<<"Nhap So Chung Minh Thu Cua Khac Hang:";
	cin.ignore();
	getline(cin,a.So_CMT);
	cout<<"Nhap Ho Khau Cua Khach Hang:";
	getline(cin,a.Ho_Khau);
	cout<<"Nhap Tuoi Cua Khach Hang:";
	cin>>a.Tuoi;
	cin.ignore();
	return is;
}
ostream& operator<<(ostream &os, Khach_Hang a){
	cout<<setw(21)<<left<<a.Ho_Ten<<"|";
	if(a.Birth_Date.Ngay<10){
		
		cout<<left<<"0"<<a.Birth_Date.Ngay<<"/";
	}
	else{
		cout<<setw(2)<<left<<a.Birth_Date.Ngay<<"/";
	}
	if(a.Birth_Date.Thang<10){
		cout<<left<<"0"<<a.Birth_Date.Thang<<"/";
	}
	else{
		cout<<setw(2)<<left<<a.Birth_Date.Thang<<"/";
	}
	cout<<setw(10)<<left<<a.Birth_Date.Nam<<"|";
	cout<<setw(15)<<left<<a.So_CMT<<"|";
	cout<<setw(15)<<left<<a.Ho_Khau<<"|";
	cout<<setw(10)<<left<<a.Tuoi<<"|";
	return os;
}
string Khach_Hang::getHo_Khau(){
	return Ho_Khau;
};
bool Khach_Hang::operator <(Khach_Hang a){
	return this->Tuoi < a.Tuoi;
};
int main(){
	int n;
	cout<<"Nhap Vao So Luong Khach Hang:";
	cin>>n;
	cin.ignore();
	Khach_Hang x[n];
	for(int i=0;i<n;i++){
		cout<<"_______Nhap Thong Tin Cho Khach Hang Thu "<<i+1<<":_______"<<endl;
		cin>>x[i];
	}
	cout<<"\n________Danh Sach Thong Tin Khach Hang Thu _______"<<endl;
	for(int i=0;i<n;i++){
		cout<<x[i]<<endl;
	}
	cout<<"\n_______Danh Sach Khac Hang Co Ho Khau Ha Noi _______"<<endl;
	for(int i=0;i<n;i++){
		if(x[i].getHo_Khau()=="Ha Noi") cout<<x[i]<<endl;
	}
	for(int i=0;i<n-1;i++){
		for(int j=i;j<n;j++){
			if(x[i]<x[j]) swap(x[i],x[j]);
		}
		
	}
	cout<<"\n_______Danh Sach Khac Hang Sap Xep Theo Do Tuoi _______"<<endl;
	for(int i=0;i<n;i++){
		cout<<x[i]<<endl;
	}
	return 0;
}