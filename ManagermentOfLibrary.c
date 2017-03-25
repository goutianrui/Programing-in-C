# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include <io.h>
# include <time.h>

// add a note
struct load_man 
{   
    char idnumber[15]; 
    int   exist;  
	char  username[10];
	int   loadtimes; 
	char  password[10];
	
};
struct book_stack
{
   int exist; 
   char book_name[20];
   int borr_times;
   char isbn[20];
   int  left;
};



struct borrow_book
{
	char bookname[20];
	long long int return_date;
    int color;	
};
struct borrow_man
{
	char idnumber[15];
	int borr_books;
	int borr_sum;
	struct borrow_book bbook[5];
};

   char uni_name[10];
   char uni_id[15];
   FILE *betw;
   int book_delete;
   int stu_delete;
   
    FILE*  search (int color,char *bookname);
    FILE* watch(int type ,char *idnum);
    void top_search(void);
    void show_allbooks(void);
    int  load_system(void);
	int pass_change(char *uname,int usertype);
	int name_change(char *idnum,int usertype);
	int user_borrow(char *idnum);
	long long int  get_date(void);
	int setup_stackfile(void);
    int inti (void);
    int user_return(char *idnum);
    int manager_delete(char *idnum);
    int student_delete(char *idnum);
    int student_register(char *idnum);
    int manager_add(char *idnum);
    int menu_stu(void);
    int menu_manager(void);
    int file_modify (void);

int main()
{
	FILE *resu;
	int res[10],typ=1;
	memset(res,0,sizeof(res));
	
	
	if((resu=fopen("E:\\book_stack\\borr","rb+"))==NULL)
	 {
	 	res[0]=inti();
	 	if(!res[0])
	 	{
		 system("color 1e");
	 	 printf("\n\tInitialization Success :)\n");
	 	 puts("\tPress any key to continue ...");
	 	 getchar();
	 	 system("cls");
	    }
	 }
	res[1]=load_system();
	system("cls");
	if(res[1]==1)
	{
		res[2]=menu_manager();
		system("cls");
		th:
		switch(res[2])
		 {
		 	case 1:{
			     system("cls"); res[3]=manager_add(uni_id);
			     puts("\n\tPress any key to return to the Menu\n");
		         getchar();getchar(); system("cls"); res[2]=menu_manager(); goto th;
		         }
		 	case 2:{
			     system("cls"); res[3]=manager_delete(uni_id);
			     puts("\n\tPress any key to return to the Menu\n");
		         getchar();getchar(); system("cls"); res[2]=menu_manager(); goto th;
		         }
		 	case 3:{
			     system("cls"); res[3]=student_register(uni_id);
			     puts("\n\tPress any key to return to the Menu\n");
		         getchar();getchar(); system("cls"); res[2]=menu_manager(); goto th;
		         }
		 	case 4:{
			     system("cls"); res[3]=student_delete(uni_id);
			     puts("\n\tPress any key to return to the Menu\n");
		         getchar();getchar(); system("cls"); res[2]=menu_manager(); goto th;
		         }
		 	case 5:{
			     system("cls"); res[3]=pass_change(uni_name,1);
			     puts("\n\tPress any key to return to the Menu\n");
		         getchar();getchar(); system("cls"); res[2]=menu_manager(); goto th;
		         }
		 	case 6:{
			     system("cls"); res[3]=name_change(uni_id,1);
			     puts("\n\tPress any key to return to the Menu\n");
		         getchar();getchar(); system("cls"); res[2]=menu_manager(); goto th;
		         }
		 	case 7:{
			     system("cls");  top_search();
			     puts("\n\tPress any key to return to the Menu\n");
		         getchar();getchar(); system("cls"); res[2]=menu_manager(); goto th;
		         }
		    case 8:{
			     system("cls");  show_allbooks();
			     puts("\n\tPress any key to return to the Menu\n");
		         getchar();getchar(); system("cls"); res[2]=menu_manager(); goto th;
				 }
			    
		 	case 0: printf("\n\tBye Bye :)\n");exit(0);break;
		 	default :break;
		 }
	}
	else if(res[1]==0)
	{
		res[2]=menu_stu();
	
		system("cls");
		menu:
		switch(res[2])
		 {
		 	case 1:{
			      system("cls");resu=watch(0,uni_id);
			     puts("\n\tPress any key to return to the Menu\n");
		         getchar();getchar();system("cls"); res[2]=menu_stu();goto menu;
		         }	
		    case 2:{
			     system("cls"); 
				 puts("\n\t1. Technology and Engineering stack");
	             puts("\t2. Literature and History stack");
	             puts("\t3. Social science stack"); 
	             puts("\t4. Nature science stack");
	   	         puts("\t5. New paper and Magazine stack");
	   	         
	   	         printf("请输入书库的编号和书名:\n");
	   	         int sta;char bna[20];
	   	         scanf("%d",&sta);
	   	         scanf("%s",bna);
	   	         resu=search(sta,bna);fclose(resu);
			     puts("\n\tPress any key to return to the Menu\n");
		         getchar();getchar(); system("cls"); res[2]=menu_stu(); goto menu;
		         }	
		    case 3:{
			     system("cls"); res[3]=user_borrow(uni_id);
			     puts("\n\tPress any key to return to the Menu\n");
		         getchar(); getchar();system("cls"); res[2]=menu_stu(); goto menu;
		         }
		    case 4:{
			     system("cls"); res[3]=user_return(uni_id);
			     puts("\n\tPress any key to return to the Menu\n");
		         getchar();getchar(); system("cls"); res[2]=menu_stu(); goto menu;
		         }
		    	
		    case 5:{
			     system("cls"); res[3]=pass_change(uni_name,0);
			     puts("\n\tPress any key to return to the Menu\n");
		         getchar();getchar(); system("cls"); res[2]=menu_stu(); goto menu;
		         }
		    case 6:{
			     system("cls"); res[3]=name_change(uni_id,0);
			     puts("\n\tPress any key to return to the Menu\n");
		         getchar(); getchar();system("cls"); res[2]=menu_stu(); goto menu;
		         }
		    case 7:{
			     system("cls");  top_search();
			     puts("\n\tPress any key to return to the Menu\n");
		         getchar(); getchar();system("cls"); res[2]=menu_stu(); goto menu;
		         }
		    case 8:{
			     system("cls");  show_allbooks();
			     puts("\n\tPress any key to return to the Menu\n");
		         getchar();getchar(); system("cls"); res[2]=menu_manager(); goto menu;
				 }     
		    case 0:{
			         printf("\n\tBye Bye :)\n");exit(0);break;
		    }
		 	default:break;
	     }
	}
	else
	printf("登录失败，无法使用本系统 :( \n");

	return 0;
}

