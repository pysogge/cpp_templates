#include "modem.h"

#include <chrono>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>

// Constructor
Modem::Modem(std::string dev, std::string apn, std::string user, std::string pass, int baudrate, int timeout)
    : device(dev), apn(apn), user(user), pass(pass), baudrate(baudrate), timeout(timeout) {
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

// Print the modem's private variables
void Modem::print() {
    std::cout << "Device: " << device << std::endl;
    std::cout << "APN: " << apn << std::endl;
    std::cout << "User: " << user << std::endl;
    std::cout << "Pass: " << pass << std::endl;
    std::cout << "Baudrate: " << baudrate << std::endl;
    std::cout << "Timeout: " << timeout << std::endl;
}

// Send an HTTP request
std::string Modem::sendRequest(std::string request) {
    // code to send the request and return the response goes here
    return "hardcoded: no response";
}

bool Modem::init() {
    // send the AT command to the modem and check the response
    std::string response = sendCommand("AT");
    if (response.find("OK") == std::string::npos) {
        return false;  // initialization failed
    }

    // set the baud rate
    response = sendCommand("AT+IPR=" + std::to_string(baudrate));
    if (response.find("OK") == std::string::npos) {
        return false;  // setting the baud rate failed
    }

    // set the timeout
    response = sendCommand("AT+SBDTC=" + std::to_string(timeout));
    if (response.find("OK") == std::string::npos) {
        return false;  // setting the timeout failed
    }

    return true;  // initialization successful
}
// This method sends the AT command to the modem to check if it is responding, 
// sets the baud rate using the AT + IPR command, and sets the timeout using the AT + SBDTC 
// command.If any of these commands fail, it returns false to indicate that the initialization 
// failed.  Otherwise, it returns true to indicate that the initialization was successful.