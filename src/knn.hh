#pragma once

#include <vector>

class KNN {
    // Training data for prediction
    vector<vector<float>> X_train;
    vector<float>         y_train;
public:
    void fit(vector<vector<float>> X_train_from_user, vector<float> y_train_from_user);

    vector<float> predict(vector<vector<float>> X_test_from_user);
};
