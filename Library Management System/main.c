#include <stdio.h>       //remove,rename
#include<stdlib.h>      //system,
#include<windows.h>     //sleep,
void add_books(void);
void view_book_list(void);
void edit_book_record(void);
void delete_book(void);
void search_book(void);

FILE *Lfile,*TLfile;

struct books_info
{
int id;
char Name[50];
char Author[50];
char Language[50];
char catagorie[50];
int quantity;
int page;
int rack_no;
};

struct books_info Lib;
char option;
int main()
{
    system("cls");
    printf("\n\n\t\t\t\t===========>>>>> Library Management System <<<<<===========\n\n");
    Sleep(1000);
    printf("\t\t\t\t          =========>>>>> Main Manu <<<<<=========          \n");
    printf("\t\t\t\t===========================================================\n");
    Sleep(1000);
    printf("\t\t\t\t===========================================================\n");
    printf("\t\t\t\t==                                                       ==\n");
    printf("\t\t\t\t==      1) Search Book                                   ==\n");
    printf("\t\t\t\t==      2) View Book List                                ==\n");
    printf("\t\t\t\t==      3) Add Book                                      ==\n");
    printf("\t\t\t\t==      4) Edit Book Record                              ==\n");
    printf("\t\t\t\t==      5) Delete Book                                   ==\n");
    printf("\t\t\t\t==      6) Close Program                                 ==\n");
    printf("\t\t\t\t==                                                       ==\n");
    printf("\t\t\t\t===========================================================\n");
    printf("\t\t\t\t===========================================================\n");
    printf("\t\t\t\t--------> Enter Your Choice = ");
    scanf(" %c",&option);

    switch(option)
         {
          case '1':
              {
                  search_book();
              }
                   break;
          case '2':
              {
                  view_book_list();
                   break;
              }
          case '3':
              {
                  add_books();
              }
                   break;
          case '4':
              {
                  edit_book_record();
              }
                   break;
          case '5':
              {
                  delete_book();
              }
                   break;
          case '6':
                   {
                    system("cls");
                    Sleep(1000);
                    printf("\n\n\t\t\t\t===========>>>>> Library Management System <<<<<===========\n\n");
                    Sleep(500);
                    printf("\t\t\t\t===========================================================\n");
                    printf("\t\t\t\t===========================================================\n");
                    Sleep(1000);
                    printf("\t\t\t\t==                                                       ==\n");
                    printf("\t\t\t\t==                       Thank you                       ==\n");
                    printf("\t\t\t\t==                          for                          ==\n");
                    printf("\t\t\t\t==                  viewing our program                  ==\n");
                    printf("\t\t\t\t==                                                       ==\n");
                    printf("\t\t\t\t==-------------------------------------------------------==\n");
                    Sleep(2000);
                    printf("\t\t\t\t==                                                       ==\n");
                    printf("\t\t\t\t==                   Program was created                 ==\n");
                    printf("\t\t\t\t==                           by                          ==\n");
                    printf("\t\t\t\t==                                                       ==\n");
                    Sleep(1500);
                    printf("\t\t\t\t==                   Md. Rakibul Hasan                   ==\n");
                    Sleep(1500);
                    printf("\t\t\t\t==                  Safat Ahmed Chowdhury                ==\n");
                    Sleep(1500);
                    printf("\t\t\t\t==                   Md. Rokib Hasan Oli                 ==\n");
                    Sleep(1500);
                    printf("\t\t\t\t==                                                       ==\n");
                    printf("\t\t\t\t===========================================================\n");
                    printf("\t\t\t\t===========================================================\n");
                    printf("\t\t\t\t                     Exiting in 3 second.\n\n");
                    Sleep(3000);
                    exit(0);
                   }
          default:
                   {
                    system("cls");
                    Sleep(1000);
                    printf("\n\n");
                    printf("\a\t\t\t\t\t\t    !!  Wrong Entry  !!");
                    Sleep(500);
                    printf("\n\n\n\t\t\t\t              Please re-entered correct option");
                    Sleep(2000);
                    main();
                   }
         }
return (0);
}

