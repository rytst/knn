#include "knn.hpp"
#include <algorithm>
#include <cfloat>
#include <iostream>
#include <map>
#include <valarray>
#include <vector>

using namespace std;

bool dist_sorter(Distance const &lhs, Distance const &rhs) {
  if (lhs.distance != rhs.distance) {
    return lhs.distance < rhs.distance;
  }
  return lhs.idx < rhs.idx;
}

double KNN::dist(vector<double> &x, vector<double> &data_i) {
  size_t distance = 0;
  for (size_t i = 0; i < x.size(); i++) {
    distance += (x[i] - data_i[i]) * (x[i] - data_i[i]);
  }
  return distance;
}

size_t KNN::searchNearest(vector<double> &x, size_t k) {

  // K = 1
  if (k == 1) {

    // Return this value from this function
    Distance nearest_data = {0, DBL_MAX};

    for (size_t i = 0; i < x_data.size(); i++) {
      double distance = dist(x, x_data[i]);
      if (distance < nearest_data.distance) {
        nearest_data.idx = i;
        nearest_data.distance = distance;
      }
    }

    return y_data[nearest_data.idx];
  }

  // K > 1
  vector<Distance> distance_data;
  vector<Distance> k_nearest_data;
  map<int, size_t> label_count;

  for (size_t i = 0; i < x_data.size(); i++) {

    double distance = dist(x, x_data[i]);
    distance_data.push_back({i, distance});
  }

  sort(distance_data.begin(), distance_data.end(), &dist_sorter);

  for (size_t i = 0; i < k; i++) {
    k_nearest_data.push_back(distance_data[i]);
  }

  for (size_t i = 0; i < k; i++) {
    int label = y_data[k_nearest_data[i].idx];
    if (label_count.count(label) > 0) {
      label_count[label]++;
    } else {
      label_count[label] = 1;
    }
  }

  auto max_elem = label_count.begin();
  for (auto it = label_count.begin(); it != label_count.end(); ++it) {
    if (it->second > max_elem->second) {
      max_elem = it;
    }
  }

  return max_elem->first;
}

void KNN::setData(vector<vector<double>> &features, vector<int> &label) {
  x_data = features;
  y_data = label;
}

vector<int> KNN::predict(vector<vector<double>> &test, size_t k) {
  vector<int> predictions;
  for (size_t i = 0; i < test.size(); i++) {
    vector<double> &x = test[i];
    size_t nearest_cls = searchNearest(x, k);

    predictions.push_back(nearest_cls);
  }

  return predictions;
}

double KNN::score(vector<int> &y_true, vector<int> &y_pred) {
  size_t correct = 0;
  for (size_t i = 0; i < y_true.size(); i++) {
    if (y_true[i] == y_pred[i]) {
      correct++;
    }
  }
  return (double)correct / y_true.size();
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
