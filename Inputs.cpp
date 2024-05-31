#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>

using namespace std ;

//Link file 
const string filePath = "C:\\Users\\ADMIN\\Final_Assignment\\Teacher.txt" ;

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

class Teacher_Class{
	private:
		vector<Teacher> teacher ;
		vector<LopHoc> lophoc; 
	public:
		//Them Thong Tin Giang Vien vao File 
		void addTeacher(){
			string name, hocVi;
			cout << "Vui long nhap thong tin Giang Vien: " << "\n" ;
			cout << "Ten Giang Vien: " ;
			cin.ignore();
			cin.getline(cin, name);
			cout << "Hoc Vi Giang Vien: ";
			cin.getline(cin, hocVi);
			teacher.push_back(Teacher(name,hocVi));
		}
	
		//Them Thong Tin Lop Hoc vao File 
		void addClass(){
			string LoaiLop, HeLop, MaLop;
			cout << "Vui long nhap thong tin Lop Hoc: " << "\n";
			cout << "Loai Lop Hoc (Lop Bai Tap/Lop Ly Thuyet): ";
			cin.ignore();
			cin.getline(LopHoc);
			cout << "He Lop (Thuong/Elitech): ";
			cin.getline(HeLop) ;
			cout << "Ma Lop: " ;
			cin.getline(MaLop);
			lophoc.push_back(LopHoc(LoaiLop, HeLop, MaLop));
		}	

		//Hien thi thong tin Giang Vien
		void displayTeacher(){
			cout << "Danh sach Giang Vien: " << "\n";
			for(const auto& t : teacher){
				cout << "Ten Giang Vien: " << t.name << "\t" << "Hoc Vi: " << t.hocVi << endl; 
			}
		}

		//Hien thi thong tin Lop Hoc
		void displayClass(){
			cout << "Danh sach lop hoc: " << "\n";
			for(const auto& c : lophoc){
				cout << "Loai Lop Hoc: " << c.LoaiLop << "\t" << "He Lop Hoc: " << c.HeLop << "\t" << "Ma Lop Hoc: " << c.MaLop << endl ;
			}
		}

		//Ham luu du lieu vao file 
		void savetoFile(){
			ofstream file (filePath);
			cout << "Vui long nhap thong tin Giang Vien can luu vao file: " ;
			file << teacher.size() << endl;
			for(const auto& t: teacher) {
				file << t.name << endl;
				file << t.hocVi << endl;
			}
			cout << "Vui long nhap thong tin Lop Hoc can luu vao file: " ;
			file << lophoc.size() << endl;
			for(const auto& c : lophoc){
				cout << "Loai Lop: ";
				file << c.LoaiLop << endl;
				cout << "He Lop: ";
				file << c.HeLop << endl;
				cout << "Ma Lop: " ;
				file << c.MaLop << endl ;
			}
			file.close();
	
		}
		void loadfromFile(){
			ifstream file(filePath);
			if(!file.is_open())return;
			else{
				
			}
}
		//Ham Lay Du Lieu tu File 
	};
