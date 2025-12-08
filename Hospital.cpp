#include "Hospital.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

// Helper trim function (simple)
    std::string trim(const std::string& s) {
    size_t start = s.find_first_not_of(" \t\n\r");
    size_t end   = s.find_last_not_of(" \t\n\r");

    if (start == std::string::npos) return "";
    return s.substr(start, end - start + 1);
}

// CONSTRUCTOR
Hospital::Hospital(std::string patient_file, std::string triage_file) 
{
    // Load triage file
    std::ifstream triage(triage_file);
    if (!triage.is_open()) {
        std::cout << "Error opening triage file.\n";
    } else {
        std::string line;
        getline(triage, line); // skip header (name,priority)

        while (getline(triage, line)) {
            std::stringstream ss(line);
            std::string cond, prio;

            getline(ss, cond, ',');
            getline(ss, prio, ',');

            cond = trim(cond);
            triage_list[cond] = stoi(prio);
        }
    }
    // Load patient file
    std::ifstream patients(patient_file);
    if (!patients.is_open()) {
        std::cout << "Error opening patient file.\n";
        return;
    }

    std::string line;
    getline(patients, line); // skip header (name,id,condition,time)

    while (getline(patients, line)) {
        std::stringstream ss(line);
        std::string name, id, cond, t;

        getline(ss, name, ',');
        getline(ss, id, ',');
        getline(ss, cond, ',');
        getline(ss, t, ',');

        name = trim(name);
        cond = trim(cond);
        t    = trim(t);

        int prio = triage_list[cond];
        add_patient(name, stoi(id), cond, t);
    }
}
// ADD PATIENT
void Hospital::add_patient(std::string name, int id, std::string condition_name, std::string datetime)
{
    int prio = triage_list[condition_name];

    Condition c(condition_name, prio, datetime);
    Patient p(name, id, c);

    // add to queue
    queue.push(p);
    // Write / append to patient file
    std::string filename = std::to_string(id) + ".csv";

    bool exists = std::ifstream(filename).good();

    std::ofstream out(filename, std::ios::app);

    if (!exists) {
        out << "condition,time,treated\n";
    }

    out << condition_name << "," << datetime << ",false\n";
    out.close();
}
// TREAT PATIENT
void Hospital::treat_patient()
{
    if (queue.empty()) {
        std::cout << "No patients to treat.\n";
        return;
    }

    Patient p = queue.top();
    queue.pop();

    int id = p.get_id();
    std::string filename = std::to_string(id) + ".csv";
    // Read entire patient record
    std::ifstream in(filename);
    if (!in.is_open()) {
        std::cout << "Cannot open patient file.\n";
        return;
    }

    std::vector<std::string> rows;
    std::string line;

    while (getline(in, line)) {
        rows.push_back(line);
    }
    in.close();

    // Replace last row's false with true
    // last row looks like: condition,time,false
    if (rows.size() > 1) {
        std::string last = rows.back();
        size_t pos = last.rfind(',');

        if (pos != std::string::npos) {
            last = last.substr(0, pos) + ",true";
        }

        rows.back() = last;
    }
    // Rewrite file
    std::ofstream out(filename);
    for (size_t i = 0; i < rows.size(); i++) {
        out << rows[i] << "\n";
    }
    out.close();

}
// SAVE QUEUE TO CSV
void Hospital::save(std::string filename)
{
    std::ofstream out(filename);
    out << "name,id,condition,priority,time\n";

    // make a copy (basic, allowed)
    std::priority_queue<Patient> temp = queue;

    while (!temp.empty()) {
        Patient p = temp.top();
        temp.pop();

        Condition c = p.get_condition();

        out << p.get_name() << ","
            << p.get_id() << ","
            << c.get_condition() << ","
            << c.get_priority() << ","
            << c.get_time()
            << "\n";
    }

    out.close();
}

