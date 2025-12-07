#ifndef PATEINT_H
#define PATEINT_H
#include "Condition.h"

/**
 * * @class Patient
 * @brief class to represent a patient with name, id and condition, used in priority queue
 */
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

        /**
         * Operator overload for patient, needed for priority queue
         * @param other other patient
         * @return true if this patient has higher priority than other
         */
        bool operator<(const Patient& other) const;
        /**
         * Get name of patient
         * @return name of patient
         */
        std::string get_name();

        /**
         * Get id of patient
         * @return id of patient
         */
        int get_id();

        /**
         * Get condition of patient
         * @return condition of patient
         */
        Condition get_condition();
};
#endif