#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

#define MAX 256

struct customerInfo{

    int roomNo;
    char name[20];
    char phn[15];
    char adress[30];
    int noPer; //Number of persons staying
    int checkInDate;
    int checkInMon;
    int checkInYear;
    int checkOutDate;

}CI[20];

struct roomInfo{

    int roomNo ;
    char *type[10];
    int bed;
    int ac;
    int rate ;
    int avail;



}RI[10];

void bookings(void);
void header(void);
void createAcc(void);
void deleteAcc(void);
void roomInfo(void);
void checkRoomInfos(void);
void clrscr();
int login(char *fname) ;
void updateRate(void);
void updateRate(void);
void manager(void);
void reception(void);
void checkIn(void);
void checkOut(void);


char *fgetstr(char *string, int n, FILE *stream)
 {
 	char *result;
 	result = fgets(string, n, stream);
 	if(!result)
 		return(result);

	if(string[strlen(string) - 1] == '\n')
		string[strlen(string) - 1] = 0;

	return(string);
}

int main() {
        //   Login System   //
// result=0 ;

    roomInfo();

	int result1 ,result2,choice1 ,choice2;


	do {

		clrscr();
		header();


		printf("  \t Press 1 for Manager and 2 for Receptionist:  :" );

		scanf("%d",&choice1);



		int errno;
		int result ;
		char *argv[2] ;
		if (choice1==1) {
			argv[1]="manager.txt";
		} else if (choice1==2) {
			argv[1]="login.txt";
		}

		result = login(argv[1]);

		if (result==1) {
			break;
		} else if (result==0) {
			printf("\n");
			printf("\n");
			printf("\t\t        ----->>>>>>>>Input -  1  >>to try again .\n\n" );
			printf("\t\t        ----->>>>>>>>Input -  2  >>to exit program .\n\n" );
			printf("\t\t        Input    :  " );
			scanf("%d",&choice2);

			if (choice2==2) {
				printf("\n");
				printf("\n");
				printf("\t\t\t\t\tProgram closing." );
				Sleep(1000);
				printf("." );
				Sleep(1000);
				printf("." );
				Sleep(1000);
				printf("." );
				printf("\n\n\t\t\t\t\tProgram closed..........");
				return ;
			}
		}

	} while(choice2==1);



	if (choice1==1) {
		 manager();
	 } else if (choice1==2) {
		 reception();
	 }


return(0);

}

void checkRoomInfos(void){

    int i ;

    clrscr();

    printf("\n\n" );

    header();

    printf("\n\n\n" );

    printf("\t" );

    printf("Room no\tRoom Type \t Number of Bed     A/C     Rate/Night     Availability[0=available,1=Not available] \n");
    printf("\t_______\t__________\t_______________   _____   _____________  ___________");
    printf("\n");
    for (i = 0; i < 10; i++) {

        Sleep(500);

    printf("\t %d   \t%s\t\t %d\t    %d        $ %d\t     %d \t\t  \n\n",RI[i].roomNo,RI[i].type,RI[i].bed,RI[i].ac,RI[i].rate,RI[i].avail);

    }

    printf("\n\n\t\t Press any key to return to main page _ _ _ " );
    getch();
    main();
}

