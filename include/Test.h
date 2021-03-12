#ifndef HW02_TEST_H_INCLUDED
#define HW02_TEST_H_INCLUDED

#define DO_CHECK(expr) check(expr, __FUNCTION__, __FILE__, __LINE__)

#include <cstddef>
#include <iostream>

class Test {
public:
    Test() = default;

    static bool showFinalResult();
    
    virtual void runAllTests() = 0;

    static int code_return();
protected:
    static int failedNum;
    static int totalNum;
                                                                
    static void check(bool expr, const char *func, const char  *filename, size_t lineNum); 
};

#endif