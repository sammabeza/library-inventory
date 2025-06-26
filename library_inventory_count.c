#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BOOKS 100
#define MAX_LENGTH 100

typedef struct
{
    char title[MAX_LENGTH];
    char author[MAX_LENGTH];
    int copies;
} book;

int main(void)
{
    int num;
    printf("How many books would you like to enter? ");
    scanf("%d", &num);

    book inventory[MAX_BOOKS];
    int unique_count = 0;

    for (int i = 0; i < num; i++)
    {
        char title[MAX_LENGTH];
        char author[MAX_LENGTH];

        printf("\nBook title: ");
        getchar(); // Clear leftover newline
        fgets(title, sizeof(title), stdin);
        title[strcspn(title, "\n")] = 0; // Remove newline

        printf("Author: ");
        fgets(author, sizeof(author), stdin);
        author[strcspn(author, "\n")] = 0;

        bool found = false;

        for (int j = 0; j < unique_count; j++)
        {
            if (strcmp(inventory[j].title, title) == 0 &&
                strcmp(inventory[j].author, author) == 0)
            {
                inventory[j].copies++;
                found = true;
                break;
            }
        }

        if (!found)
        {
            strcpy(inventory[unique_count].title, title);
            strcpy(inventory[unique_count].author, author);
            inventory[unique_count].copies = 1;
            unique_count++;
        }
    }

    printf("\n===== INVENTORY SUMMARY =====\n");
    for (int k = 0; k < unique_count; k++)
    {
        printf("%s by %s - %d copies\n",
               inventory[k].title,
               inventory[k].author,
               inventory[k].copies);
    }

    return 0;
}