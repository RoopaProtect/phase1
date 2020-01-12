#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
struct med
{
    int id;
    char medname[20];
    char company[20];
    int sample;
    int sampleleft;
}m,mc;
struct user
{
    int id;
    char name[20];
    int medid;
    char medname[20];
}u,uc;
FILE *pm,*pu;
void main_menu(void);
void admin(void);
void user(void);
void exitset(void);
void addmed(void);
int midcheck(int);
void medmenu(void);
void editmed(void);
void deletemed(int id);
void usermenu(void);
void adduser(void);
int uidcheck(int);
void listmed(void);
void listuser(void);
void issuemed(void);
void edituser(void);
void deleteuser(int);
void userinfo(void); 
void searchmed(void);
char password[20]="roopa";
int main(void)
{
	system("cls");
	printf("\n\t\t\t\t\t\t Medical Store Management System \n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t By ");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t Roopa\n\n\n");
	printf("\nPress any key to continue");
	getch();
	main_menu();
}
void main_menu(void)
{
	system("cls");
	int choice;
	printf("\n\n\n\t\t\t\t\t\t MainMenu");
	printf("\n\n\n\t\t\t\t 1.Adminstrator");
	printf("\n\n\n\t\t\t\t 2.User");
	printf("\n\n\n\t\t\t\t 3.Exit");
	printf("\n\n\t\t Please Enter Your choice ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:admin();
		break;
		case 2:user();
		break;
		case 3:exitset();
		break;
		default:printf("\n\\n\t\t\t\t\t\t\t Invalid Choice");
		
	}
}
void admin(void)
{
	system("cls");
	printf("\n\t please enter the password");
	char str[20];
	char ch;
	int i=0;
	while((ch=getch())!='\r'&&i<20)
	{
		putch('*');
		str[i++]=ch;
	}
	str[i]='\0';
	if(strcmp(str,password)==0)
	{
		printf("\n\t Authentication sucessfull");
		printf("\n\n\t press any key to continue");
		getch();
	}
	else
	{
		printf("\n\t Incorrect Password");
		return;
	}
	int choice;
	do
	{
		system("cls");
		printf("\n\n\t\t\t\t ADMINSTRATOR MENU");
		printf("\n\n\t\t\t\t\t 1.Add/List Drugs");
		printf("\n\n\t\t\t\t\t 2.Add/Edit Patients");
		printf("\n\n\t\t\t\t\t 3.List Drugs");
		printf("\n\n\t\t\t\t\t 4.List Patients");
		printf("\n\n\t\t\t\t\t 5.Issue Drug");
		printf("\n\n\t\t\t\t\t 6.MainMenu");
		printf("\n\n\t\t\t\t\t 7.Exit");
		printf("\n\n\t\t Please Enter the choice : ");
	    scanf("%d",&choice);
	    switch(choice)
	    {
            case 1: medmenu();break;
            case 2: usermenu();break;
            case 3: listmed();break;
            case 4: listuser();break;
            case 5: issuemed();break;
            case 6: return;
            case 7: exitset();break;
            default: printf("\n\n\t\t Invalid Choice");
        	getch();
        }
    }while(1);  
}
void user(void)
{
	system("cls");
	int choice;
	printf("\n\n\n\t\t\t\t\t Patient Details");
	printf("\n\n\t\t\t\t\t 1.Patient Info");
	printf("\n\n\t\t\t\t\t 2.Search Drug");
	printf("\n\n\t\t\t\t\t 3.MainMenu");
	printf("\n\n\t\t\t\t\t 4.Exit");
	printf("\n\n\t\t Enter your choice");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:userinfo();
		break;
		case 2:searchmed();
		break;
		case 3:return;
		case 4:exitset();
		break;
		default:printf("\n\n\t\t invlaid choice");
		
	}
}
void exitset(void)
{
	system("cls");
	printf("\n\n\t\t Do You Really Want to Continue?(y/n)");
	char ch;
	scanf(" %c",&ch);
	if(ch=='Y'|| ch=='y')
	exit(1);
	else
	main_menu();
}
void medmenu(void)
{
    int choice;
    do
    {
        system("cls");
        printf("\n\n\t\t\t\t Medicines Menu");
        printf("\n\n\t\t 1. Add Medicine \n\t\t 2. Edit Medicines Details \n\t\t 3. Delete Medicine \n\t\t 4. Administrator Menu \n\t\t 5. Exit");
        printf("\n\n\t\t Please Enter the choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:addmed();break;
          	case 2:editmed();break;
            case 3:deletemed(0);break;
            case 4:return;
            case 5:exitset();break;
            default: printf("\n\n\t\t Invalid Choice");
                     getch();
        }
    }while(1);
}

