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
    // TODO(Pair_B) : add check parameters
    checkParameters();
    // TODO(Pair_B) : If dt <=0 - throw domain error
    // TODO(Pair_B) : If gains <=0 - throw domain error
}

double PID::getKp() {return _Kp;}

double PID::getKi() {return _Ki;}

double PID::getKd() {return _Kd;}

double PID::calculateErrorDerivative(double error) {
    double derivative = (error - _previous_error) / _dt;
    return derivative;
}


double PID::calculateErrorIntegral(double error) {
    double integral = _integral_sum + error * _dt;
    return integral;
}


void PID::checkParameters() {
            if (_dt <= 0.0) {
        throw std::domain_error("dt must be positive and non-zero");
    } else if (_Kp <= 0 || _Ki <= 0 || _Kd <= 0) {
        throw std::domain_error("gains must be positive and non-zero");
    }
}

double PID::computeOutput(double initial_state, double final_state) {
    // TODO(Pair_B): calculate the derivative, integral and proportioanl error
    // TODO(Pair_B): calculate the output
    // and update the integral sum and previous error
    // TODO(Pair_B): clip output to min / max if less than / greater than

    double error = final_state - initial_state;
    double integral = calculateErrorIntegral(error);
    double derivative = calculateErrorDerivative(error);
    double output = _Kp*error +  _Ki*integral + _Kd*derivative;
    std::cout << integral <<" " << derivative << std::endl;

    _previous_error = error;
    _integral_sum += integral;

    if (output <= _min)
        output = _min;
    else if (output >= _max)
        output = _max;

    std::cout << "output = " << output << std::endl;


        if (_dt <= 0.0) {
        throw std::domain_error("dt must be positive and non-zero");
    } else if (_Kp <= 0 || _Ki <= 0 || _Kd <= 0) {
        throw std::domain_error("gains must be positive and non-zero");
    }

    return output;
}