void manager(void){

        clrscr();
		int choice3 ;
	    header();
		Sleep(1500);
	    printf("                                                      .................WELCOME  MANAGER ...................\n" );
	    printf("\n" );
		Sleep(1500);
	    printf("\n" );

	    printf("\t \t  ------->>>>> INPUT  1 to >> Create new Receptionist account \n\n" );
        Sleep(300);
	    printf("\t \t  ------->>>>> INPUT  2 to >> Delete a Receptioist account  \n\n" );
        Sleep(300);
	    printf("\t \t  ------->>>>> INPUT  3 to >> See Room Informations           \n\n" );
        Sleep(300);
	    printf("\t \t  ------->>>>> INPUT  4 to >> Update Room Rates        \n\n" );
        Sleep(300);
	    printf("\t \t  ------->>>>> INPUT  5 to >> Show customer details                    \n\n" );
        Sleep(300);
        printf("\t \t  ------->>>>> INPUT  6 to >> Sign Out                \n\n" );
        Sleep(300);

	    printf("\t \t  ------->>>>> INPUT  7 to >> Exit program                \n\n" );
	    printf("\n" );
	    printf("\n" );
	    printf("\t\t\t\tEnter your choice   :  " );

	    scanf("%d",&choice3 );
        fflush (stdin);

        switch (choice3) {
            case 1:
                createAcc();
                break;
            case 2:
                deleteAcc();
                break;
            case 3:
                checkRoomInfos();
                break;
            case 4:
                updateRate();
                break;
            case 5:
                bookings();
                break;
            case 6:
                main();
                break;
            case 7:
                exit ;
        }

}


void bookings(void){

    clrscr();

    header();

    printf("\n\t\t\t\t**** Customer Details ****\n\n" );

    FILE *fp;
    char a,b,c ;

    fp=fopen("checkins.txt","r");

    if(fp == NULL)
             {
                    printf("\nCan't open file or file doesn't exist.");
                    exit(0);
             }
             int i=0;
             printf("\n\n \t\t\t\t  ^^^^Informations of customers currently staying in the hotel^^^^ \n" );
             printf("\n\n \t\t\t\t  ^^^^________________________________________________________^^^^ \n\n" );
        while(!feof(fp)){
             fscanf(fp,"%d\n",&CI[i].roomNo);
             printf("\t\t\t\t\t\t Room no : %d  \n\n",CI[i].roomNo );
             fgetstr(CI[i].name, 20, fp);
             printf("\t\t\t Customer Name : %s  \n\n",CI[i].name );
             fgetstr(CI[i].phn, 15, fp);
             printf("\t\t\t Phone no : %s  \n\n",CI[i].phn );
             fgetstr(CI[i].adress, 30, fp);
             printf("\t\t\t Adress : %s  \n\n",CI[i].adress );
             fscanf(fp,"%d\n",&CI[i].noPer);
             printf("\t\t\t Number of persons staying : %d  \n\n",CI[i].noPer );
             fscanf(fp,"%d%c%d%c%d\n",&CI[i].checkInDate,&a,&CI[i].checkInMon,&b,&CI[i].checkInYear);
             printf("\t\t\t Check-In date : %d/%d/%d  \n\n\n",CI[i].checkInDate,CI[i].checkInMon,CI[i].checkInYear);
             //fgetstr(CI[i].checkInDate,10, fp);
             i++;
             Sleep(400);
        }

        fclose(fp);
        printf("\t\t\t Numbers of rooms occupied curently : %d \n\n",i+1 );

        FILE *fp1;

        fp1=fopen("checkouts.txt","r");

        char *checkOutDate[15];
        int bill;
        if(fp1 == NULL)
                 {
                        printf("\nCan't open file or file doesn't exist.");
                        exit(0);
                 }
                 int j=0;
                 printf("\n\n\n\n \t\t\t\t  ^^^^^Informations of customers stayed in the hotel^^^^ \n" );
                 printf("\n\n \t\t\t\t  ______________________________________________________ \n\n" );
            while(!feof(fp1)){
                 fscanf(fp1,"%d\n",&CI[j].roomNo);
                 printf("\t\t\t\t\t\t Room no : %d  \n\n",CI[j].roomNo );
                 fgetstr(CI[j].name, 20, fp1);
                 printf("\t\t\t Customer Name : %s  \n\n",CI[j].name );
                 fgetstr(CI[j].phn, 15, fp1);
                 printf("\t\t\t Phone no : %s  \n\n",CI[j].phn );
                 fgetstr(CI[j].adress, 30, fp1);
                 printf("\t\t\t Adress : %s  \n\n",CI[j].adress );
                 fscanf(fp1,"%d\n",&CI[j].noPer);
                 printf("\t\t\t Number of persons staying : %d  \n\n",CI[j].noPer );
                 fscanf(fp1,"%d%c%d%c%d\n",&CI[j].checkInDate,&a,&CI[j].checkInMon,&b,&CI[j].checkInYear);
                 printf("\t\t\t Check-In date : %d/%d/%d  \n\n\n",CI[j].checkInDate,CI[j].checkInMon,CI[j].checkInYear);
                 fgetstr(checkOutDate,15, fp1);
                 printf("\t\t\t Check-Out date : %s\n\n",checkOutDate);
                 fscanf(fp1,"%d\n",&bill);
                 printf("\t\t\t Total amount paid : %d\n\n",bill);
                 j++;
                 Sleep(500);
            }

            fclose(fp1);

        printf("Press any key to go to main page _ _ _ " );

        getch();

        manager();





}
void reception(void){


		int f ;
        int choice4;

        clrscr();
	    header();
		Sleep(1500);
	    printf("                                                      .................WELCOME  RECEPTIONIST ...................\n" );
	    printf("\n" );
		Sleep(1500);
	    printf("\n" );

	    printf("\t \t  ------->>>>> INPUT  1 to >> CHECK IN \n\n" );
        Sleep(300);
	    printf("\t \t  ------->>>>> INPUT  2 to >> CHECK OUT  \n\n" );
        Sleep(300);
	    printf("\t \t  ------->>>>> INPUT  3 to >> CHECK ROOM AVAILABILITY       \n\n" );
        Sleep(300);
	    printf("\t \t  ------->>>>> INPUT  4 to >> Show customer details       \n\n" );
        Sleep(300);
	    printf("\t \t  ------->>>>> INPUT  5 to >> Sign Out                 \n\n" );
        Sleep(300);
        printf("\t \t  ------->>>>> INPUT  6 to >> Exit program                 \n\n" );
        printf("\n" );
	    printf("\n" );

	    printf("\t\t\t\tEnter your choice   :  " );

	    scanf("%d",&choice4 );

        switch (choice4) {
            case 1:
                checkIn();
                break;
            case 2:
                checkOut();
                break;
            case 4:
                bookings();
                break;
            case 3:
                checkRoomInfos();
                break;
            case 5:
                main();
                break;
            case 6:
                exit ;
        }

}
void clrscr()
{
    system("@cls||clear");
}

