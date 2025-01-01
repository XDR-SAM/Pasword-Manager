/*
 * Author: Sami
 * Email: [tdxfarhan@gmail.com]
 * Description:
 * This program is a simple yet functional Password Manager developed in C++.
 * It allows users to securely store, manage, and retrieve their account credentials 
 * with features such as:
 *   - Adding, viewing, searching, and deleting accounts.
 *   - Generating strong random passwords.
 *   - Encrypting and decrypting passwords using a basic Caesar cipher for security.
 *   - Exporting account data to an HTML file for easier readability.
 *
 * Core concepts demonstrated in this program:
 *   - File I/O operations for data persistence (passwords.txt and passwords.html).
 *   - Use of structures (struct) for data encapsulation.
 *   - Simple encryption and decryption techniques.
 *   - Dynamic memory handling with vectors for account management.
 *   - Utility functions for generating random passwords and formatting data.
 *
 * This project is designed to showcase practical applications of C++ programming
 * in solving real-world problems. It reflects my passion for software development
 * and serves as a stepping stone toward more advanced projects in the future.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

// Encrypt and decrypt passwords (simple Caesar cipher)
std::string encrypt(const std::string& password) {
    std::string encrypted = password;
    for (char& c : encrypted) c += 3; // Shift characters by 3
    return encrypted;
}

std::string decrypt(const std::string& password) {
    std::string decrypted = password;
    for (char& c : decrypted) c -= 3; // Shift characters back by 3
    return decrypted;
}

// Structure to store account details
struct Account {
    std::string website;
    std::string username;
    std::string password;
};

// Function prototypes
void addAccount();
void viewAccounts();
void searchAccount();
void deleteAccount();
void generatePassword();
void saveToHTML();

// Function to add a new account
void addAccount() {
    std::ofstream file("passwords.txt", std::ios::app); // Append mode
    if (!file) {
        std::cerr << "Error opening file.\n";
        return;
    }
    Account account;
    std::cout << "Enter website/app name: ";
    std::cin >> account.website;
    std::cout << "Enter username: ";
    std::cin >> account.username;
    std::cout << "Enter password: ";
    std::cin >> account.password;

    account.password = encrypt(account.password);

    file << account.website << " " << account.username << " " << account.password << "\n";
    file.close();
    std::cout << "Account saved successfully.\n";
}

// Function to view all accounts
void viewAccounts() {
    std::ifstream file("passwords.txt");
    if (!file) {
        std::cerr << "Error opening file.\n";
        return;
    }
    Account account;
    std::cout << std::setw(15) << "Website" << std::setw(15) << "Username" << std::setw(15) << "Password\n";
    std::cout << "---------------------------------------------------------\n";

    while (file >> account.website >> account.username >> account.password) {
        account.password = decrypt(account.password);
        std::cout << std::setw(15) << account.website << std::setw(15) << account.username << std::setw(15) << account.password << "\n";
    }
    file.close();
}

// Function to search for an account by website
void searchAccount() {
    std::ifstream file("passwords.txt");
    if (!file) {
        std::cerr << "Error opening file.\n";
        return;
    }
    std::string searchWebsite;
    Account account;
    bool found = false;

    std::cout << "Enter website/app name to search: ";
    std::cin >> searchWebsite;

    while (file >> account.website >> account.username >> account.password) {
        if (account.website == searchWebsite) {
            account.password = decrypt(account.password);
            std::cout << "Website: " << account.website << "\nUsername: " << account.username
                      << "\nPassword: " << account.password << "\n";
            found = true;
            break;
        }
    }
    if (!found) std::cout << "No account found for " << searchWebsite << ".\n";
    file.close();
}

// Function to delete an account
void deleteAccount() {
    std::ifstream file("passwords.txt");
    if (!file) {
        std::cerr << "Error opening file.\n";
        return;
    }
    std::vector<Account> accounts;
    Account account;
    std::string deleteWebsite;
    std::cout << "Enter website/app name to delete: ";
    std::cin >> deleteWebsite;

    bool deleted = false;
    while (file >> account.website >> account.username >> account.password) {
        if (account.website == deleteWebsite) {
            deleted = true;
            continue;
        }
        accounts.push_back(account);
    }
    file.close();

    if (deleted) {
        std::ofstream outFile("passwords.txt", std::ios::trunc);
        for (const auto& acc : accounts) {
            outFile << acc.website << " " << acc.username << " " << acc.password << "\n";
        }
        outFile.close();
        std::cout << "Account deleted successfully.\n";
    } else {
        std::cout << "No account found for " << deleteWebsite << ".\n";
    }
}

// Function to generate a random password
void generatePassword() {
    const std::string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";
    std::string password;
    int length;

    std::cout << "Enter desired password length: ";
    std::cin >> length;

    srand(time(0)); // Seed for randomness
    for (int i = 0; i < length; i++) {
        password += chars[rand() % chars.size()];
    }
    std::cout << "Generated Password: " << password << "\n";
}

// Function to save passwords in HTML format
void saveToHTML() {
    std::ifstream file("passwords.txt");
    if (!file) {
        std::cerr << "Error opening file.\n";
        return;
    }
    std::ofstream htmlFile("passwords.html");
    if (!htmlFile) {
        std::cerr << "Error creating HTML file.\n";
        return;
    }
    htmlFile << "<html><body><table border='1'><tr><th>Website</th><th>Username</th><th>Password</th></tr>\n";
    Account account;
    while (file >> account.website >> account.username >> account.password) {
        account.password = decrypt(account.password);
        htmlFile << "<tr><td>" << account.website << "</td><td>" << account.username << "</td><td>" << account.password << "</td></tr>\n";
    }
    htmlFile << "</table></body></html>";
    file.close();
    htmlFile.close();
    std::cout << "Passwords saved to passwords.html.\n";
}

// Main menu
int main() {
    int choice;
    do {
        std::cout << "\nPassword Manager\n";
        std::cout << "1. Add Account\n";
        std::cout << "2. View Accounts\n";
        std::cout << "3. Search Account\n";
        std::cout << "4. Delete Account\n";
        std::cout << "5. Generate Password\n";
        std::cout << "6. Save to HTML\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addAccount();
                break;
            case 2:
                viewAccounts();
                break;
            case 3:
                searchAccount();
                break;
            case 4:
                deleteAccount();
                break;
            case 5:
                generatePassword();
                break;
            case 6:
                saveToHTML();
                break;
            case 7:
                std::cout << "Exiting Password Manager.\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);
    return 0;
}
