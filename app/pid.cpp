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
 * Part 2
 * @author Rishabh Mukund - Driver (rmukund@umd.edu)
 * @author Maaruf Vazifdar - Navigator (maaruf98@umd.edu)
 * @version 0.2
 * @date 2021-10-03
 *
 */

#include <pid.hpp>

PID::PID(double Kp, double Ki, double Kd, double dt, double min,
        double max) :_Kp{Kp}, _Ki{Ki}, _Kd{Kd}, _dt{dt},
                _min{min}, _max{max} {
    checkParameters();    /// Checking if the PID gains and td are appropriate
}

/// function to return the private kp variable
double PID::getKp() {return _Kp;}

/// function to return the private ki variable
double PID::getKi() {return _Ki;}

/// function to return the private kd variable
double PID::getKd() {return _Kd;}

double PID::calculateErrorIntegral(double cumm_error) {
    return (cumm_error * _dt);   /// integration of the error
}

double PID::calculateErrorDerivative(double error) {
    return ((error - _previous_error) / _dt);  /// differentiation of the error
}

void PID::checkParameters() {
    if (_dt <= 0.0) {
        throw std::domain_error("dt must be positive and non-zero");
    } else if (_Kp <= 0 || _Ki <= 0 || _Kd <= 0) {
        throw std::domain_error("gains must be positive and non-zero");
    }
}

double PID::computeOutput(double initial_state, double final_state) {
    double error = final_state - initial_state;
    _integral_sum += error;   /// updating the cumulative error

    double increment_val = PID::getKp() * error +
        PID::getKi() * PID::calculateErrorIntegral(_integral_sum) +
        PID::getKd() * PID::calculateErrorDerivative(error);

    /// checking for PID output to be in the range of [min, max]
    increment_val = increment_val > _max ? _max : increment_val;
    increment_val = increment_val < _min ? _min : increment_val;

    _previous_error = error;   /// updating previous error

    return increment_val;
}





