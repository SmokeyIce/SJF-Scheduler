/*
* COP 4610 Operating Systems
 * Irina Vorobieva
 * Z23678087
 *
 * This project file simulates a SJF Scheduler
 * Data is pulled from the process_data.txt file
 * and is used to test the functionality of the program
 *
 */

#include "sjf/sjf_scheduler.h"
#include <iostream>
#include <stdexcept>

int main() {
    try {
        std::cout << "Starting SJF (Shortest Job First) Scheduler" << std::endl;
        SJFScheduler scheduler("process_data.txt");
        scheduler.run();
        
        std::cout << "\nPress Enter to exit...";
        std::cin.ignore();
        std::cin.get();
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
} 