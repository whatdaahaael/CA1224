/*----------------------------
		Student_Marks.c
			Sujan
	      14.10.24
----------------------------*/

#include <stdio.h>
#include <stdlib.h>

typedef struct StudentType{
	int RegNo;
	char Name[36];
	int M1,M2,M3;
	int Total;
	float Avg;
	int Result;
}STUDENT;

// PROTOTYPES
void fnInputStudentData(); // Input and Process
void fnPrintStudReport();  // Consolidated Report Card
void fnPrintIndReport();   // Individual Report Card
void fnMenu(int *Choice);  // Menu

// GLOBAL VARIABLES
STUDENT S[20];
int N;

// MAIN METHOD
int main()
{
	int Choice;
	fnMenu(&Choice);
	
	while(Choice){
		switch(Choice){
			case 1:
					fnInputStudentData();
					fnMenu(&Choice);
					break;
			case 2:
					fnPrintStudReport();
					fnMenu(&Choice);
					break;
			case 3:
					fnPrintIndReport();
					fnMenu(&Choice);
					break;
			case 4:
					exit(1);
					break;
			defualt:
					fnMenu(&Choice);
					break;
			
		}
	}
}

// INPUTING AND PROCESSING STUDENT DATA
void fnInputStudentData()
{
	int i;
	system("cls");
	
	printf("Enter the number of Students:\n");
	scanf("%d",&N);
	
	for(i=1;i<=N;i++){
		printf("Enter %d Student Data:\n",i);
		printf("Enter RegNo and Name:\n");
		scanf("%d%s",&S[i].RegNo,S[i].Name);
		
		printf("Enter C Prog, FC and Unix Marks:\n");
		scanf("%d%d%d",&S[i].M1,&S[i].M2,&S[i].M3);
		
		S[i].Total = S[i].M1 + S[i].M2 + S[i].M3;
		S[i].Avg=(float)S[i].Total/3;
		
		if(S[i].M1>=35 && S[i].M2>=35 && S[i].M3>=35 && S[i].Avg>=40.0){ // CHANGED
			if(S[i].Avg>=80.0){
				S[i].Result=0;
			} else if(S[i].Avg>=60.0){
				S[i].Result=1;
			} else if(S[i].Avg>=50.0){
				S[i].Result=2;
			} else {
				S[i].Result=3;
			}
		} else {
			S[i].Result=-1;
		}
		
		system("cls");
	}
}

// PRINTING CONSOLIDATED REPORT
void fnPrintStudReport()
{
	int i;
	system("cls");
	
	printf("\t\t\tST JOSEPHS UNIVERSITY\n");
	printf("\t\tConsolidated Student Report\n");
	
	printf(" RegNo\t| Name\t| C Prog| FC\t| Unix\t| Total\t| Avg\t| Result\n");
	
	for(i=1;i<=N;i++){
		printf(" %d\t| %s\t| %d\t| %d\t| %d\t| %d\t| %0.2f\t|",S[i].RegNo,S[i].Name,S[i].M1,S[i].M2,S[i].M3,S[i].Total,S[i].Avg);
		
		switch(S[i].Result){
			case 0:
					printf(" Distinction\n");
					break;
			case 1:
					printf(" First Class\n");
					break;
			case 2:
					printf(" Second Class\n");
					break;
			case 3:
					printf(" Pass\n");
					break;
			case -1:
					printf(" Fail\n");
					break;
			
		}
	}
	
}

// PRINTING INDIVIDUAL CONSOLIDATED REPORT CARD
void fnPrintIndReport()
{
	int i, j=-1, SearchNum;
	system("cls");
	
	printf("Enter the Student Number:\n");
	printf("Available Numbers:\n");
	for(i=1;i<=N;i++){
		printf("  %d\n",S[i].RegNo);
	}
	scanf("%d",&SearchNum);
	
	for(i=1;i<=N;i++){
		if(SearchNum==S[i].RegNo){
			j=i;
			break;
		}
	}
	
	if(j==-1){
		printf("Not Found\n");
		return;
	}

	system("cls");
	printf("\n\nSt Joseph's University\n");
	printf("\tMARKS CARD\t\n");
	printf("RegNo:\t\t%d\n",S[j].RegNo);
	printf("Name:\t\t%s\n",S[j].Name);
	printf("C Prog:\t\t%d\n",S[j].M1);
	printf("Fund Comp:\t%d\n",S[j].M2);
	printf("Unix:\t\t%d\n",S[j].M3);
	printf("Total:\t\t%d\n",S[j].Total);
	printf("Average:\t%0.2f\n",S[j].Avg);
	
	if(S[j].M1>=35.0 && S[j].M2>=35.0 && S[j].M3>=35.0 && S[j].Avg>=40.0) {
		if(S[j].Avg>=75.0){
			printf("DISTINCTION!!\n");
		} else if(S[j].Avg>=60.0){
			printf("1st Class.\n");
		} else if(S[j].Avg>=50.0){
			printf("2nd Class.\n");
		} else {
			printf("Pass.\n");
		}
	} else {
		printf("Student has Failed.\n");
	}
}

// MENU OPTIONS
void fnMenu(int *Choice){
	printf("\n\nEnter choice:\n");
	printf("1. Input Student Data\n");
	printf("2. Print Consolidated Marks Card\n");
	printf("3. Print Individual Marks Card\n");
	printf("4. Exit\n");
	scanf("%d",Choice);
}
