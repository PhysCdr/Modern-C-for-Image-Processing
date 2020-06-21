#include <digit_counting.h>
#include <gtest/gtest.h>
#include <iostream>
#include <random>

using std::cout;
using std::endl;

TEST(TestWarp, ZeroFactor){
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(-1e10, 1e10);
    double num = dis(gen);
    double factor = 0;
    double result = Warp(num, factor);
    cout << "Number " << num << endl;
    cout << "Factor " << factor << endl;
    cout << "Result " << result << endl;
    EXPECT_NEAR(num, result, 0); 
}

TEST(TestWarp, SmallFactor){
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(-1e10, 1e10);
    double num = dis(gen);
    double factor = num/1e10;
    double result = Warp(num, factor);
    cout << "Number " << num << endl;
    cout << "Factor " << factor << endl;
    cout << "Result " << result << endl;
    EXPECT_NEAR(num, result, factor); 	
}

TEST(TestWarp, LargeFactor){
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(-1e10, 1e10);
    double num = dis(gen);
    double factor = num * 1e10;
    double result = Warp(num, factor);
    cout << "Number " << num << endl;
    cout << "Factor " << factor << endl;
    cout << "Result " << result << endl;
    EXPECT_NE(num, result); 	
}