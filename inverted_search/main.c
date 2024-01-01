/*
NAME:Madivleppa Dadigundi
DATE:30/12/2023
DESCRIPTION:inverted search
*/
int create_db;
#include "header.h"
#include <stdio_ext.h>
int main(int argc, char* argv[])
{
    file_node* head=NULL;//read and validation for the command line arguments

    read_and_validate_files(argc ,argv,&head); 
    file_node* temp=head;
   
   int flag=1;
   int opt;
   main_table* arr=malloc(27 * sizeof(main_table));//create main table
   for(int i=0;i<27;i++)//update the  main table link with NULL
   {
       arr[i].link=NULL;
   }

  while(flag)
  {
      //display the menu
     printf("\n1.Create Database\n2.Display Database\n3.Search Database\n4.Update Database\n5.Save Database\n6.clear screen\n7.exit");
     printf("\n Enter the option : ");
     __fpurge(stdin);
     scanf("%d",&opt);
     switch (opt)
     {
         case 1:
             create_database(arr,head);//function call for the create database
             break;
         case 2:
             display_database(arr); //function call for the display the database
             break;
         case 3:
             search_database(arr);//function call for seach the word
             break;
         case 4:
             update_database(arr,&head);//function call for the update the database
             break;
         case 5:
             save_database(arr);//save database
             break;
         case 6:
            CLR_SCREEN;//macro for clear the screen
             break;
         case 7:
             flag=0;
             break;
         default:
             printf("\nEnter the correct option!!");
     }
  }


    return 0;
}


