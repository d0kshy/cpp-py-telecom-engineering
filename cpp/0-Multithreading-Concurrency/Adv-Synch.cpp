#include <atomic>
#include <condition_variable>

std::atomic<int> packetsSent{ 0 };
std::condition_variable cv;
std::mutex cv_m;
bool dataReady = false;

void consumer() {
    std::unique_lock<std::mutex> lock(cv_m);
    cv.wait(lock, [] { return dataReady; });
    std::cout << "Data processed. Total packets: " << packetsSent << "\n";
}

void producer() {
    {
        std::lock_guard<std::mutex> lock(cv_m);
        packetsSent++;
        dataReady = true;
    }
    cv.notify_one(); 
}