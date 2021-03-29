#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<stdlib.h>


void input();
void display();
void search();
void searchByRoll();
void searchByName();
void modify();
void deleteStudentInfo();

struct student{
           char name[30];
           char stream[15];
           int roll;

}s;

FILE *fp;

long size = sizeof(s);

int main()
    {
        int choice;
        while(1)
           {
              system("cls");
               printf("\n<== School Management ==>\n");
                printf("1. Input New Student Info. \n");
                printf("2. Display Student Info. \n");
                printf("3. Search Student Info. \n");
                printf("4. Modify Student Info. \n");
                printf("5. Delete Student Info.  \n");
                printf("0. Exit \n");
                printf("Enter your choice : ");
                scanf("%d",&choice);
                    switch(choice)
                            {
                                  case 1:  input();
                                            break;

                                  case 2:  display();
                                            break;

                                  case 3:   search();
                                            break;

                                  case 4:   modify();
                                            break;

                                  case 5:   deleteStudentInfo();
                                            break;

                                  case 0:  exit(0);

                                  default: printf("\nInvalid choice....");
                            }

                            getch();


           }

     }


void input()
    {


        fp=fopen("file1.txt","ab");
          fflush(stdin);
        printf("Enter Student Name : ");
        gets(s.name);
        fflush(stdin);
        printf("Enter stream : ");
        scanf("%s",s.stream);
        printf("Enter Roll Number : ");
        scanf("%d",&s.roll);
        fwrite(&s,sizeof(s),1,fp);
        printf("Record Saved Successfully...");
        fclose(fp);

    }


void display()
    {
          system("cls");
          printf("\n<==  School Management  ==>\n");
          printf("%-30s %-20s %-15s \n","Name","Stream","RollNo.");
          fp=fopen("file1.txt","rb");
          while(fread(&s,sizeof(s),1,fp)==1)
                {
                    printf("%-30s %-20s %-15d \n",s.name,s.stream,s.roll);
                }
            fclose(fp);
            printf("Press Any key to Continue...");
    }


void search()
        {
            int ch;
            while(1)
             {
                system("cls");
                printf("<== School Management ==>\n");
                printf("<== Search ==>\n");
                printf("1. Search by  Roll no.\n");
                printf("2. Search by  Name.\n");
                printf("0. Back to main menu\n");
                printf("\nEnter your choice : ");
                scanf("%d",&ch);
                switch(ch)
                    {
                        case 0: main();
                                break;
                        case 1: searchByRoll();
                                break;
                        case 2: searchByName();
                                break;
                        default: printf("Invalid Choice...");

                    }

                    getch();

                }
        }


void searchByRoll()
        {

            int roll, temp=0;
            printf("Enter RollNo. to serch : ");
            scanf("%d",&roll);
            fp=fopen("file1.txt","rb");
            while(fread(&s,sizeof(s),1,fp)==1)
            {
                if(roll==s.roll)
                 {

                    temp=1;
                printf("%-30s %-20s %-15d \n",s.name,s.stream,s.roll);
                break;
                 }

            }
            fclose(fp);
            if(temp==0)
            printf("Record Not Found...");
            else
            printf("Record Found Successfully...");


        }


void searchByName()
        {
            char name[30];
             int temp=0;
             printf("Enter Name to serch : ");
             fflush(stdin);
            gets(name);
            printf("%-30s %-20s %-15s \n","Name","Stream","RollNo.");
            fp=fopen("file1.txt","rb");
            while(fread(&s,sizeof(s),1,fp)==1)
            {
                if(strcmpi(name,s.name)==0)
                 {

                    temp=1;
                printf("%-30s %-20s %-15d \n",s.name,s.stream,s.roll);
                break;
                 }

            }
            fclose(fp);
            if(temp==0)
            printf("Record Not Found...");
            else
            printf("Record Found Successfully...");

        }


void modify()
        {
            int roll,temp=0;
            printf("Enter RollNo. to Modify : ");
            scanf("%d",&roll);
            fp=fopen("file1.txt","rb+");
            while(fread(&s,sizeof(s),1,fp)==1)
            {
                if(roll==s.roll)
                 {

                    temp=1;
                    printf("Enter New Name : ");
                    fflush(stdin);
                    gets(s.name);
                    printf("Enter New Stream : ");
                    scanf("%s",s.stream);
                    printf("Enter New Roll No. : ");
                    scanf("%d",&s.roll);
                    fseek(fp,-size,1);
                    fwrite(&s,sizeof(s),1,fp);
                    fclose(fp);
                    break;

                 }

            }
            if(temp==0)
            printf("Record Not Found...");
            else
            printf("Record Modified Successfully...");

        }

void deleteStudentInfo()
        {
            int roll,temp=0;
            printf("Enter Roll No. to delete : ");
            scanf("%d",&roll);
            FILE *ftemp;
            fp=fopen("file1.txt","rb");
            ftemp=fopen("temp.txt","ab");
            while(fread(&s,sizeof(s),1,fp)==1)
                    {
                        if(roll==s.roll)
                            temp=1;
                        else
                            fwrite(&s,sizeof(s),1,ftemp);

                    }
                    fclose(fp);
                    fclose(ftemp);
                    remove("file1.txt");
                    rename("temp.txt","file1.txt");
                   if(temp==0)
                        printf("Record Not Found...");
                   else
                        printf("Record Deleted  Successfully...");


        }
