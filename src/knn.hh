#pragma once

#include <vector>

using namespace std;

class KNN {
 private:
  // Training data for prediction
  vector<vector<double>> x_data;
  vector<double> y_data;

  double dist(vector<double>& x, vector<double>& y);
  size_t searchNearest(vector<double>& x);

 public:
  void setData(vector<vector<double>> &features, vector<double>& label);
  vector<size_t> predict(vector<vector<double>>& test);

  void printX();
  void printY();
};
