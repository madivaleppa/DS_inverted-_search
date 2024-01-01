#ifndef HEADER_H
#define HEADER_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
//macros
#define SUCCESS 0
#define FAILURE 1
#define FILE_EMPTY 2
#define LIST_EMPTY 3
#define LEN 255
#define CLR_SCREEN system("clear") // command for clearing the console

//structure declaration
typedef struct sub_node
{
    char f_name[LEN];
    int w_count;
    struct sub_node *link;
}sub_node;

typedef struct node
{
    char word[LEN];
    struct node *link;
    sub_node *sub_link;
    int f_count;
}main_node;

typedef struct file_node
{
    char f_name[LEN];
    struct file_node *link;
}file_node;

typedef struct main_table
{
    int index;
    main_node* link;
}main_table;

//function declarations read and validate
int read_and_validate_files(int argc ,char* argv[],file_node** head);
int insert_file_to_node(file_node** head,char* str);
int file_type(char* file);
int check_file_empty(FILE* fptr);

//end 

//create database function 

void create_database(main_table arr[],file_node* head);

//display database

void display_database(main_table arr[]);
void search_database(main_table arr[]);
void save_database(main_table arr[]);
void update_database(main_table arr[],file_node** head);
void check_for_cl_fname(char* str,file_node** head);

#endif

