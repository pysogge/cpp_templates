#include "modem.h"

// Constructor
Modem::Modem(std::string dev, std::string apn, std::string user, std::string pass)
    : device(dev), apn(apn), user(user), pass(pass) {
    // code to initialize the modem goes here
    // (e.g. open the serial port, set the baud rate, etc.)
}

// Connect to the network
void Modem::connect() {
    // code to establish a connection to the network goes here
}

// Disconnect from the network
void Modem::disconnect() {
    // code to terminate the connection goes here
}

// Check if the modem is connected to the internet
bool Modem::isConnected() {
    // code to check the connection status goes here
    return false;
}

// Send an HTTP request
std::string Modem::sendRequest(std::string request) {
    // code to send the request and return the response goes here
    return "hardcoded: no response";
}
