#include "header.h"

int read_and_validate_files(int argc ,char* argv[],file_node** head)
{
    FILE* fptr;
    for(int i=1;i<argc;i++)
    {
        if(file_type(argv[i])==SUCCESS)
        {
            fptr=fopen(argv[i],"r");
            if(fptr==NULL)
            {
                printf("\n%s file is not exist",argv[i]);
            }
            else
            {
                if(check_file_empty(fptr)==SUCCESS)
                {
                    if(insert_file_to_node(head,argv[i])==SUCCESS)
                    {
                        printf("\n %s added to list successfully",argv[i]);
                        fclose(fptr);
                    }
                }
                else
                {
                    printf("\n%s file is empty",argv[i]);
                }

            }

        }
        else
        {
            printf("\n%s is not .txt file",argv[i]);
        }
    }
   
    if(*head!=NULL)
    printf("\n read and validation of files success!!");
    return SUCCESS;
}
int file_type(char* file)
{
    char* str;
    str=strstr(file,".txt");
    if(str==NULL)
        return FAILURE;
    if(strcmp(str,".txt")==0)
    {
        return SUCCESS;
    }
}

int check_file_empty(FILE* fptr)
{
    fseek(fptr,0,SEEK_END);
    if(ftell(fptr))
    {
        return SUCCESS;
    }
    else
        return FILE_EMPTY;
}

int insert_file_to_node(file_node** head,char* str)
{
    file_node* new=malloc(sizeof(file_node));
    strcpy(new->f_name,str);
    new->link=NULL;
    if(new==NULL)
        return FAILURE;
    if(*head==NULL)
    {
        *head=new;
        return SUCCESS;
    }
    file_node* temp=*head;
    file_node* prev=*head;
    while(temp)
    {
        if(!strcmp(str,temp->f_name))
        {
            printf("\n%s is duplicate file",str);
            return FAILURE;
        }
        prev=temp;
        temp=temp->link;
    }
    prev->link=new;
    return SUCCESS;
}



