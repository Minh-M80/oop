#include<bits/stdc++.h>

using namespace std;

class HangHoa{
	private:
	string maHang;
	string tenHang;
	static int dem;
	public:
		HangHoa();
		HangHoa(int maHang,string tenHang);
		~HangHoa();
		void nhap();
		void xuat();
		string getTenHang(){
			return this->tenHang;
		}
	
};
int HangHoa::dem=1;
string chuanHoa(string s){
    string res="";
    stringstream ss(s);
    string token;
    while(ss>>token){
        res+=toupper(token[0]);
        for(int i=1;i<token.length();i++){
            res+=tolower(token[i]);
        }
        res+=" ";
    }
    res.erase(res.length()-1);
    return res;
}
HangHoa::HangHoa(){
};
HangHoa::HangHoa(int maHang,string tenHang){
	this->maHang=maHang;
	this->tenHang=tenHang;
}
HangHoa::~HangHoa(){
};
void HangHoa::nhap(){
	this->maHang="HH" +string(3-to_string(dem).length(),'0')+ to_string(dem);

		dem++;
	cout<<"Nhap ten hang:";
	getline(cin,this->tenHang);
	this->tenHang=chuanHoa(this->tenHang);
}
void HangHoa::xuat(){

	
	cout<<"ma hang:"<<this->maHang<<" ten hang:"<<this->tenHang<<" ";
	
}


class MayTinh:public HangHoa{
	private:
		string nhasx;
		string namsx;
		float gianiemyet;
		static float rate;
	public:
		
		MayTinh();
		MayTinh(int maHang,string tenHang,string nhasx,string namsx,float gianiemyet);
		
		~MayTinh();
		void nhap();
		void xuat();
		float giabanthucte() const;
		
		float getGiaNiemYet(){
			return this->gianiemyet;
		}
};
MayTinh::MayTinh(){
};
MayTinh::~MayTinh(){
};
MayTinh::MayTinh(int maHang,string tenHang,string nhasx,string namsx,float gianiemyet):HangHoa(maHang,tenHang){
	this->nhasx=nhasx;
	this->namsx=namsx;
	this->gianiemyet=gianiemyet;
}
void MayTinh::nhap(){
	HangHoa::nhap();
	cout<<"Nha san x:";
	getline(cin,this->nhasx);
	cout<<"Nam sx:";
	getline(cin,this->namsx);
	cout<<"Nhap gia niem yet:";
	cin>>this->gianiemyet;
	this->gianiemyet=giabanthucte();
	cin.ignore();
}

float MayTinh::rate=0.2;
void MayTinh::xuat(){
	HangHoa::xuat();
	cout<<"nha sx:"<<this->nhasx<<" nam sx:"<<this->namsx<<" gia thuc te:"<<this->gianiemyet<<endl;
}

float MayTinh:: giabanthucte() const{
	return this->gianiemyet-this->gianiemyet*this->rate;
}
bool operator > (const MayTinh &a, const MayTinh &b) {
	return a.giabanthucte() > b.giabanthucte();
}

void sapxep(MayTinh a[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]){
				swap(a[i],a[j]);
			}
		}
	}
}

int main(){
	HangHoa a;
	a.nhap();
	a.xuat();
	cout<<endl;
	int n;
	do{
		cout<<"Nhap n may tinh:";
		cin>>n;
		cin.ignore();
	}while(n<=0);
	MayTinh b[n];
	for(int i=0;i<n;i++){
		cout<<"Nhap thong tin may tinh thu"<<i+1<<":"<<endl;
		b[i].nhap();
	}
	cout<<"in n doi tg may tinh:"<<endl;
	for(int i=0;i<n;i++){
		
		b[i].xuat();
	}
	cout<<endl;
	sapxep(b,n);
	cout<<endl;
	for(int i=0;i<n;i++){
		
		b[i].xuat();
	}
	
	
}