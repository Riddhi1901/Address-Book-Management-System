#  Address Book Management System (C Project)

## 📌 Project Description
The Address Book Management System is a command-line application developed in C that allows users to store, manage, and organize contact details efficiently. The system supports adding, viewing, searching, editing, and deleting contacts using file handling for persistent storage.

## Features
- Add new contact (Name, Phone Number, Email)
- View all contacts
- Search contact by name or number
- Edit existing contact details
- Delete contact
- Data stored permanently using files

## 🛠️ Technologies Used
- C Programming
- Structures
- File Handling (Text/Binary Files)
- Pointers
- String Manipulation
- Functions

## 📊 How It Works
- Contacts are stored in a file using structures
- User interacts through a menu-driven interface
- Based on user input, operations like add, search, edit, or delete are performed
- File is updated dynamically to maintain latest data

## 🧾 Data Structure Used
```c
typedef struct
{
    char name[50];
    char phone[15];
    char email[50];
} Contact;
