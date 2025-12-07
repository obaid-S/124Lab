#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <map>
#include <queue>
#include "Condition.h"
#include "Patient.h"
/**
 * * @class Hospital
 * @brief class to represent a hospital with a priority queue of patients, saves and loads from csv files, saves individual patient records to csv files
 */
class Hospital {
    private: 
        std::priority_queue<Patient> queue;
        std::map<std::string, int> triage_list;
    public:
        /**
         * Creates priority queue of patients based on list
         * @param patient_file csv of patients and conditions
         * @param triage_file csv of conditions and prioirty
         */
        Hospital(std::string patient_file, std::string triage_file);
        /**
         * Addes new patient to priority queue based on condition
         * @param name name of patient
         * @param id id of patient all ids are unique
         * @param condition_name name of condition found, used for priority
         * @param datetime if two patients have same prioirty, earlier is admitted 
         */
        void add_patient(std::string name, int id, std::string condition_name, std::string datetime);
        /**
         * Removes the highest priority patient from queue, and changes status treated to true
         */
        void treat_patient();
        /**
         * Saves the current patient queue list to a CSV file
         */
        void save(std::string filename);
};

#endif