void checkIn(void){

    clrscr();

    header();

    printf("\n\n\t\t\t\t\t  *** Input Customer Details  ***" );

    printf("\n\n\t\t\t Room no : ");

    scanf("%d",&CI[0].roomNo);

    fflush(stdin);

    printf("\n\n\t\t\t Name  :  ");

    gets(CI[0].name);

    printf("\n\n\t\t\t Phone no : ");

    gets(CI[0].phn);

    printf("\n\n\t\t\t Adress : ");

    gets(CI[0].adress);

    printf("\n\n\t\t\t Number of persons staying : ");

    scanf("%d",&CI[0].noPer);


        char *ct;

        time_t currentTime ;

        time(&currentTime);

        struct tm *myTime =localtime(&currentTime);

        CI[0].checkInDate= myTime->tm_mday;
        CI[0].checkInMon=myTime->tm_mon;
        CI[0].checkInYear=myTime->tm_year;

    FILE *fp1 ;

    fp1=fopen("checkins.txt","a");

    fprintf(fp1,"%d\n",CI[0].roomNo);
    fprintf(fp1,"%s\n",CI[0].name);
    fprintf(fp1,"%s\n",CI[0].phn);
    fprintf(fp1,"%s\n",CI[0].adress);
    fprintf(fp1,"%d\n",CI[0].noPer);
    fprintf(fp1,"%d/%d/%d\n",CI[0].checkInDate,CI[0].checkInMon+1,CI[0].checkInYear+1900);

    fclose(fp1);

    switch (CI[0].roomNo) {
        case 101:
            RI[0].avail=1 ;
            break;
        case 102:
            RI[1].avail=1 ;
            break;
        case 103:
            RI[2].avail=1 ;
            break;
        case 104:
            RI[3].avail=1 ;
            break;
        case 105:
            RI[4].avail=1 ;
            break;
        case 106:
            RI[5].avail=1 ;
            break;
        case 107:
            RI[6].avail=1 ;
            break;
        case 108:
            RI[7].avail=1 ;
            break;
        case 109:
            RI[8].avail=1 ;
            break;
        case 110:
            RI[9].avail=1 ;
            break;
        default:
            printf("\n\t\t Room No. not valid" );
    }

    FILE *fp3 ;

    int k=0;

    fp3=fopen("avail.txt","w");

    for(k=0;k<10;k++){
        fprintf(fp3,"%d\n",RI[k].avail);
    }

    fclose(fp3);

    printf("\n\n\t\t\t\t\t Check-In complete for %s ",CI[0].name);

    printf("\n\n\t\t\t\t\tCheck-In Date : %d/%d/%d\n",CI[0].checkInDate,CI[0].checkInMon+1,CI[0].checkInYear+1900);


    printf("\n\n\t\t\t\t\t Room no. %d is occupied by %s ",CI[0].roomNo,CI[0].name);

    printf("\n\n\t\tPress any key to return to main page _ _ _ " );

    getch();

    reception();
}

