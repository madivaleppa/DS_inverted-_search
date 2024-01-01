#include"header.h"
void create_database(main_table arr[],file_node* head)
{
    extern int create_db;
    char word[50];
    int ind;
    main_node* m_temp;
    sub_node* s_temp;
    main_node* pm_temp;
    sub_node* ps_temp;
    char s_flag=0;
    if(head==NULL)
    {
        printf("\nThere are no files to create database!!");
        printf("\n Usage: ./a.out <.txt files>");
        return;
    }
    if(create_db==1)
    {
        printf("\nalready database is created ");
        return;
    }
    file_node* temp=head;
    while(temp)
    {
        FILE* fptr=fopen(temp->f_name,"r");
        while(fscanf(fptr,"%s",word)==1)
        {
            for(int i=0;word[i];i++)
            {
                word[i]=tolower(word[i]);
            }
            if(word[0]>96 && word[0]<123)
                ind=word[0]%97;
            else
                ind=26;
            //if no contents are present in the arr of indedx then insert at first
            if(arr[ind].link==NULL)
            {
                //create sub_node update the default values
                sub_node* s_node=malloc(sizeof(sub_node));
                strcpy(s_node->f_name,temp->f_name);
                s_node->w_count=1;
                s_node->link=NULL;

                //create main_node and update word node
                main_node* m_node=malloc(sizeof(main_node));
                strcpy(m_node->word,word);
                m_node->link=NULL;
                m_node->f_count=1;
                m_node->sub_link=s_node;
                //link to main table
                arr[ind].link=m_node;

            }
            else    //else insert at last
            {
                m_temp=arr[ind].link;   //creat a temp and traverse
                while(m_temp)
                {
                    //if word matches then 
                    if(!strcmp(m_temp->word,word))
                    {
                        s_temp=m_temp->sub_link;
                        ps_temp=s_temp;
                        //create a sub temp and traverse
                        while(s_temp)
                        {
                            //if file name matches then increment the word count
                            if(!strcmp(s_temp->f_name,temp->f_name))
                            {
                                s_temp->w_count++;
                                break;
                            }
                            //else traverse to next node
                            ps_temp=s_temp;
                            s_temp=s_temp->link;
                        }
                        //create sub_node
                        if(s_temp==NULL)//if file didn't match then create new sub node ,update values and insert at last
                        {
                            sub_node* s_node=malloc(sizeof(sub_node));
                            strcpy(s_node->f_name,temp->f_name);
                            s_node->w_count=1;
                            s_node->link=NULL;
                            ps_temp->link=s_node;
                            (m_temp->f_count)++;//increment the file count in main node
                            s_flag=1;
                            break;
                        }
                    }
                    else
                    {
                        pm_temp=m_temp;//else traverse to next node
                        m_temp=m_temp->link;
                    }
                }
                if(m_temp==NULL)//if the word didn't match then create a new word node and and subnode and insert at last
                {
                    //create sub_node
                    sub_node* s_node=malloc(sizeof(sub_node));
                    strcpy(s_node->f_name,temp->f_name);
                    s_node->w_count=1;
                    s_node->link=NULL;

                    //create main_node
                    main_node* m_node=malloc(sizeof(main_node));
                    strcpy(m_node->word,word);
                    m_node->link=NULL;
                    m_node->f_count=1;
                    m_node->sub_link=s_node;
                    //attach to main table
                    pm_temp->link=m_node;
                }
            }
        }
        temp=temp->link;
    }
    printf("\n created database successfully!!");
    create_db=1;
}








