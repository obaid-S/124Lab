#include "Patient.h"

Patient::Patient(std::string n, int i, Condition cond){
    name=n;
    id=i;
    condition=cond;
};

Condition Patient::get_condition(){
    return condition;
};

int Patient::get_id(){
    return id;
};

std::string Patient::get_name(){
    return name;
};

bool Patient::operator<(const Patient& other) const{
    return this->condition < other.condition;
};