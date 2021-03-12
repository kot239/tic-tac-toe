#include "Test.h"

int Test::totalNum = 0;
int Test::failedNum = 0;

void Test::check(bool expr, const char *func, const char  *filename, size_t lineNum) {
    totalNum++;
    if (!expr){
        failedNum++;
        std::cerr << "Test failed in: " << func << ": " << filename << " line " << lineNum << "\n";
    };
    return;
};

bool Test::showFinalResult() {
    std::cerr << "The number of tests: " << totalNum 
    << "\nThe number of passed tests: " << totalNum - failedNum
    << "\nThe number of failed tests: " << failedNum << "\n";
    return failedNum == 0;
};

int Test::code_return() {
    if (failedNum > 0)
        return 1;
    return 0;
};