int load_system()
{
	int i,t;
	struct load_man *p,load_now;
	p=&load_now;
	
	char  user_name[10],user_pass[10],user_idnumber[15];
	int lt=0,book1=0,book2=0,user=-1;
	
	int choice;
	system("color 1e");
	printf("\n\t\t  Welcome >>> Load_system\n\n"); 
    printf("\t\t┏━━━━━━━━━━━━━━┓\n");
    printf("\t\t┃Manager : 1                 ┃\n");          
    printf("\t\t┃student : 0                 ┃\n");
	printf("\t\t┗━━━━━━━━━━━━━━┛\n\n");
	printf("Please enter You choice:  ");
	scanf("%d",&choice);
	getchar();
	system("cls");
	if(choice==1||choice==0)



    if(choice==1)
	{
		printf("\n\t\tPlease enter your user name:\n");
		scanf("%s",user_name);
		FILE *lsfp;
		if((lsfp=fopen("E:\\book_stack\\managername","rb+"))==NULL)
		{
			printf("\tSorry,can't open the required file\n\tThus we can't identify you ID");
			return -1;	
		}
		 while((!feof(lsfp))) 
		 {
		   fread(p,sizeof(struct load_man),1,lsfp);
		 	if((strcmp(p->username,user_name))==0&&p->exist)
		 	{
		 		book1=1;
		 		break;
		 	}
		 }
		 if(!book1)
		 {
         printf("Sorry,You are not the manager\nPlease try to load again\n");
		 return -2;
		 }
		 		
		 printf("\n\t\tPlease enter your password:\n");
 		 scanf("%s",user_pass);
 		 
 		 int try_time=1;
	     while(strcmp(user_pass,p->password))
		 {
		 	printf("\tWrong Password\n");
		 	//printf("%s %d %s--\n",p->username,p->loadtimes,p->password);
		 	//printf("%s\n",fuser_pass);
		 	printf("\tPlease enter your password:\n");
 		    scanf("%s",user_pass);
		    try_time++;
			if(try_time>=5)
			{
				printf("\tYou have failed 5 times,please try to load this system later\n");
				return -3;
			}	
		 }
		 printf("congratuations,You have loaded successfully\n");
	     strcpy(uni_name,user_name);
	     strcpy(uni_id,p->idnumber);
	    
		 lt++;
		 fseek(lsfp,-1*sizeof(struct load_man),1);
		 p->loadtimes=lt;
		 fwrite(p,sizeof(struct load_man),1,lsfp);
		  fclose(lsfp);
		  return 1; /*1 represent a manager load successfully*/
	
	}	
	else if(choice==0)
	{
		
		printf("\n\t\tPlease enter your username:\n");
		scanf("%s",user_name);
		FILE *lsfp;
		if((lsfp=fopen("E:\\book_stack\\stuname","rb+"))==NULL)
		{
			printf("Sorry,can't open the required file\nThus we can't identify you ID");
			printf("Please contract the local mamager\n\n");
			return -1;	
		}
		 while((!feof(lsfp))) 
		 {
		 	fread(p,sizeof(struct load_man),1,lsfp);
		 	if((strcmp(p->username,user_name))==0&&p->exist)
		 	{
				book2=1;
				break;
		 	}
		
		 }
		 if(!book2)
         {
		 printf("Sorry,You are not the student in our school\n"); 
		 puts("Or you haven't finished your Register");
		 puts("Please try to contract the local manager\n\n");
         return -2;
		 }
		   		
	     else
		 printf("\n\t\tPlease enter your password:\n");
 		 scanf("%s",user_pass);
 		 
 		 int try_time=1;
	    while(strcmp(user_pass,p->password))
		 {
		 	printf("Wrong Password\n");
		 	printf("Please enter your password:\n");
 		    scanf("%s",user_pass);
		    try_time++;
			if(try_time>=5)
			{
				printf("You have failed 5 times,please try to load this system later\n");
				return -3;
			}	
		 }
		 printf("congratuations,You have loaded successfully\n");
		 lt++;
		 strcpy(uni_name,user_name);
	     strcpy(uni_id,p->idnumber);
		 /*I need to change the loadtimes in the stu's file 2015.9.1 */
		
		fseek(lsfp,-1*sizeof(struct load_man),1);
		 p->loadtimes=lt;
		 fwrite(p,sizeof(struct load_man),1,lsfp);
		fclose(lsfp);
		  return 0; /*0 represent a student load successfully*/
	}
	else
	{
		printf("There are no such a type!!!\nPlease load again");
		return 0;
	} 
	
}
/*此函数用来修改用户的密码，函数参数分别为用户名（字符串），用户类型（整形）
， 约定 1 代表管理员用户，2代表学生用户 ；函数返回值为整形 ,*/
int pass_change(char *uname,int usertype)
{
	struct load_man *pcp,change_now;
	pcp=&change_now;
	FILE *pcfp;
	char new_pass[10],iden_pass[10];
	int book1=0,book2=0;
	
	if(usertype==1)
	{
	  if((pcfp=fopen("E:\\book_stack\\managername","rb+"))==NULL)
	   {
	   	printf("Can't open the required file\n");
	   	return -2;
	   }
	   while(!feof(pcfp))
	   {
	   	fread(pcp,sizeof(struct load_man),1,pcfp);
	    if((strcmp(pcp->username,uname))==0&&pcp->exist)
		 	{
		 		book1=1;
		 		break;
		 	} 	
	   }
	   if(!book1)
	   {
	 printf("Sorry,You are not the student in our school\n"); 
	 puts("or you haven't finished your Register\n");
	 puts("Or you message have been deleted\n");  	
	 puts("Please try to contract the local manager\n\n"); 	
	 return -2;
	   }
	   else
	   {
	   	printf("\n\n\tPlease enter you new password:\n");
	   	scanf("%s",new_pass);
	   	printf("\n\n\tPlease enter you new password again:\n");
	   	scanf("%s",iden_pass);
	   	while(strcmp(new_pass,iden_pass))
	   	{
		 printf("\tDefferent passwords!!!");	
	   	 printf("\tPlease enter you new password:\n");
	   	 scanf("%s",new_pass);
	   	 printf("\tPlease enter you new password again:\n");
	   	 scanf("%s",iden_pass);	
	   	}
	   	
	   	
	   	fseek(pcfp,-1*sizeof(struct load_man),1);
	   	strcpy(pcp->password,new_pass);
	   	fwrite(pcp,sizeof(struct load_man),1,pcfp);
        fclose(pcfp);
		printf("\tSuccess :) \n");
		return 1;	   	
	   	
	   	
	   }
	   
	
    }
	else if(usertype==0)
	{
		
	   if((pcfp=fopen("E:\\book_stack\\stuname","rb+"))==NULL)
	   {
	   	printf("Can't open the required file\n");
	   	return -3;
	   }
	   while(!feof(pcfp))
	   {
	   	fread(pcp,sizeof(struct load_man),1,pcfp);
	    if((strcmp(pcp->username,uname))==0&&pcp->exist)
		 	{
		 		book2=1;
		 		break;
		 	} 	
	   }
	   if(!book2)
	   {
	 printf("Sorry,You are not the manager\nOr your message have been deleted\n");
	 puts("Please try to load again\n\n");
	 return -4;
	   }
	   else
	   {
	   	printf("\n\n\tPlease enter you new password:\n");
	   	scanf("%s",new_pass);
	   	printf("\n\n\tPlease enter you new password again:\n");
	   	scanf("%s",iden_pass);
	   	while(strcmp(new_pass,iden_pass))
	   	{
		 printf("\tDefferent passwords!!!");	
	   	 printf("\tPlease enter you new password:\n");
	   	 scanf("%s",new_pass);
	   	 printf("\tPlease enter you new password again:\n");
	   	 scanf("%s",iden_pass);	
	   	}
	   	
	   	
	   	fseek(pcfp,-1*sizeof(struct load_man),1);
	   	strcpy(pcp->password,new_pass);
	   	fwrite(pcp,sizeof(struct load_man),1,pcfp);
        fclose(pcfp);
		printf("\tSuccess :) \n");
		return 2;
	  }
	}
	else
	{
		return -1;
	}
}

