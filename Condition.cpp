#include "Condition.h"
#include <iostream>
Condition::Condition(std::string cond, int prio, std::string t ){
    condition=cond;
    priority=prio;
    time=t;
};

Condition::Condition(){
    priority=10;
    time="9999-12-31 23:59";
    condition="healthy";
}

bool Condition::operator<(const Condition& other) const{
    if(this->priority==other.priority){
        return this->time>other.time;       //if priority same, earlier time higher priority
    }
    else if(this->priority>other.priority){ //if this priority number is larger, it is lower priority
        return true;
    }else{
        return false;
    }
}

std::string Condition::get_condition(){
    return condition;
};

int Condition::get_priority(){
    return priority;
};

std::string Condition::get_time(){
    return time;
};

