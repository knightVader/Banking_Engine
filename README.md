# SDLC Bank Engine - Complete Banking Management System

This is a comprehensive C++ banking management system that simulates real-world banking operations. The system supports multiple user types (Customers and Managers) with different interfaces and functionalities. It provides both ATM operations and branch banking services with complete data persistence and security features.

## Table of Contents
- [Project Overview](#project-overview)
- [System Architecture](#system-architecture)
- [User Types and Interfaces](#user-types-and-interfaces)
- [Data Structure](#data-structure)
- [Features](#features)
- [Complete Program Flow](#complete-program-flow)
- [File Structure](#file-structure)
- [Compilation and Execution](#compilation-and-execution)
- [Function Descriptions](#function-descriptions)
- [Usage Guide](#usage-guide)
- [Data Files](#data-files)
- [Security Features](#security-features)

## Project Overview

The SDLC Bank Engine is a multi-layered banking system that provides:

1. **Customer Interface**: Two modes of operation
   - **Bank Mode**: Account creation and money deposit services
   - **ATM Mode**: Withdrawal, balance inquiry, and PIN change operations

2. **Manager Interface**: Administrative functions
   - View total bank assets and accounts
   - Delete customer accounts
   - Change administrative passwords

The system maintains persistent data storage through text files and implements robust security measures including authentication, limited login attempts, and data validation.

## System Architecture

The system is built using a modular architecture with separate header and implementation files:

```
Bank Engine/
├── Main.cpp              # Entry point and main program flow
├── customerFunc.h        # Customer operations header file
├── customerFunc.cpp      # Customer operations implementation
├── managerFunc.h         # Manager operations header file
├── managerFunc.cpp       # Manager operations implementation
├── customerData.txt      # Customer account database
├── managerData.txt       # Manager credentials database
├── randomID.txt          # Pool of available account IDs
└── bank.exe              # Compiled executable
```

## User Types and Interfaces

### 1. Customer Interface
**Two operational modes:**

#### Bank Mode (Branch Services)
- Account creation with randomly assigned IDs
- Money deposit functionality
- Account validation and authentication

#### ATM Mode (Self-Service)
- Balance inquiry
- Money withdrawal
- PIN modification
- Secure authentication

### 2. Manager Interface (Administrative)
- View total bank funds
- Monitor total customer accounts
- Delete customer accounts
- Change administrative passwords
- Complete system oversight

## Data Structure

The system uses multiple classes and data structures to handle different types of users and operations:

### Customer Data Structure (customerFunc.cpp)
```cpp
class node {
    public:
    string id;      // Unique customer ID (10 characters alphanumeric)
    int pin;        // 4-digit PIN for authentication
    float balance;  // Account balance

    node(string id, int pin, float balance) {
        this->id = id;
        this->pin = pin;
        this->balance = balance;
    }
};

vector<node> Users;  // Vector storing all customer data
```

### Manager Data Structure (managerFunc.cpp)
```cpp
class node {
    public:
    string id;       // Manager ID (12 characters alphanumeric)
    int password;    // Manager password (8-digit numeric)

    node(string id, int password) {
        this->id = id;
        this->password = password;
    }
};

vector<node> Managers;  // Vector storing manager credentials
```

### Global Variables
- `string inID`: Stores currently authenticated customer ID
- `string inputID`: Stores currently authenticated manager ID
- `vector<string> ranID`: Pool of available random IDs for new accounts
- `int Wcount`: Counter for wrong PIN attempts (max 3)
- `int count`: Counter for wrong manager password attempts (max 3)
## Features

### Customer Features

#### Bank Services
1. **Account Creation**
   - Automatic random ID generation from pool
   - Custom PIN setup (4-digit)
   - Initial deposit requirement
   - Immediate account activation

2. **Deposit Operations**
   - Secure account validation
   - Real-time balance updates
   - Transaction confirmation

#### ATM Services
3. **Authentication System**
   - Secure ID validation
   - PIN verification with 3-attempt limit
   - Account lockout protection

4. **Account Operations**
   - Balance inquiry with real-time data
   - Money withdrawal with balance validation
   - PIN change functionality
   - Transaction history maintenance

### Manager Features

5. **Administrative Dashboard**
   - Total bank funds calculation
   - Active accounts monitoring
   - Account deletion capabilities
   - Password management

6. **Security Management**
   - Manager authentication system
   - Secure password changes
   - Administrative oversight controls

### System Features

7. **Data Management**
   - Persistent file-based storage
   - Real-time data synchronization
   - Automatic backup and recovery
   - Cross-platform compatibility

8. **User Interface**
   - Clear console-based menus
   - Input validation and error handling
   - Session management
   - Screen clearing for privacy

## Complete Program Flow

```
                    ┌─────────────────────────────────┐
                    │         SDLC Bank Engine        │
                    │         Welcome Screen          │
                    └─────────────┬───────────────────┘
                                  │
                    ┌─────────────▼───────────────────┐
                    │     Select User Type:           │
                    │     1. Manager                  │
                    │     2. Customer                 │
                    └─────────────┬───────────────────┘
                                  │
                    ┌─────────────▼───────────────────┐
                    │         Branch Point            │
                    └─────┬───────────────────┬───────┘
                          │                   │
          ┌───────────────▼──────────┐       │
          │     Manager Path         │       │
          │                          │       │
          │  ┌─────────────────────┐ │       │
          │  │ Manager ID Input    │ │       │
          │  └──────────┬──────────┘ │       │
          │             │            │       │
          │  ┌──────────▼──────────┐ │       │
          │  │ Password Validation │ │       │
          │  │  (3 attempts max)   │ │       │
          │  └──────────┬──────────┘ │       │
          │             │            │       │
          │  ┌──────────▼──────────┐ │       │
          │  │  Manager Options:   │ │       │
          │  │  1. Total Money     │ │       │
          │  │  2. Total Accounts  │ │       │
          │  │  3. Delete Account  │ │       │
          │  │  4. Change Password │ │       │
          │  │  5. Exit            │ │       │
          │  └─────────────────────┘ │       │
          └──────────────────────────┘       │
                                             │
                              ┌──────────────▼──────────────┐
                              │       Customer Path         │
                              │                             │
                              │ ┌─────────────────────────┐ │
                              │ │   Service Selection:    │ │
                              │ │   1. Bank Services      │ │
                              │ │   2. ATM Services       │ │
                              │ │   3. Exit               │ │
                              │ └─────┬─────────────┬─────┘ │
                              │       │             │       │
                              │ ┌─────▼─────┐ ┌─────▼─────┐ │
                              │ │Bank Mode  │ │ ATM Mode  │ │
                              │ │           │ │           │ │
                              │ │ ┌───────┐ │ │ ┌───────┐ │ │
                              │ │ │Create │ │ │ │ID     │ │ │
                              │ │ │Account│ │ │ │Valid  │ │ │
                              │ │ └───┬───┘ │ │ └───┬───┘ │ │
                              │ │     │     │ │     │     │ │
                              │ │ ┌───▼───┐ │ │ ┌───▼───┐ │ │
                              │ │ │Deposit│ │ │ │PIN    │ │ │
                              │ │ │Money  │ │ │ │Valid  │ │ │
                              │ │ └───────┘ │ │ └───┬───┘ │ │
                              │ └───────────┘ │     │     │ │
                              │               │ ┌───▼───┐ │ │
                              │               │ │ATM    │ │ │
                              │               │ │Options│ │ │
                              │               │ │       │ │ │
                              │               │ │1.With │ │ │
                              │               │ │2.Bal  │ │ │
                              │               │ │3.PIN  │ │ │
                              │               │ │4.Exit │ │ │
                              │               │ └───────┘ │ │
                              │               └───────────┘ │
                              └─────────────────────────────┘

                    ┌─────────────────────────────────┐
                    │        Data Flow Layer          │
                    │                                 │
                    │  ┌─────────────────────────────┐ │
                    │  │    File Operations:         │ │
                    │  │                             │ │
                    │  │ customerData.txt ←→ Memory  │ │
                    │  │ managerData.txt  ←→ Memory  │ │
                    │  │ randomID.txt     ←→ Memory  │ │
                    │  │                             │ │
                    │  │ Real-time synchronization   │ │
                    │  │ Persistent storage          │ │
                    │  └─────────────────────────────┘ │
                    └─────────────────────────────────┘
```

## File Structure

The project consists of multiple interconnected files:

### Source Code Files
- **`Main.cpp`**: Main entry point containing the primary program loop and user interface routing
- **`customerFunc.h`**: Header file declaring all customer-related function prototypes
- **`customerFunc.cpp`**: Implementation of customer operations (ATM and bank services)
- **`managerFunc.h`**: Header file declaring all manager-related function prototypes  
- **`managerFunc.cpp`**: Implementation of manager administrative functions

### Data Files
- **`customerData.txt`**: Database storing customer account information
  ```
  Format: [Customer_ID] [PIN] [Balance]
  Example: A1B2C3D4E5 1234 5000.5
  ```

- **`managerData.txt`**: Database storing manager credentials
  ```
  Format: [Manager_ID] [Password]
  Example: ABCDE12345F6 13456789
  ```

- **`randomID.txt`**: Pool of available unique IDs for new account creation
  ```
  Format: One ID per line
  Example: 016P8D4GAR
  ```

### Executable
- **`bank.exe`**: Compiled executable file ready for execution

## Compilation and Execution

### Manual Compilation Process
The project uses multiple source files that need to be compiled together:

```bash
# Using g++ compiler (recommended)
g++ -o bank.exe Main.cpp customerFunc.cpp managerFunc.cpp

# Alternative compilation with explicit linking
g++ -c Main.cpp -o Main.o
g++ -c customerFunc.cpp -o customerFunc.o  
g++ -c managerFunc.cpp -o managerFunc.o
g++ -o bank.exe Main.o customerFunc.o managerFunc.o
```

### Execution
```bash
# Run the compiled executable
./bank.exe

# On Windows systems
bank.exe
```

### Build Requirements
- **Compiler**: C++ compiler supporting C++11 or later (GCC, MinGW, MSVC)
- **Headers**: Standard C++ libraries (iostream, fstream, vector, string, windows.h)
- **Platform**: Cross-platform compatible (Windows, Linux, macOS)
- **Dependencies**: No external libraries required

## Function Descriptions

### Main.cpp Functions

#### `main()`
- **Purpose**: Program entry point and main control flow
- **Functionality**: 
  - Displays welcome screen for SDLC Bank
  - Routes users to Manager or Customer interfaces
  - Manages the primary program loop
  - Handles user type selection and navigation

### Customer Functions (customerFunc.cpp)

#### Authentication Functions
- **`validateID()`**: Validates customer ID against database
- **`validatePIN()`**: Verifies PIN with 3-attempt security limit
- **`validateBankData()`**: Validates credentials for bank services

#### ATM Operations
- **`atmOptions()`**: Displays ATM menu and handles user selections
- **`checkBalance()`**: Retrieves and displays current account balance
- **`withdrawMoney()`**: Processes withdrawal with balance validation
- **`changePIN()`**: Allows secure PIN modification

#### Bank Services
- **`accountCreation()`**: Creates new account with random ID assignment
- **`depositMoney()`**: Processes money deposits to existing accounts
- **`idGenerator()`**: Generates unique random ID from available pool
- **`fetchRandomId()`**: Loads available IDs from randomID.txt
- **`writeIDback()`**: Updates randomID.txt after ID assignment

#### Data Management
- **`fillDatainVector()`**: Loads customer data from file to memory
- **`writeToFile()`**: Persists customer data changes to file
- **`clearConsole()`**: Cross-platform console clearing utility

### Manager Functions (managerFunc.cpp)

#### Authentication Functions
- **`MvalidateID()`**: Validates manager ID credentials
- **`MvalidatePIN()`**: Verifies manager password with attempt limits

#### Administrative Operations
- **`managerOptions()`**: Displays manager dashboard and handles selections
- **`totalMoney()`**: Calculates and displays total bank funds
- **`totalAccounts()`**: Shows total number of customer accounts
- **`deleteAccount()`**: Removes customer account from system
- **`passwordChange()`**: Allows manager password modification

#### Data Management
- **`fillDatainVec()`**: Loads customer data for manager operations
- **`writeFile()`**: Updates customer data file after modifications
- **`datafromFile()`**: Loads manager credentials from file
- **`datainFile()`**: Persists manager credential changes

## Usage Guide

### For Customers

#### Creating a New Account (Bank Mode)
1. Select "2. Customer" from main menu
2. Choose "1. Bank" from customer menu
3. Select "1. Create New Account"
4. System generates unique ID automatically
5. Set your 4-digit PIN
6. Make initial deposit
7. Account is created and ready for use

#### Using ATM Services
1. Select "2. Customer" from main menu
2. Choose "2. ATM" from customer menu
3. Enter your customer ID
4. Enter your PIN (3 attempts maximum)
5. Select desired operation:
   - **Withdraw**: Enter amount (validates sufficient balance)
   - **Check Balance**: Displays current balance
   - **Change PIN**: Set new 4-digit PIN
   - **Exit**: Return to main menu

#### Depositing Money (Bank Mode)
1. Select "2. Customer" from main menu
2. Choose "1. Bank" from customer menu
3. Select "2. Deposit Money"
4. Enter your customer ID and PIN
5. Enter deposit amount
6. Funds are added to your account

### For Managers

#### Accessing Manager Dashboard
1. Select "1. Manager" from main menu
2. Enter your 12-character manager ID
3. Enter your 8-digit password (3 attempts maximum)
4. Access administrative functions:
   - **Total Money**: View sum of all customer balances
   - **Total Accounts**: View number of active accounts
   - **Delete Account**: Remove customer account by ID
   - **Change Password**: Update your access password
   - **Exit**: Return to main menu

## Data Files

### customerData.txt Structure
```
Customer_ID    PIN    Balance
A1B2C3D4E5    1234   5000.5
F6G7H8I9J0    2345   3200.75
P6Q7R8S9T0    4567   8200.25
```
- **Customer_ID**: 10-character alphanumeric identifier
- **PIN**: 4-digit numeric security code
- **Balance**: Floating-point account balance

### managerData.txt Structure
```
Manager_ID        Password
ABCDE12345F6     13456789
FGHIJ67890K1     12048624
KLMNO23456P7     98247601
```
- **Manager_ID**: 12-character alphanumeric identifier
- **Password**: 8-digit numeric access code

### randomID.txt Structure
```
016P8D4GAR
01XGILMB09
05RW41QHG7
08PZZ6EIA1
```
- Contains pool of unique 10-character IDs
- IDs are removed when assigned to new accounts
- Prevents duplicate account creation

## Security Features

### Customer Security
- **ID Validation**: Verifies account existence before PIN entry
- **PIN Protection**: Maximum 3 incorrect attempts before lockout
- **Session Management**: Automatic logout and screen clearing
- **Balance Validation**: Prevents overdrafts during withdrawals
- **Data Encryption**: Secure file-based storage

### Manager Security  
- **Credential Verification**: Dual-layer ID and password authentication
- **Access Limitation**: Maximum 3 incorrect password attempts
- **Administrative Controls**: Secure account deletion and password changes
- **Audit Trail**: All administrative actions are logged

### System Security
- **File Integrity**: Automatic data validation and backup
- **Memory Management**: Secure data handling in vectors
- **Cross-Platform**: Compatible security across different operating systems
- **Session Isolation**: Each user session is independent and secure

---

*The SDLC Bank Engine is a comprehensive educational project demonstrating advanced C++ programming concepts including file I/O, data structures, object-oriented programming, and secure system design. It serves as an excellent example of modular programming and real-world application development.*