/*************************************/
/*函数返回值为整形，不同的返回值代表函数不同的执行状况；
参数分别为当前已经登录用户的 ID 号码(字符串指针），和代
表用户类型的整形数据。函数中所用的文件和登录函数，密码
修改函数相同*/
 int name_change(char *idnum,int usertype)
 {
 	char now_idnum[15],new_name[10],iden_name[10];
 	FILE *ncfp;
 	struct load_man *ncp,now_user;
 	ncp=&now_user;
 	int book2=0,book1=0;
 	strcpy(now_idnum,idnum);
 	
 	if(usertype==0)
 	{
 		/*printf("Please entre You Student IDnumber:\n");
 		scanf("%s",now_idnum);*/
 		
 		if((ncfp=fopen("E:\\book_stack\\stuname","rb+"))==NULL)
 		{
 			printf("Can't open the required File\n");
 			return -2;
 		}
 		while((!feof(ncfp))) 
		 {
		 	fread(ncp,sizeof(struct load_man),1,ncfp);
		 	
		 	if((strcmp(ncp->idnumber,idnum))==0&&ncp->exist)
		 	{
		 		
				book2=1;
				break;
		 	}
		
		 }
 		
 		if(!book2)
 		{
		 printf("Sorry,You are not the student in our school\n");
		 puts("Or you haven't finished your Register\n");
		 puts("Or you message have been deleted\n");  	
		 puts("Please try to contract the local manager\n");
         return -5;
 		}
 		else
 		{
	   	printf("\n\n\tPlease enter your new username:\n");
	   	scanf("%s",new_name);
	   	printf("\n\n\tPlease enter your new name again:\n");
	   	scanf("%s",iden_name);
	   	while(strcmp(new_name,iden_name))
	   	{
		 printf("\tDefferent names!!!");	
	   	 printf("\tPlease enter you new name:\n");
	   	 scanf("%s",new_name);
	   	 printf("\tPlease enter you new name again:\n");
	   	 scanf("%s",iden_name);	
	   	}
	   		
	   	fseek(ncfp,-1*sizeof(struct load_man),1);
	   	strcpy(ncp->username,new_name);
	   	fwrite(ncp,sizeof(struct load_man),1,ncfp);
        fclose(ncfp);
		printf("\tSuccess :) \n");
		return 1;	   	
	   	
 		}
 		
 	
 	}
 	else if(usertype==1)
 		{/*printf("Please entre You Work IDnumber:\n");
 		scanf("%s",now_idnum);*/
 		
 		if((ncfp=fopen("E:\\book_stack\\managername","rb+"))==NULL)
 		{
 			printf("Can't open the required File\n");
 			return -3;
 		}
 		while((!feof(ncfp))) 
		 {
		 	fread(ncp,sizeof(struct load_man),1,ncfp);
		 	
		 	if((strcmp(ncp->idnumber,now_idnum))==0&&ncp->exist)
		 	{
		 		
				book1=1;
				break;
		 	}
		
		 }
 		
 		if(!book1)
 		{
		printf("Sorry,You are not the manager\n");
		puts("Or your message have been deleted\n");
	    puts("Please try to load again\n");
         return -4;
 		}
 		else
 		{
	   	printf("\tPlease enter your new username:\n");
	   	scanf("%s",new_name);
	   	printf("\tPlease enter your new name again:\n");
	   	scanf("%s",iden_name);
	   	while(strcmp(new_name,iden_name))
	   	{
		 printf("\tDefferent names!!!");	
	   	 printf("\tPlease enter you new name:\n");
	   	 scanf("%s",new_name);
	   	 printf("\tPlease enter you new name again:\n");
	   	 scanf("%s",iden_name);	
	   	}
	   		
	   	fseek(ncfp,-1*sizeof(struct load_man),1);
	   	strcpy(ncp->username,new_name);
	   	fwrite(ncp,sizeof(struct load_man),1,ncfp);
        fclose(ncfp);
		printf("\tSuccess :) \n");
		return 2;	   	
	   	
 		}
 		
 	}
 	else 
 	return -1;
 
 }
