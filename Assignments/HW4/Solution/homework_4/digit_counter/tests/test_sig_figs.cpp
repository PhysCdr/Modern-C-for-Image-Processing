#include <digit_counting.h>
#include <gtest/gtest.h>
#include <iostream>
#include <random>

using std::cout;
using std::endl;

TEST(TestSigFigs, SameNumber){
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(-1e10, 1e10);
    double num = dis(gen);
    int figs = CountSameSignificantDigits(num, num);
    cout << "Number1 " << num << endl;
    cout << "Number2 " << num << endl;
    cout << "Figs " << figs << endl;
    EXPECT_EQ(100, figs);
}

TEST(TestSigFigs, FixedNumbers){
	double num1 = 100000;
	double num2 = 100.1938479347;

	int figs = CountSameSignificantDigits(num1, num2);
    cout << "Number1 " << num1 << endl;
    cout << "Number2 " << num2 << endl;
    cout << "Figs " << figs << endl;
    EXPECT_EQ(3, figs);
	
}

TEST(TestSigFigs, RandomNumbers){
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(-1e10, 1e10);
    double num1 = dis(gen);
    double num2 = dis(gen);
    int figs = CountSameSignificantDigits(num1, num2);
    cout << "Number1 " << num1 << endl;
    cout << "Number2 " << num2 << endl;
    cout << "Figs " << figs << endl;
    EXPECT_LT(figs, 100);
}