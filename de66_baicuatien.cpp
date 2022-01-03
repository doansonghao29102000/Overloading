#include <iostream>
#include <iomanip>
using namespace std;
class Developer
{
	protected:
	    string MaSo;
	    string HoTen; 
	    string NgaySinh;//  dd/mm/yyyy
	    long HeSoluong;
      public:
          Developer(string MaSo="01x" ,string HoTen = "Nguyen Van X" , string NgaySinh = "dd/mm/yyyy" , 
	    long HeSoluong = 1)
    	    {
          	   this->MaSo = MaSo;
          	   this->HoTen = HoTen;
          	   this->NgaySinh = NgaySinh;
          	   this->HeSoluong = HeSoluong;
          }
          ~Developer()
    	    {
          	   MaSo = HoTen = NgaySinh =  "";
          	   HeSoluong = 0;
          }
          void Nhap()
          {
          	   cout<<"Nhap Ma So:";
          	   getline(cin, MaSo);
          	   cout<<"Nhap Ho Ten:";  
          	   getline(cin, HoTen);
          	   cout<<"Nhap Ngay Sinh:"; 
          	   getline(cin, NgaySinh);      //  dd/mm/yyyy
          	   cout<<"Nhap He So Luong:";
          	   cin>>HeSoluong;
          	   cin.ignore();
          }
          void In()
          {
          	   cout<<MaSo<<"    "<<HoTen<<"    "<<NgaySinh<<"    "<<HeSoluong; 
          }
          
};

class TeamLeader : public Developer
{
	private:
	    long LuongTrachNhiem;
	    int SoNamCongTac;
      public:
          TeamLeader(string MaSo="01x" ,string HoTen = "Nguyen Van X" , string NgaySinh = "dd/mm/yyyy" , 
	    long HeSoluong = 1 , long LuongTrachNhiem = 1 , int SoNamCongTac = 1)
    	    {
          	   this->MaSo = MaSo;
          	   this->HoTen = HoTen;
          	   this->NgaySinh = NgaySinh;
          	   this->HeSoluong = HeSoluong;
          	   this->LuongTrachNhiem = LuongTrachNhiem;
          	   this->SoNamCongTac = SoNamCongTac;
          }
          ~TeamLeader()
    	    {
          	   MaSo = HoTen = NgaySinh =  "";
          	   HeSoluong = LuongTrachNhiem = SoNamCongTac = 0 ;
          }
          friend istream &operator >>(istream &is, TeamLeader &a)
    	    {
   	         cout<<"Nhap Ma So:";
          	   getline(is, a.MaSo);
          	   cout<<"Nhap Ho Ten:";  
          	   getline(is, a.HoTen);
          	   cout<<"Nhap Ngay Sinh:"; 
          	   getline(is, a.NgaySinh);      //  dd/mm/yyyy
          	   cout<<"Nhap He So Luong:";
          	   is>>a.HeSoluong;
          	   cout<<"Nhap Luong Trach Nhiem:";
          	   is>>a.LuongTrachNhiem;
          	   cout<<"Nhap So Nam Cong Tac:";
          	   is>>a.SoNamCongTac;
          	   is.ignore();
          	   return is;
          }
          long long TinhTienLuong()
          {
          	   return HeSoluong*1300000 + SoNamCongTac*90000 + LuongTrachNhiem; 
          }
          bool operator !=(float x){
     	         return (this->LuongTrachNhiem != x);
          }
          friend ostream &operator <<(ostream &os, TeamLeader &a)
          {
     	         os<<a.MaSo<<"    "<<a.HoTen<<"    "<<a.NgaySinh<<"    "<<a.HeSoluong<<"   "<<a.LuongTrachNhiem;
	         os<<"    "<<a.SoNamCongTac<<endl; 
               return os;
          }
};
int main()
{
	int n;
	cout<<"Nhap Vao So Luong TeamLeader:";
	cin>>n;
	cin.ignore();
	TeamLeader a[n];
	for(int i=0;i<n;i++){
		cout<<"Nhap Thong Tin TeamLeader Thu "<<i+1<<endl;
		cin >> a[i];
	}
	cout<<"\nDanh Sach Thong Tin Cac TeamLeader"<<endl;
	for(int i=0;i<n;i++){
		cout << a[i];
	}
	Developer c;
	c.In();
	TeamLeader b;
	b.In();
	return 0;
}