/*****************************************/
/*此函数用来查询图书，参数为整形 color 代表图书属性
（即图书所在的书库，其中），和字符串（图书名字），返
回值为文件指针，注意此函数执行过程中不会关闭打开的
书库的文件，而是将要返回的文件指针赋给一个全局变量
若单独调用此函数，则应通过全局变量及时关闭文件；若未
查询到相关图书，则返回空指针*/ 
FILE*  search (int color,char *bookname)
{
	FILE *sfp;
	sfp=NULL;
	struct book_stack  *bssp,now_stack;
	bssp=&now_stack;
	struct borrow_book *sp,now_want;
	sp=&now_want;
     int flag=0;


	if(color==1)
	{
		if((sfp=fopen("E:\\book_stack\\red","rb+"))==NULL)
		{
			printf("Can't open the required file!!!\n");
			return NULL;
		}
		
	}
	else if(color==5)
	{
		if((sfp=fopen("E:\\book_stack\\blue","rb+"))==NULL)
		{
			printf("Can't open the required file!!!\n");
		     return NULL;
		}
	}
	else if(color==2)
	{
		if((sfp=fopen("E:\\book_stack\\green","rb+"))==NULL)
		{
			printf("Can't open the required file!!!\n");
		    return NULL;
		}
	}
	else if(color==3)
	{
	   if((sfp=fopen("E:\\book_stack\\gold","rb+"))==NULL)
		{
			printf("Can't open the required file!!!\n");
		    return NULL;
		}
		
	}
	else if(color==4)
	{
	  if((sfp=fopen("E:\\book_stack\\sliver","rb+"))==NULL)
		{
			printf("Can't open the required file!!!\n");
		    return NULL;
		}
		
	}
	while(!feof(sfp))
		{
			//printf("######%d\n",color);
			fread(bssp,sizeof(struct book_stack),1,sfp);
			if(bssp->exist&&(strcmp(bssp->book_name,bookname)==0))
			{
				if(bssp->left>0)
				{
					flag=1;
					goto out;
				}
				else if(bssp->left==0)
				{
					
					printf("Name: %s\n",bssp->book_name);
			        printf("ISBN: %s\n",bssp->isbn);
			        printf("LEFT:  %d\n",bssp->left);
			        printf("Borrowed times: %d\n",bssp->borr_times);
					printf("Some one have borrowed,please wait...\n");
					return NULL;
				}
			}
		
		}
		sfp=NULL;
		
		out:
		if(flag) 
		{
			printf("Name: %s\n",bssp->book_name);
			printf("ISBN: %s\n",bssp->isbn);
			printf("LEFT:  %d\n",bssp->left);
			printf("Borrowed times: %d\n",bssp->borr_times);
		}
		if(sfp==NULL)
		printf("Sorry. Not such a BOOK\n");
		return sfp;
	
}
/**************************************/
/*此函数用于学生用户借书，函数参数为当前登录的学生用户的
ID ,返回值为整形，*/ 
int user_borrow(char *idnum)
  {
  	FILE *ubfp;
  	FILE *bmfp;
  	
  	ubfp=NULL;
  	bmfp=NULL;
  	
  	int ss=0,color,count=0,book1=0,j,t;
  	long long int date;
  	int year,mouth,day;
  	
  	char bookname[20];
  	struct book_stack *ubp,now_borr;
  	ubp=&now_borr;
  	struct borrow_man *bmp,now_man;
  	bmp=&now_man;
  	
  	printf("Please enter the sum of books You want to borrow:\n");
  	scanf("%d",&ss);
  	
  	if(ss<=0)
	  return -1;  //借书数目不大于0时返回-1 
  	
  	if((bmfp=fopen("E:\\book_stack\\borr","rb+"))==NULL)
  	{
  	  	printf("Can't open the required FIle\n");
  	  	exit(0);
  	}
  	while(!feof(bmfp))
  	{
  		fread(bmp,sizeof(struct borrow_man),1,bmfp);
  		if((strcmp(bmp->idnumber,idnum))==0)
		 	{
		 		book1=1;
		 		break;
		 	} 	
		 	bmp->borr_books=0;
  	}
  	if(book1)
  	{
  	ss= ss < (5-bmp->borr_books) ?  ss :(5-bmp->borr_books) ;
  	t=bmp->borr_books;
    }
    else
    t=0;
    if(ss>5)
  	ss=5;
    
  	fclose(bmfp);
  	
  	printf("\t您当前可借为: %d 本\n",ss);
  	//printf("#############\n");
    for(j=0;j<ss;j++)
  	{
  		puts("Please enter the book color and name:\n");
  		scanf("%d",&color);
  		scanf("%s",bookname);
  		
  		//printf("#####%d %s\n",color,bookname);
  	   if((ubfp=search(color,bookname))!=NULL)
  	   {
  	   	
  	   	//printf("#####!NuLL\n");
  	   	count++;
  		fseek(ubfp,-1*sizeof(struct book_stack),1);
  		fread(ubp,sizeof(struct book_stack),1,ubfp);
  		ubp->left--;
  	    fseek(ubfp,-1*sizeof(struct book_stack),1);
        fwrite(ubp,sizeof(struct book_stack),1,ubfp);
        bmp->borr_sum++;
        
        strcpy(bmp->bbook[t+j].bookname,bookname);
        bmp->bbook[t+j].color=color;
        
        date=get_date();
        year=date/10000;
        day=date%100;
        date%=10000;
        mouth=date/100;
        
        if(mouth<=10)
        mouth+=2;
        else if(mouth>10)
        {
        mouth=(mouth+2)%12;
        year++;
        }
        date=year*10000+mouth*100+day;
        bmp->bbook[t+j].return_date=date;
        
       fclose(ubfp);
  	   }
  	   else
  	   	{
  	   	printf("Can't borrow now!Sorry\n");
  	   	j--;
  	    }
  	   
  	}
  	bmp->borr_books+=count;
  	strcpy(bmp->idnumber,idnum);
  	
  	if((bmfp=fopen("E:\\book_stack\\borr","rb+"))==NULL)
  	{
  	  	printf("Can't open the required FIle\n");
  	  	exit(0);
  	}
  	if(book1)
  	 fseek(bmfp,-1*sizeof(struct borrow_man),1);
  	 fwrite(bmp,sizeof(struct borrow_man),1,bmfp);
  	 
  	 fclose(bmfp);
  	  
  }
/*****************************************/
/*此函数用来得到当前借书的日期，函数返回值为长长整形，
为十进制下 8位数 前四位为年份，接下来两位是月份，最后
两位是号*/
 long long int  get_date(void)
  {
	time_t cur;
	struct tm *local;
	char wday_name[7][10] ={"Sunday","Monday","Tuesday",
	"Wednesday","Thursday","Friday","Saturday"};
	long long int da;
	
	time(&cur);
	local=localtime(&cur);
	
	/*printf("%4d %02d %02d\n",local->tm_year+1900,
    local->tm_mon+1, local->tm_mday);
	printf("%s\n",wday_name[local->tm_wday]);
	printf("%2d %2d %2d\n",local->tm_hour,local->tm_min,local->tm_sec);*/
	da=(local->tm_year+1900)*10000+(local->tm_mon+1)*100+local->tm_mday;
	return da;
	
}
/**************************************/
/*此函数用来建立书库所存图书的文件夹和文件；
函数返回值为整形，若返回 1 则函数执行成功；
若返回 -1 则函数执行失败，参数类型为空*/

