/**
 * @file main.cpp
 * @author Siddharth Telang (stelang@umd.edu)
 * @author Dani Lerner (dalerner@umd.edu)
 * @brief main file
 * @version 0.1
 * @date 2021-09-30
 * 
 * Copyright (c) 2021 Pair A
 * 
 */

#include <iostream>
#include <pid.hpp>

int main() {
    PID pid;
    std::cout << pid.computeOutput(0, 1) << std::endl;
    return 0;
}