void add_books(void)
{
     int id,count=0;
     system("cls");
     printf("\n\n\t\t\t\t===========>>>>> Library Management System <<<<<===========\n\n");
     printf("\t\t\t\t          =========>>>>> Add Books <<<<<=========          \n");
     printf("\t\t\t\t      ===============================================        \n");
     Sleep(1000);
     Lfile=fopen("Books.bin","ab+");
     if(Lfile==NULL)
     {
         printf("\n\n\t\t\t\t\t\t    !! File Not Found !!");
         printf("\n\n\t\t\t\t\t\t Press anykey for main manu.\n");
         fflush(stdin);
         getchar();
         main();
     }
     else
     {
         printf("\n\t\t\t\t  Enter Book ID : ");
         scanf("%d",&id);
         rewind(Lfile);
         while(fread(&Lib,sizeof(Lib),1,Lfile)==1)
         {
             if(id==Lib.id)
             {
                 printf("\n\t\t\t\t There is a book in this ID.");
                 printf("\n\t\t\t\t Would you like to try again with another ID.");
                 printf("\n\t\t\t\t Press 'Y' for add more books.");
                 printf("\n\t\t\t\t Press anykey for main manu.\n");
                 count=1;
             }
             else
             {
                 Lib.id=id;
             }
         }
         if(count==1)
         {
             printf("\n\t\t\t\t --> ");
             fflush(stdin);
             scanf("%c",&option);
             if(option=='Y'||option=='y')
                {
                    add_books();
                }
             else
                {
                    main();
                }
         }
         printf("\n\t\t\t\t  Enter Book Name                : ");
         fflush(stdin);
         fgets(Lib.Name,sizeof(Lib.Name),stdin);
         printf("\n\t\t\t\t  Enter Book Author              : ");
         fflush(stdin);
         fgets(Lib.Author,sizeof(Lib.Author),stdin);
         printf("\n\t\t\t\t  Enter Book written in Language : ");
         fflush(stdin);
         fgets(Lib.Language,sizeof(Lib.Language),stdin);
         printf("\n\t\t\t\t  Enter Book Catagorie           : ");
         fflush(stdin);
         fgets(Lib.catagorie,sizeof(Lib.catagorie),stdin);
         printf("\n\t\t\t\t  Enter Book Quantity            : ");
         scanf("%d",&Lib.quantity);
         printf("\n\t\t\t\t  Enter Book Total Page          : ");
         scanf("%d",&Lib.page);
         printf("\n\t\t\t\t  Enter Book Rack No             : ");
         scanf("%d",&Lib.rack_no);

         fseek(Lfile,0,SEEK_END);
         fwrite(&Lib,sizeof(Lib),1,Lfile);
         fclose(Lfile);

         printf("\n\n\t\t\t\t\a  Book successfully added.");
         Sleep(1000);
         printf("\n\n\t\t\t\t  Would you like to add more books? ");
         printf("\n\t\t\t\t  Press 'Y' for add more books.");
         printf("\n\t\t\t\t  Press anykey for main manu.\n");
         printf("\n\t\t\t\t --> ");
         fflush(stdin);
         scanf("%c",&option);
         if(option=='Y'||option=='y')
         {
             add_books();
         }
         else
         {
             main();
         }
     }
}

