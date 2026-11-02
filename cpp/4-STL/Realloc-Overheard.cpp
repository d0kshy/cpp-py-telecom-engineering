#include <iostream>
#include <vector>

int main()
{
    std::vector<int> packetQueue;

    // GOOD PRACTICE: If you know roughly how much data you will have, reserve memory upfront.
    // This prevents the vector from reallocating multiple times as it grows.
    packetQueue.reserve(10000);

    std::cout << "Size: " << packetQueue.size() << "\n";         // Output: 0
    std::cout << "Capacity: " << packetQueue.capacity() << "\n"; // Output: 10000

    packetQueue.push_back(42);

    // Because we reserved space, adding elements does not trigger a heavy memory reallocation,
    // and any existing pointers to elements remain perfectly valid.

    return 0;
}