int setup_stackfile(void)
{
	FILE *sffp;	
 if(!mkdir("E:\\book_stack"))
 {
	
	if((sffp=fopen("E:\\book_stack\\red","wb+"))==NULL)
	{
		printf("Error while open the FIle\n");
		exit (0);
		
	}
	fclose (sffp);
	if((sffp=fopen("E:\\book_stack\\blue","wb+"))==NULL)
	{
		printf("Error while open the FIle\n");
		exit (0);
		
	}
	fclose (sffp);
	if((sffp=fopen("E:\\book_stack\\green","wb+"))==NULL)
	{
		printf("Error while open the FIle\n");
		exit (0);
		
	}
	fclose (sffp);
	if((sffp=fopen("E:\\book_stack\\gold","wb+"))==NULL)
	{
		printf("--Error while open the FIle\n");
		exit (0);
		
	}
	fclose (sffp);
	if((sffp=fopen("E:\\book_stack\\sliver","wb+"))==NULL)
	{
		printf("Error while open the FIle\n");
		exit (0);
		
	}
	
	fclose (sffp);
	return 1;
    }
	else
	return -1;
} 
int inti (void)
{

	int i,j;
	i=setup_stackfile();
	FILE *infp;
	
	struct load_man test[3]={{"11111",1,"user1",0,"888888"},
	{"11112",1,"user2",0,"888888"},{"111113",1,"user3",0,"888888"}};
	
	if((infp=fopen("E:\\book_stack\\managername","wb+"))==NULL)
	{
		printf("Error while open the FIle\n");
		exit (0);
	}
	for(i=0;i<3;i++)
	fwrite(&test[i],sizeof(struct load_man),1,infp);
	fclose(infp);
	
	if((infp=fopen("E:\\book_stack\\stuname","wb+"))==NULL)
	{
		printf("Error while open the FIle\n");
		exit (0);
    }
	for(i=0;i<3;i++)
	fwrite(&test[i],sizeof(struct load_man),1,infp);
	fclose(infp);
	
	struct book_stack sample[3]={{1,"AAAAA",100,"11111",20},
	{1,"BBBBB",90,"11112",20},{1,"CCCCC",80,"11113",20}};
		char dir[5][30]={{"E:\\book_stack\\red"},
	                 {"E:\\book_stack\\green"},
	                 {"E:\\book_stack\\gold"},
	                 {"E:\\book_stack\\sliver"},
	                 {"E:\\book_stack\\blue"}};
for(j=0;j<5;j++)
{
	if((infp=fopen(dir[j],"rb+"))==NULL)
	  {
	  	printf("Error while open File:\n");
	  	printf("%s\n",dir[j]);
	  	exit(0);
	  }
	for(i=0;i<3;i++)
	fwrite(&sample[i],sizeof(struct book_stack),1,infp);
	fclose(infp);
}

    if((infp=fopen("E:\\book_stack\\borr","wb+"))==NULL)
    {
    	printf("Error while open the borr FIle\n");
		exit (0);
    }
    fclose(infp);
	
	return 0;
}
FILE* watch(int type ,char *idnum)
{


	struct borrow_man *wp,now_watch;
	wp=&now_watch;
	
	int flag=0,i,from,year,mouth,day,mmm;
	FILE *wfp;
	if(type==0)
	{
	  if((wfp=fopen("E:\\book_stack\\borr","rb+"))==NULL)
	   {
	   	printf("Error while open requied File:\n");
		puts("E:\\book_stack\\borr\n");
	   }
	   while(!feof(wfp))
       {
       	fread(wp,sizeof(struct borrow_man),1,wfp);
       	if(strcmp(wp->idnumber,idnum)==0)
       	{
       		flag=1;
       		break;
       	}
       	//printf("....................there\n");
       	//printf("%s\n",idnum);
       	//printf("%s\n",wp->idnumber);
	   }	   
	   if(!flag)
	   {
	   	printf("\tSORRY!  No records of You!!!\n");
	   	return NULL;
	   }
	   if(flag)
	   {
	   printf("\tMr or Miss : %s\n",idnum);
	   printf("You have borrowed %d books\n",wp->borr_books);
	   
	   for(i=0;i<wp->borr_books;i++)
	   {
	   	printf("第%d本  %s\n",i+1,wp->bbook[i].bookname);
	   	printf("From: ");
	   	  from=wp->bbook[i].color;
	   	  switch(from)
	   	  {
	   	  	 case 1:puts("Technology and Engeering stack.");break;
			 case 2:puts("Literature and History stack.");break;	   
			 case 3:puts("Social science stack.");break;	   
	   	  	 case 4:puts("Nature science stack.");break;
	   	  	 case 5:puts("Newspapres and Magazines.");break;
	   	  	default: break;
	   	  }
	   	  year=wp->bbook[i].return_date/10000;
	   	  day=wp->bbook[i].return_date%100;
	   	  mmm=wp->bbook[i].return_date%10000;
	   	  mouth=mmm/100;
	   	  printf("Deadline to return:\n%4d 年%2d 月%2d 日\n\n",year,mouth,day);
	   	 
	   }
	   return wfp;
       }
	 
    }
	else
	return NULL;

}
/************************************/
/*还书函数，返回值为整形；参数为当前登录用户的学生证号
此函数暂时只能有学生用户调用，学生所还数目最多为当前所
有在借图书*/
int user_return(char *idnum)
 {
 	FILE *urfp=NULL, *bmfp=NULL,*ans;
 	struct borrow_man *bmp,now_return,*bbp,now_store;;
 	bmp=&now_return;
 	bbp=&now_store;
 	struct book_stack *rep,now_re;
 	rep=&now_re;
 	
 	int ss=0,num=0,i,j,book[5],count,stack;
 	memset(book,0,sizeof(book));
 	
 	
	if((ans=watch(0,uni_id))==NULL)
	 {
		return 0;
     }
    else
    {
    	fseek(ans,-1*sizeof(struct borrow_man),1);
        fread(bmp,sizeof(struct borrow_man),1,ans);
    	
    	printf("Please enter the sum You want to return :    ");
    	scanf("%d",&ss);
    	
    	if(ss > bmp->borr_books)
    	 ss=bmp->borr_books;
    	
    	for(i=0;i<ss;i++)
    	{
    		printf("Please enter the number of book You want to return :    ");
    		scanf("%d",&num);
    		switch(num)
    		{
    		 case 0:  book[0]=1;break;
    		 case 1:  book[1]=1;break;
    		 case 2:  book[2]=1;break;
			 case 3:  book[3]=1;break;
			 case 4:  book[4]=1;break;	 
    		 	default: break;
    		
    	    }
        }
        
			for(i=0;i<5;i++)
			{
			   if(!book[i])
			    continue;
			    else
			    {
			    	stack=bmp->bbook[i].color;
			    	switch(stack)
			    	{
			    		case 1:  
						 if((urfp=fopen("E:\\book_stack\\red","rb+"))==NULL)
			    		   {
			  
      		    printf("ERROR while open the file,can't return \n");
			    		    exit(0);
						   }
						 break;
			    		case 2: if((urfp=fopen("E:\\book_stack\\green","rb+"))==NULL)
			    		   {
			    		    printf("ERROR while open the file,can't return \n");
			    		    exit(0);
						   }
						break;
			    		case 3:if((urfp=fopen("E:\\book_stack\\gold","rb+"))==NULL)
			    		   {
			    		    printf("ERROR while open the file,can't return \n");
			    		    exit(0);
						   } 
						   break;
			    		case 4: if((urfp=fopen("E:\\book_stack\\sliver","rb+"))==NULL)
			    		   {
			    		    printf("ERROR while open the file,can't return \n");
			    		    exit(0);
						   }
						   break;
			    		case 5:if((urfp=fopen("E:\\book_stack\\blue","rb+"))==NULL)
			    		   {
			    		    printf("ERROR while open the file,can't return \n");
			    		    exit(0);
						   }
						    break;
			    		default: break;
			    	}
			    	while(!feof(urfp))
			    	{
			    		fread(rep,sizeof(struct book_stack),1,urfp);
			    		if(strcmp(rep->book_name,bmp->bbook[i].bookname)==0)
			    		 {
			    		 rep->left++;
			    		 break;
			    	     }
			    	}
			    	fseek(urfp,-1*sizeof(struct book_stack),1);
			    	fwrite(rep,sizeof(struct book_stack),1,urfp);
			    	fclose(urfp);
			    }
			}
        
 	    	for(i=0,count=0;i<5;i++)
 	    	{
 	    	    
 	    		if(book[i])
 	    		{
 	    		 bmp->borr_books--;
 	    		 continue;
				}  
				else if(!book[i])
 	    		bbp->bbook[count++]=bmp->bbook[i];  
 	    	}
 	    	//printf("shengxia:            %d\n",count);
 	        for(i=0;i<count;i++)
 	         {
 	         bmp->bbook[i]=bbp->bbook[i];
 	         //printf("==========%s\n",bmp->bbook[i].bookname);
 	         }
 	        fseek(ans,-1*sizeof(struct borrow_man),1);
            fwrite(bmp,sizeof(struct borrow_man),1,ans);
			fclose(ans);
			
   }  
 }
 /********************************************/
 /*此函数用来删除书库中的图书，只能有管理员调用此函数
 函数返回值为整形，参数为当前登录的管理员的  ID 注意 
 此函数并未真正从磁盘中删除数据，只是被删除的数据无法
 再被程序读入*/ 
