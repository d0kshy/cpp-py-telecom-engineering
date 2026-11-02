#include <iostream>
#include <queue>
#include <mutex>
#include <thread>
#include <string>
#include <vector>

class ThreadSafeLogger {
private:
    std::queue<std::string> logQueue;
    std::mutex mtx; 

public:
    void addLog(const std::string& message) {
        std::lock_guard<std::mutex> lock(mtx);
        logQueue.push(message);
    }
};

void simulateDevice(ThreadSafeLogger& logger, int deviceId) {
    logger.addLog("Device " + std::to_string(deviceId) + " connected.");
}

int main() {
    ThreadSafeLogger logger;
    std::vector<std::thread> devices;

    for (int i = 0; i < 10; ++i) {
        devices.push_back(std::thread(simulateDevice, std::ref(logger), i));
    }

    for (auto& t : devices) {
        t.join(); 
    }

    return 0;
}