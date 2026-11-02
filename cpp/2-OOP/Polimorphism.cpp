#include <iostream>
#include <vector>
#include <memory>

class ProtocolHandler
{
public:
    // virtual makes compiler create vtable. This adds little delay at the call.
    virtual void processPacket()
    {
        std::cout << "Processing raw packet...\n";
    }
    virtual ~ProtocolHandler() = default; // Basic class destructror is always virtual!
};

class LteHandler : public ProtocolHandler
{
public:
    // override saves from misstyping in nethod's name.
    void processPacket() override
    {
        std::cout << "Processing 4G LTE packet...\n";
    }
};

class FiveGHandler final : public ProtocolHandler
{
public:
    // final says to compiler, that there won't be any child classes.
    // This allows compiler a call optimization (devirtualization).
    void processPacket() override
    {
        std::cout << "Processing 5G packet...\n";
    }
};