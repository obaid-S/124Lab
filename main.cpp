#include "Condition.h"
#include "Hospital.h"
#include "Patient.h"
#include <iostream>

int main(){

    Condition cond("Hand missing", 2, "2025-12-20 12:00");
    Condition cond2("Hand missing", 3, "2025-12-20 12:00");
    bool test= cond<cond2;

    std::cout<< "(expect 0): " << test << std::endl;

    cond2= Condition("Foot missing", 0, "2025-12-21 12:00");
    test= cond<cond2;
    std::cout<< "(expect 1): " << test << std::endl;


    Hospital h("patients.csv", "conditions.csv");
    h.save("SAVE_patients.csv");                          //saves initial queue

    //treat the first x peopke
    int x=5;
    for(int i=0; i<x; i++){
        h.treat_patient();
    }

    h.save("SAVE_remaining_patients.csv"); //saves queue 

    //load in the next_patients
    h= Hospital("next_patients.csv", "conditions.csv");
    h.save("SAVE_next_patients.csv"); //saves new initial queue

     for(int i=0; i<x; i++){
        h.treat_patient();
    }
    h.save("SAVE_next_remaining_patients.csv"); //saves new remaining queue


    
    return 0;
}