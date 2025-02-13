#include "knn.hh"

#include <vector>

void KNN::fit(vector<vector<float>> X_train_from_user,
              vector<float> y_train_from_user);

vector<float> KNN::predict(vector<vector<float>> X_test_from_user);