void view_book_list(void)
{
     system("cls");
     int Total_book=0;
     printf("\n\n\t\t\t\t===========>>>>> Library Management System <<<<<===========\n\n");
     printf("\t\t\t\t       =========>>>>> View Book List <<<<<=========          \n");
     printf("\t\t\t\t  ======================================================     \n\n");
     Sleep(1000);

     Lfile=fopen("Books.bin","rb");
     if(Lfile==NULL)
       {
         printf("\n\n\t\t\t\t\t\t    !! File Not Found !!");
         printf("\n\n\t\t\t\t\t\t Press anykey for main manu.\n");
         fflush(stdin);
         getchar();
         main();
       }
     else
       {
         while(fread(&Lib,sizeof(Lib),1,Lfile)==1)
         {
             printf("\t\t\t\t\tID = %d     ",Lib.id);
             fflush(stdout);
             printf("--------> Book Name = %s",Lib.Name);
             fflush(stdout);
             printf("\t\t\t\t\t\t    --------> Author    = %s",Lib.Author);
             printf("\t\t\t\t\t\t    --------> Language  = %s",Lib.Language);
             printf("\t\t\t\t\t\t    --------> Catagorie = %s",Lib.catagorie);
             printf("\t\t\t\t\t\t    --------> Quantity  = %d\n",Lib.quantity);
             printf("\t\t\t\t\t\t    --------> Page      = %d\n",Lib.page);
             printf("\t\t\t\t\t\t    --------> Rack NO   = %d\n\n",Lib.rack_no);
             Total_book=(Total_book+(Lib.quantity));
         }
         printf("\t=======================================================================================================\n\n");
         printf("\t\t\t\t  Total Book Quantity = %d\n\n",Total_book);
         printf("\n\t\t\t\t  Press anykey for main manu.\n");
         fflush(stdin);
         getchar();
         main();
       }
       fclose(Lfile);
}

void edit_book_record(void)
{
     system("cls");
     int id,count=0;
     printf("\n\n\t\t\t\t===========>>>>> Library Management System <<<<<===========\n\n");
     printf("\t\t\t\t      =========>>>>> Edit Book Record <<<<<=========          \n");
     printf("\t\t\t\t    ==================================================       \n");
     Sleep(1000);

     Lfile=fopen("Books.bin","rb+");
     if(Lfile==NULL)
       {
         printf("\n\n\t\t\t\t\t\t    !! File Not Found !!");
         printf("\n\n\t\t\t\t\t\t Press anykey for main manu.\n");
         fflush(stdin);
         getchar();
         main();
       }
     else
       {
         printf("\n\t\t\t\t  Enter Book ID : ");
         scanf("%d",&id);
         while(fread(&Lib,sizeof(Lib),1,Lfile)==1)
         {
             if(id==Lib.id)
             {
                 printf("\n\t\t\t\t\a Book is availble.");
                 printf("\n\n\t\t\t\t Book ID : %d",Lib.id);
                 printf("\n\t\t\t\t  Enter New Book Name                : ");
                 fflush(stdin);
                 fgets(Lib.Name,sizeof(Lib.Name),stdin);
                 printf("\n\t\t\t\t  Enter New Book Author              : ");
                 fflush(stdin);
                 fgets(Lib.Author,sizeof(Lib.Author),stdin);
                 printf("\n\t\t\t\t  Enter New Book written in Language : ");
                 fflush(stdin);
                 fgets(Lib.Language,sizeof(Lib.Language),stdin);
                 printf("\n\t\t\t\t  Enter New Book Catagorie           : ");
                 fflush(stdin);
                 fgets(Lib.catagorie,sizeof(Lib.catagorie),stdin);
                 printf("\n\t\t\t\t  Enter New Book Quantity            : ");
                 scanf("%d",&Lib.quantity);
                 printf("\n\t\t\t\t  Enter New Book Total Page          : ");
                 scanf("%d",&Lib.page);
                 printf("\n\t\t\t\t  Enter New Book Rack No             : ");
                 scanf("%d",&Lib.rack_no);

                 fseek(Lfile,ftell(Lfile)-sizeof(Lib),0);
                 fwrite(&Lib,sizeof(Lib),1,Lfile);
                 fclose(Lfile);
                 printf("\n\n\t\t\t\t\a  Book record successfully edited.");
                 Sleep(1000);
                 printf("\n\n\t\t\t\t  Would you like to edit book record ");
                 printf("\n\t\t\t\t  Press 'Y' for edit book record.");
                 printf("\n\t\t\t\t  Press 'L' for view book list.");
                 printf("\n\t\t\t\t  Press anykey for main manu.\n");
                 printf("\n\t\t\t\t --> ");
                 fflush(stdin);
                 scanf("%c",&option);
                 if(option=='Y'||option=='y')
                   {
                      edit_book_record();
                   }
                 else if(option=='L'||option=='l')
                   {
                      view_book_list();
                   }
                 else
                   {
                      main();
                   }

                 count=1;
             }
          }
       }
     if(count==0)
         {

             printf("\n\t\t\t\t\a Book is not availble in this ID.");
             Sleep(1000);
             printf("\n\n\t\t\t\t  Would you like to edit book record ");
             printf("\n\t\t\t\t  Press 'Y' for edit book record.");
             printf("\n\t\t\t\t  Press 'L' for view book list.");
             printf("\n\t\t\t\t  Press anykey for main manu.\n");
             printf("\n\t\t\t\t --> ");
             fflush(stdin);
             scanf("%c",&option);
             if(option=='Y'||option=='y')
                   {
                      edit_book_record();
                   }
             else if(option=='L'||option=='l')
                   {
                      view_book_list();
                   }
             else
                   {
                      main();
                   }
         }
}