void addmed(void)
{
    pm=fopen("medicines.txt","a");
    char ch;
    do
    {
        label:
        system("cls");
        printf("\n\n\t\t\t Add Medicines");
        printf("\n\n\t\t Please Enter the following details");
        printf("\n\n\t MedicineId : ");
        scanf("%d",&m.id);
        if(midcheck(m.id)==0)
        {
            printf("\n\t Medicine Name : ");
            scanf(" %[^\n]s",m.medname);
            printf("\n\t Company : ");
            scanf(" %[^\n]s",m.company);
            printf("\n\t Number of Samples :");
            scanf("%d",&m.sample);
            m.sampleleft=m.sample;
            fwrite(&m,sizeof(struct med),1,pm);
            printf("\n\t Medicine Successfully added");
			printf("\n\t Do you want to enter details of another medicine? (Y/N)");
            scanf(" %c",&ch);
        }
        else
        {
            printf("\n\t MedId already exists ");
            printf("\n\t Press any key to continue ");
            getch();
            goto label;
        }
    }while(ch=='Y'||ch=='y');
    fclose(pm);
    return;
}
int midcheck(int id)
{
    FILE *m;
    int i=0;
    m=fopen("medicines.txt","r");
    while(!feof(m))
    {
        if(fread(&mc,sizeof(struct med),1,m)==1)
            if(mc.id==id)
        {
            i=1;
            break;
        }
    }
    fclose(m);
    return i;
}
void editmed(void)
{
    int id,choice;
    char ch;
    system("cls");
    printf("\n\n\t\t\t\t Edit Medicine Details");
    printf("\n\t Enter the MedicineId you want to edit : ");
    scanf("%d",&id);
    if(midcheck(id)==1)
    {
        deletemed(id);
        struct med me;
        me=mc;
        l2:
        printf("\n\t Existing Medicine Information : ");
        printf("\n\t MedId : %d \n\t 1. MedName : %s \n\t 2. Company : %s \n\t 3. Number of samples : %d ",me.id,me.medname,me.company,me.sample);
        printf("\n\n\t Please Enter the field to edit : ");
        scanf("%d",&choice);
        switch(choice)
        {
            
			case 1: printf("\n\n\t Enter the new medicine name : ");
            scanf(" %[^\n]s",me.medname);
            break;
        	case 2: printf("\n\n\t Enter the new Company name : ");
            scanf(" %[^\n]s",me.company);
            break;
        
        	case 3: printf("\n\n\t Enter the new number of Samples : ");
                int temp;
                temp=me.sample;
                scanf("%d",&me.sample);
                me.sampleleft=me.sampleleft+me.sample-temp;
            break;
        	default: printf("\n\n\t Invalid choice");
                printf("\n\n\t Press any key to continue");
                getch();
                goto l2;
        }
    	printf("\n\n\t Do you want to edit anything else ? (Y/N)");
    	scanf(" %c",&ch);
    	if(ch=='Y'||ch=='y')
    	goto l2;
    	pm=fopen("medicines.txt","a");
    	fwrite(&me,sizeof(struct med),1,pm);
   		fclose(pm);
    	printf("\n\t Medicine Successfully updated ");
	    printf("\n\t Press any key to continue ");
    	getch();
    }
    else
    {
    	printf("\n\n\t Entered MedId does not exist");
	    printf("\n\n\t Press any key to continue");
	    getch();
    }
    return;
}
void deletemed(int id)
{
    FILE *temp;
    int flag=0;
    temp=fopen("temp.txt","w");
    if(id==0)
    {
        flag=1;
        label:
        system("cls");
        printf("\n\n\t\t Delete Medicine");
        printf("\n\t Enter the MedId to be deleted : ");
        scanf("%d",&id);
        if(midcheck(id)==0)
        {
            printf("\n\t MedId does not exist");
            printf("\n\t Press any key to continue");
            getch();
            goto label;
        }
    }
    pm=fopen("medicines.txt","r");
    while(!feof(pm)) 
	   {
    if(fread(&m,sizeof(struct med),1,pm)==1)
    if(m.id!=id)
    fwrite(&m,sizeof(struct med),1,temp);
    }
    fclose(pm);
    fclose(temp);
    remove("medicines.txt");
    rename("temp.txt","medicines.txt");
    if(flag)
    {
        printf("\n\t Medicine successfully deleted");
        printf("\n\t Press any key to continue");
        getch();
    }
    return;
}
void usermenu(void)
{
    int choice;
    do
    {
		system("cls");
		printf("\n\n\t\t\t\t User Menu");
		printf("\n\n\t\t 1. Add User \n\t\t 2. Edit User Details \n\t\t 3. Delete User \n\t\t 4. Administrator Menu \n\t\t 5. Exit");
		printf("\n\n\t\t Please Enter the choice : ");
		scanf("%d",&choice);
        switch(choice)
        {
    		case 1:adduser();break;
    		case 2:edituser();break;
    		case 3:deleteuser(0);break;
    		case 4:return;
    		case 5:exitset();break;
			default: printf("\n\n\t\t Invalid Choice");
			getch();
        }
    }while(1);
}
void adduser( )
{
    pu=fopen("users.txt","a");
    char ch;
    do
    {
        label:
        system("cls");
		printf("\n\n\t\t\t Add User");
		printf("\n\n\t\t Please Enter the following details");
		printf("\n\n\t UserId : ");
		scanf("%d",&u.id);
		if(uidcheck(u.id)==0)
        {
            printf("\n\t Name : ");
            scanf(" %[^\n]s",u.name);
			fwrite(&u,sizeof(struct user),1,pu);
			printf("\n\t User Successfully added");
			printf("\n\t Do you want to enter details of another user? (Y/N)");
			scanf(" %c",&ch);
		}
		else
		{	
			printf("\n\t UserId already exists");
			printf("\n\t Press any key to continue");
			getch();
			goto label;
        }
    }while(ch=='Y'||ch=='y');
    fclose(pu);
    return;
}
int uidcheck(int id)
{
    FILE *u;
    int i=0;
    u=fopen("users.txt","r");
    while(!feof(u))
    {
        if(fread(&uc,sizeof(struct user),1,u)==1)
            if(uc.id==id)
        {
            i=1;
            break;
        }
    }
    fclose(u);
    return i;
}
void listmed(void)
{
    pm=fopen("medicines.txt","r");
    system("cls");
    printf("\n\n\t\t Medicine Record");
    printf("\n %5s %20s %20s %12s %11s","Id","Medicine Name","Company Name","No.of Samples","Samples Left");
    while(!feof(pm))
    {
		if(fread(&m,sizeof(struct med),1,pm)==1)
		printf("\n %5d %20s %20s %12d %11d",m.id,m.medname,m.company,m.sample,m.sampleleft);
    }
    fclose(pm);
    printf("\n\n\t Press any key to continue");
    getch();
    return;
}
void listuser(void)
{
    pu=fopen("users.txt","r");
    system("cls");
    printf("\n\n\t\t User Record");
    printf("\n %5s %20s %6s ","Id","Name","MedId");
    while(!feof(pu))
    {
        if(fread(&u,sizeof(struct user),1,pu)==1)
		printf("\n %5d %20s %6d",u.id,u.name,u.medid);
    }
    fclose(pu);
    printf("\n\n\t Press any key to continue");
    getch();
    return;
    return;
}
void issuemed(void)
{
    system("cls");
    printf("\n\n\t\t\t Issue Medicine");
    printf("\n\t Enter the UserId : ");
    int idb,idu;
    scanf("%d",&idu);
    if(uidcheck(idu)==1)
    {
		
			printf("\n\t Enter the MedId to be issued : ");
			scanf("%d",&idb);
			if(midcheck(idb)==1)
			{
				if(mc.sampleleft==0)
				{
					printf("\n\t Medicine not available now");
					printf("\n\t Press any key to continue");
					getch();
				}
				else
				{
					pu=fopen("users.txt","a");
					uc.medid=idb;
					fwrite(&uc,sizeof(struct user),1,pu);
					fclose(pu);
					deletemed(mc.id);
					pm=fopen("medicines.txt","a");
					mc.sampleleft--;
					fwrite(&mc,sizeof(struct med),1,pm);
					fclose(pm);
					printf("\n\t Medicine Issued Successfully");
					printf("\n\t Press any key to continue");
					getch();
				}
			}
			else
			{
				printf("\n\t MedicineId does not exist");
				printf("\n\t Press any key to continue");
				getch();
			}
					
	}
	else
	{
		printf("\n\t UserId does not exist");
		printf("\n\t Press any key to continue");
		getch();
	}
    return;
}
void deleteuser(int id)
{
    FILE *temp;
    int flag=0;
    temp=fopen("temp.txt","w");
    if(id==0)
    {
        flag=1;
        label:
        system("cls");
        printf("\n\n\t\t Delete User");
        printf("\n\t Enter the UserId to be deleted : ");
        scanf("%d",&id);
        if(uidcheck(id)==0)
        {
            printf("\n\t UserId does not exist");
            printf("\n\t Press any key to continue");
            getch();
            goto label;
        }
    }
    pu=fopen("users.txt","r");
    while(!feof(pu))
    {
        if(fread(&u,sizeof(struct user),1,pu)==1)
            if(u.id!=id)
                fwrite(&u,sizeof(struct user),1,temp);
    }
    fclose(pu);
    fclose(temp);
    remove("users.txt");
    rename("temp.txt","users.txt");
    if(flag)
    {
        printf("\n\t User successfully deleted");
        printf("\n\t Press any key to continue");
        getch();
    }
    return;
}
void edituser(void)
{
	int id,choice;
	char ch;
	system("cls");
	printf("\n\n\t\t\t\t Edit User Details");
	printf("\n\t Enter the UserId you want to edit : ");
	scanf("%d",&id);
	if(uidcheck(id)==1)
	{
		deleteuser(id);
		struct user ue;
		ue=uc;  
		l2:
		printf("\n\t Existing User Information : ");
		printf("\n\t 1. UserId : %d \n\t 2. User Name : %s ",ue.id,ue.name);
		printf("\n\n\t Please Enter the field to edit : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			l1:
			printf("\n\n\t Enter the new userid : ");
			scanf("%d",&ue.id);
			if(uidcheck(ue.id)==1)
			{
				printf("\n\n\t UserId already exists");
				printf("\n\n\t Press any key to continue");
				getch();
				goto l1;
			}
			break;
			case 2: printf("\n\n\t Enter the new user name");
			scanf(" %[^\n]s",ue.name);
			break;
			default: printf("\n\n\t Invalid choice");
			printf("\n\n\t Press any key to continue");
			getch();
			goto l2;
		}
		printf("\n\n\t Do you want to edit anything else ? (Y/N)");
		scanf(" %c",&ch);
		if(ch=='Y'||ch=='y')
		goto l2;
		pu=fopen("users.txt","a");
		fwrite(&ue,sizeof(struct user),1,pu);
		fclose(pu);
		printf("\n\t user Successfully updated ");
		printf("\n\t Press any key to continue ");
		getch();
	}	
	else
	{
		printf("\n\n\t Entered userId does not exist");
		printf("\n\n\t Press any key to continue");
		getch();
	}
    return;
}
void userinfo(void)
{
    pu=fopen("users.txt","r");
    char ch;
	int id,i;
    do
    {
		system("cls");
		i=0;
		rewind(pu);
		printf("\n\n\t\t\t\t User Info ");
		printf("\n\t Enter the UserId : ");
		scanf(" %d",&id);
		while(!feof(pu))
		{		
			if(fread(&u,sizeof(struct user),1,pu)==1)
			if(u.id==id)
			{
				i++;
				printf("\n\t Search Successful ");
				printf("\n\t UserId : %d \n\t Name : %s \n\t Medicine Id : %d  ",u.id,u.name,u.medid);
			}
		}
		if(i==0)
		printf("\n\t No such user found");
		printf("\n Do you want to search for any other user ? (Y/N)");
		scanf(" %c",&ch);
    }while(ch=='Y'||ch=='y');
    fclose(pu); 
    return;
}
void searchmed(void)
{
	pm=fopen("medicines.txt","r");
	char ch,name[20];
	int i;
	do
	{
		system("cls");
		i=0;
		rewind(pm);
		printf("\n\n\t\t\t\t Medicine Search ");
		printf("\n\t Enter the name of the Medicine to search : ");
		scanf(" %[^\n]s",name);
		while(!feof(pm))
		{
			if(fread(&m,sizeof(struct med),1,pm)==1)
			if(strcmpi(m.medname,name)==0)
			{
				i++;
				printf("\n\t Search Result : %d",i);
				printf("\n\t MedId : %d \n\t MedName : %s \n\t Company : %s \n\t Number of samples : %d \n\t Number of samplesleft : %d",m.id,m.medname,m.company,m.sample,m.sampleleft);
			}
		}
		if(i==0)
		printf("\n\t No such Medicine found");
		printf("\n Do you want to search for any other medicine ? (Y/N)");
		scanf(" %c",&ch);
	}while(ch=='Y'||ch=='y');
	fclose(pm);
return;
}

