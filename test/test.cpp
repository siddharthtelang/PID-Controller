/**
 * @file test.cpp
 * @author Siddharth Telang (stelang@umd.edu)
 * @author Dani Lerner (dalerner@umd.edu)
 * @brief Test file for PID Controller
 * @version 0.1
 * @date 2021-09-30
 *
 * Copyright (c) 2021
 *
 */
#include <gtest/gtest.h>
#include <pid.hpp>

TEST(PIDTest, test_computeOutput) {
  PID pid(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
  double output = pid.computeOutput(0, 1);
  EXPECT_NEAR(4.0, output, 0.5);
}

TEST(PIDTest, test_calculateErrorIntegral) {
  PID pid(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
  double output = pid.calculateErrorIntegral(0, 1);
  EXPECT_NEAR(0.0, output, 0.5);
}

TEST(PIDTest, test_calculateErrorDerivative) {
  PID pid(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
  double output = pid.calculateErrorDerivative(0, 1);
  EXPECT_NEAR(0.0, output, 0.5);
}

// TEST(PIDTest, test_Kp) {
//   PID pid(5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
// }