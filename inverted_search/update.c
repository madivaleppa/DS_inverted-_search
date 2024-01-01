#include "header.h"
void update_database(main_table arr[],file_node** head)
{
    extern int create_db;
    if(create_db==1)
    {
        printf("\ncan't perform update database after create database!");
        return;
    }
    char f_name[20];
    FILE* fptr;
    char ch;
    while(1)
    {
        printf("\nEnter the file name:");
        scanf("%s",f_name);
        fptr=fopen(f_name,"r");
        if(fptr==NULL)
        {
            CLR_SCREEN;
            printf("\nFILE NOT EXIST!");
            printf("RETRY(y/n):");
            getchar();
            scanf("%c",&ch);
            if(ch=='n')
                return;
        }
        else
            break;
    }
    char string[1000];
    int index;
    int f_count, w_count;
    main_node *m_node;
    sub_node *s_node;
    char* str;
    while(fscanf(fptr,"%s",string)==1)
    {
        str=strtok(string,";");                         //index 
        sscanf(&str[1], "%d", &index);
        str=strtok(NULL,";");                      //word
        while(1)
        {
            m_node=malloc(sizeof(main_node));
            s_node=malloc(sizeof(sub_node));

            strcpy(m_node->word,str);
            str=strtok(NULL,";");                    //filecount
            sscanf(str,"%d",&f_count);
            m_node->f_count=f_count;
            //insert at first
            m_node->link=arr[index].link;
            m_node->sub_link=NULL;
            arr[index].link=m_node;         

            for(int i=0;i<f_count;i++)
            {
                s_node=malloc(sizeof(sub_node));
                str=strtok(NULL,";");                     //filename
                strcpy(s_node->f_name,str);

                check_for_cl_fname(str,head);

                str=strtok(NULL,";");                     //wordcount
                sscanf(str,"%d",&w_count);
                s_node->w_count=w_count;
                s_node->link=m_node->sub_link;
                m_node->sub_link=s_node;
            }

            str=strtok(NULL,";");                         //last #
            if(str[0]=='#')
                break;
        }
    }
    file_node *temp=*head;
    printf("\n Update database successful!!");
}


void check_for_cl_fname(char* str,file_node** head)
{
    if(*head==NULL)
        return;
    file_node* temp=*head;
    file_node* ptemp=*head;
    while(temp)
    {
        if(!strcmp(temp->f_name,str))
        {
            if(temp==*head)
            {
                *head=temp->link;
                printf("\nremoved duplicate file :%s",str);
                return;
            }
            ptemp->link=temp->link;
            printf("\nremoved duplicate file :%s",str);
            return;
        }
        ptemp=temp;
        temp=temp->link;
    }
}