void checkOut(void){

    clrscr();

    header();

    printf("\n\t\t\t\t\t\t\t  **** Check-Out  Page  **** \n" );

    FILE *fp;
    char a,b,c ;

    fp=fopen("checkins.txt","r");

    if(fp == NULL)
             {
                    printf("\nCan't open file or file doesn't exist.");
                    exit(0);
             }
             int i=0;
        while(!feof(fp)){
             fscanf(fp,"%d\n",&CI[i].roomNo);
             fgetstr(CI[i].name, 20, fp);
             fgetstr(CI[i].phn, 15, fp);
             fgetstr(CI[i].adress, 30, fp);
             fscanf(fp,"%d\n",&CI[i].noPer);
             fscanf(fp,"%d%c%d%c%d\n",&CI[i].checkInDate,&a,&CI[i].checkInMon,&b,&CI[i].checkInYear);
             //fgetstr(CI[i].checkInDate,10, fp);
             i++;
        }

                //printf("%d\n%s\n%s\n%s\n%d\n%d/%d/%d",CI[0].roomNo,CI[0].name,CI[0].phn,CI[0].adress,CI[0].noPer,CI[0].checkInDate,CI[0].checkInMon,CI[0].checkInYear);
                //printf("\n");
                //printf("%d\n%s\n%s\n%s\n%d\n%d/%d/%d",CI[0].roomNo,CI[0].name,CI[0].phn,CI[0].adress,CI[0].noPer,CI[0].checkInDate,CI[0].checkInMon,CI[0].checkInYear);

        int roomNo,date,mon,year,bill,stay,rate;

        printf("\n\n\t\t\t Enter the room no :  " );

        scanf("%d",&roomNo);

                char *ct;

                time_t currentTime ;

                time(&currentTime);

                struct tm *myTime =localtime(&currentTime);

                date= myTime->tm_mday;
                mon=myTime->tm_mon;
                year=myTime->tm_year;

        i=0;

        for(i=0;i<10;i++){

            if(roomNo==CI[i].roomNo){
                printf("\n\n\t\t\t Customer Name : %s\n\n",CI[i].name );

                printf("\t\t\t Check-in Date : %d/%d/%d\n",CI[i].checkInDate,CI[i].checkInMon,CI[i].checkInYear );

                printf("\n\t\t\tCheck Out date : %d/%d/%d",date,mon+1,year+1900);

                if (date>CI[i].checkInDate) {
                    stay=date-CI[i].checkInDate;
                } else if (date<CI[i].checkInDate) {
                    stay=(30-CI[i].checkInDate)+date ;
                } else if(date==CI[i].checkInDate){
                    stay=1 ;
                }

                printf("\n\n\t\t\tStay time : %d  days",stay );

                switch (roomNo) {
                    case 101:
                        rate=RI[0].rate;
                        RI[0].avail=0;
                        break;
                    case 102:
                        rate=RI[1].rate;
                        RI[1].avail=0;
                        break;
                    case 103:
                        rate=RI[2].rate;
                        RI[2].avail=0;
                        break;
                    case 104:
                        rate=RI[3].rate;
                        RI[3].avail=0;
                        break;
                    case 105:
                        rate=RI[4].rate;
                        RI[4].avail=0;
                        break;
                    case 106:
                        rate=RI[5].rate;
                        RI[5].avail=0;
                        break;
                    case 107:
                        rate=RI[6].rate;
                        RI[6].avail=0;
                        break;
                    case 108:
                        rate=RI[7].rate;
                        RI[7].avail=0;
                        break;
                    case 109:
                        rate=RI[8].rate;
                        RI[8].avail=0;
                        break;
                    case 110:
                        rate=RI[9].rate;
                        RI[9].avail=0;
                        break;
                }

                bill=stay*rate ;

                printf("\n\n\t\t\tAmount to be paid  : $ %d ",bill);


            FILE *fp ;
            fp=fopen("checkouts.txt","a");
            fprintf(fp,"%d\n",CI[i].roomNo);
            fprintf(fp,"%s\n",CI[i].name);
            fprintf(fp,"%s\n",CI[i].phn);
            fprintf(fp,"%s\n",CI[i].adress);
            fprintf(fp,"%d\n",CI[i].noPer);
            fprintf(fp,"%d/%d/%d\n",CI[i].checkInDate,CI[i].checkInMon,CI[i].checkInYear);
            fprintf(fp,"%d/%d/%d\n",date,mon+1,year+1990);
            fprintf(fp,"%d\n",bill);

            fclose(fp);


            printf("\n\n\t\t\t\tPress any key after reciving payment _ _ _ " );

            getch();
            printf("\n\n\t\t\t\t**** Payment recieved ***** " );

            FILE *fp3 ;

            int k=0;

            fp3=fopen("avail.txt","w");

            for(k=0;k<10;k++){
                fprintf(fp3,"%d\n",RI[k].avail);
            }

            fclose(fp3);

            printf("\n\n\t\t\t Press any key ro return to main page _ _ _");

            getch();

            reception();
        }

}



}

