#include "Condition.h"

class Patient {
    private:
        std::string name;
        int id;
        Condition condition;
    public:
        Patient(std::string n, int i, Condition cond);

        std::string get_name();

        int get_id();

        Condition get_condition();
};