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

bool Condition::operator<(Condition other){
    if(this->priority==other.priority){
        return this->time<other.time;
    }
    else if(this->priority<other.priority){
        return true;
    }else{
        return false;
    }
}