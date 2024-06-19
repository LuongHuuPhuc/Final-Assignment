void printMatchingRows(const std::vector<std::vector<std::string>>& data, int col, std::string value) {
    for (const auto& row : data) {
        if (col < row.size() && row[col].find(value) == 0) {
            for (const auto& field : row) {
                std::cout << field << "   " ;
            }
            std::cout << std::endl;
        }
    }
}

void printFile(const std::string& file_name) {
    auto data = readFile(file_name);
    for (const auto& row : data) {
        for (const auto& field : row) {
            std::cout << field  << " ";
        }
        std::cout << std::endl;
    }
}
