#ifndef SJF_SCHEDULER_H
#define SJF_SCHEDULER_H

#include "../process.h"
#include <queue>
#include <vector>
#include <string>
#include <map>

// Comparison function for SJF priority queue
struct CompareSJF {
    bool operator()(Process* a, Process* b) {
        return a->next_CPU_burst() > b->next_CPU_burst();
    }
};

class SJFScheduler {
public:
    explicit SJFScheduler(const std::string& filepath);
    void run();

private:
    std::string filepath;
    std::vector<Process> processes;
    std::priority_queue<Process*, std::vector<Process*>, CompareSJF> ready_queue;
    std::vector<Process*> waiting_queue;
    std::vector<Process*> completed_processes;
    Process* current_process = nullptr;
    
    int current_time = 0;
    int cpu_busy_time = 0;
    
    std::map<int, int> waiting_times;
    std::map<int, int> turnaround_times;
    std::map<int, int> response_times;

    void initialize_system();
    void run_next_process();
    void check_IO_completions();
    void update_process_times();
    void complete_process(Process* process);
    bool CPU_is_idle() const;
    bool all_processes_completed() const;
    void print_system_state() const;
    void print_final_metrics() const;
    std::vector<Process> load_process_data(const std::string& filepath);
};

// Main function declaration
int main();

#endif 