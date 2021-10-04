/**
 * @file pid.hpp
 * @author Siddharth Telang (stelang@umd.edu)
 * @author Dani Lerner (dalerner@umd.edu)
 * @brief Header file for PID Controller
 * @version 0.1
 * @date 2021-09-30
 * 
 * Copyright (c) 2021 Pair A
 * 
 */
#pragma once
#include <iostream>
#include <stdexcept>

class PID {
 public:
    /**
     * @brief Construct a new PID object
     * 
     * @param Kp (double) - Proportional constant
     * @param Ki (double) - Integral constant
     * @param Kd (double) - Derivative constant
     * @param dt (double) - time
     * @param previous_error (double) previous error
     * @param integral_sum (double)  the integration summation
     */
    PID(double Kp, double Ki, double Kd, double dt, double min, double max);
    /**
     * @brief Calculates the error integral
     * 
     * @param initial_state (double) - initial state
     * @param final_state (double) - final state
     * @return (double) - error integral
     */
    double calculateErrorIntegral(double error);
    /**
     * @brief Calculates the error derivative
     * 
     * @param initial_state (double) - initial state
     * @param final_state (double) - final state
     * @return double (double) - error derivative
     */
    double calculateErrorDerivative(double error);
    /**
     * @brief calculates the velocity output
     * 
     * @param initial_state (double) - initial state
     * @param final_state (double) - final state
     * @return (double) - final velocity
     */
    double computeOutput(double initial_state, double final_state);
    /**
     * @brief Get the Kp parameter
     * 
     * @return double 
     */
    double getKp();
    /**
     * @brief Get the Kd parameter
     * 
     * @return double 
     */
    double getKd();
    /**
     * @brief Get the Ki parameter
     * 
     * @return double 
     */
    double getKi();
    /**
     * @brief check parameters
     * 
     */
    void checkParameters();

 private:
    double _Kp, _Ki, _Kd, _dt;
    double _previous_error {}, _integral_sum{};
    double _min, _max;
};