void header(void){
	printf("\n" );
	printf("\n" );


	printf("            ________________________________________________________________________\n");

	printf("            ________________________________________________________________________\n");

	printf("            **********             Hotel Management System             ************\n" );

	printf("            ________________________________________________________________________\n");

	printf("            ________________________________________________________________________\n");


	printf("\n" );
	printf("\n" );

}

int login(char *fname) {

	char name2[4];
	char pass2[4];

	printf("\n");
	printf("\n");

	printf("\t\t\t >>>>>>>>>>>>>LOGIN FIRST TO CONTINUE<<<<<<<<<<<<<<<<\n" );

	printf("\n");
	printf("\n");
	printf("\n");

	printf("                \t User Name  :" );

	scanf("%s",&name2);




	int matchedLine1,matchedLine2 ;
	int line_num = 1;
	int find_result = 0;
	char temp[512];
	int result1 ,result2 ;

	int line_num2 = 1;
	int find_result2 = 0;
	char temp2[512];

	FILE *fp;

	if((fp = fopen(fname, "r")) == NULL) {
		return(-1);
	}
	while(fgets(temp, 512, fp) != NULL) {
		if((strstr(temp, name2)) != NULL) {
			// printf("A match found on line: %d\n", line_num);
			// printf("\n%s\n", temp);
			find_result++;
			result1=1 ;
			matchedLine1=line_num;

		}
		line_num++;
	}


	if(fp) {
		fclose(fp);
	}

	fflush(stdin);

	printf("\n");
	printf("\n");

	printf("                \t Password   :" );

	gets(pass2);

	FILE *fp1;



	if((fp = fopen(fname, "r")) == NULL) {
		return(-1);
	}

	while(fgets(temp2, 512, fp) != NULL) {
		if((strstr(temp2, pass2)) != NULL) {
			// printf("A match found on line: %d\n", line_num2);
			// printf("\n%s\n", temp2);
			find_result2++;
			result2=1 ;
			matchedLine2=line_num2;
		}
		line_num2++;
	}



	if (matchedLine1==matchedLine2-1) {
		clrscr();
		printf("\n");
		printf("               Sign in Successful." );
		Sleep(600);
		printf("." );
		Sleep(600);
		printf("." );
		Sleep(600);
		printf("." );
		Sleep(600);
		printf("." );
		printf("\n");
		return 1 ;

	} else {
		clrscr();
		printf("\n");
		printf("\n\t\t             !!!!!!Wrong username or password!!!!!!!!!!  \n" );
		printf("\n");
		return 0 ;
	}




	if(fp1) {
		fclose(fp1);
	}
   	return(0);
}

