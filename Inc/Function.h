#include <iostream>
#include"TKB.h"
#include"GV.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include<iomanip>

#ifndef FUNCTION_H
#define FUNCTION_H


bool isTimeConflict(const string& day1, const string& time1, const string& day2, const string& time2) {
    if (day1 != day2) {
        return false; // Không có xung đột vì khác ngày
    }

    // Kiểm tra độ dài của chuỗi thời gian trước khi sử dụng substr
    if (time1.size() < 9 || time2.size() < 9) {
        return false; // Thời gian không hợp lệ, không có xung đột
    }

    // Chuyển đổi thời gian từ định dạng "HHMM-HHMM" start1end1-start2end2 1505
    int start1 = stoi(time1.substr(0, 2)) * 60 + stoi(time1.substr(2, 2));
    int end1 = stoi(time1.substr(5, 2)) * 60 + stoi(time1.substr(7, 2));
    int start2 = stoi(time2.substr(0, 2)) * 60 + stoi(time2.substr(2, 2));
    int end2 = stoi(time2.substr(5, 2)) * 60 + stoi(time2.substr(7, 2));

    // Kiểm tra xem có xung đột thời gian không
    if (start1 < end2 && end1 > start2) {
        return true; // Có xung đột
    }

    return false; // Không xung đột
}


bool assignTeacherToSubject(SubjectTable& subject, const Teacher& teacher, unordered_map<string, vector<pair<string, string>>>& teacherSchedule) {
    if (teacher.Subject1 == subject.Name || teacher.Subject2 == subject.Name) {
        bool conflict = false; //phân công thất bại

        // Kiểm tra xung đột thời gian với lịch giảng dạy hiện tại của giáo viên
        if (teacherSchedule.find(teacher.Name) != teacherSchedule.end()) {
            for (const auto& schedule : teacherSchedule[teacher.Name]) {
                if (isTimeConflict(schedule.first, schedule.second, subject.DayOfWeek, subject.Time)) {
                    conflict = true;
                    break;
                }
            }
        }
        
        if (!conflict) {
            subject.TeacherName = teacher.Name;
            teacherSchedule[teacher.Name].emplace_back(subject.DayOfWeek, subject.Time);
            return true; // Phân công thành công
        }
    }
    return false; // Phân công thất bại
}

void writeScheduleToFile(const vector<SubjectTable>& listSubject) {
    ofstream file("phancong.csv");
    if (!file.is_open()) {
        cerr << "Không thể mở tệp để ghi." << endl;
        return;
    }

    // Ghi dữ liệu các môn học đã được sắp xếp
    for (const auto& subject : listSubject) {
        
        file << subject.IDClass << ","
             << subject.CourseID << ","
             << subject.Name << ","
             << subject.DayOfWeek << ","
             << subject.Time << ","
             << subject.Place << ","
             << subject.TeacherName << "\n";
        
    }

    file.close();
}

vector<vector<string>> readFile(const string& file_name) {
    vector<vector<string>> data;
    ifstream file(file_name);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string item;
        vector<string> row;
        while (getline(ss, item, ',')) {
            row.push_back(item);
        }
        data.push_back(row);
    }
    file.close();
    return data;
}

void writeCSV(const std::string& filename, const std::vector<std::vector<std::string>>& data) {
    std::ofstream file(filename);
    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            if (i != 0) file << ",";
            file << row[i];
        }
        file << std::endl;
    }
    file.close();
}

void editFile(const std::string& file_name, int row, int col, const std::string& newValue) {
    std::vector<std::vector<std::string>> data = readFile(file_name);
    
    if (row < 0 || row >= data.size()) {
        std::cerr << "Invalid row index." << std::endl;
        return;
    }
    
    if (col < 0 || col >= data[row].size()) {
        std::cerr << "Invalid column index." << std::endl;
        return;
    }

    data[row][col] = newValue;
    writeCSV(file_name, data);
}

void printMatchingRows(const std::vector<std::vector<std::string>>& data, int col, std::string value) {
    for (const auto& row : data) {
        if (col < row.size() && row[col].find(value) == 0) {
            for (const auto& field : row) {
                std::cout << field << ", " ;
            }
            std::cout << std::endl;
        }
    }
}

void printFile(const std::string& file_name) {
    auto data = readFile(file_name);
    for (const auto& row : data) {
        for (const auto& field : row) {
            std::cout << field  << ", ";
            
        }
        std::cout << std::endl;
    }
}

#endif