void delete_book(void)
{
     system("cls");
     int id,count=0;
     printf("\n\n\t\t\t\t===========>>>>> Library Management System <<<<<===========\n\n");
     printf("\t\t\t\t         =========>>>>> Delete Book <<<<<=========          \n");
     printf("\t\t\t\t    ==================================================       \n");
     Sleep(1000);
     Lfile=fopen("Books.bin","rb+");
     if(Lfile==NULL)
       {
         printf("\n\n\t\t\t\t\t\t    !! File Not Found !!");
         printf("\n\n\t\t\t\t\t\t Press anykey for main manu.\n");
         fflush(stdin);
         getchar();
         main();
       }
     else
       {
         printf("\n\t\t\t\t  Enter Book ID to delete that book info : ");
         scanf("%d",&id);
         while(fread(&Lib,sizeof(Lib),1,Lfile)==1)
         {
             if(id==Lib.id)
             {
                 printf("\n\t\t\t\t\a  Book is availble.");
                 printf("\n\n\t\t\t\t  Book ID : %d\n",Lib.id);
                 printf("\n\t\t\t\t  Enter New Book Name                : %s",Lib.Name);
                 printf("\n\t\t\t\t  Enter New Book Author              : %s",Lib.Author);
                 printf("\n\t\t\t\t  Enter New Book written in Language : %s",Lib.Language);
                 printf("\n\t\t\t\t  Enter New Book Catagorie           : %s",Lib.catagorie);
                 printf("\n\t\t\t\t  Enter New Book Quantity            : %d\n",Lib.quantity);
                 printf("\n\t\t\t\t  Enter New Book Total Page          : %d\n",Lib.page);
                 printf("\n\t\t\t\t  Enter New Book Rack No             : %d\n\n",Lib.rack_no);
                 Sleep(1000);
                 printf("\n\t\t\t\t  Press 'Y' for delete  book.");
                 printf("\n\t\t\t\t  Press anykey for main manu.\n");
                 printf("\n\t\t\t\t  --> ");
                 fflush(stdin);
                 scanf("%c",&option);
                 if(option=='Y'||option=='y')
                   {
                       TLfile=fopen("Temporary Books.bin","wb+");
                       if(TLfile==NULL)
                       {
                        printf("\n\n\t\t\t\t\t\t    !! File Not Found !!");
                        printf("\n\n\t\t\t\t\t\t Press anykey for main manu.\n");
                        fflush(stdin);
                        getchar();
                        main();
                       }
                       else
                       {

                       rewind(Lfile);
                       while(fread(&Lib,sizeof(Lib),1,Lfile)==1)
                       {
                           if(Lib.id!=id)
                           {
                               fseek(TLfile,ftell(TLfile)-sizeof(Lib),0);
                               fwrite(&Lib,sizeof(Lib),1,TLfile);
                           }
                       }
                       fclose(Lfile);
                       fclose(TLfile);
                       remove("Books.bin");
                       rename("Temporary Books.bin","Books.bin");

                       printf("\n\t\t\t\t\a  Successfully deleted book.\n\n");
                       Sleep(1000);
                       printf("\n\t\t\t\t  Press 'Y' for delete another book.");
                       printf("\n\t\t\t\t  Press 'L' for view book list.");
                       printf("\n\t\t\t\t  Press anykey for main manu.\n");
                       printf("\n\t\t\t\t  --> ");
                       fflush(stdin);
                       scanf("%c",&option);
                       if(option=='Y'||option=='y')
                         {
                           delete_book();
                         }
                       else if(option=='L'||option=='l')
                         {
                           view_book_list();
                         }
                       else
                         {
                           main();
                         }
                       }
                   }
                 else
                   {
                      main();
                   }

                 count=1;
             }
          }
       }
       if(count==0)
         {

             printf("\n\t\t\t\t\a  Book is not availble in this ID.");
             Sleep(1000);

             printf("\n\t\t\t\t  Press 'Y' for delete another book.");
             printf("\n\t\t\t\t  Press 'L' for view book list.");
             printf("\n\t\t\t\t  Press anykey for main manu.\n");
             printf("\n\t\t\t\t  --> ");
             fflush(stdin);
             scanf("%c",&option);
             if(option=='Y'||option=='y')
                   {
                      delete_book();
                   }
             else if(option=='L'||option=='l')
                   {
                      view_book_list();
                   }
             else
                   {
                      main();
                   }
         }
}

