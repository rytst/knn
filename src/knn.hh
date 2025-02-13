#pragma once

#include <vector>

using namespace std;

class KNN {
 private:
  // Training data for prediction
  vector<vector<double>>& data;

  double dist(vector<double>& x, vector<double>& y);
  size_t searchNearest(vector<double>& x);

 public:
  void setData(vector<vector<double>>& labeled_data);

  vector<size_t> predict(vector<vector<double>>& test);
};
