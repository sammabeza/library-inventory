# Library Inventory Tracker

## Description
This is an enhanced library inventory management system that allows librarians to efficiently track books, authors, and copy counts. The program features intelligent duplicate detection, robust input validation, and professional formatting for inventory management.

## Features

### Core Functionality
- **Smart Book Entry**: Add books by entering title and author
- **Intelligent Duplicate Detection**: Automatically identifies duplicate books (case-insensitive)
- **Copy Counting**: Tracks multiple copies of the same book
- **Professional Display**: Formatted inventory summary with totals

### Enhanced Features (v2.0)
- **Input Validation**: Prevents empty entries and invalid data
- **Case-Insensitive Matching**: "Harry Potter" and "harry potter" are treated as the same book
- **Whitespace Handling**: Ignores extra spaces in book titles and authors
- **File Output**: Automatically saves inventory to `book_inventory.txt`
- **Progress Tracking**: Shows current progress during data entry
- **Error Handling**: Graceful handling of input errors and file operations
- **Statistical Summary**: Displays total unique books and total copies

## How to Compile and Run

```bash
gcc -o library_inventory library2.c
./library_inventory
```

## Example Usage

```
=== BOOK INVENTORY SYSTEM ===
How many books would you like to enter? 4

--- Book 1 of 4 ---
Book title: The Great Gatsby
Author: F. Scott Fitzgerald
Added new book: 'The Great Gatsby' by F. Scott Fitzgerald

--- Book 2 of 4 ---
Book title: 1984
Author: George Orwell
Added new book: '1984' by George Orwell

--- Book 3 of 4 ---
Book title: the great gatsby
Author: f. scott fitzgerald
Added copy of 'The Great Gatsby' by F. Scott Fitzgerald (now 2 copies)

--- Book 4 of 4 ---
Book title: To Kill a Mockingbird
Author: Harper Lee
Added new book: 'To Kill a Mockingbird' by Harper Lee

==================================================
           INVENTORY SUMMARY
==================================================
Title                          Author               Copies
--------------------------------------------------
The Great Gatsby               F. Scott Fitzgerald  2
1984                           George Orwell        1
To Kill a Mockingbird          Harper Lee           1
--------------------------------------------------
Total unique books: 3
Total book copies: 4
==================================================
Inventory saved to 'book_inventory.txt'
```

## File Output
The program creates a `book_inventory.txt` file containing a formatted list of all books for record-keeping and sharing.

## Technical Improvements

### Code Structure
- **Modular Design**: Code organized into logical functions
- **Input Validation**: Comprehensive error checking and user-friendly prompts
- **Memory Safety**: Proper string handling and bounds checking
- **Professional Formatting**: Clean, readable output with proper alignment

### Key Functions
- `get_book_count()`: Validates and retrieves number of books to enter
- `get_book_info()`: Handles book data input with validation
- `find_book()`: Intelligent duplicate detection with case-insensitive matching
- `add_book()`: Manages adding new books or updating existing copies
- `display_inventory()`: Professional formatting of inventory data
- `save_to_file()`: Persistent storage of inventory data

## Learning Concepts Demonstrated

- **Structs and Arrays**: Efficient data organization
- **String Manipulation**: Case conversion, whitespace handling, comparison
- **File I/O**: Reading from and writing to files
- **Input Validation**: Robust user input handling
- **Modular Programming**: Function-based code organization
- **Error Handling**: Graceful failure management
- **Boolean Logic**: Duplicate detection algorithms

## Future Enhancements

### Planned Features
- **Search Functionality**: Find books by title or author
- **Edit/Delete Options**: Modify or remove existing entries
- **Load from File**: Import existing inventory data
- **Sort Options**: Organize by title, author, or copy count
- **CSV Export**: Export data for spreadsheet applications
- **Book Details**: Add ISBN, genre, publication year
- **Low Stock Alerts**: Notification when copies are running low

### Advanced Features (Future Versions)
- **Database Integration**: SQLite support for larger libraries
- **Barcode Scanning**: Integration with barcode readers
- **User Management**: Track who borrowed which books
- **Due Date Tracking**: Library checkout system
- **Reports**: Generate usage statistics and reports

## Version History

- **v1.0**: Basic inventory tracking with duplicate detection
- **v2.0**: Enhanced input validation, file output, case-insensitive matching, professional formatting

---

*This project demonstrates progression from basic C programming to more sophisticated software design principles, making it suitable for real-world library management scenarios.*
=======
This is a simple program designed to log and track books in a library. It allows users to input book titles, authors, and automatically counts how many copies of each book exist. It can detect duplicate entries and update the inventory accordingly.

## Features
- Add books to the inventory by entering the title and author.
- Automatically count the number of copies of each book, updating the inventory if a duplicate entry is found.
- Display the book inventory summary with titles, authors, and the number of copies.

## Example Output

```
How many books would you like to enter? 3
Book title: Wuthering Heights
Author: Emily Brontë

Book title: Jane Eyre
Author: Charlotte Brontë

Book title: Wuthering Heights
Author: Emily Brontë

===== INVENTORY SUMMARY =====
Wuthering Heights by Emily Brontë - 2 copies
Jane Eyre by Charlotte Brontë - 1 copy
```
