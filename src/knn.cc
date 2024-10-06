#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void read_file(string file_name) {
    string line;
    ifstream file(file_name);

    if (file.is_open()) {
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        // When cannot read file
        cerr << "Cannot read " << file_name << endl;
        exit(1);
    }
}

int main(int argc, char* argv[])
{
    // Check CLI usage
    if (argc != 2) {
        cerr << "Usage: knn file.csv" << endl;
        exit(1);
    }

    string file_name = argv[1];
    read_file(file_name);

    return 0;
}
