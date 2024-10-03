#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

#ifndef GV_H
#define GV_H

using namespace std;

class Teacher {
public:
    string Name;
    string telNum;
    string Subject1;
    string Subject2;

    Teacher() {}
    Teacher(string _Name, string _Subject1, string _Subject2, string _telNum)
        : Name(_Name), Subject1(_Subject1), Subject2(_Subject2), telNum(_telNum) {}

    static vector<Teacher> readData(const string& filename) {
        vector<Teacher> teachers;
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Không thể mở tệp " << filename << endl;
            return teachers;
        }

        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string Name, telNum, Subject1, Subject2;
            getline(ss, Name, ',');
            getline(ss, telNum, ',');
            getline(ss, Subject1, ',');
            getline(ss, Subject2, ',');
            teachers.push_back(Teacher(Name, Subject1, Subject2, telNum));
        }

        file.close();
        return teachers;
    }
};

#endif
