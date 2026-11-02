#include <iostream>
#include <vector>
#include <utility> // for std::move

class TelecomPacket
{
private:
    int *payload;
    size_t size;

public:
    // Regular Constructor
    TelecomPacket(size_t s) : size(s), payload(new int[s])
    {
        std::cout << "Packet Allocated.\n";
    }

    // Deep Copy Constructor (Slow!)
    TelecomPacket(const TelecomPacket &other) : size(other.size), payload(new int[other.size])
    {
        std::copy(other.payload, other.payload + size, payload);
        std::cout << "Packet Copied (Heavy CPU Load).\n";
    }

    // Move Constructor (Fast!) - Uses "&&" to indicate an rvalue reference
    TelecomPacket(TelecomPacket &&other) noexcept : size(other.size), payload(other.payload)
    {
        // 1. Steal the data pointer
        // 2. Nullify the old object so its destructor doesn't delete our stolen memory
        other.payload = nullptr;
        other.size = 0;
        std::cout << "Packet Moved (Zero Allocation Overhead).\n";
    }

    ~TelecomPacket()
    {
        delete[] payload;
    }
};

int main()
{
    TelecomPacket packetA(10000); // Created

    // We want to put packetA into a vector, but we don't need packetA in main() anymore.
    std::vector<TelecomPacket> queue;

    // std::move casts packetA to an rvalue, triggering the Move Constructor.
    queue.push_back(std::move(packetA));

    // packetA.payload is now nullptr. It is empty and safe to destroy.
    return 0;
}