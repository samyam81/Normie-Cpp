# Employee Management System

This repository contains a simple Employee Management System implemented in C++. The system allows users to create and manage two types of employees: visiting employees and permanent employees. It enables users to input basic information about employees, such as ID and name, and specific information depending on the type of employee. Additionally, it can calculate and display the salary of each employee.

## Usage

To run the Employee Management System, follow these steps:

1. Compile the `Employee.cpp` file using a C++ compiler.
2. Execute the compiled binary file.
3. Follow the on-screen instructions to interact with the system.

## Employee Classes

### Employee (Abstract Class)

- Provides basic functionality for all types of employees.
- Contains methods for inputting basic information and displaying basic information.
- Defines two pure virtual functions:
  - `inputInfo()`: This function must be overridden by derived classes to input specific information about the employee.
  - `calculateSalary()`: This function must be overridden by derived classes to calculate the salary of the employee.

### Visiting Employee (Derived Class)

- Inherits from the `Employee` class.
- Represents employees who work for a specific number of days with daily wages.
- Overrides the `inputInfo()` and `calculateSalary()` functions to input and calculate information specific to visiting employees.

### Permanent Employee (Derived Class)

- Inherits from the `Employee` class.
- Represents employees who have a fixed monthly salary.
- Overrides the `inputInfo()` and `calculateSalary()` functions to input and calculate information specific to permanent employees.

## Main Program

- The `main()` function serves as the entry point of the program.
- It provides a menu-driven interface for users to create either visiting employees or permanent employees, or to exit the program.
- Depending on the user's choice, it dynamically allocates memory for the selected type of employee using polymorphism.
- It then prompts the user to input basic information and specific information for the employee.
- After input, it displays the employee's basic information and calculates and displays the employee's salary.
- Finally, it deallocates the memory before exiting the program.

## Contributing

Feel free to contribute to this project by submitting pull requests or reporting issues.