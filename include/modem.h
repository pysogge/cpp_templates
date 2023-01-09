#include <string>

class Modem {
  private:
    std::string device;  // device name (e.g. "/dev/ttyUSB0")
    std::string apn;     // access point name
    std::string user;    // username for connecting to the network
    std::string pass;    // password for connecting to the network

  public:
    // Constructor
    Modem(std::string dev, std::string apn, std::string user, std::string pass);

    // Connect to the network
    void connect();

    // Disconnect from the network
    void disconnect();

    // Check if the modem is connected to the internet
    bool isConnected();

    // Print the modem's private variables
    void print();

    // Send an HTTP request
    std::string sendRequest(std::string request);
};