void createAcc(void){

    clrscr();
    char name1[20];
    char pass1[10];
    printf("\n\n");
    header();
    printf("\n\n");
    printf("\t\t\t  To Create a new Admin Account First Chosse a Username and a password\n\n\n" );


     FILE *fp ;
     fp=fopen("login.txt","a");
     printf("\n\n\t\t\t\tEnter your desiered username : ");
     scanf(" %s",name1 );
     fprintf(fp,"%s\n",name1 );
     printf("\n");
     printf("\t\t\t\tEnter your desired password : ");
     scanf(" %s",pass1 );
     fprintf(fp,"%s\n",pass1 );


     fclose(fp);

     printf("\n\n\t\t\t\t\tAccount creation Successful\n\n");
     printf("\tPress ant key to return to main page_ _ _ " );
     getch();
     manager();

}

void deleteAcc(){

            clrscr();

            printf("\n\n");

            header();

            printf("\n\n\t\t\tEnter the username of the account you want to delete . \n\n");

    		char name2[4];
    		char fname2[]="login.txt";
    		int matchedLine1;
    		int line_num = 1;
    		int find_result = 0;
    		char temp3[512];



    		printf("\t\t\t\t\t User Name  :" );

    		scanf("%s",&name2);


    		FILE *fp;

    		if((fp = fopen(fname2, "r")) == NULL) {
    			return(-1);
    		}
    		while(fgets(temp3, 512, fp) != NULL) {
    			if((strstr(temp3, name2)) != NULL) {
    				// printf("A match found on line: %d\n", line_num);
    				// printf("\n%s\n", temp);
    				find_result++;
    				matchedLine1=line_num;

    			}
    			line_num++;
    		}


    		if(fp) {
    			fclose(fp);
    		}


    		int lno,lno2, ctr = 0;
            char ch;
            FILE *fptr1, *fptr2;
    		char fname[]="login.txt";
            char str[MAX], temp[] = "temp.txt";

            fptr1 = fopen(fname, "r");
            if (!fptr1)
    		{
                    printf(" File not found or unable to open the input file!!\n");
                    return 0;
            }
            fptr2 = fopen(temp, "w"); // open the temporary file in write mode
            if (!fptr2)
    		{
                    printf("Unable to open a temporary file to write!!\n");
                    fclose(fptr1);
                    return 0;
            }
            lno=matchedLine1;
    		lno2=matchedLine1+1;
            // copy all contents to the temporary file except the specific line
            while (!feof(fptr1))
            {
                strcpy(str, "\0");
                fgets(str, MAX, fptr1);
                if (!feof(fptr1))
                {
                    ctr++;
                    /* skip the line at given line number */
                    if (ctr != lno && ctr != lno2)
                    {
                        fprintf(fptr2, "%s", str);
                    }
                }
            }
            fclose(fptr1);
            fclose(fptr2);
            remove(fname);  		// remove the original file
            rename(temp, fname); 	// rename the temporary file to original name
            Sleep(2000);
            printf("\n\n\t\t\t %s account deleted ......",name2);
            Sleep(2000);
            printf("\n\n\t\tReturning to main page " );
            Sleep(1000);
            printf(" ." );
            Sleep(1000);
            printf(" ." );
            Sleep(1000);
            printf(" ." );

            manager();
}

