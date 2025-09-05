# ATM Management System

This is a comprehensive C++ ATM (Automated Teller Machine) simulation program that allows users to perform banking operations like checking balance, withdrawing money, and changing PIN. The program reads customer data from a file, performs operations, and updates the file accordingly.

## Table of Contents
- [Program Overview](#program-overview)
- [Data Structure](#data-structure)
- [Features](#features)
- [Function Descriptions](#function-descriptions)
- [Program Flow Diagram](#program-flow-diagram)
- [File Structure](#file-structure)
- [Usage](#usage)

## Program Overview

This ATM simulation program provides a text-based interface for users to interact with their bank accounts. It validates user credentials (ATM ID and PIN) before allowing access to account operations. The program maintains user data in a file called `customerData.txt` and keeps an in-memory representation of this data for quick operations.

## Data Structure

The program uses a custom `node` class to store customer information:

```cpp
class node{
    public:
    string id;      // ATM ID of the customer
    int pin;        // PIN for authentication
    float balance;  // Account balance

    node(string id, int pin, float balance){
        this->id=id;
        this->pin=pin;
        this->balance=balance;
    }
};
```

All customer data is stored in a vector of these nodes:
```cpp
vector <node>Users;
```

## Features

1. **Authentication System**
   - ID validation
   - PIN validation
   - Security measures (limited PIN attempts)

2. **Account Operations**
   - Check account balance
   - Withdraw money
   - Change PIN
   
3. **Data Management**
   - Read from file
   - Write to file
   - In-memory data processing

## Function Descriptions

### Main Functions

1. **`main()`**
   - Entry point of the program
   - Initializes the data vector from file
   - Implements the main program loop

2. **`validateID()`**
   - Prompts user to enter ATM ID
   - Validates ID against the database
   - Proceeds to PIN validation if ID is valid

3. **`validatePIN()`**
   - Prompts user to enter PIN
   - Validates PIN against the database
   - Allows access to ATM options if PIN is correct
   - Limits incorrect PIN attempts to 3

4. **`atmOptions()`**
   - Displays menu of available operations
   - Handles user choices
   - Routes to appropriate functions based on selection

### Account Operation Functions

5. **`checkBalance()`**
   - Retrieves and displays the current account balance

6. **`withdrawMoney()`**
   - Handles money withdrawal process
   - Validates if sufficient balance exists
   - Updates balance and writes to file if successful

7. **`changePIN()`**
   - Allows user to set a new PIN
   - Updates PIN in memory and in the file

### Data Management Functions

8. **`fillDatainVector()`**
   - Reads customer data from the file
   - Populates the Users vector with node objects

9. **`writeToFile()`**
   - Writes updated customer data back to the file
   - Ensures persistence of changes

### Utility Functions

10. **`clearConsole()`**
    - Clears the console screen
    - Cross-platform implementation (Windows/Unix)

## Program Flow Diagram

```
┌────────────────┐
│     main()     │
└───────┬────────┘
        │
        ▼
┌────────────────┐
│fillDatainVector│
└───────┬────────┘
        │
        ▼
┌────────────────┐
│  validateID()  │◄─────┐
└───────┬────────┘      │
        │               │
        ▼               │
┌────────────────┐      │
│ validatePIN()  │      │
└───────┬────────┘      │
        │               │
        ▼               │
┌────────────────┐      │
│  atmOptions()  │      │
└───────┬────────┘      │
        │               │
        ▼               │
┌─────────────────────┐ │
│ Choose Operation:   │ │
│ 1. withdrawMoney()  │ │
│ 2. checkBalance()   │ │
│ 3. changePIN()      │ │
│ 4. EXIT             │─┘
└─────────────────────┘
```

## File Structure

- **Main.cpp**: Contains all the program code
- **customerData.txt**: Stores customer data in the format: 
  ```
  [ATM ID] [PIN] [Balance]
  ```
  Example:
  ```
  A1B2C3D4E5 1234 5000.5
  F6G7H8I9J0 2345 3200.75
  ```
- **Main.exe**: Compiled executable file

## Usage

1. Run the executable file (`Main.exe`)
2. Enter your ATM ID when prompted
3. Enter your PIN when prompted (you have 3 attempts)
4. Choose from the available options:
   - Withdraw money
   - Check balance
   - Change PIN
   - Exit

### Security Features

- The program allows only 3 wrong PIN attempts
- The console is cleared after each session for privacy
- The program validates all inputs before processing

---

*This ATM simulation is designed for educational purposes and demonstrates file handling, data structures, and user interface programming in C++.*