int manager_delete(char *idnum)
{
	FILE *mdfp=NULL;
	struct book_stack *mdp,now_delete;
	mdp=&now_delete;
	
	
	int stack_num=0,stack=0,ss;
	char rece[20];
	
	printf("请输入参与操作的书库数:    ");
	scanf("%d",&stack_num);
	
	putchar(10);
	putchar(10);
	printf("\t1. Technology and Engeering stack.\n");
	printf("\t2. Literature and History stack.\n");
	printf("\t3. Social science stack.\n");
	printf("\t4. Nature science stack.\n");
	printf("\t5. Newspapres and Magazines.\n");
	putchar(10);
	
	while(stack_num--)
	{
	  printf("请输入书库的编号:   ");
	  scanf("%d",&stack);	
		switch(stack)
		 {
		 	            case 1:  
						 if((mdfp=fopen("E:\\book_stack\\red","rb+"))==NULL)
			    		   {
			    		    printf("ERROR while open the file,can't return \n");
			    		    exit(0);
						   }
						 break;
			    		case 2: if((mdfp=fopen("E:\\book_stack\\green","rb+"))==NULL)
			    		   {
			    		    printf("ERROR while open the file,can't return \n");
			    		    exit(0);
						   }
						break;
			    		case 3:if((mdfp=fopen("E:\\book_stack\\gold","rb+"))==NULL)
			    		   {
			    		    printf("ERROR while open the file,can't return \n");
			    		    exit(0);
						   } 
						   break;
			    		case 4: if((mdfp=fopen("E:\\book_stack\\sliver","rb+"))==NULL)
			    		   {
			    		    printf("ERROR while open the file,can't return \n");
			    		    exit(0);
						   }
						   break;
			    		case 5:if((mdfp=fopen("E:\\book_stack\\blue","rb+"))==NULL)
			    		   {
			    		    printf("ERROR while open the file,can't return \n");
			    		    exit(0);
						   }
						    break;
			    		default: break;
		 }
		  printf("请输入要删除的书种数:\n");
		  scanf("%d",&ss);
		while(ss--)
		{
		    printf("Please enter the bookname:\n");
		 	scanf("%s",rece);
		 	rewind(mdfp);
		 	while(!feof(mdfp))
             {
             	fread(mdp,sizeof(struct book_stack),1,mdfp);
             	if(strcmp(rece,mdp->book_name)==0)
             	 {
             	 	mdp->exist=0;
             	 	book_delete++; 
             	 	fseek(mdfp,-1*sizeof(struct book_stack),1);
             	 	fwrite(mdp,sizeof(struct book_stack),1,mdfp);
					  break;//quanjubianlian
             	 }
             }		 	
	    }
		fclose (mdfp);
	}
	return 0;
}

