#include "Condition.h"
#include "Hospital.h"
#include "Patient.h"
#include <iostream>

int main(){

    Condition cond("Hand missing", 2, "2025-12-20 12:00");
    Condition cond2("Hand missing", 3, "2025-12-20 12:00");
    
    bool test=cond<cond2;               //is cond 1 higher priority, yes
    std::cout<<test<<std::endl;


    Condition cond3("Hand missing", 3, "2025-12-20 12:30");
    Condition cond4("Hand missing", 3, "2025-12-20 12:01");
    
    test=cond3<cond4;                //is cond 3 higher priority, no
    std::cout<<test<<std::endl;

    test=cond<cond3;                //is cond 1 higher priority, yes
    std::cout<<test<<std::endl;

    return 0;
}