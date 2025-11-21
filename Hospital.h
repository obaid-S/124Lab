#include <map>
#include <queue>
#include <Condition.h>
#include <Patient.h>
class Hospital {
    private: 
        std::priority_queue<Patient> queue;
        std::map<std::string, int> triage_list;
    public:
        Hospital(std::string patient_file, std::string triage_file);
        void add_patient(std::string name, int id, std::string condition_name, std::string datetime);
        void treat_patient();
        void save(std::string filename);
};
