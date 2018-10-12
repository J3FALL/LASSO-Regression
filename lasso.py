import matplotlib.pyplot as plt
import numpy as np

x = np.array([i * np.pi / 180 for i in range(60, 300, 4)])

X = np.zeros((len(x), 16))
for idx in range(len(x)):
    X[idx, 0] = x[idx]
    for j in range(1, 16):
        X[idx, j] = X[idx, j - 1] * x[idx]

np.random.seed(10)
Y = np.sin(x) + np.random.normal(0, 0.15, len(x))


def normalize_features(feature_matrix):
    norms = np.linalg.norm(feature_matrix, axis=0)
    normalized_features = feature_matrix / norms
    return normalized_features, norms


def predict_output(feature_matrix, weights):
    predictions = np.dot(feature_matrix, weights)
    return predictions


def from_file(path):
    return np.loadtxt(path)


weights = np.full((16,), fill_value=0.5)


# def calculate_ro(num_features, feature_matrix, output, prediction, weights):
#     for i in range(num_features):
#         ro_i = (feature_matrix[:, i] * (output - prediction)).sum()
#         # ro_arr.append(ro_i)
#         print(ro_i)
#         print(i)
#     return 0
#
#
# ro = calculate_ro(16, X, Y, predict_output(X, weights), weights)


def lasso_coordinate_descent_step(num_features, feature_matrix, output, weights, l1_penalty):
    # compute prediction
    prediction = predict_output(feature_matrix, weights)
    # z_i= (feature_matrix*feature_matrix).sum()

    for i in range(num_features + 1):
        # compute ro[i] = SUM[ [feature_i]*(output - prediction + weight[i]*[feature_i]) ]
        ro_i = (feature_matrix[:, i] * (output - prediction + weights[i] * feature_matrix[:, i])).sum()

        print("RO %d: : %f" % (i, ro_i))
        if i == 0:  # intercept -- do not regularize
            new_weight_i = ro_i
        elif ro_i < -l1_penalty / 2.:
            new_weight_i = (ro_i + (l1_penalty / 2))
        elif ro_i > l1_penalty / 2.:
            new_weight_i = (ro_i - (l1_penalty / 2))
        else:
            new_weight_i = 0.

    return new_weight_i


def lasso_cyclical_coordinate_descent(feature_matrix, output, initial_weights,
                                      l1_penalty, tolerance):
    condition = True
    while condition:
        max_change = 0
        for i in range(len(initial_weights)):
            # max_change=0
            old_weight_i = initial_weights[i]
            initial_weights[i] = lasso_coordinate_descent_step(i,
                                                               feature_matrix, output,
                                                               initial_weights, l1_penalty)
            coordinate_change = abs(old_weight_i - initial_weights[i])
            if coordinate_change > max_change:
                max_change = coordinate_change
                # print(max_change)
        if max_change < tolerance:
            # print("out: ", max_change)
            condition = False
    return initial_weights


l1_penalty = 0.01
tolerance = 0.01

X, norms = normalize_features(X)

penalties = [1e-10, 1e-5, 0.001, 0.01, 0.1, 1, 10, 100]

# weights = lasso_cyclical_coordinate_descent(X, Y, weights, l1_penalty, tolerance)

weights = from_file("weights.txt")

print(weights)

plt.scatter(x, Y)
plt.plot(x, predict_output(X, weights))
plt.show()

# fig, axes = plt.subplots(2, 4)
# for idx in range(len(penalties)):
#     print(idx)
#     l1 = penalties[idx]
#     weights = lasso_cyclical_coordinate_descent(X, Y,
#                                                 weights, l1, tolerance)
#
#     i, j = divmod(idx, 4)
#     print((i, j))
#     axes[i, j].set_title("lasso with alpha = %.3g" % l1)
#     axes[i, j].scatter(x, Y)
#     axes[i, j].plot(x, predict_output(X, weights))
#
#     print(weights)
# plt.show()
