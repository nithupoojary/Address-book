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
}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
   
}
