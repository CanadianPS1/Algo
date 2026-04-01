#include <iostream>
#include <vector>
#include "Starter.h"
#include "Testing/Test.h"
#include "BubbleSort/BubbleSort.h"
void Runner::MainMethod(){
    std::vector<int> arr = {5,2,9,1,4,6,3,7,10,8};
    BubbleSort<int> bubble;
    arr = bubble.Sort(arr);
    for(int num : arr){
        std::cout<<num<<"\n";
    }
}
int main(){
    Runner run;
    run.MainMethod();
    return 0;
}
