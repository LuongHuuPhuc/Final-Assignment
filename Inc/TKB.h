#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

#ifndef TKB_H
#define TKB_H

using namespace std;

class SubjectTable {
public:
    string IDClass;
    string CourseID;
    string Course;
    string Name;
    string DayOfWeek;
    string Time;
    string Place;
    string TeacherName;
    
    SubjectTable() {}
    SubjectTable(string _IDClass, string _CourseID, string _Name, string _DayOfWeek, string _Time, string _Place, string _TeacherName)
        : IDClass(_IDClass), CourseID(_CourseID), Name(_Name), DayOfWeek(_DayOfWeek), Time(_Time), Place(_Place), TeacherName(_TeacherName) {}

    static vector<SubjectTable> readData(const string& filename) {
        vector<SubjectTable> subjects;
        ifstream file(filename); //thao tác trực trên biến file
        if (!file.is_open()) {
            cerr << "Không thể mở tệp " << filename << endl;
            return subjects;
        }

        string line;
        while (getline(file, line)) {
            stringstream ss(line); //thao tác trực tiếp trên ss
            string IDClass, CourseID, Name, DayOfWeek, Time, Place, TeacherName;
            getline(ss, IDClass, ',');
            getline(ss, CourseID, ',');
            getline(ss, Name, ',');
            getline(ss, DayOfWeek, ',');
            getline(ss, Time, ',');
            getline(ss, Place, ',');
            getline(ss, TeacherName, ',');
            subjects.push_back(SubjectTable(IDClass, CourseID, Name, DayOfWeek, Time, Place, TeacherName));
        }

        file.close();
        return subjects;
    }
};


#endif
