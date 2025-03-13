
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "../main/hi.cpp"  // Include the main file to test its function

// Function to capture console output
std::string captureOutput() {
    std::ostringstream buffer;
    std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());  // Redirect stdout to buffer

    main();  // Call the main function of hello1.cpp

    std::cout.rdbuf(old);  // Restore stdout
    return buffer.str();
}

// Test Case: Check if output is correct
TEST(HelloTest, OutputCheck) {
    std::string expectedOutput = "Have an amazing day!!\n";  // Expected output
    EXPECT_EQ(captureOutput(), expectedOutput);
}

// Main function for running tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
