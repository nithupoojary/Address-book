#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
//#include "populate.h"
void listContacts(AddressBook *addressBook) 
{
    // Sort contacts based on the choosen criteria
    int i, j;
    Contact temp;
    for(i = 0; i < addressBook->contactCount - 1; i++)
    {
        for(j = 0; j < addressBook->contactCount - 1 - i; j++)
        {
            if(strcmp(addressBook->contacts[j].name,
                      addressBook->contacts[j + 1].name) > 0)
            {
                temp = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j + 1];
                addressBook->contacts[j + 1] = temp;
            }

            else if(strcmp(addressBook->contacts[j].name,
                           addressBook->contacts[j + 1].name) == 0)
            {
                if(strcmp(addressBook->contacts[j].phone,
                          addressBook->contacts[j + 1].phone) > 0)
                {
                    temp = addressBook->contacts[j];
                    addressBook->contacts[j] = addressBook->contacts[j + 1];
                    addressBook->contacts[j + 1] = temp;
                }

                else if(strcmp(addressBook->contacts[j].phone,
                               addressBook->contacts[j + 1].phone) == 0)
                {
                    if(strcmp(addressBook->contacts[j].email,
                              addressBook->contacts[j + 1].email) > 0)
                    {
                        temp = addressBook->contacts[j];
                        addressBook->contacts[j] = addressBook->contacts[j + 1];
                        addressBook->contacts[j + 1] = temp;
                    }
                }
            }
        }
    }
    printf("\n--- Contact List ---\n");

    for(i = 0; i < addressBook->contactCount; i++)
    {
        printf("Name  : %s\n", addressBook->contacts[i].name);
        printf("Phone : %s\n", addressBook->contacts[i].phone);
        printf("Email : %s\n\n", addressBook->contacts[i].email);
    }
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    
    // Load contacts from file during initialization (After files)
    //loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}
int valid_name(char *name);
int valid_phone(char *phone);
int valid_email(char *email);
void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    do{
    printf("Enter the name:");
    scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
    }
   while(valid_name(addressBook->contacts[addressBook->contactCount].name)==0);
   do{
    printf("Enter the phone number:\n");
    scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].phone);
   }
   while(valid_phone(addressBook->contacts[addressBook->contactCount].phone)==0);
   do{
    printf("Enter the email:\n");
    scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].email);
   }
   while(valid_email(addressBook->contacts[addressBook->contactCount].email)==0);
   addressBook->contactCount++;
 printf("Contact created successfully\n");
}
int valid_name(char *name)
{
    int length=strlen(name);
    if(length<2)
    {
        printf("Please enter minimum two character");
        return 0;
    }
    else
    {
        return 1;
    }
}
int valid_phone(char *phone)
{
    int len = strlen(phone);

    if(len!=10)
    {
        printf("Invalid number.\n");
        return 0;
    }
        if(phone[0] < '6' || phone[0]>'9')
        {
             printf("Invalid number.\n");
             return 0;
        }
        printf("Valid number\n");
        return 1;
    }
int valid_email(char *email)
 {
    int i=0;
    int at=0;
    int dot=0;
    while(email[i]!='\0')
    {
        if(email[i]>='A' && email[i]<='Z')
        {
            printf("Invalid email.Add again");
            return 0;
        }
        //
        if(email[i]=='@')
        {
         at++;  
         if(i==0)
         {
            printf("Invalid email.Enter the email again");
            return 0;
         } 
        }
        //
        if(email[i]=='.')
        {
            dot=1;
        }
        i++;
    }
     if(at!=1)
     {
        printf("Invalid enail.Enter the email again");
        return 0;
     }
    if(dot==0)
    {
        printf("Invalid email.Enter the email again");
        return 0;
    }
    int len = strlen(email);
if(len < 4 ||
   email[len - 4] != '.' ||
   email[len - 3] != 'c' ||
   email[len - 2] != 'o' ||
   email[len - 1] != 'm')
{
    printf("Invalid email.\n");
    return 0;
}
return 1;
 }