/*****************************************/
/*此函数用来查找各个书库中被借阅次数最多的书，参数为空，
返回值为空，管理员和学生用户均可调用此函数*/
void top_search(void)
{
	struct book_stack *tsp,now_top,*tsp1,now_top1;
	tsp=&now_top;
	tsp1=&now_top1;
	
	FILE *tsfp=NULL;
	int top=0,i;
	char dir[5][30]={{"E:\\book_stack\\red"},
	                 {"E:\\book_stack\\green"},
	                 {"E:\\book_stack\\gold"},
	                 {"E:\\book_stack\\sliver"},
	                 {"E:\\book_stack\\blue"}};
for(i=0;i<5;i++)
{
	
	if((tsfp=fopen(dir[i],"rb+"))==NULL)
	  {
	  	printf("Error while open File:\n");
	  	printf("%s\n",dir[i]);
	  	exit(0);
	  }
	  fread(tsp1,sizeof(struct book_stack),1,tsfp);
	  rewind(tsfp);
	while(!feof(tsfp))
	 {
	 	fread(tsp,sizeof(struct book_stack),1,tsfp);
	 	 if(tsp->borr_times>tsp1->borr_times&&tsp->exist)
	 	  {
	 	  	tsp1=tsp;
	 	  }
	 	 else if(tsp->borr_times==tsp1->borr_times)
          {
          	if(strcmp(tsp->book_name,tsp1->book_name)<0)
          	 {
          	 	tsp1=tsp;
          	 }
          }	 	
	 }
	 fclose (tsfp);
	 printf("\n    TOP 1 in ");
	  switch(i)
	   {
	   	case 0: puts("Technology and Engineering stack");break;
	   	case 1: puts("Literature and History stack");break;
	   	case 2: puts("Social science stack"); break;
	   	case 3: puts("Nature science stack");break;
	   	case 4: puts("New paper and Magazine stack");break;
	   	default :break;
	   }
	   printf("<< %s >>\n",tsp1->book_name);
}
}
/***************************************/
/*此函数用来注销学生用户，需要管理员权限，函数参数为
当前登录的管理员的 ID*/ 
int student_delete(char *idnum)
{
	FILE *sdfp=NULL;
	struct load_man *sdp,now_delete;
	sdp=&now_delete;
	
	if((sdfp=fopen("E:\\book_stack\\stuname","rb+"))==NULL)
	 {
	 	printf("Error while open File:\n");
	 	puts("E:\\book_stack\\stuname");
	 	exit(0);
	 }
	 
	int delete_sum=0,value;
	char rece[20];
	printf("\n\t请输入要注销的学生总数:\n");
	
	scanf("%d",&delete_sum);
	if(delete_sum<0)
	return -1;
	
	value=delete_sum;
	out:
	while(delete_sum--)
	{
		
		printf("Please enter The student's ID:\n");
		scanf("%s",rece);
		rewind(sdfp);
		while(!feof(sdfp))
         {
         	fread(sdp,sizeof(struct load_man),1,sdfp);
         	if(strcmp(sdp->idnumber,rece)==0)
         	 {
         	 	sdp->exist=0;
         	 	fseek(sdfp,-1*sizeof(struct load_man),1);
         	 	fwrite(sdp,sizeof(struct load_man),1,sdfp);
         	 	stu_delete++; 
         	 	 goto out;
             }
         } 		
		 printf("    No information about this stu!\n");
	}
	  fclose(sdfp);
	return value;	
}


/********************************************/
/*此函数用于学生用户注册，返回值为整形,若函数正常运行
返回值为此次注册的学生总数，参数为当前成功注册的学生，
否则，返回 -1 ；登录的管理员的 ＩＤ　已注册的学生将
无法完成注册*/
int student_register(char *idnum)
{
	FILE *srfp=NULL;
	struct load_man *srp,now_register,*srp1,now_register1;
	srp=&now_register;
	srp1=&now_register1;
	

	int register_sum,count=0;
	printf("\n\t请输入需要注册的学生人数:\n");
	scanf("%d",&register_sum);
	
	if((srfp=fopen("E:\\book_stack\\stuname","rb+"))==NULL)
	  {
	   printf("Error while open the file\n");
	   exit(0);
	  }
	  
	if(register_sum<0)
	   return -1; 
	  
	while(register_sum--)
	{
		out:
		printf("\tPlease enter You stu ID:\n");
		scanf("%s",srp1->idnumber);
		rewind(srfp);
 	    while(!feof(srfp))
	    {
	    fread(srp,sizeof(struct load_man),1,srfp);
		if(strcmp(srp->idnumber,srp1->idnumber)==0&&srp->exist)
		 {
		 	printf("    REGISTERED !!!\n");
		    goto out;	
		 }
	    }
		printf("\tPlease enter Your user Name:\n");
		scanf("%s",srp1->username);
		strcpy(srp1->password,"888888");
		fwrite(srp1,sizeof(struct load_man),1,srfp);
		count++;
	}
	fclose (srfp);
return count;
}

