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


TEST(InvalidDt, test_checkParameters) {
  EXPECT_THROW(PID pid(1.0, 2.0, 3.0, 0.0, 0.0, 0.0), std::domain_error);
  EXPECT_THROW(PID pid(1.0, 2.0, 3.0, -5.0, 0.0, 0.0), std::domain_error);
}

TEST(InvalidGains, test_checkParameters) {
  //  invalid Kp
  EXPECT_THROW(PID pid(0.0, 2.0, 3.0, 1.0, 0.0, 0.0), std::domain_error);
  EXPECT_THROW(PID pid(-2.0, 2.0, 3.0, 1.0, 0.0, 0.0), std::domain_error);

  //  invalid Ki
  EXPECT_THROW(PID pid(1.0, 0.0, 3.0, 1.0, 0.0, 0.0), std::domain_error);
  EXPECT_THROW(PID pid(1.0, -2.0, 3.0, 1.0, 0.0, 0.0), std::domain_error);

  //  invalid Kd
  EXPECT_THROW(PID pid(2.0, 2.0, 0.0, 1.0, 0.0, 0.0), std::domain_error);
  EXPECT_THROW(PID pid(2.0, 2.0, -3.0, 1.0, 0.0, 0.0), std::domain_error);
}

TEST(ValidGains, test_checkParameters) {
  //  valid Kp
  EXPECT_NO_THROW(PID pid(0.2, 2.0, 3.0, 1.0, 0.0, 0.0));
  EXPECT_NO_THROW(PID pid(2.0, 2.0, 3.0, 1.0, 0.0, 0.0));

  //  valid Ki
  EXPECT_NO_THROW(PID pid(1.0, 0.2, 3.0, 1.0, 0.0, 0.0));
  EXPECT_NO_THROW(PID pid(1.0, 2.0, 3.0, 1.0, 0.0, 0.0));

  //  valid Kd
  EXPECT_NO_THROW(PID pid(1.0, 2.0, 0.9, 1.0, 0.0, 0.0));
  EXPECT_NO_THROW(PID pid(2.0, 2.0, 3.0, 1.0, 0.0, 0.0));
}

TEST(PIDTest, test_computeOutput) {
  PID pid(0.5, 0.4, 0.6, 1.0, -20.0, 20.0);

  double output = pid.computeOutput(0, 5);
  ASSERT_NEAR(7.5, output, 0.5);

  output = pid.computeOutput(output, 5);
  ASSERT_NEAR(-4.75, output, 0.5);

  output = pid.computeOutput(output, 5);
  ASSERT_NEAR(19.125, output, 0.5);
}

TEST(SaturationTest, test_computeOutput) {
  PID pid1(10, 5, 45, 1.0, -20.0, 20.0);
  PID pid2(10, 5, 45, 1.0, -20.0, 20.0);
  ASSERT_LE(pid1.computeOutput(0, 5), 20);
  ASSERT_GE(pid2.computeOutput(5, 0), -20);
}

TEST(ParamVerificationTest, verifyParameters) {
  PID pid(10, 5, 45, 1.0, -20.0, 20.0);
  ASSERT_EQ(pid.getKp(), 10);
  ASSERT_EQ(pid.getKi(), 5);
  ASSERT_EQ(pid.getKd(), 45);
}

TEST(IntegralTest, test_integral) {
  PID pid(0.5, 0.4, 0.6, 1.0, -20.0, 20.0);
  ASSERT_NEAR(pid.calculateErrorIntegral(5), 5, 0.5);
}

TEST(DerivativeTest, test_derivative) {
  PID pid(0.5, 0.4, 0.6, 1.0, -20.0, 20.0);
  ASSERT_NEAR(pid.calculateErrorDerivative(5), 5, 0.5);
}