void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    int choice;
    char search[50];
    int found = 0;

    printf("\nSearch Contact\n");
    printf("1. Search by name\n");
    printf("2. Search by phone\n");
    printf("3. Search by email\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if(choice == 1)
    {
        printf("Enter the name: ");
        scanf(" %[^\n]", search);

        for(int i = 0; i < addressBook->contactCount; i++)
        {
            if(strcmp(addressBook->contacts[i].name, search) == 0)
            {
                printf("\nName  : %s\n", addressBook->contacts[i].name);
                printf("Phone : %s\n", addressBook->contacts[i].phone);
                printf("Email : %s\n", addressBook->contacts[i].email);

                found = 1;
            }
        }
    }

    else if(choice == 2)
    {
        printf("Enter the phone number: ");
        scanf(" %[^\n]", search);

        for(int i = 0; i < addressBook->contactCount; i++)
        {
            if(strcmp(addressBook->contacts[i].phone, search) == 0)
            {
                printf("\nName  : %s\n", addressBook->contacts[i].name);
                printf("Phone : %s\n", addressBook->contacts[i].phone);
                printf("Email : %s\n", addressBook->contacts[i].email);

                found = 1;
            }
        }
    }

    else if(choice == 3)
    {
        printf("Enter the email: ");
        scanf(" %[^\n]", search);

        for(int i = 0; i < addressBook->contactCount; i++)
        {
            if(strcmp(addressBook->contacts[i].email, search) == 0)
            {
                printf("\nName  : %s\n", addressBook->contacts[i].name);
                printf("Phone : %s\n", addressBook->contacts[i].phone);
                printf("Email : %s\n", addressBook->contacts[i].email);

                found = 1;
            }
        }
    }

    else
    {
        printf("Invalid choice\n");
        return;
    }

    if(found == 0)
    {
        printf("\nContact not found\n");
    }
}


void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    int choice;
    int editChoice;

    printf("\n--- Contacts ---\n");

    for(int i = 0; i < addressBook->contactCount; i++)
    {
        printf("%d. %s  %s  %s\n",
               i + 1,
               addressBook->contacts[i].name,
               addressBook->contacts[i].phone,
               addressBook->contacts[i].email);
    }

    printf("\nEnter contact number to edit: ");
    scanf("%d", &choice);

    if(choice < 1 || choice > addressBook->contactCount)
    {
        printf("Invalid contact number\n");
        return;
    }

    int index = choice - 1;

    printf("\nWhat do you want to edit?\n");
    printf("1. Name\n");
    printf("2. Phone\n");
    printf("3. Email\n");
    printf("Enter your choice: ");
    scanf("%d", &editChoice);

    if(editChoice == 1)
    {
        do
        {
            printf("Enter new name: ");
            scanf(" %[^\n]", addressBook->contacts[index].name);

        } while(valid_name(addressBook->contacts[index].name) == 0);
    }
    else if(editChoice == 2)
    {
        do
        {
            printf("Enter new phone number: ");
            scanf(" %[^\n]", addressBook->contacts[index].phone);

        } while(valid_phone(addressBook->contacts[index].phone) == 0);
    }
    else if(editChoice == 3)
    {
        do
        {
            printf("Enter new email: ");
            scanf(" %[^\n]", addressBook->contacts[index].email);

        } while(valid_email(addressBook->contacts[index].email) == 0);
    }
    else
    {
        printf("Invalid choice\n");
        return;
    }

    printf("\nContact updated successfully!\n");
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
    int choice;

    printf("\n--- Contacts ---\n");

    for(int i = 0; i < addressBook->contactCount; i++)
    {
        printf("%d. %s  %s  %s\n",
               i + 1,
               addressBook->contacts[i].name,
               addressBook->contacts[i].phone,
               addressBook->contacts[i].email);
    }

    printf("\nEnter contact number to delete: ");
    scanf("%d", &choice);

    if(choice < 1 || choice > addressBook->contactCount)
    {
        printf("Invalid contact number\n");
        return;
    }

    int index = choice - 1;

    for(int i = index; i < addressBook->contactCount - 1; i++)
    {
        addressBook->contacts[i] = addressBook->contacts[i + 1];
    }

    addressBook->contactCount--;

    printf("Contact deleted successfully\n");
}

