//
// Created by ahmad on 7/29/26.
//

#include <bitset>
#include <cstdint>
#include <iostream>


constexpr uint8_t mask_execute{1 << 0}; // 0000 0001
constexpr uint8_t mask_write{1 << 1}; // 0000 0010
constexpr uint8_t mask_read{1 << 2}; // 0000 0100

// we can actually define mask_execute using mask_read | mask_write, e.g.
constexpr uint8_t mask_read_write{ mask_read | mask_write};
constexpr uint8_t mask_all{mask_read | mask_write | mask_execute};

//helper function to help print the permissions visually
void displayPermissions(uint8_t current_flag) {
    std::cout << "Visual: ";
    std::cout << ((current_flag & mask_read) ? "r" : "-");
    std::cout << ((current_flag & mask_write) ? "w" : "-");
    std::cout << ((current_flag & mask_execute) ? "x" : "-");

    // to print out the raw bit
    std::cout << "  |  Binary: " << std::bitset<8>(current_flag) << "\n\n";
}

int main() {
    // uint8_t fileFlags{06}; // 6 is read + write
    uint8_t fileFlags{mask_read | mask_write}; // more clear and understandable

    std::cout << " === === == LINUX FILE PERMISSION SIMULATOR == === === \n";
    //set bit, turn execute on
    fileFlags |= mask_execute;
    displayPermissions(fileFlags);

    // verify if write is allowed
    if (fileFlags & mask_write) {
        std::cout << "Check applied: Write permission is currently ON \n";
    }

    std::cout << "Action: Revoking write permission \n";
    fileFlags &= ~mask_write;
    displayPermissions(fileFlags);

    //-- toggle execute status by flipping
    std::cout << "Action: Toggling execute permission\n";
    fileFlags ^= mask_execute; //bitwise XOR
    displayPermissions(fileFlags);

    return 0;
}
