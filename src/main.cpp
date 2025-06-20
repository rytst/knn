#include "knn.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void readCSV(string file_name, vector<vector<double>> &features,
             vector<int> &label);
void printVector(vector<double> &data);
void print2dVector(vector<vector<double>> &data);

int main(int argc, char *argv[]) {
  // Check CLI usage
  if (argc != 4) {
    cerr << "Usage: knn k train.csv test.csv" << endl;
    exit(1);
  }

  size_t k = stoi(argv[1]);
  string train_file_name = argv[2];
  string test_file_name = argv[3];

  cout << "K = " << k << endl;
  vector<vector<double>> features;
  vector<int> label;
  readCSV(train_file_name, features, label);

  vector<vector<double>> x_test;
  vector<int> y_test;
  readCSV(test_file_name, x_test, y_test);

  KNN model;
  model.setData(features, label);
  vector<int> y_pred = model.predict(x_test, k);
  double score = model.score(y_test, y_pred);

  cout << score << endl;
  return 0;
}

// csv -> vectors
void readCSV(string file_name, vector<vector<double>> &features,
             vector<int> &label) {
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
