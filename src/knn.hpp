#pragma once

#include <vector>

using namespace std;

struct Distance {
  size_t idx;
  double distance;
};

bool dist_sorter(Distance const &lhs, Distance const &rhs);

class KNN {
private:
  // Training data for prediction
  vector<vector<double>> x_data;
  vector<int> y_data;

  double dist(vector<double> &x, vector<double> &y);
  size_t searchNearest(vector<double> &x, size_t k);

public:
  void setData(vector<vector<double>> &features, vector<int> &label);
  vector<int> predict(vector<vector<double>> &test, size_t k);
  double score(vector<int> &y_true, vector<int> &y_pred);

  void printX();
  void printY();
};
