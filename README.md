# 📚 Library Management System  

A simple **C-based Library Management System** developed for the **CSE115L.8 Programming Language I Lab** project.  
This system allows users to manage a collection of books by adding, searching, editing, deleting, and viewing book records.  
The data is stored in a binary file (`Books.bin`) to ensure persistence.  

---

## 📝 Project Proposal  

The **Library Management System** is designed to digitalize book management. It provides a menu-driven interface where users can:  
- Add new books with details (ID, Name, Author, Language, Category, Quantity, Pages, Rack No).  
- Search and view book records quickly.  
- Update or delete book records when necessary.  
This project was developed by:  
- **Md. Rakibul Hasan**  
- **Safat Ahmed Chowdhury**  
- **Md. Rokib Hasan Oli**  

---

## 🎯 Goal of the Project  

The goal of this project is to create a simple yet effective **book management solution** that helps organize library operations.  
It aims to allow librarians or users to manage records efficiently without needing a database, using only file handling in C.  
This reduces manual errors, improves accessibility, and provides a structured way to keep track of books.  

---

## 📖 User Manual  

1. **Run the Program**  
   - Compile using:  
     ```bash
     gcc main.c -o library.exe
     ./library.exe
     ```  

2. **Main Menu Options**  
   - `1` → Search Book (by ID)  
   - `2` → View Book List (all books with details)  
   - `3` → Add Book (enter new book information)  
   - `4` → Edit Book Record (update existing book details)  
   - `5` → Delete Book (remove a book from records)  
   - `6` → Exit Program  

3. **Data Storage**  
   - All records are stored in `Books.bin`.  
   - The program creates this file automatically if not present.  

---

## ⚙️ Features  

1. **Add Books** – Adds new books with detailed information.  
   - Implemented using `fwrite()` with `Books.bin`.  
2. **View Book List** – Displays all books and total quantity.  
   - Implemented using `fread()` in a loop.  
3. **Search Books** – Find specific books by ID.  
   - Implemented by scanning through `Books.bin`.  
4. **Edit Book Record** – Modify details of an existing book.  
   - Uses `fseek()` to update binary file at correct position.  
5. **Delete Books** – Removes a record and rewrites remaining data.  
   - Achieved using a temporary file and `rename()`.  

---

## 👥 Task Distribution  

- **Md. Rakibul Hasan** → Implemented **Add** and **Edit** book functions.  
- **Safat Ahmed Chowdhury** → Implemented **Search** and **Delete** functions.  
- **Md. Rokib Hasan Oli** → Implemented **View Book List** and handled **file operations**.  

---

## 🛠️ Tech Stack  

- **Language**: C  
- **Libraries**:  
  - `stdio.h` → Standard I/O operations  
  - `stdlib.h` → System functions  
  - `windows.h` → `Sleep()` and console handling (for Windows only)  
- **Data Storage**: Binary file (`Books.bin`)  

---

## 🏆 Academic Context  

This project was developed as part of the **CSE115L.8 Programming Language I Lab** course requirement to demonstrate:  
- File handling (`fopen`, `fread`, `fwrite`, `fseek`, `rename`, `remove`)  
- Structures in C (`struct books_info`)  
- Menu-driven programming  
- Practical problem-solving with C  

---

## 📌 Notes  

- Works on **Windows** (due to `windows.h`).  
- On Linux/Mac:  
  - Replace `Sleep()` with `sleep()`  
  - Remove `windows.h`  

---
