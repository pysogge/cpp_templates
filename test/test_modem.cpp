#include <cassert>
#include <iostream>
#include <sstream>

#include "modem.h"

void test_private_variables(Modem modem) {
    std::cout << "Testing private variables..." << std::endl;

    // Capture the modem.print() method's cout output to a string variable
    std::string output;
    std::streambuf* old = std::cout.rdbuf();
    std::ostringstream ss;
    std::cout.rdbuf(ss.rdbuf());
    modem.print();
    std::cout.rdbuf(old);
    output = ss.str();

    // Print output
    std::cout << "Output: \n"
              << output << std::endl;

    // Assert statements for the modem.print() method
    assert(output.find("Device: /dev/ttyUSB0") != std::string::npos);
    assert(output.find("APN: myapn") != std::string::npos);
    assert(output.find("User: myuser") != std::string::npos);
    assert(output.find("Pass: mypass") != std::string::npos);
    assert(output.find("Baudrate: 115200") != std::string::npos);
    assert(output.find("Timeout: 1000") != std::string::npos);
}

void test_connection(Modem modem) {
    std::cout << "Testing connection..." << std::endl;

    // Assert statements for the class methods
    assert(modem.isConnected() == false);

    // Connect to the network
    modem.connect();

    if (modem.isConnected()) {
        std::cout << "Successfully connected to the network!" << std::endl;
    } else {
        std::cout << "Failed to connect to the network." << std::endl;
    }

    // Disconnect from the network
    modem.disconnect();

    if (modem.isConnected()) {
        std::cout << "Failed to disconnect from the network." << std::endl;
    } else {
        std::cout << "Successfully disconnected from the network!" << std::endl;
    }
}

int main() {
    // Create an instance of the Modem class
    Modem modem("/dev/ttyUSB0", "myapn", "myuser", "mypass", 115200, 1000);

    // Test private variables
    test_private_variables(modem);

    // Test connection
    test_connection(modem);

    // Send an HTTP request
    std::string response = modem.sendRequest("GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n");
    std::cout << "Response: " << response << std::endl;

    // Disconnect from the network
    modem.disconnect();

    return 0;
}
