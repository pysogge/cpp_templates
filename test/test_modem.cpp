#include "modem.h"
#include <iostream>

int main() {
  // Create an instance of the Modem class
  Modem modem("/dev/ttyUSB0", "myapn", "myuser", "mypass");

  // Connect to the network
  modem.connect();
  if (modem.isConnected()) {
    std::cout << "Successfully connected to the network!" << std::endl;
  } else {
    std::cout << "Failed to connect to the network." << std::endl;
  }

  // Send an HTTP request
  std::string response = modem.sendRequest("GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n");
  std::cout << "Response: " << response << std::endl;

  // Disconnect from the network
  modem.disconnect();

  return 0;
}
