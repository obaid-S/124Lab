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
        Condition(std::string cond, int prio, std::string t);


};