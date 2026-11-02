#include <iostream>
#include <thread>
#include <chrono>

std::thread simulateBackgroundTask()
{
    int deviceId = 42;

    // BAD: Capturing a local stack variable by reference [&]
    auto task = [&deviceId]()
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Processing device: " << deviceId << "\n";
    };

    std::thread t(task);
    return t;
} // WARNING: deviceId is destroyed here because the function ends!

int main()
{
    std::thread worker = simulateBackgroundTask();
    worker.join(); // The thread wakes up, tries to read deviceId, and CRASHES (Segmentation Fault).
    return 0;
}