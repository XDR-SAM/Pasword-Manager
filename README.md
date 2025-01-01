# Password Manager in C++

## Description
This project is a **Password Manager** application developed in C++. It provides a simple and effective way to manage account credentials securely. The program supports functionalities such as adding, viewing, searching, and deleting account records. Additionally, it includes a random password generator and the ability to export stored credentials to an HTML file.

---

## How It Works

### Features
1. **Add Account**: Stores website/app name, username, and an encrypted password in a file.
2. **View Accounts**: Displays all stored accounts with decrypted passwords.
3. **Search Account**: Searches for account details by the website/app name.
4. **Delete Account**: Deletes an account by its website/app name.
5. **Generate Password**: Creates a strong, random password of the desired length.
6. **Save to HTML**: Exports account details into a formatted HTML file for better readability.

### Technology Used
- **Caesar Cipher**: Encrypts and decrypts passwords for basic security.
- **File Handling**: Uses text files to store account data persistently.
- **HTML Export**: Generates a styled table for account details in an HTML file.

### Prerequisites
- A C++ IDE environment such as **Visual Studio**, **Code::Blocks**, or **CLion**.
- The project uses standard C++ libraries and doesn't require external dependencies.

### Steps to Run
1. Clone or download the project files to your system.
2. Open the project in your preferred IDE.
3. Compile the code. Ensure your IDE supports C++17 or later.
4. Run the program and follow the interactive menu.

---

## Author Information

**Author**: Sami  
**Email**: [tdxfarhan@gmail.com]  

This project reflects my passion for software development and serves as a practical demonstration of core C++ features. It is a beginner-friendly application that combines utility with learning.

---

## Notes
- Ensure the `passwords.txt` file is in the same directory as the executable.
- The program uses a simple Caesar cipher for encryption, which is not recommended for sensitive data in real-world scenarios.
- Exported HTML files can be opened with any modern web browser.

---

## License
This project is open-source and available for educational purposes. Feel free to modify and expand it!
