/*----------------------------
		  Student_Marks.c
    			Sujan
	      14.10.24
----------------------------*/

#include <stdio.h>
#include <stdlib.h>

// PROTOTYPES
void InputMat(int N, int M, int A[10][10]);
void PrintMat(int N, int M, int A[10][10]);
void MultMat(int N, int P, int M, int A[10][10], int B[10][10], int C[10][10]);

// MAIN METHOD
int main() 
{
	int N, P, M, A[10][10], B[10][10], Mul[10][10];
	
	printf("Add 2 matrices using function sub-programs\n");
	printf("Enter rows and columns and columns:\n");
	scanf("%d%d%d",&N,&P,&M);
	
	printf("Enter %d Numbers into Matrix A:\n",N*P);
	InputMat(N,P,A);
	printf("Enter %d Numbers into Matrix B:\n",P*M);
	InputMat(P,M,B); 
	
	printf("Matrix A:\n");
	PrintMat(N,P,A);
	printf("Matrix B:\n");
	PrintMat(P,M,B);
	
	printf("Multiplied Matrix:\n");
	MultMat(N,P,M,A,B,Mul);
	PrintMat(N,M,Mul);
	
	return 0;
}

// INPUTING MATRIX
void InputMat(int N, int M, int A[10][10])
{
	int i,j;
	int ctr=1;
	for(i=1;i<=N;i++){
		for(j=1;j<=M;j++){
			A[i][j]=ctr;
			ctr++;
		}
	}
	
	printf("Done.\n");
}

// PRINTING MATRIX
void PrintMat(int N, int M, int A[10][10])
{
	int i,j;
	
	for(i=1;i<=N;i++){
		for(j=1;j<=M;j++){
			printf("%d\t|",A[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
}

// MULTIPLYING MATRICES
void MultMat(int N, int P, int M, int A[10][10], int B[10][10], int C[10][10])
{
	int i,j,k;
	
	for(i=1;i<=N;i++){
		for(j=1;j<=M;j++){
			C[i][j]=0;
			for(k=1;k<=P;k++){
				C[i][j]=C[i][j]+A[i][k]*B[k][j];
			}
		}
	}
}
