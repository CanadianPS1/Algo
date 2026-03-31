#include <iostream>
#include "Starter.h"
#include "Testing/Test.h"
void Runner::MainMethod(){
    Test test;
    std::cout << test.Addition(5, 10) << std::endl;
}
int main(){
    Runner run;
    run.MainMethod();
    return 0;
}
