//
// Created by user on 05.10.2018.
//

#include <chrono>
#include <cmath>
#include <random>
#include <iostream>
#include "DataSet.h"

DataSet::DataSet() {
    std::uniform_real_distribution<double> uniform(0, 0.15);
    std::default_random_engine engine;
    engine.seed(std::chrono::system_clock::now().time_since_epoch().count());
    //engine.seed(10);


    for (int deg = 60; deg < 300; deg+=4) {
        sample.push_back(polynomial(deg * M_PI / 180.0, 15));
        target.push_back(sin(sample.back()[0]) + uniform(engine));
    }
}

std::vector<double> DataSet::polynomial(double x, int maxPower) {
    std::vector<double> result;

    result.push_back(x);
    for (int power = 1; power <= maxPower; power++) {
        double last = result.back();
        result.push_back(last * x);
    }

    return result;
}