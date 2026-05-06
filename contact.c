#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

//check whether entered phone is unique or not
int unique_phone(char temp[] , AddressBook *AddressBook)
{
    int i;
    for(i = 0; i < AddressBook->contactCount; i++)
    {
        if(strcmp(AddressBook->contacts[i].phone, temp) == 0)
        {
            printf("Enter a unique phone number, as number already exists\n");
            return 1;
        }
    }
    return 0;
}

//check whether entered email is unique or not
int unique_email(char temp[] , AddressBook *AddressBook)
{
    int i;
    for(i = 0; i < AddressBook->contactCount; i++)
    {
        if(strcmp(AddressBook->contacts[i].email, temp) == 0)
        {
            printf("Enter a unique email, as email already exists\n");
            return 1;
        }
    }
    return 0;
}

//validate whether user entering proper name or not
int validate_name(char temp[])
{
    int i = 0;

    while(temp[i] != '\0')
    {
        if(temp[i] >= 'a' && temp[i] <= 'z' || temp[i] >= 'A' && temp[i] <= 'Z' || temp[i] == ' ')
        {
            i++;
        }
        else
        {
            printf("Invalid name entered\n");
            return 1;

        }
    }

    return 0;

}

//validate whether user entering proper phone/mobile or not
int validate_mobile(char temp[])
{
    int i = 0;

    while(temp[i] != '\0')
    {
        if(temp[i] >= '0' && temp[i] <= '9' )
        {
            i++;
        }
        else
        {
            printf("Entered phone is invalid\n");
            return 1;

        }
    }
    if(i > 10 || i < 10)
    {
        printf("Entered phone is invalid\n");
            return 1;
    }

    return 0;

}

//validate whether user entering proper email or not
int validate_email(char temp[])
{
    int i = 0;
    char com[] = ".com";
    char target[] = "@";

    if(strstr(temp,com) == NULL)
    {
        printf("Entered mail is invalid, \".com\" is missing\n");
        return 1;
    }

    if(strstr(temp,target) == NULL)
    {
        printf("Entered mail is invalid, \"@\" is missing\n");
        return 1;
    }
    return 0;
}
void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    Contact dummy;
    int i, j;
    
    switch(sortCriteria)
    {
        case 1:
        printf("Sorted based on Name\n");
        //logic to sort and displayed based on name
        for (i = 0; i < addressBook->contactCount; i++)
        {
                for( j = 0; j < addressBook->contactCount-1; j++)
                {
                    if((strcmp(addressBook->contacts[j].name,addressBook->contacts[j+ 1].name))>0)
                    {
                        dummy = addressBook->contacts[j];
                        addressBook->contacts[j] = addressBook->contacts[j+1];
                        addressBook->contacts[j+1] = dummy; 
                    }
                }
        }


        break;


        case 2:
        printf("Sorted based on phone\n");
        //logic to sort and displayed based on phone

        for (i = 0; i < addressBook->contactCount; i++)
        {
                for( j = 0; j < addressBook->contactCount-1; j++)
                {
                    if((strcmp(addressBook->contacts[j].phone,addressBook->contacts[j+ 1].phone))>0)
                    {
                        dummy = addressBook->contacts[j];
                        addressBook->contacts[j] = addressBook->contacts[j+1];
                        addressBook->contacts[j+1] = dummy; 
                    }
                }
        }


        break;

        case 3:
        printf("Sorted based on email\n");
            //logic to sort and displayed based on email
        for (i = 0; i < addressBook->contactCount; i++)
        {
                for( j = 0; j < addressBook->contactCount-1; j++)
                {
                    if((strcmp(addressBook->contacts[j].email,addressBook->contacts[j+ 1].email))>0)
                    {
                        dummy = addressBook->contacts[j];
                        addressBook->contacts[j] = addressBook->contacts[j+1];
                        addressBook->contacts[j+1] = dummy; 
                    }
                }
        }


        break;

        default:
        printf("Selection criteria is invalid\n");
           

        return;
    }

    printf("_______________________________________________________________>\n");
    printf("INDEX\tNAME\t\tMOBILE NUMBER\t\tEMAIL\n");
    printf("_______________________________________________________________>\n");

    // Sort contacts based on the chosen criteria
    
    for (i = 0; i < addressBook->contactCount; i++)
    {
        printf("%d\t%s\t%s\t%s\n",i+1,addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }
    
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
   //populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    char temp[50];
    printf("Menu-> Create contat\n");
    printf("----------------------------------------------------->\n");
    //for check no is unique if not create contact
    do
    {
        /* code */
        printf("Enter a name\n");
        scanf(" %[^\n]",temp);
        getchar();
    } while (validate_name(temp));
    strcpy(addressBook->contacts[addressBook->contactCount].name,temp);
    
    //validate mobile and create a contact
    do
    {
        /* code */
        printf("Enter a phone\n");
        scanf("%s",temp);
        getchar();
    } while (validate_mobile(temp) | unique_phone(temp , addressBook)); // to avoid short circuting using bitwise or operator
    strcpy(addressBook->contacts[addressBook->contactCount].phone,temp);

    //for validate email and create contact
    do
    {
        /* code */
        printf("Enter a email\n");
        scanf("%s",temp);
        getchar();
    } while (validate_email(temp) | unique_email(temp , addressBook));// to avoid short circuting using bitwise or operator
    strcpy(addressBook->contacts[addressBook->contactCount].email,temp);

    printf("Creating contact sucessful\n");
    addressBook->contactCount++;
}

int searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    int option,count = 0;
    char temp[20];

    printf("Menu - Search Contact");
    printf("\nPress 1 for search by name\nPress 2 for search by phone\nPress 3 for search by email\n");

    scanf("%d",&option);
     getchar();
    switch (option)
    {
    case 1 :
        /* code */
        do
        {
            /* code */
         printf("Enter the name\n");
        scanf("%[^\n]",temp);
        getchar();
        } while (validate_name(temp));

        for(int i = 0; i < addressBook->contactCount; i++)
        {
            if(strcasestr(addressBook->contacts[i].name,temp) != NULL)
            {
                count++;
                printf("%d\t%s\t%s\t%s\n",i+1,addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
            }

            
        }

      
        if(count == 0)
            {
                printf("Contact not found\n");
                return 0;
            }
        
        break;
    case 2 :
        /* code */
        
         printf("Enter the phone\n");
        scanf("%[^\n]",temp);
        getchar();
        

        for(int i = 0; i < addressBook->contactCount; i++)
        {
            if(strcasestr(addressBook->contacts[i].phone,temp) != NULL)
            {
                count++;
                printf("%d\t%s\t%s\t%s\n",i+1,addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
            }
            
        }
        
        if(count == 0)
            {
                printf("Phone number not found\n");
                return 0;
            }
        break;

    case 3 :
        /* code */
        
         printf("Enter the email\n");
        scanf("%[^\n]",temp);
        getchar();
        

        for(int i = 0; i < addressBook->contactCount; i++)
        {
            if(strcasestr(addressBook->contacts[i].email,temp) != NULL)
            {
                count++;
                printf("%d\t%s\t%s\t%s\n",i+1,addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
            }
            
        }
   
        if(count == 0)
            {
                printf("email not found\n");
                return 0;
            }
        break;
        
    default:
        printf("Entered option is invalid");
            return 0;
        break;
    }
      return 1;
}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    int index,option;
    char var[50];
    printf("Menu------------Edit contact\n");
     if(!searchContact(addressBook)) 
     {
        return;
     }
    printf("Enter the index to edit---->\n");
    scanf("%d",&index);
    getchar();

    if(index < 0 || index > addressBook->contactCount)
    {
        printf("You have entered a invalid index\n");
        return;
    }
    edit:
    printf("1. Edit Name\t 2. Edit Phone\t 3.Edit Email\n");
    scanf("%d",&option);
    getchar();

    switch (option)
    {
         case 1 :
                do{
                printf("Enter the name to edit\n");
                scanf("%[^\n]",var);
                }while (validate_name(var));
                strcpy(addressBook->contacts[index-1].name,var);
                printf("Name edited successfully\n");
                break;
        case 2:
                do{
                printf("Enter the phone to edit\n");
                scanf("%s",var);
                }while (validate_mobile(var) || unique_phone(var,addressBook));
                strcpy(addressBook->contacts[index-1].phone,var);
                printf("Phone edited successfully\n");
                break;
        case 3:
                do{
                printf("Enter the email to edit\n");
                scanf("%s",var);
                }while (validate_email(var) || unique_email(var,addressBook));
                strcpy(addressBook->contacts[index-1].email,var);
                printf("Email edited successfully\n");
                break;
        default:
            {
            printf("Entered option is invalid\n");
            goto edit;
            } 
    }

}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
    int index, i;
    printf("Menu -- Delete Contact\n");

    if(! searchContact(addressBook)) 
    return;
     
    printf("Enter the index to edit---->    ");
    scanf("%d",&index);
    getchar();

    if(index < 0 || index > addressBook->contactCount)
    {
        printf("You have entered a invalid index\n");
        return;
    }

   for(i = index-1; i < addressBook->contactCount-1; i++)
   {
        addressBook->contacts[i] = addressBook->contacts[i+1];
   }

   addressBook->contactCount--;

   printf("Contact deleted successfully\n");
}
