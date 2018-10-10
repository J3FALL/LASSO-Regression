cmake_minimum_required(VERSION 3.12)
project(LassoRegression)

set(CMAKE_CXX_STANDARD 17)

add_executable(LassoRegression main.cpp DataSet.cpp DataSet.h LassoRegression.cpp LassoRegression.h matrix.cpp matrix.h)

