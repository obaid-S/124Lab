
#ifndef CONDITION_H
#define CONDITION_H
#include <string>
/**
 * * @class Condition
 * @brief class to represent a condition with its priority and time (YYYY-MM-DD HH:MM format).  
 */
class Condition{
    private:    
        std::string condition;
        int priority;
        std::string time;
    public:
        /**
         * Create condition profile for a patient
         * @param cond condition name
         * @param prio priority, 1 being highest
         * @param t time addmitted format "YYYY-MM-DD HH:MM";
         */
        Condition(std::string cond, int prio, std::string t);
        /**
         * Default constuctor for patient class
         */
        Condition();
        /**
         * Operator overload for condition, needed for priority queue
         * @param other other condition
         */
        bool operator<(Condition other);


};
#endif