void search_book(void)
{
     int id;
     system("cls");
     printf("\n\n\t\t\t\t===========>>>>> Library Management System <<<<<===========\n\n");
     printf("\t\t\t\t         =========>>>>> Search Book <<<<<=========          \n");
     printf("\t\t\t\t===========================================================        \n");
     Sleep(1000);
     Lfile=fopen("Books.bin","rb+");
     if(Lfile==NULL)
       {
         printf("\n\n\t\t\t\t\t\t    !! File Not Found !!");
         printf("\n\n\t\t\t\t\t\t Press anykey for main manu.\n");
         fflush(stdin);
         getchar();
         main();
       }
     else
       {
         printf("\n\t\t\t\t  Enter Search Book ID : ");
         scanf("%d",&id);
         while(fread(&Lib,sizeof(Lib),1,Lfile)==1)
         {
             if(id==Lib.id)
             {
                 printf("\n\t\t\t\t\a  Book is availble.");
                 printf("\n\n\t\t\t\t  Book ID                            : %d\n",Lib.id);
                 printf("\n\t\t\t\t  Enter New Book Name                : %s",Lib.Name);
                 printf("\n\t\t\t\t  Enter New Book Author              : %s",Lib.Author);
                 printf("\n\t\t\t\t  Enter New Book written in Language : %s",Lib.Language);
                 printf("\n\t\t\t\t  Enter New Book Catagorie           : %s",Lib.catagorie);
                 printf("\n\t\t\t\t  Enter New Book Quantity            : %d\n",Lib.quantity);
                 printf("\n\t\t\t\t  Enter New Book Total Page          : %d\n",Lib.page);
                 printf("\n\t\t\t\t  Enter New Book Rack No             : %d\n\n",Lib.rack_no);
             }
         }
         printf("\t\t\t\t===========================================================        \n");
         Sleep(1000);
         printf("\n\t\t\t\t\a  In this ID, there is no book available.\n");
         printf("\n\t\t\t\t  Press 'Y' for again search book.");
         printf("\n\t\t\t\t  Press 'L' for view book list.");
         printf("\n\t\t\t\t  Press anykey for main manu.\n");
         printf("\n\t\t\t\t  --> ");
         fflush(stdin);
         scanf("%c",&option);
         if(option=='Y'||option=='y')
                {
                    search_book();
                }
         else if(option=='L'||option=='l')
                {
                    view_book_list();
                }
         else
                {
                    main();
                }
       }
}
