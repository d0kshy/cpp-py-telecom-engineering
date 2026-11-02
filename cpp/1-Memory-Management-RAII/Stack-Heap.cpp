#include <iostream>
#include <vector>
#include <memory>

class Packet
{
public:
    int id;
    int payload[256]; // Packet data simulation
    Packet(int i) : id(i) {}
};

void processPackets()
{
    // Option nr1: Data in stack. Vector contains objects.
    // Nice cache locality, every object lays in the memory one by one in a line.
    std::vector<Packet> stackPackets;
    for (int i = 0; i < 1000; ++i)
    {
        stackPackets.emplace_back(i);
    }

    // Option nr2: Data in the heap. Vector only contains pointers.
    // Objects in heap. Processor has to "jump" over addresses non-stop (cache misses).
    std::vector<std::unique_ptr<Packet>> heapPackets;
    for (int i = 0; i < 1000; ++i)
    {
        heapPackets.push_back(std::make_unique<Packet>(i));
    }
}