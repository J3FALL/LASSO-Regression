//
// Created by user on 05.10.2018.
//

#include <chrono>
#include <cmath>
#include <random>
#include "DataSet.h"

DataSet::DataSet() {
    std::uniform_real_distribution<double> uniform(0, 0.15);
    std::default_random_engine engine;
    engine.seed(std::chrono::system_clock::now().time_since_epoch().count());
    for (int deg = 60; deg < 300; deg++) {
        sample.push_back(deg * M_PI / 180.0);
        target.push_back(sin(sample.back()) + uniform(engine));
    }
}