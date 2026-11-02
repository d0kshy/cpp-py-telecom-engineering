#include <iostream>
#include <unistd.h> // POSIX System Call

class NetworkSocket
{
private:
    int socketDescriptor;

public:
    // Constructor: resource acquisition
    NetworkSocket(int fd) : socketDescriptor(fd)
    {
        std::cout << "Socket " << socketDescriptor << " acquired and opened.\n";
    }

    // Destructor: Garantied free resource
    ~NetworkSocket()
    {
        if (socketDescriptor != -1)
        {
            std::cout << "Socket " << socketDescriptor << " safely closed.\n";
            close(socketDescriptor); // Linux System Close Call
        }
    }

    // Remove copying ability (socket has to be unic)
    NetworkSocket(const NetworkSocket &) = delete;
    NetworkSocket &operator=(const NetworkSocket &) = delete;
};

void simulateConnection()
{
    NetworkSocket simSocket(42); // Сокет открыт
    // If throw std::runtime_error("Error!"); happenes
    // Destructor simSocket will be called and will close socket.
}