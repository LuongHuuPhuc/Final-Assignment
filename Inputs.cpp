#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
#include<cstdlib> //system() , 
#include<iomanip>	// for std::setw(n), std::setfill(ch), std::left, std::right

using namespace std ;

//Lam sach man hinh console sau moi lan chuyen giao dien
void clearScreen(){
#ifdef _Win32
	system("cls");
#else 
	system("clear");
#endif

//Link file 
const string filePath1 = "C:\\Users\\ADMIN\\Final_Assignment\\Teacher.csv" ;
const string filePath2 = "C:\Users\ADMIN\Final_Assignment\\Class.csv" ;

//Dinh nghia va khai bao cac lop va cac ham
class Teacher{
	public: //Bien thanh vien 
	string name;
	string hocVi;

	public: //Ham tao dinh nghia 
	Teacher(string n, string h) {
		name = n;
		hocVi = h;
	}

class LopHoc{
	public: //Bien than vien 
	string LoaiLop;
	string TenLop;
	string HeLop;
	string MaLop;

	public: // Ham tao dinh nghia 
	LopHoc(string l, string h, long m){
		LoaiLop = l;
		HeLop = h;
		MaLop = m;
	}
};
//Cac ham su dung
void addTeacher();
void addClass();
void displayTeacher();
void displayClass();
void savetoFile();
void loadfromFile();
void delete_Teacher();
void delete_Class();
void update_Teacher();
void update_Class();

class Teacher_Class{

	private:
		vector<Teacher> teacher ;
		vector<LopHoc> lophoc; 
	public:
		//Them thong tin vao file
		void addTeacher(){
			ofstream file1;
			file1.open(filePath1,ios::out);
			//ios::out Dung cho ghi thong tin vao file, neu file ton tai, du lieu cu se bi xoa va file se bat dau tu dau
			//Neu file khong ton tai, no se duoc tao moi
			string name, hocVi;
			cout << "Vui long nhap thong tin Giang Vien: " << "\n" ;
			cout << "Ten Giang Vien: " ;
			cin.ignore();
			getline(cin,name);
			cout << "Hoc Vi Giang Vien: ";
			getline(cin,hocVi);
			teacher.push_back(Teacher(name,hocVi));
		}

		void addClass(){
			ofstream file2;
			file2.open(filePath2, ios::out);
			string LoaiLop, HeLop, MaLop;
			cout << "Vui long nhap thong tin Lop Hoc: " << "\n";
			cout << "Loai Lop Hoc (Lop Bai Tap/Lop Ly Thuyet): ";
			cin.ignore();
			getline(cin,LopHoc);
			cout << "He Lop (Thuong/Elitech): ";
			getline(cin,HeLop) ;
			cout << "Ma Lop: " ;
			getline(cin,MaLop);
			lophoc.push_back(LopHoc(LoaiLop, HeLop, MaLop));
		}	

		//Hien thi thong tin file
		void displayTeacher(){
			cout << "Danh sach Giang Vien: " << "\n";
			for(int i=0; i< teacher.size(); i++){
				cout << "Ten Giang Vien: " << teacher[i].name << "\t" << "Hoc Vi: " << teacher[i].hocVi << endl; 
			}
		}

		void displayClass(){
			cout << "Danh sach lop hoc: " << "\n";
			for(int i=0; i< lophoc.size(); i++){
				cout << "Loai Lop Hoc: " << lophoc[i].LoaiLop << "\t" ;
				cout << "He Lop Hoc: " << lophoc[i].HeLop << "\t";
			  cout << "Ma Lop Hoc: " << lophoc[i].MaLop << endl ;
			}
		}

		//Ham luu du lieu moi vao file
		void savetoFile(){
			ofstream file1(filePath1,ios::app); //Them vao cuoi file ios::app
			/* ofstream file1;
		           file1.open(filePath1); */
			cout << "Vui long nhap thong tin Giang Vien can luu vao file: " ;
			file1 << teacher.size() << endl;
			for(int i=0; i< teacher.size(); i++) {
				file1 << teacher[i].name << endl; //Ghi du lieu vao tep "<<" 
				file1 << teacher[i].hocVi << endl;
				file1.setf(ios::unitbuf); //Che do thiet lap luong dau ra, lam sach buffer sau moi lan ghi 
			}
			file1.close();

			ofstream file2(filePath2, ios::app);
			/* ofstream file2;
			   file2.open(filePath2); */
			cout << "Vui long nhap thong tin Lop Hoc can luu vao file: " ;
			file2 << lophoc.size() << endl;
			for(int i=0; i< lophoc.size(); i++){
				cout << "Loai Lop: ";
				file2 << lophoc[i].LoaiLop << endl;
				cout << "He Lop: ";
				file2 << lophoc[i].HeLop << endl;
				cout << "Ma Lop: " ;
				file2 << lophoc[i].MaLop << endl ;
				file2.setf(ios::unitbuf); 
			}
			file2.close(); //Dong sau khi tep da ghi xong 
	
		}
		//Ham doc thong tin tu file
		void loadfromFile(){
			ifstream file1;
			//Khoi tao doi tuong file dong thoi mo filePath1
		  file1.open(filePath1, ios::in);	//Thiet lap flags(cờ)/che do dau vao cho file
			//Neu file khong ton tai, viec doc du lieu se that bai
			//Khong khai bao class o day vi chua co du du lieu cho Teacher va LopHoc
			/*Neu tao doi tuong ngay tu dau se gay ra cac van de ve khoi tao doi tuong
				cung nhu cacs gia tri thieu hoac ko hop le */
			string name, hocVi, LoaiLop, TenLop, HeLop, MaLop;
			string line;
			if(!file1.is_open()) return; //Kiem tra xem file co dang mo khong 
			teacher.clear();
			while(getline(file1,line)){
				stringstream ss(line); 
				getline(ss, name, ',');
				getline(ss, hocVi, ',');
				teacher.push_back(Teacher(name, hocVi));
			}
			file1.close();

		  ifstream file2;
			file2.open(filePath2, ios::in);
			if(!file2.is_open()) return;
			lophoc.clear();
			while(getline(file2, line)){
				stringstream ss(line);
				getline(ss, LoaiLop,',');
				getline(ss, TenLop,',');
				getline(ss, HeLop,',');
				getline(ss, MaLop,',');
				lophoc.push_back(LopHoc(LoaiLop, TenLop, HeLop, MaLop));
			}
			file2.close();
		}

		//Ham xoa du lieu tu file
		void delete_Teacher(){
			string name;
			cout << "Nhap ten giao vien can xoa: ";
			cin.ignore();
			getline(cin, name);
			for(int i=0; i< teacher.size(); i++){
				if(teacher[i].name == name){
					teacher.erase(teacher.begin() + i); //begin() tro den phan tu dau tien trong vector sau do + i
					break;
				}
			}
		}
		void delete_Class(){
			string MaLop;
			cout << "Nhap ma lop can xoa: " ;
			cin.ignore();
			getline(cin, MaLop);
			for(int i=0; i< lophoc.size(); i++){
				if(lophoc[i].MaLop == MaLop){
					lophoc.erase(lophoc.begin() + i);
					break;
				}
			}
		}

		//Ham cap nhat thong tin file
		void update_Teacher(){
			string name;
			cout << "Vui long nhap ten giang vien: ";
			getline(cin, name);
			for(int i=0; i< teacher.size(); i++){
				if(teacher[i].name == name){
					cout << "Cap nhat ten giang vien: " << '\n' ;
					getline(cin, teacher[i].name);
					cout << "Cap nhat hoc vi giang vien: " << '\n';
					getline(cin, teacher[i].hocVi);
					break;
				}
			}
		}

		void update_Class(){
			string MaLop;
			cout << "Vui long nhap ma lop: " ;
			getline(cin, MaLop);
			for(int i=0; i< lophoc.size(); i++){
				if(lophoc[i].MaLop == MaLop){
					cout << "Cap nhat ma lop hoc: " <<'\n';
					getline(cin, lophoc[i].MaLop);
					cout << "Cap nhat loai lop: " << '\n';
					getline(cin, lophoc[i].LoaiLop);
					cout << "Cap nhat he Lop" << '\n' ;
					getline(cin, lophoc[i].HeLop);
					cout << "Cap nhat ten lop: " << '\n';
					getline(cin, lophoc[i].TenLop);
					break;
				}
			}
		}
};
void CanGiua(const string& text, int width){
	int pad_left = (width - text.length()) / 2; 
	int pad_right = width - text.length() - pad_left;
	cout << string(pad_left, ' ') << text << string(pad_right,' ') << endl;
}

int main(){
	Teacher_Class tc;
	tc.loadfromFile();
	int pick;
	int width = 50;
	vector<string> Text;
	do{
		cout << '\t' << "================================MENU=============================" << '\t';
		Text = {
        "1. THEM THONG TIN " ,
	    	"2. CAP NHAT THONG TIN " ,
		    "3. XOA THONG TIN " ,
	      "4. HIEN THI THONG TIN " ,
	     	"0.Exit\n "
		};
		for(int i=0; i<Text.size(); i++){
			CanGiua(Text[i], width); 
		}
		cout << "Vui long nhap lua chon: " ;
		cin >> pick ;																						

		switch(pick){
			case 1: 
				clearScreen();
				int 	choice;
				cout << "1. Them thong tin giang vien \n" ;
				cout << "2. Them thong tin lop hoc \n" ;
				switch(choice){
					case 1: 
						clearScreen();
						
						addTeacher();
				}
				
				break;
			case 2: 
				clearScreen();
				break;
			case 3:
				clearScreen();
				break;
			case 4: 
				clearScreen();
				break;
			case 0:
				clearScreen();
				cout << "Dang thoat...\n" ;
				exit(0); //Thoat khoi man hinh Command
				break; 

			default: 
				clearScreen();
				cout << "Lua chon khong co trong menu, vui long nhap lai !";
				break;
		}

	} while(pick != 0);
		return 0 ;
		}
