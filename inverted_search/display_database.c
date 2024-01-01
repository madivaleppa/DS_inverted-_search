#include"header.h"

void display_database(main_table arr[])
{
            main_node* m_temp;
            sub_node* s_temp;
    printf("[index]      [word]     file_count          file/s:file         file_name       word_count\n");
    for(int i=0;i<27;i++)
    {
        if(arr[i].link!=NULL)
        {
            m_temp=arr[i].link;
            while(m_temp)
            {
                printf("\n[%d]      ",i);
                printf("    [ %s ] ",m_temp->word);
                printf("%10d       ",m_temp->f_count);
                printf("        file/s : ");
                s_temp=m_temp->sub_link;
                while(s_temp)
                {
                    printf("file : %s  ",s_temp->f_name);
                    printf("%d  ",s_temp->w_count);
                    s_temp=s_temp->link;
                }
                m_temp=m_temp->link;
            }
        }
    }
}


/*
input:array of structure  of main hash table
operation:search for matching word in the hash table ,if the word is present prints index number nad file details.
   */
void search_database(main_table arr[])
{
    char s_word[50]={0};
    printf("\n Enter the word to be searched: ");
    scanf("%s",s_word);//reads the string from the user
    s_word[0]=tolower(s_word[0]);
    int index=s_word[0]%97;
    if(arr[index].link==NULL)//if index is null print not found message
        printf("Word not found!!");
    else
    {
       //create a temp variable and serch for the word
       main_node* temp=arr[index].link;
       while(temp)//traverseing
       {
            if(!strcmp(temp->word,s_word))//if the word matches print the file details and word count and file count
            {
                sub_node* s_temp=temp->sub_link;
                printf("\n word \"%s\" is present in %d files(s)",s_word,temp->f_count);
                while(s_temp)
                {
                    printf("\n %s -> %d times(s)",s_temp->f_name,s_temp->w_count);
                    s_temp=s_temp->link;
                }
                return;
            }
            temp=temp->link;
       }
       printf("\n Word not found");
    }
}

/*
operation: ask user for the file name, creates a new .txt file and store the all contents of hash table.
   */
void save_database(main_table arr[])
{
    char f_name[20];
    while(1)
    {
    printf(" Enter the file name with .txt extension:");
    scanf("%s",f_name);
    if(!strstr(f_name,".txt"))
    {
        printf("\nwrog file extension \nplease");
    }
    else
        break;
    }
    FILE* fptr=fopen(f_name,"w+");
    if(fptr==NULL)
    {
        printf("file not opened!!");
        return;
    }
    main_node* m_ptr=NULL;
    sub_node* s_ptr=NULL;
    for(int i=0;i<27;i++)
    {
        if(arr[i].link!=NULL)
        {
            fprintf(fptr,"#");
            m_ptr=arr[i].link;
            fprintf(fptr,"%d;",i);
            while(m_ptr)
            {
                fprintf(fptr,"%s;%d;",m_ptr->word,m_ptr->f_count);
                s_ptr=m_ptr->sub_link;
                while(s_ptr)
                {
                    fprintf(fptr,"%s;%d;",s_ptr->f_name,s_ptr->w_count);
                    s_ptr=s_ptr->link;
                }
                m_ptr=m_ptr->link;
            }
            fprintf(fptr,"#\n");
        }
    }
    fclose(fptr);
    printf("\nsaved database successfully!!");
}

                





















