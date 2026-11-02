#include <iostream>
#include <memory>

class BaseStation; // Forward declaration

class UserEquipment
{
public:
    // shared_ptr causes memory Leak,
    // weak_ptr breaks the loop.
    std::weak_ptr<BaseStation> connectedStation;
    ~UserEquipment() { std::cout << "UE Destroyed\n"; }
};

class BaseStation
{
public:
    std::shared_ptr<UserEquipment> activeUe;
    ~BaseStation() { std::cout << "Base Station Destroyed\n"; }
};

int main()
{
    auto station = std::make_shared<BaseStation>();
    auto ue = std::make_shared<UserEquipment>();

    station->activeUe = ue;
    ue->connectedStation = station; // Destructors won't be called with shared_ptr.

    return 0; // Memory clears correctly.
}