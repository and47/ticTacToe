#include<gtest/gtest.h>
#include"../funs.hpp"

TEST(ExampleTests, testGtest) {
	EXPECT_TRUE(true);
}

TEST(ExampleTests, testRndGen) {
	EXPECT_EQ(ran(0), 0);
}

TEST(ExampleTests, testDefaultVicCondsN) {
	EXPECT_EQ(std::size(genAllVicCombos(3)), 8);
}

TEST(ExampleTests, test4x4VicCondsN) {
	EXPECT_EQ(std::size(genAllVicCombos(4)), 10);
}
