#include "project.h"
u8 count_entries=0;
int main()
{
    u32 student_ID;
    u32 student_Year;
    u32 subjects[3];
    u32 grades [3];
    static u8 count=0;
    u8 IsFull,UsedSize,add_entry,read_entry,existance,choice;
    while(1)
    {
        printf("make your choice \n");
        printf("1:ADD An Entry \n");
        printf("2:Read An Entry\n");
        printf("3:Delete An Entry \n");
        printf("4:Check Existanc of An Entry \n");
        printf("5:View list of Entries \n");
        printf("6:Exit \n");
        scanf("%d",&choice);

        switch(choice)
	{
		case (1) :
		{
            UsedSize=SDB_GetUsedSize();
			printf("The used size of the database = %d\n",UsedSize);
			IsFull=SDB_IsFull();
			if (IsFull==0)
			{
				printf("Enter your ID : ");
				scanf("%d",&student_ID);
				printf("Enter your Year : ");
				scanf("%d",&student_Year);
				int index=0;
				for (index = 0; index < 3; ++index)
				{
					printf("Enter the ID of course %d : ",index+1);
					scanf("%d",&subjects[index]);
					printf("Enter the grade of course %d (out of 100): ",index+1);
					scanf("%d",&grades[index]);
					while(grades[index]>100)
					{
						printf("Invalid grade\n");
						printf("Enter the grade of course %d (out of 100): ",index+1);
						scanf("%d",&grades[index]);
					}
				}

				add_entry=SDB_AddEntry(student_ID, student_Year, &subjects[0], &grades[0]);

				if (add_entry==1)
				{
					printf("The entry is created successfully\n");
					++count;
					count_entries=count;
				}
				else
				{
					printf("The entry is not created\n");
					break;
				}
			}
			else
			{
				printf("The database is full.\nNote: The maximum size of the database is 10 entries only.\n");
			}

			break;

		}
        case (2) :
		{
			u32 id;
			printf("Enter your ID : ");
			scanf("%d",&id);
			read_entry=SDB_ReadEntry(id);
			if (read_entry==1)
			{
				printf("Your ID exist\n");
			}
			else
			{
				printf("Your ID not exist\n");
			}
			break;
		}
		case (3) :
		{
			u32 id;
			printf("Enter your ID : ");
			scanf("%d",&id);
			SDB_DeleteEntry(id);
			break;
		}
		case (4) :
		{
			u32 id;
			printf("Enter your ID : ");
			scanf("%d",&id);
			existance=SDB_IsIdExist(id);
			if (existance==1)
			{
				printf("Your ID exist\n");
			}
			else
			{
				printf("Your ID not exist\n");
			}
			break;
		}
		case (5) :
		{
			SDB_GetList();
			break;
		}
		case (6) :
		{
			break;
		}
		default :
		{
			printf("Invalid choice\n");
			break;
		}
    }
if(choice==6)
{
	break;
}
else{}

printf("");
}

return 0;
}

