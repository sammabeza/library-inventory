#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_BOOKS 100
#define MAX_LENGTH 100

typedef struct
{
    char title[MAX_LENGTH];
    char author[MAX_LENGTH];
    int copies;
} book;

// function to clear input buffer
void clear_input_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// function to trim whitespace and convert to lowercase for comparison
void normalize_string(char *str, char *normalized)
{
    int i = 0, j = 0;

    // skip leading whitespace
    while (str[i] && isspace(str[i])) i++;

    // copy and convert to lowercase, removing extra spaces
    while (str[i])
    {
        if (isspace(str[i]))
        {
            // Add single space for word separation
            if (j > 0 && normalized[j-1] != ' ')
            {
                normalized[j++] = ' ';
            }
        }
        else
        {
            normalized[j++] = tolower(str[i]);
        }
        i++;
    }

    // remove trailing space
    if (j > 0 && normalized[j-1] == ' ') j--;
    normalized[j] = '\0';
}

// function to get valid number of books
int get_book_count(void)
{
    int num;
    while (true)
    {
        printf("How many books would you like to enter? ");
        if (scanf("%d", &num) == 1 && num > 0 && num <= MAX_BOOKS)
        {
            clear_input_buffer();
            return num;
        }
        else
        {
            printf("Please enter a valid number between 1 and %d.\n", MAX_BOOKS);
            clear_input_buffer();
        }
    }
}

// function to get book input with validation
bool get_book_info(char *title, char *author)
{
    printf("\nBook title: ");
    if (!fgets(title, MAX_LENGTH, stdin))
    {
        printf("Error reading title.\n");
        return false;
    }
    title[strcspn(title, "\n")] = 0; // Remove newline

    // check if title is empty
    if (strlen(title) == 0)
    {
        printf("Title cannot be empty.\n");
        return false;
    }

    printf("Author: ");
    if (!fgets(author, MAX_LENGTH, stdin))
    {
        printf("Error reading author.\n");
        return false;
    }
    author[strcspn(author, "\n")] = 0;

    // Check if author is empty
    if (strlen(author) == 0)
    {
        printf("Author cannot be empty.\n");
        return false;
    }

    return true;
}

// function to find existing book (case-insensitive)
int find_book(book *inventory, int count, const char *title, const char *author)
{
    char norm_title1[MAX_LENGTH], norm_author1[MAX_LENGTH];
    char norm_title2[MAX_LENGTH], norm_author2[MAX_LENGTH];

    normalize_string((char*)title, norm_title1);
    normalize_string((char*)author, norm_author1);

    for (int i = 0; i < count; i++)
    {
        normalize_string(inventory[i].title, norm_title2);
        normalize_string(inventory[i].author, norm_author2);

        if (strcmp(norm_title1, norm_title2) == 0 &&
            strcmp(norm_author1, norm_author2) == 0)
        {
            return i;
        }
    }
    return -1; // not found
}

// function to add or update book
void add_book(book *inventory, int *unique_count, const char *title, const char *author)
{
    int existing = find_book(inventory, *unique_count, title, author);

    if (existing != -1)
    {
        inventory[existing].copies++;
        printf("Added copy of '%s' by %s (now %d copies)\n",
               inventory[existing].title, inventory[existing].author,
               inventory[existing].copies);
    }
    else
    {
        strcpy(inventory[*unique_count].title, title);
        strcpy(inventory[*unique_count].author, author);
        inventory[*unique_count].copies = 1;
        (*unique_count)++;
        printf("Added new book: '%s' by %s\n", title, author);
    }
}

// function to display inventory with better formatting
void display_inventory(book *inventory, int count)
{
    printf("\n==================================================\n");
    printf("           INVENTORY SUMMARY\n");
    printf("==================================================\n");

    if (count == 0)
    {
        printf("No books in inventory.\n");
        return;
    }

    printf("%-30s %-20s %s\n", "Title", "Author", "Copies");
    printf("--------------------------------------------------\n");

    int total_books = 0;
    for (int i = 0; i < count; i++)
    {
        printf("%-30s %-20s %d\n",
               inventory[i].title,
               inventory[i].author,
               inventory[i].copies);
        total_books += inventory[i].copies;
    }

    printf("--------------------------------------------------\n");
    printf("Total unique books: %d\n", count);
    printf("Total book copies: %d\n", total_books);
    printf("==================================================\n");
}

// function to save inventory to file
void save_to_file(book *inventory, int count)
{
    FILE *file = fopen("book_inventory.txt", "w");
    if (file == NULL)
    {
        printf("Warning: Could not save to file.\n");
        return;
    }

    fprintf(file, "BOOK INVENTORY\n");
    fprintf(file, "==============\n\n");

    for (int i = 0; i < count; i++)
    {
        fprintf(file, "Title: %s\n", inventory[i].title);
        fprintf(file, "Author: %s\n", inventory[i].author);
        fprintf(file, "Copies: %d\n\n", inventory[i].copies);
    }

    fclose(file);
    printf("Inventory saved to 'book_inventory.txt'\n");
}

int main(void)
{
    book inventory[MAX_BOOKS];
    int unique_count = 0;

    printf("=== BOOK INVENTORY SYSTEM ===\n");

    int num = get_book_count();

    for (int i = 0; i < num; i++)
    {
        char title[MAX_LENGTH];
        char author[MAX_LENGTH];

        printf("\n--- Book %d of %d ---", i + 1, num);

        // Keep asking until valid input
        while (!get_book_info(title, author))
        {
            printf("Please try again.\n");
        }

        add_book(inventory, &unique_count, title, author);
    }

    display_inventory(inventory, unique_count);
    save_to_file(inventory, unique_count);

    return 0;
}
