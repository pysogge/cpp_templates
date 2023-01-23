#include <string>

class Modem {
   private:
    std::string device;  // device name (e.g. "/dev/ttyUSB0")
    std::string apn;     // access point name
    std::string user;    // username for connecting to the network
    std::string pass;    // password for connecting to the network
    int baudrate;        // baud rate for serial communication
    int timeout;         // timeout for read/write operations (in

   public:
    // Constructor
    Modem(std::string dev, std::string apn, std::string user, std::string pass, int baudrate, int timeout);

    // Connect to the network
    void connect();

    // Disconnect from the network
    void disconnect();

    // private function to send a command to the modem and return the response
    std::string sendCommand(std::string cmd);

    // Check if the modem is connected to the internet
    bool isConnected();

    // Init
    bool init();

    /**********************************************************************
     * HTTP Methods
     **********************************************************************/

    // Send an HTTP request
    std::string sendRequest(std::string request);

    /**********************************************************************
     * Cellular Data Methods
     **********************************************************************/

    // Get the modem's firmware version
    std::string getFirmwareVersion();

    // Get the modem's IMEI number
    std::string getIMEI();

    // Get the modem's SIM card status
    std::string getSIMStatus();

    // Get the modem's network status
    std::string getNetworkStatus();

    // Get the modem's signal strength
    int getSignalStrength();

    /**********************************************************************
     * Debugging Methods
     **********************************************************************/

    // Print the modem's private variables
    void print();
};
