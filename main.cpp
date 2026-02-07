// Include Libraries
#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

// Mutex
std::atomic<bool> Status;

// True Bool
void TR() {

    // Loop
    while (true) {

        // True
        Status.store(true);

        // Sleep
        std::this_thread::sleep_for(std::chrono::milliseconds(250));

    }
}

// False Bool
void FL() {

    // Loop
    while (true) {

        // True
        Status.store(false);

        // Sleep
        std::this_thread::sleep_for(std::chrono::milliseconds(250));

    }
}

// Main Function
int main(int argc, char *argv[]) {

    // Start Thread
    std::thread trt(TR);
    std::thread flt(FL);

    // Detach Thread
    trt.detach();
    flt.detach();

    // Cout
    while (true) {

        // Cout
        std::cout << Status.load() << std::endl;

        // Sleep
        std::this_thread::sleep_for(std::chrono::milliseconds(250));

    }
}
