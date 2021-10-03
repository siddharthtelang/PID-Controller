/**
 * @file pid.cpp
 * @author Siddharth Telang (stelang@umd.edu)
 * @author Dani Lerner (dalerner@umd.edu)
 * @brief implementation file for PID Controller
 * @version 0.1
 * @date 2021-09-30
 * 
 * Copyright (c) 2021 Pair A
 * 
 */

#include <pid.hpp>

PID::PID(double Kp, double Ki, double Kd, double dt, double min,
        double max) :_Kp{Kp}, _Ki{Ki}, _Kd{Kd}, _dt{dt},
                _min{min}, _max{max} {
    checkParameters();
}

double PID::getKp() {return _Kp;}

double PID::getKi() {return _Ki;}

double PID::getKd() {return _Kd;}

double PID::calculateErrorIntegral(double error) {
    return 0.0;
}

double PID::calculateErrorDerivative(double error) {
    return 0.0;
}

void PID::checkParameters() {
    if (_dt <= 0.0) {
        throw std::domain_error("dt must be positive and non-zero");
    } else if (_Kp <= 0 || _Ki <= 0 || _Kd <= 0) {
        throw std::domain_error("gains must be positive and non-zero");
    }
}

double PID::computeOutput(double initial_state, double final_state) {
    // checkParameters();
    // TODO(Pair_B): calculate the derivative, integral and proportioanl error
    // TODO(Pair_B): calculate the output
    // and update the integral sum and previous error
    // TODO(Pair_B): clip output to min / max if less than / greater than
    return 4;
}
