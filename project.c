#include "project.h"

static struct data *head=NULL;
static struct data *prev_entry=NULL;
struct data *temp_head,*prev_head;

bool SDB_IsFull(void)
{
    if (count_entries>=10)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
u8 SDB_GetUsedSize(void)
{
    return count_entries;
}
bool SDB_AddEntry(u32 id, u32 year, u32*subjects, u32* grades)
{
    struct data *entry;
    entry=malloc(sizeof(struct data));
    entry->next=NULL;
    entry->student_ID=id;
    entry->student_Year=year;
    entry->subjects[0]=*(subjects);
    entry->subjects[1]=*(subjects+1);
    entry->subjects[2]=*(subjects+2);
    entry->grades[0]=*(grades);
    entry->grades[1]=*(grades+1);
    entry->grades[2]=*(grades+2);

    if(head==NULL)
    {
        head=entry;
        temp_head=head;
    }
    else
    {
        prev_entry->next=entry;
    }
    prev_entry=entry;

     if(entry->next== NULL)
     {
         return 1;
     }
     else
     {
         return 0;
     }
}
void SDB_DeleteEntry(u32 id)
{
    struct data *temp;
    while(1)
    {
        if (head==temp_head)
       {

            if(head->student_ID==id)
        {
            temp=head;
            head=head->next;
            temp_head=head;
            prev_entry=head;
            free(temp);
            printf("ID is removed from database \n");
            --count_entries;
            break;
        }
           else
        {
          prev_head=head;
          head=head->next;
        }

       }
       else if(head->next==NULL)
       {
           if(head->student_ID==id)
           {
               temp=head;
               prev_head->next=NULL;
               prev_entry=prev_head;
               head=temp_head;
               free(temp);
               printf("ID is removed from database \n");
               --count_entries;
               break;
           }
           else
           {
               printf("ID not exist \n");
               head=temp_head;
               break;
           }
       }
       else
       {
           if(head->student_ID==id)
           {
               temp=head;
               prev_head->next=head->next;
               head=temp_head;
               free(temp);
               printf("ID is removed from database \n");
               --count_entries;
               break;
           }
           else
            {
                prev_head=head;
                head=head->next;
            }
       }
    }

}
bool SDB_ReadEntry(u32 id)
{
    while(1)
    {
        if(head!=NULL)
        {
            if(head->student_ID==id)
            {
                printf("your ID: %d\n",head->student_ID);
                printf("your Year: %d\n",head->student_Year);
                printf("your Subject ID: %d and its grade: %d\n",head->subjects[0],head->grades[0]);
                printf("your Subject ID: %d and its grade: %d\n",head->subjects[1],head->grades[1]);
                printf("your Subject ID: %d and its grade: %d\n",head->subjects[2],head->grades[2]);
                head=temp_head;
                return 1;
                break;

            }
            else
            {
               head=head->next;
            }
        }
        else
        {
            head=temp_head;
            return 0;
            break;
        }
    }
}
void SDB_GetList(void)
{
    printf("The list of IDs:\n");
    while(1)
    {
        if(head!=NULL)
        {
            printf("%d\n",head->student_ID);
            head=head->next;
        }
        else
        {
            head=temp_head;
        break;
        }
    }
}
bool SDB_IsIdExist(u32 id)
{
    while(1)
    {
        if(head!=NULL)
        {
            if(head->student_ID==id)
            {
                head=temp_head;
                return 1;
            }
            else
            {
                head=head->next;
            }
        }
        else
        {
            head=temp_head;
            return 0;
        }
    }
}