void updateRate(void){

    int roomNo,i,rate ;

    clrscr();

    header();

    printf("\n\n\t\t\t\t **Current Room Rates**\n" );

    printf("\n\n\t\t Room no\t Room Type\t  Rate/Night  \n\n" );

    for (i = 0; i < 10; i++) {

        Sleep(300);

        printf("\t\t  %d   \t %s\t     $ %d\  \n\n",RI[i].roomNo,RI[i].type,RI[i].rate);

    }

    printf("\n\n\n" );
    printf("\t\tEnter the Room no to change rate : ");

    scanf("%d",&roomNo);

    printf("\n\n\t\tEnter new rate of the room  : " );

    scanf("%d",&rate );

    switch (roomNo) {
        case 101:
            RI[0].rate=rate ;
            break;
        case 102:
            RI[1].rate=rate ;
            break;
        case 103:
            RI[2].rate=rate ;
            break;
        case 104:
            RI[3].rate=rate ;
            break;
        case 105:
            RI[4].rate=rate ;
            break;
        case 106:
            RI[5].rate=rate ;
            break;
        case 107:
            RI[6].rate=rate ;
            break;
        case 108:
            RI[7].rate=rate ;
            break;
        case 109:
            RI[8].rate=rate ;
            break;
        case 110:
            RI[9].rate=rate ;
            break;
        default:
            printf("\n\t\t Room No. not valid" );
    }

    FILE *fp3 ;

    int k=0;

    fp3=fopen("rates.txt","w");

    for(k=0;k<10;k++){
        fprintf(fp3,"%d\n",RI[k].rate);
    }

    fclose(fp3);


    printf("\n\n\t\tRate of the room changed..\n");

    printf("\n\t\tPress any key to go to main page_ _ _ " );

    getch();

    manager() ;

}

void roomInfo(void){

    RI[0].roomNo=101;
    RI[1].roomNo=102;
    RI[2].roomNo=103;
    RI[3].roomNo=104;
    RI[4].roomNo=105;
    RI[5].roomNo=106;
    RI[6].roomNo=107;
    RI[7].roomNo=108;
    RI[8].roomNo=109;
    RI[9].roomNo=110;

    strcpy(RI[0].type,"Standard    ");
    strcpy(RI[1].type,"Standard    ");
    strcpy(RI[2].type,"Standard    ");
    strcpy(RI[3].type,"Standard    ");
    strcpy(RI[4].type,"Delux       ");
    strcpy(RI[5].type,"Delux       ");
    strcpy(RI[6].type,"Delux       ");
    strcpy(RI[7].type,"Premier Suit");
    strcpy(RI[8].type,"Premier Suit");
    strcpy(RI[9].type,"Oceanview   ");

    RI[0].bed=1;
    RI[1].bed=1;
    RI[2].bed=2;
    RI[3].bed=2;
    RI[4].bed=1;
    RI[5].bed=1;
    RI[6].bed=2;
    RI[7].bed=3;
    RI[8].bed=4;
    RI[9].bed=1;

    RI[0].ac=0;
    RI[1].ac=1;
    RI[2].ac=0;
    RI[3].ac=1;
    RI[4].ac=1;
    RI[5].ac=1;
    RI[6].ac=1;
    RI[7].ac=1;
    RI[8].ac=1;
    RI[9].ac=1;


    FILE *fp2 ;

    int j=0;

    fp2=fopen("rates.txt","r");

    while (!feof(fp2)) {
        fscanf(fp2,"%d",&RI[j].rate);
        j++;
    }

    fclose(fp2);




    FILE *fp1 ;

    int i=0;

    fp1=fopen("avail.txt","r");

    while (!feof(fp1)) {
        fscanf(fp1,"%d",&RI[i].avail);
        i++;
    }

    fclose(fp1);




}
