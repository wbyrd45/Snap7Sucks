#include "source/snap7.h"
#include <iostream>
#include <cstring>
#include <thread>
#include <chrono>

int main() {
    TS7Client plc;
    int result = plc.ConnectTo("192.168.0.1", 0, 1); // Replace with your PLC IP, rack, and slot

    if (result != 0) {
        std::cerr << "Error connecting to PLC: " << result << std::endl;
        return 1;
    }

    std::cout << "Connected to PLC!" << std::endl;

    uint8_t data[1];
    for (int i = 0; i < 5; ++i) { // Flash DB2, byte 0, bit 0 five times
        // Read DB2
        result = plc.DBRead(2, 0, 1, data);
        if (result != 0) {
            std::cerr << "Error reading DB2: " << result << std::endl;
            break;
        }

        // Toggle bit 0
        data[0] ^= 0x01; // Flip bit 0
        result = plc.DBWrite(2, 0, 1, data);
        if (result != 0) {
            std::cerr << "Error writing DB2: " << result << std::endl;
            break;
        }

        std::cout << "Toggled bit 0: " << ((data[0] & 0x01) ? "ON" : "OFF") << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(1)); // Delay 1 second
    }

    plc.Disconnect();
    std::cout << "Disconnected from PLC." << std::endl;
    return 0;
}
