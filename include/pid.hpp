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

class PID {
 private:
    double _Kp, _Ki, _Kd, _dt;
    double previous_error {}, integral{};

 public:
    /**
     * @brief Construct a new PID object
     * 
     * @param Kp (double) - Proportional constant
     * @param Ki (double) - Integral constant
     * @param Kd (double) - Derivative constant
     * @param dt (double) - time
     */
    explicit PID(double Kp = 0.0, double Ki = 0.0, double Kd = 0.0,
         double dt = 1.0) :_Kp{Kp}, _Ki{Ki}, _Kd{Kd}, _dt{dt} {}
    /**
     * @brief Calculates the error integral
     * 
     * @param initial_state (double) - initial state
     * @param final_state (double) - final state
     * @return (double) - error integral
     */
    double calculateErrorIntegral(double initial_state, double final_state);
    /**
     * @brief Calculates the error derivative
     * 
     * @param initial_state (double) - initial state
     * @param final_state (double) - final state
     * @return double (double) - error derivative
     */
    double calculateErrorDerivative(double initial_state, double final_state);
    /**
     * @brief calculates the velocity output
     * 
     * @param initial_state (double) - initial state
     * @param final_state (double) - final state
     * @return (double) - final velocity
     */
    double computeOutput(double initial_state, double final_state);
};