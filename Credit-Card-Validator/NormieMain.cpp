#include <iostream>
#include <string>
#include <algorithm>

bool isValidCreditCard(const std::string& cardNumber) {
    // Remove spaces from the card number
    std::string cleanNumber = cardNumber;
    cleanNumber.erase(std::remove(cleanNumber.begin(), cleanNumber.end(), ' '), cleanNumber.end());

    // Check if the length of the card number is valid
    if (cleanNumber.length() != 16) {
        return false;
    }

    // Check if all characters are digits
    if (std::find_if(cleanNumber.begin(), cleanNumber.end(), [](char c) { return !std::isdigit(c); }) != cleanNumber.end()) {
        return false;
    }

    // Luhn algorithm for validation
    int sum = 0;
    for (int i = 0; i < 16; i++) {
        int digit = cleanNumber[i] - '0';
        if (i % 2 == 0) {
            digit *= 2;
            if (digit > 9) {
                digit -= 9;
            }
        }
        sum += digit;
    }

    return (sum % 10 == 0);
}

int main() {
    std::string cardNumber;
    std::cout << "Enter your credit card number: ";
    std::getline(std::cin, cardNumber);

    if (isValidCreditCard(cardNumber)) {
        std::cout << "Valid credit card number." << std::endl;
    } else {
        std::cout << "Invalid credit card number." << std::endl;
    }

    return 0;
}
