#include "knn.hh"
#include <iostream>
#include <cfloat>
#include <vector>

using namespace std;

double KNN::dist(vector<double> &x, vector<double> &data_i) {
  size_t distance = 0;
  for (size_t i = 0; i < x.size(); i++) {
    distance += (x[i] - data_i[i + 1]) * (x[i] - data_i[i + 1]);
  }
  return distance;
}

size_t KNN::searchNearest(vector<double> &x) {
  size_t nearest_idx = 0;
  double nearest_dist = DBL_MAX;
  size_t i;
  for (i = 0; i < data.size(); i++) {
    double distance = dist(x, data[i]);
    if (distance < nearest_dist) {
      nearest_idx = i;
      nearest_dist = distance;
    }
  }

  return nearest_idx;
}

void KNN::setData(vector<vector<double>> &labeled_data) { data = labeled_data; }

vector<size_t> KNN::predict(vector<vector<double>> &test) {
  vector<size_t> predictions;
  for (size_t i = 0; i < test.size(); i++) {
    vector<double> &x = test[i];
    size_t nearest_idx = searchNearest(x);

    cout << data[nearest_idx][0] << endl;
    predictions.push_back(data[nearest_idx][0]);
  }

  return predictions;
}
