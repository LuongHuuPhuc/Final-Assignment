#include <iostream>
#include"src/TKB.h"
#include"src/GV.h"
#include"src/Function.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


int main() {
    // Đọc dữ liệu từ file CSV
    vector<SubjectTable> listSubject = SubjectTable::readData("TKB.csv");
    vector<Teacher> listTeacher = Teacher::readData("GV.csv");
    unordered_map<string, vector<pair<string, string>>> teacherSchedule; // Lưu trữ lịch giảng dạy của giảng viên
    // Phân công giảng viên cho các lớp học
    for (auto& subject : listSubject) {
        for (const auto& teacher : listTeacher) {
            if (assignTeacherToSubject(subject, teacher, teacherSchedule)) {
                break; // Nếu phân công thành công, thoát khỏi vòng lặp
            }
        }
    }
    // Ghi dữ liệu phân công vào file
    writeScheduleToFile(listSubject);
    cout << "Phân công giảng viên đã được ghi vào file phancong.csv" << endl;
    
    char x;
    do {
    auto data = readFile("phancong.csv");
    cout << "Chuc nang" << endl;
    cout<<"1. Xem toan bo thoi khoa bieu"<<endl;
    cout<<"2. Xem theo ten giao vien"<<endl;
    cout<<"3. Xem theo ma hoc phan"<<endl;
    cout<<"4. Xem theo ngay trong tuan"<<endl;
    cout<<"5. Chinh sua TKB" << endl;
    cout<<"Chon lua chon: ";
    string value;
    int option;
    cin >> option;
        if(option == 1){//In toan bo thoi khoa bieu
            // string filename;
            // cin.ignore();
            // getline(cin, filename);
            printFile("phancong.csv");
        } else if (option == 2){ // IN theo ten giang vien
            for(const auto& teacher : listTeacher){
                cout << teacher.Name << endl;
            }
            cout << "Nhap ten giang vien: ";
            cin.ignore();
            getline(cin, value);
            printMatchingRows(data, 6, value);
        } else if (option == 3) { // In theo ma hoc phan
            for(auto& subject : listSubject){
                cout << subject.CourseID << "\t " << subject.Name << endl;
            }
            cout << "Nhap ma hoc phan: ";
            cin.ignore();
            getline(cin, value);
            printMatchingRows(data, 1, value);

        } else if (option == 4){
            for(int i = 1; i < data.size(); ++i){
                printMatchingRows(data, 3, to_string(i));
            }
        } else if (option == 5){ 
            do{
                
                int option_t;
                cin >> option_t;
                int row;
                if(option_t == 1) {    
                    cout << "Vi tri thong tin muon sua: ";
                    cin >> row;
                    cin.ignore();
                    getline(cin, value);
                    editFile("phancong.csv", row - 1, 6, value);
                } else if (option_t == 2){
                    cout << "Vi tri thong tin muon sua: ";
                    cin >> row;
                    cin.ignore();
                    getline(cin, value);
                    editFile("phancong.csv", row - 1, 4, value);
                } else if (option_t == 3){
                    cout << "Vi tri thong tin muon sua: ";
                    cin >> row;
                    cin.ignore();
                    getline(cin, value);
                    editFile("phancong.csv", row - 1, 5, value);
                }
                cout << "Tiep tuc chinh sua? Y/N ";
                cin >> x;
            } while(x == 'y' || x == 'Y');
        }
        cout << "Tiep tuc chuong trinh? Y/N ";
        cin >> x;
    } while (x == 'y' || x == 'Y');
    
    
    return 0;
}
