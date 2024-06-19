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
