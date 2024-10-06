#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


// csv -> vector
void read_csv(string file_name, vector<vector<float>> data) {
    ifstream file(file_name);

    if (!file.is_open()) {
        // When cannot read file
        cerr << "Cannot read " << file_name << endl;
        exit(1);
    }

    for (string line; getline(file, line); ) {
        istringstream ss(move(line));
        vector<float> row;
        if (!data.empty()) {
            row.reserve(data.front().size());
        }
        for (string elem; getline(ss, elem, ','); ) {
            float value = stof(elem);
            row.push_back(move(value));
        }
        data.push_back(move(row));
    }
    file.close();
}

int main(int argc, char* argv[])
{
    // Check CLI usage
    if (argc != 2) {
        cerr << "Usage: knn file.csv" << endl;
        exit(1);
    }

    string file_name = argv[1];
    vector<vector<float>> data;
    read_csv(file_name, data);

    return 0;
}
