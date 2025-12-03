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
         * @param t time addmitted
         */
        Condition(std::string cond, int prio, std::string t);


};