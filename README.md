# Password Strength Analysis Tool 🔑⏱️
This project is a comprehensive toolset designed to demonstrate and analyze password strength from a security and computational perspective. It consists of a C++ program for calculating brute-force crack times and a set of helper scripts to automate the creation and analysis of test user passwords.

### 💡 Key Features
+ Brute-Force Time Estimation: A C++ program that accurately estimates the time required to brute-force a password of a given length and a specified hash rate.

+ Comprehensive Character Set: The strength analysis is based on a large character set of 96 characters, including uppercase, lowercase, digits, and special characters.

+ Automated Testing: A Bash script automates the creation of test users with progressively longer passwords and analyzes each one.

+ User Cleanup: A Python script is included to easily remove all test users and their home directories, ensuring a clean system after testing.

+ Educational Focus: Ideal for educational purposes to visually and computationally prove the importance of password length and complexity.

### ⚙️ Components
+ calculate.cpp - Password Strength Calculator: The core C++ program that takes a password length and a hash rate to calculate the total possible combinations and the estimated time to crack it.

+ hash.sh - Test User Creation Script: A Bash script that requires sudo privileges to create 10 test users with passwords of varying lengths and then analyzes their strength using calculate.cpp.

+ python_user_removel.py - Cleanup Script: A Python script to remove all the test users created by hash.sh.

### 🛠️ Prerequisites
1. A C++ compiler (like g++).

2. Bash for the shell script.

3. Python 3.x for the user removal script.

### 🏗️ How to Build
First, compile the C++ program from the terminal:

    g++ -o calculate calculate.cpp

### 🚀 Usage

**1. Brute-Force Time Estimation
**To calculate the crack time for a specific password length and hash rate, run the compiled C++ program

       ./calculate <password_length> <hashes_per_second>

**Example**:
To analyze a password of length 8 with a hash rate of 100 billion hashes per second:

    ./calculate 8 100000000000

**2. Automated Test User Creation
**To automatically create test users and analyze their passwords, use the Bash script with sudo privileges:

       sudo ./hash.sh <hashes_per_second>

**Example**:
To create test users and analyze them with a hash rate of 1 million hashes per second:

    sudo ./hash.sh 1000000

**3. Cleaning Up Test Users
**After testing, use the Python script to remove the users:

        python3 python_user_removel.py

### ⚠️ Security Considerations & Limitations
+ Plaintext Passwords: The hash.sh script displays the generated passwords in plaintext. This tool should only be used in a safe, controlled testing environment.

+ Brute-Force Assumption: The time estimations assume a pure, sequential brute-force attack and do not account for more sophisticated methods like dictionary attacks or common password patterns, which can significantly reduce the time needed to crack a password.

+ Constant Hash Rate: The calculations assume a constant hash rate without accounting for real-world factors like network latency, hardware limitations, or system throttling.