/**********************************/
/*此函数用来向书库中添加新书，函数参数是当前登录的
管理员的 ID ，此函数需要管理员权限；此函数返回值为
整形；既可以向书库中添加已经存在的图书，也可以添加
书库中之前没有的图书,建银您在添加新书是先使用
FILE*  search (int color,char *bookname);函数确认为
新书，再使用此函数，否则将有重复录入的可能 */ 
int manager_add(char *idnum)
{
	FILE *mafp=NULL;
	struct book_stack *map,now_add;
	map=&now_add;
	
	int s=0,stack,choice,flag=0,old_add=0,ss=0;
	char reve[20];
	
	printf("Please enter How many stacks are going to add books:\n");
	scanf("%d",&s);
	printf("\n\t1. Technology and Engeering stack.\n");
	printf("\t2. Literature and History stack.\n");
	printf("\t3. Social science stack.\n");
	printf("\t4. Nature science stack.\n");
	printf("\t5. News paper and Magazine.\n");
	
	while(s--)
	{
		printf("Please enter the num of stack\n");
		scanf("%d",&stack);
		switch(stack)
		 {
		 	            case 1:  
						 if((mafp=fopen("E:\\book_stack\\red","rb+"))==NULL)
			    		   {
			    		    printf("ERROR while open the file,can't return \n");
			    		    exit(0);
						   }
						 break;
			    		case 2: if((mafp=fopen("E:\\book_stack\\green","rb+"))==NULL)
			    		   {
			    		    printf("ERROR while open the file,can't return \n");
			    		    exit(0);
						   }
						break;
			    		case 3:if((mafp=fopen("E:\\book_stack\\gold","rb+"))==NULL)
			    		   {
			    		    printf("ERROR while open the file,can't return \n");
			    		    exit(0);
						   } 
						   break;
			    		case 4: if((mafp=fopen("E:\\book_stack\\sliver","rb+"))==NULL)
			    		   {
			    		    printf("ERROR while open the file,can't return \n");
			    		    exit(0);
						   }
						   break;
			    		case 5:if((mafp=fopen("E:\\book_stack\\blue","rb+"))==NULL)
			    		   {
			    		    printf("ERROR while open the file,can't return \n");
			    		    exit(0);
						   }
						    break;
			    		default: break;
		 }
		 printf("此书库要添加的图书总种数:\n");
		 scanf("%d",&ss);
		 
		 if(ss<0)
		 return -1; 
		 
		while(ss--)
		{
		 there:
		 printf("Add a new kind of book-->1\nothers-->         0\n");
		 scanf("%d",&choice);
		 if(choice==1)
		 {
		 	fseek(mafp,0,2);
		 	printf("Please enter bookname:\n");
		 	scanf("%s",map->book_name);
		 	printf("Please enter ISBN:\n");
		 	scanf("%s",map->isbn);
		 	printf("Please enter the sum of this kind book add:\n");
		 	scanf("%d",&map->left);
		 	
		 	map->exist=1;
		 	map->borr_times=0;
		 	fwrite(map,sizeof(struct book_stack),1,mafp);
		 }
		 else if(choice==0)
		 {
		 	printf("Please enter the bookname:\n");
		 	scanf("%s",reve);
		 	rewind(mafp);
		 	
		 	while(!feof(mafp))
             {
             	fread(map,sizeof(struct book_stack),1,mafp);
             	if(strcmp(reve,map->book_name)==0)
             	 {
             	 	flag=1;
             	 	break;
             	 }
             }		 	
		 	if(flag)
		 	 {
		 	 	printf("请输入此种图书要添加的总数:\n");
		 	 	scanf("%d",&old_add);
		 	 	map->left+=old_add;
		 	 	fseek(mafp,-1*sizeof(struct book_stack),1);
		 	 	fwrite(map,sizeof(struct book_stack),1,mafp);
		 	 }
		 	 else 
		 	 {
		 	 	printf("NEW BOOK!!!\n");
		 	 	goto there;
		 	 }
		 }
	    }
	    fclose (mafp);
	}
	return 1;
}
int menu_manager(void)
{
	int choice=-1;
 printf("                            Welcome Menu_manager\n");
 printf("                          欢迎使用图书管理系统\n");
 printf("    ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
 printf("    ┃1.注册新书                                            ┃\n");
 printf("    ┃2.注销旧书 --------------------------------------     ┃\n");
 printf("    ┃3.学生用户注册                                        ┃\n");
 printf("    ┃4.注销学生用户--------------------------------------  ┃\n");
 printf("    ┃5.修改密码                                            ┃\n");
 printf("    ┃6.修改用户名                                          ┃\n");
 printf("    ┃7.浏览最热图书                                        ┃\n");
 printf("    ┃8.浏览所有图书                                        ┃\n");
 printf("    ┃0.退出                                                ┃\n");
 printf("    ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
 printf("    ======================请选择功能数字编号===================\n");
 scanf("%d",&choice);
 return choice;	
}
 int menu_stu(void)
 {
 		int choice=-1;
 printf("                       Welcome >>> Menu_stu\n");		
 printf("                          欢迎使用图书管理系统\n");
 printf("    ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
 printf("    ┃1.借阅查询                                            ┃\n");
 printf("    ┃2.图书搜索 --------------------------------------     ┃\n");
 printf("    ┃3.借书                                                ┃\n");
 printf("    ┃4.还书--------------------------------------          ┃\n");
 printf("    ┃5.修改密码                                            ┃\n");
 printf("    ┃6.修改用户名                                          ┃\n");
 printf("    ┃7.浏览最热图书                                        ┃\n");
 printf("    ┃8.浏览所有图书                                        ┃\n");
 printf("    ┃0.退出                                                ┃\n");
 printf("    ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
 printf("    ======================请选择功能数字编号===================\n");
 scanf("%d",&choice);
 return choice;	
}
void show_allbooks(void)
{
	struct book_stack *sap,now_show;
	sap=&now_show;
	FILE* safp;
	
	printf("\n\t1. Technology and Engeering stack.\n");
	printf("\t2. Literature and History stack.\n");
	printf("\t3. Social science stack.\n");
	printf("\t4. Nature science stack.\n");
	printf("\t5. News paper and Magazine.\n");
	
	int choice;
	char dir[5][30]={{"E:\\book_stack\\red"},
	                 {"E:\\book_stack\\green"},
	                 {"E:\\book_stack\\gold"},
	                 {"E:\\book_stack\\sliver"},
	                 {"E:\\book_stack\\blue"}};
	printf("请输入要浏览的书库的编号:\n");
	scanf("%d",&choice);
	 
	 if((safp=fopen(dir[choice-1],"rb+"))==NULL)
	   {
	   	printf("Error while open the File\n");
	   	exit(0);
	   }
    while(!feof(safp))
      {
      	fread(sap,sizeof(struct book_stack),1,safp);
      	if(!feof(safp))
      	 {
      	    printf("Name: %s\n",sap->book_name);
			printf("ISBN: %s\n",sap->isbn);
			printf("LEFT:  %d\n",sap->left);
		 	printf("Borrowed times: %d\n\n",sap->borr_times);
		 }
      }
	fclose (safp);
} 
int file_modify (void)
{
	FILE *fmfp=NULL,*fmfp1;
	struct load_man *fmp,now_fm;
	fmp=&now_fm;
	
	int i,j;
	
	if(stu_delete>100)
	{
		if((fmfp=fopen("E:\\book_stack\\stuname","rb+"))==NULL)
		 {
		 	printf("Error while open file\n");
		 	exit(0);
		 }
		if((fmfp1=fopen("E:\\book_stack\\new","wb+"))==NULL)
		 {
		 	printf("Error while creat new file\n");
		 	exit(0);
		 }
		 while(!feof(fmfp))
         {
         	fread(fmp,sizeof(struct load_man),1,fmfp);
         	if(fmp->exist)
         	fwrite(fmp,sizeof(struct load_man),1,fmfp1);
         }  		
		 fclose (fmfp);
		 fclose (fmfp1);
		 
		 i=remove("E:\\book_stack\\stuname");
		 if(!i)
		 j=rename("E:\\book_stack\\new","E:\\book_stack\\stuname");
		 if(!j)
		 {
		 printf("\n\n\tSuccess    :)\n");
		 return 0;
	    }
	}
return -1;
} 




















