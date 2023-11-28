#include <iostream>
using namespace std;
class date{
	public:
		int ngay, thang, nam;
		void nhap(){
			cout<<"nhap vao ngay thang nam: ";
			cin>>ngay>>thang>>nam;
			}
		void xuat(){
			cout<<ngay<<"/"<<thang<<"/"<<nam<<"/t";
			}			
};
class canbo{
	private:
		string macb, madv, hoten;
		date ngaysinh;
	public:
		string get_madv(){
			return madv;
			}
		void nhap(){
			cout<<"Ma can bo: ";
			getline(cin,macb);
			cout<<"Ma don vi: ";
			getline(cin,madv);
			cout<<"Ho va ten: ";
			getline(cin,hoten);
			cout<<"Ngay sinh: ";
			ngaysinh.date::nhap();
		}
		void xuat(){
		cout<<macb<<"\t"<<madv<<"\t"<<hoten<<"\t"; ngaysinh.xuat();
		}			
		
		
};
class luong: public canbo{
	long phucap,baohiem;
	float hsl;
 	public:
 		void nhap_luong()
		{
			nhap();
			cout<<"Phu cap: "; cin>>phucap;
			cout<<"He so luong: "; cin>>hsl;
			cout<<"Bao hiem: "; cin>>baohiem;
			cin.ignore();
		}	

		long luongcb()
		{
			return (hsl*1350000+phucap-baohiem);
		}

		void xuat_luong()
		{
			xuat();
			cout<<phucap<<"\t"<<hsl<<"\t"<<baohiem<<"\t"<<luongcb()<<"\n";
		}

};
int main()
	{
		luong cb[50];
		int n;
		do
		{

			cout<<"Nhap so luong can bo: ";
			cin>>n;
			}while (n>50);

				cin.ignore();
				//nhap du lieu cho can bo
				for(int i=0 ;i<n;i++)
				cb[i].nhap_luong();

				cout<<"Bang luong cua can bo theo tung don vi: \n";
				//sap xep can bo theotheo ma don vi
				for (int i=0;i<n-1;i++)
					for (int j=i+1;j<n;j++)
						if(cb[i].get_madv() > cb[j].get_madv())
						{
							luong tam;
							tam = cb[i];
							cb[i]= cb[j];
							cb[j]= tam;
						}
//in theo ma don vi
						for(int i=0 ; i<n ; i++)
						{
							if (i==0 || cb[i].get_madv() != cb[i-1].get_madv())
							cout<<" -- Ma don vi : "<<cb[i].get_madv()<<endl;
							cb[i].xuat_luong();
						}

return 0;
}
