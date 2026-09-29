#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    // Sort contacts based on the choosen criteria

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


void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    printf("Enter the name");
    scanf("[^\n]",addressbook->contacts[addressbook->contactcount].name);
   while( valid_name(addressbook->contacts[addressbook->contactcount].name));
    printf("Enter the phone number");
    scanf("[^\n]",addressbook->contacts[addressbook->contactcount].phone);
    valid_contact(addressbook->contacts[addressbook->contactcount].phone);
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
void valid_phone(char *phone)
{
    len=strlen(phone);
    if(len==10)
    {
        if(phone[0]>=6 && phone[0]<=9)
        {
            
        }
    }
    else
    {
        printf("Invalid number enter again")
    }
    
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
void validphone(char *phone)
{

}
