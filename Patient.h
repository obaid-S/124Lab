#include "Condition.h"

class Patient {
    private:
        std::string name;
        int id;
        Condition condition;
    public:
        /**
         * Creates patient with name, id and condition
         * @param n name of patient
         * @param i unique id
         * @param cond condition used for priority
         */
        Patient(std::string n, int i, Condition cond);

        std::string get_name();

        int get_id();

        Condition get_condition();
};