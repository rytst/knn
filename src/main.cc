#include "knn.hh"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void readCsv(string file_name, vector<vector<double>> &features,
             vector<double> &label);
void printVector(vector<double> &data);
void print2dVector(vector<vector<double>> &data);

int main(int argc, char *argv[]) {
  // Check CLI usage
  if (argc != 2) {
    cerr << "Usage: knn file.csv" << endl;
    exit(1);
  }

  string file_name = argv[1];
  vector<vector<double>> features;
  vector<double> label;
  readCsv(file_name, features, label);

  // printVector(label);
  // print2dVector(features);

  vector<vector<double>> x_test;
  x_test.push_back(features[0]);

  // features.erase(features.begin());
  // label.erase(label.begin());

  KNN model;
  model.setData(features, label);

  // model.printX();
  // model.printY();
  model.predict(x_test);

  return 0;
}

// csv -> vectors
void readCsv(string file_name, vector<vector<double>> &features,
             vector<double> &label) {
  ifstream file(file_name);

  if (!file.is_open()) {
    // Cannot read file
    cerr << "Cannot read " << file_name << endl;
    exit(1);
  }

  for (string line; getline(file, line);) {
    istringstream ss(move(line));
    vector<double> record;
    if (!features.empty()) {
      record.reserve(features.front().size());
    }

    string elem;
    if (getline(ss, elem, ',')) {
      double value = stof(elem);
      label.push_back(move(value));
    }
    for (; getline(ss, elem, ',');) {
      double value = stof(elem);
      record.push_back(move(value));
    }
    features.push_back(move(record));
  }
  file.close();
}

void printVector(vector<double> &data) {
  for (int i = 0; i < data.size(); i++) {
    cout << data[i] << endl;
  }
}
void print2dVector(vector<vector<double>> &data) {
  for (int i = 0; i < data.size(); i++) {
    for (int j = 0; j < data[i].size(); j++) {
      cout << " " << data[i][j];
    }
    cout << endl;
  }
}
