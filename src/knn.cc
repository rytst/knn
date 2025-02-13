#include "knn.hh"
#include <iostream>
#include <cfloat>
#include <vector>

using namespace std;

double KNN::dist(vector<double> &x, vector<double> &data_i) {
  size_t distance = 0;
  for (size_t i = 0; i < x.size(); i++) {
    distance += (x[i] - data_i[i]) * (x[i] - data_i[i]);
  }
  return distance;
}

size_t KNN::searchNearest(vector<double> &x) {
  size_t nearest_idx = 0;
  double nearest_dist = DBL_MAX;
  size_t i;
  for (i = 0; i < x_data.size(); i++) {
    double distance = dist(x, x_data[i]);
    if (distance < nearest_dist) {
      nearest_idx = i;
      nearest_dist = distance;
    }
  }

  return nearest_idx;
}

void KNN::setData(vector<vector<double>> &features, vector<double>& label) {
  x_data = features;
  y_data = label;
}

vector<size_t> KNN::predict(vector<vector<double>> &test) {
  vector<size_t> predictions;
  for (size_t i = 0; i < test.size(); i++) {
    vector<double> &x = test[i];
    size_t nearest_idx = searchNearest(x);

    cout << nearest_idx << endl << y_data[nearest_idx] << endl;
    predictions.push_back(y_data[nearest_idx]);
  }

  return predictions;
}


void KNN::printX() {
  for (size_t i = 0; i < x_data.size(); i++) {
    for (size_t j = 0; j < x_data[i].size(); j++) {
      cout << " " << x_data[i][j];
    }
    cout << endl;
  }
}
void KNN::printY() {
  for (size_t i = 0; i < y_data.size(); i++) {
    cout << y_data[i] << endl;
  }
}
