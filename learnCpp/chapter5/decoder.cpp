#include <cstdint>
#include <string_view>
#include <iostream>
#include <iomanip>
//
// Created by ahmad on 7/24/26.
//
constexpr int MAX_LOGIN_ATTEMPT{3};

// literals in diff bases
const uint32_t HEX_SECTOR{0xAF39};
const uint32_t BIN_MASK{0b11110000};
const uint32_t OCTAL_PERMISSION{0755};

//-- constexpr  std::string_view
constexpr std::string_view SYSTEM_NAME{"AHMAD CYBER-HACK TERMINAL V1.0"};
constexpr std::string_view SYSTEM_STATUS_OK{"SECURE"};
constexpr std::string_view SYSTEM_STATUS_ALERT{"COMPROMISED"};

//function prototypes
void printNumeralDemo();

void printBanner();

std::string getPayload();

bool parsePayload(std::string_view payload, std::string_view& status, std::string_view& username,
                  std::string_view& hexCode);

int getPassCode();

void printResult(std::string_view status, std::string_view username, std::string_view hexCode, int passcode);

void demonstrateViewDanger(); // shows what happens with dangling views

// FNXTN DEFINITIONS
void printBanner() {
    std::cout << "============================================\n";
    std::cout << "        " << SYSTEM_NAME << "\n";
    std::cout << "============================================\n";

    std::cout << "System Status: " << SYSTEM_STATUS_OK << "\n\n";
}

void printNumeralDemo() {
    std::cout << "--- NUMERAL SYSTEM DEMO ---";
    std::cout << "Hex sector:     0x" << std::hex << HEX_SECTOR << std::dec << "\n";
    std::cout << "Binary Mask:    0b";

    for (int i = 7; i >= 0; i--) {
        std::cout << ((BIN_MASK >> i) & 1);
    }
    std::cout << "\n";
    std::cout << "Octal Permission: " << std::oct << OCTAL_PERMISSION << std::dec << "\n";
    std::cout << "MAX ATTEMPTS:   " << MAX_LOGIN_ATTEMPT << "\n";
    std::cout << "------------------------\n\n";
}

std::string getPayload() {
    std::cout << "Enter raw payload (Format: STATUS:USER:HEX_CODE):\n";
    std::cout << "Example: COMPROMISED:Agent47:0x99\n";
    std::cout << "> ";

    std::string payload{};
    std::getline(std::cin >> std::ws, payload);
    return payload;
}

bool parsePayload(std::string_view payload, std::string_view& status, std::string_view& username,
                  std::string_view& hexCode) {
    //finding delimiters
    size_t firstColon{payload.find(':')};
    size_t secondColon{payload.find(':', firstColon + 1)};

    if (firstColon == std::string_view::npos || secondColon == std::string_view::npos)
        return false;

    // clicing without copying
    status = payload.substr(0, firstColon);
    username = payload.substr(firstColon + 1, secondColon - firstColon - 1);
    hexCode = payload.substr(secondColon + 1);

    return true;
}

int getPassCode() {
    std::cout << "\nEnter digital passcode: ";
    int code{};
    std::cin >> code;
    return code;
}

void demonstrateViewDanger() {
    std::string_view danglingView;

    // creating a local string in a block
    {
        std::string localStr{"THIS STRING WILL BE DESTROYED"};
        danglingView = localStr;
        std::cout << "Inside block: " << danglingView << "\n";
    } //localStr will be destroyed here, coz it is beyond the block

    //-- dangling view -- undefined behaviour
    std::cout << "Outside block (DANGLING VIEW)";
    std::cout << danglingView << "\n"; // this should be avoided

    std::cout << "This demonstrates why we should never view local variables";
}

void printResult(std::string_view status, std::string_view username, std::string_view hexCode, int passcode) {
    std::cout << "\n --- DECRYPTION RESULTS --- \n";
    std::cout << "Status:      " << status << "\n";
    std::cout << "Operator:    " << username << "\n";
    std::cout << "Hex Checksum:" << hexCode << "\n";
    std::cout << "Passcode:    " << passcode << "\n";

    //=== if/else based on string view coparison
    if (status == SYSTEM_STATUS_ALERT) {
        std::cout << "[ALERT] System status is compromised\n";
        if (passcode == 0xDEAD) //57005 in decimal
            std::cout << "Emergenccy overrride code expected. \n";
        else
            std::cout << "WARNING: Unauthorized access detected";
    } else if (status == SYSTEM_STATUS_OK) {
        std::cout << "\n[OK] System is secure. \n";
    } else {
        std::cout << "UNKNOWN: Unrecognized system status\n";
    }

    //--- validation against binary mask
    std::cout << "\n--- Validation --- \n";
    uint32_t enteredMask {static_cast<uint32_t>(passcode)};
    if ((enteredMask & BIN_MASK) == BIN_MASK) {
        std::cout << "Binary Mask Validation Passed \n";
    }else {
        std::cout << "Binary Mask validation failed \n";
    }

    std::cout << "--- END OF RESULTS ---";
}

int main() {
    printBanner();
    printNumeralDemo();

    std::string rawPayload{getPayload()};

    std::string_view status{};
    std::string_view username{};
    std::string_view hexCode{};

    if (!parsePayload(rawPayload, status, username, hexCode)) {
        std::cout << "\n [ERROR] Malformed Packet \n";
        return 1;
    }

    int passcode{getPassCode()};

    printResult(status, username, hexCode, passcode);

    std::cout << " --- Demonstrate string_view danger --- \n";
    demonstrateViewDanger();

    return 0;
}
