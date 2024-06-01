# Credit Card Validator

This repository contains a simple C++ program to validate credit card numbers using the Luhn algorithm.

## Usage

1. Clone this repository to your local machine.
2. Compile the `NormieMain.cpp` file.
3. Run the compiled executable.
4. Enter your credit card number when prompted.
5. The program will output whether the entered credit card number is valid or invalid.

## Algorithm

The program uses the Luhn algorithm for credit card number validation. Here's how it works:
1. Remove any spaces from the input credit card number.
2. Check if the length of the card number is 16 digits.
3. Verify that all characters are digits.
4. Apply the Luhn algorithm:
   - Starting from the rightmost digit, double the value of every second digit.
   - If the doubled value is greater than 9, subtract 9 from it.
   - Sum all the digits.
5. If the sum is divisible by 10, the credit card number is valid; otherwise, it's invalid.

## File Structure

- `NormieMain.cpp`: Contains the main code for credit card number validation.
- `README.md`: This file providing information about the repository.

## Example

```
Enter your credit card number: 4111 1111 1111 1111
Valid credit card number.
```
