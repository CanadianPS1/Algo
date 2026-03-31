#include <iostream>
#include "Starter.h"
#include "Testing/Test.h"
#include "BubbleSort/BubbleSort.h"
void Runner::MainMethod(){
    BubbleSort bubble;
    bubble.Sort();
}
int main(){
    Runner run;
    run.MainMethod();
    return 0;
}
