# JR Library Management System

![JR Library Logo](https://img.shields.io/badge/JR-Library-blue)
![C++](https://img.shields.io/badge/Language-C%2B%2B-orange)
![Version](https://img.shields.io/badge/Version-1.0.0-green)

A comprehensive library management system built in C++ that helps educational institutions manage their books and magazines efficiently. This system demonstrates fundamental programming concepts by implementing custom data structures and algorithms without relying on Standard Template Library containers.

## 📚 Features

- **User Authentication**
  - Admin and Customer login systems
  - User registration with password protection
  - Password reset functionality

- **Admin Management**
  - Admin account creation, editing, and deletion
  - Staff information management
  - Report generation

- **Book Management**
  - Add, edit, and delete books
  - View all, available, or borrowed books
  - Search books by ID, title, author, or year

- **Magazine Management**
  - Similar functionality as book management
  - Custom implementation of Bubble Sort for organizing magazines
  - Custom implementation of Binary Search for finding magazines

- **Borrowing & Returning**
  - Borrow books/magazines with due dates
  - Return processing
  - View borrowing history
  - Generate borrowing reports by month/year

## 🔍 Educational Purpose

This project is designed to demonstrate:

- Custom implementation of common algorithms (Bubble Sort, Binary Search)
- Custom implementation of data structures (linked lists)
- Object-Oriented Programming concepts with C++
- File I/O operations for data persistence
- Error handling without using exceptions

## 🛠️ Technical Requirements

The code is designed to follow these educational constraints:
- No use of STL containers like std::vector
- No use of built-in algorithm library functions
- Implementation of manual memory management
- Custom implementation of sorting/searching algorithms

## 🚀 Getting Started

### Prerequisites

- C++ compiler (GCC, Clang, or MSVC)
- Basic knowledge of command line interface

### Compilation

```bash
# Navigate to the project directory
cd Library_Management_System

# Compile the code
g++ -o library_system library_management_system.c++

# Run the program
./library_system
```

## 👥 User Guide

### Admin Interface

1. Log in with default credentials (admin/admin)
2. Manage books, magazines, and user accounts
3. Generate reports and view borrowed items

### Customer Interface

1. Register an account or log in
2. Browse available books and magazines
3. Borrow items with due dates
4. Return borrowed items
5. View borrowing history

## 🔒 Data Storage

The system uses text files to store data:
- admin.txt - Admin account information
- books.txt - Book inventory
- magazine.txt - Magazine inventory
- customer.txt - Customer account information
- borrowedBook.txt - Book borrowing records
- borrowedMagazines.txt - Magazine borrowing records
- review.txt - Book reviews

## 📝 Contributing

This project is developed for educational purposes. Contributions that enhance the learning experience or add new features while maintaining the educational constraints are welcome.

## 📄 License

This project is available for educational use.

## 📧 Contact

For questions or support, please contact: support@jrlibrary.example.com
