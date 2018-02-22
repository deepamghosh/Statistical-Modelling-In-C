#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "sta.h"

int main() {  
   /* Start of Declation of varibales of statistical model*/
   char buffer[1024] ;
   char *record,*line;
   int i=0,j=0,k=0,l=0;
   int p,q;
   int count = 0;
   int year;
   float mean1,mean2,maximum1,maximum2,minimum1,minimum2;
   float median1,variance1,std1,kurt1,skew1;
   float data1[150][2]; //matrix with 100 rows and 2 columns in which the 1st dataset will be stored
   float data2[150][2];// matrix with 100 rows and 2 columns in which the 2nd dataset will be stored
   int   *mat1; //pointer storing the reference to the first column of 1st Dataset
   float *mat2; //pointer storing the reference to the second columns of 1st Dataset
   int   *mat11;//pointer storing the reference to the first columns of 2nd Dataset
   float *mat12;//pointer storing the reference to the second columns of 2nd Dataset
   
   /* Take the users Choice */
	int choice;
	printf("Enter Your Choice \n 1 - Statistical Analysis of Rainfall \n 2 - Rainfall Prediction\n\n ");
	scanf("%d",&choice);
	

   
   
   FILE *fstream1  = fopen("bihar-jkh.csv","r"); // pointer storing the referene to the 1st file
   FILE *fstream2  = fopen("coastal.csv","r"); // pointer storing the referene to the 2nd file
   FILE *fstream3  = fopen("gujarat.csv","r"); // pointer storing the referene to the 3rd file
   FILE *fstream4  = fopen("himachalpradesh.csv","r"); // pointer storing the referene to the 4th file
   FILE *fstream5  = fopen("j&k.csv","r"); // pointer storing the referene to the 5th file
   FILE *fstream6  = fopen("kerala.csv","r"); // pointer storing the referene to the 6th file
   FILE *fstream7  = fopen("mp-cg.csv","r"); // pointer storing the referene to the 7th file
   FILE *fstream8  = fopen("maharashtra.csv","r"); // pointer storing the referene to the 8th file
   FILE *fstream9  = fopen("northeast.csv","r"); // pointer storing the referene to the 9th file
   FILE *fstream10 = fopen("punjab.csv","r"); // pointer storing the referene to the 10th file
   FILE *fstream11 = fopen("rajasthan.csv","r"); // pointer storing the referene to the 11th file
   FILE *fstream12 = fopen("subhimalayan.csv","r"); // pointer storing the referene to the 12tt file
   FILE *fstream13 = fopen("tamilnadu.csv","r"); // pointer storing the referene to the 13th file
   FILE *fstream14 = fopen("ap-telangana.csv","r"); // pointer storing the referene to the 14th file
   FILE *fstream15 = fopen("uttarakhand.csv","r"); // pointer storing the referene to the 15th file
   FILE *fstream16 = fopen("uttarpradesh.csv","r"); // pointer storing the referene to the 16th file
   
   /* End of Declaraion of Varibales of Statistical Models */
   
   /* Start of Declaration of Variables of Prediction Model */
    char buffer1[1024] ;
    char *record1,*line1;
    int i1=0,j1=0;
	int p1,q1,count1=0,yes1=0,no1=0;	
    float avgyes,stdevyes,varyes,probabilityyes,x1;
    float avgno,stdevno,varno,probabilityno,x2;
    float part1_yes,part2_yes,denopart1_yes,numpart2_yes,denopart2_yes;
    float part1_no,part2_no,denopart1_no,numpart2_no,denopart2_no;
	float data[1000][2]; // 2D matrix in which the entire dataset will be stored		
    //float yesrainfall[16];
    float *humdyes; //pointer to store yes values of humidity
    float *humdno; // pointer to store no values of humidity
    float *tempyes; // pointer to store yes values of temperature
    float *tempno; // pointer to store no values of temperature
   	
   	FILE *fstream17 = fopen("Book2.csv","r"); // pointer storing the referene to the yes
   
    /* End of Declararion of Variables of Prediction Model */
	 
	/*Checking of file of SM */    
    if(fstream1 == NULL || fstream2 == NULL || fstream3 == NULL || fstream4 == NULL || fstream5 == NULL || fstream6 == NULL 
	|| fstream7 == NULL || fstream8 == NULL || fstream9 == NULL || fstream10 == NULL || fstream11 == NULL || fstream12 == NULL
	|| fstream13 == NULL || fstream14 == NULL || fstream15 == NULL || fstream16 == NULL){
    printf("\n file opening failed "); // if file1 is not there
    return -1 ;
    } 
    
	/*Checking of file of PM */
   	if(fstream17 == NULL){
		printf("\n file opening failed "); // if file1 is not there
     	return -1 ;
    }
   
    /* assigning 0 value to all the rows and the columns of the SM Data Set */
   	for( p = 0 ; p <150; p++){ 
   		for( q = 0; q < 3; q++){
   		data1[p][q] = 0;  
		}
	}
	/* assigning 0 value to all the rows and the columns of the PM Data Set */
     
   	for( p1 = 0 ; p1 < 600; p1++){ // assigning 0 value to all the rows and the columns of the 1st Data Set
   		for( q1 = 0; q1 < 2; q1++){  //600 rows and 2 column
   		data[p1][q1] = 200;  
		}
    }
   if(choice == 1){ 	/* Print Regions on Screen only for Statistical Analysis */
   FILE *select;
   int choice1;
   printf("\nEnter the Region:\n 1-Bihar & Jharkhand \n 2-Coastal Areas \n 3-Gujarat \n 4-Himachal Pradesh \n 5-Jammu & Kashmir \n 6-Kerala \n 7-Madhya Pradesh & Chhattisgarh \n 8-Maharashtra \n 9-NorthEast \n 10-Punjab \n 11-Rajasthan \n 12-SubHimalayan \n 13-TamilNadu \n 14-Andhra Pradesh & Telengana \n 15-Uttrakhand \n 16-Uttar Pradesh\n");
   scanf("\n%d",&choice1);
   switch(choice1){
   	case 1: {
   		//printf("fault");
   		select = fstream1;
   		break;
	}
   	case 2: {
  		select= fstream2;//printf("fault");
		break;
	}
	case 3: {
		//printf("fault");
		select = fstream3;
		break;
	}
	case 4: {
		//printf("fault");
		select = fstream4;
		break;
	}
	case 5: {
		//printf("fault");
		select = fstream5;
		break;
	}
	case 6: {
		//printf("fault");
		select = fstream6;
		break;
	}
	case 7: {printf("fault");
		select = fstream7;
		break;
	}
	case 8: {printf("fault");
		select = fstream8;
		break;
	}
	case 9: {//printf("fault");
		select = fstream9;
		break;
	}
	case 10: {//printf("fault");
		select = fstream10;
		break;
	}
	case 11: {//printf("fault");
		select = fstream11;
		break;
	}
	case 12: {//printf("fault");
		select = fstream12;
		break;
	}
	case 13: {//printf("fault");
		select = fstream13;
		break;
	}
	case 14: {//printf("fault");
		select = fstream14;
		break;
	}
	case 15: {//printf("fault");
		select = fstream15;
		break;
	}
	case 16: {//printf("fault");
		select = fstream16;
		break;
	}
	default:
		printf("Wrong Choice Entered \n");
}
    /*Importing 1st Dataset - SM*/
    while((line=fgets(buffer,sizeof(buffer),select))!=NULL) { // fetching the file row the dataset
    	record = strtok(line,",");
    	while(record != NULL) {
   		data1[i][j++] = atof(record); // storing the data into the 2D matrix
    	record = strtok(NULL,",");
    	}
    ++i ;
    j=0;
   }
}//printf("fault1");
   /* Importing Dataset - PM */
    while((line1=fgets(buffer1,sizeof(buffer1),fstream17))!=NULL) { // fetching the file row the dataset
    //printf(line);
    	record1 = strtok(line1,",");
    	while(record1 != NULL) {
    	data[i1][j1++] = atof(record1); // storing the data into the 2D matrix
     	record1 = strtok(NULL,",");
    	}
    ++i1 ;
    j1=0;
   }
   /* finding the total number of rows in the SM dataset which are present in the matrix */
    for(i = 0; i <150 ; i++) {	
	j = 0;
	if(data1[i][j] != 0) {
		count++; //counting number of rows with entries 
	}
   }
   /* finding the total number of rows in the SM dataset which are present in the matrix */
   	for(i1 = 0; i1 < 600; i1++) {	
	j1 = 0;
	if(data[i1][j1] != 200) {
		count1++; //counting number of rows with entries 
	}
   }
   	//printf("Total Number of Rows in the Matrix1 %d\n", count); //number of rows in the SM matrix with entries from the dataset1
	//printf("\n%d",count1); ////number of rows in the PM matrix with entries from the dataset1
   	 
   /*printing the 2D matrix of SM 
   for(i = 0;i < count; i++){
   	for(j = 0;j < 2; j++){
   		printf("%.1f ",data1[i][j]); 
	}
   printf("\n");
   }
   */
   /* printing the 2D matrix of PM
   for(i1 = 0;i1 < count1; i1++){
   	for(j1 = 0;j1 < 2; j1++){
   		printf("%.1f ",data[i1][j1]); 
	}
   printf("\n");
   } */
   
   /*counting the total number of '1' values of rain*/
   for(i1 = 0; i1< 600; i1++){
   	j1 = 1;
   	if(data[i1][j1] == 1){
   		yes1++;
	   }
   }
   no1 = count1 - yes1; //total number of '0' values of rain
   
   //printf("\n%d",yes1);
   //printf("\n%d",no1);
   
   /*allocation of memory of the different columns of SM Dataset*/
   mat1 = (int *)calloc(count, sizeof(int)); 
   mat2 = (float *)calloc(count, sizeof(float));
   mat11 = (int *)calloc(count, sizeof(int));
   mat12=(float *)calloc(count1, sizeof(float)); 
   
   /* verify if allocation successful */
    if ((mat1 || mat2) == NULL) {
            printf("Error: Allocation Failed!");
            exit(EXIT_FAILURE);
    }
    
    /*allocation of memory of the different class of PM Dataset*/
   humdyes = (float *)calloc(yes1, sizeof(float));
   humdno  = (float *)calloc(no1, sizeof(float));
   tempyes = (float *)calloc(yes1, sizeof(float));
   tempno  = (float *)calloc(no1, sizeof(float));
   
   /* verify if allocation successful */
    if ((humdyes || humdno) == NULL) {
            printf("Error: Allocation Failed!");
            exit(EXIT_FAILURE);
    }
 
   /* Start of Separation of Columns of the Dataset in individual arrays in SM */
    	
   for(i=0; i< count; i++){	//separating the 1st column into an array
    	j=0;
		*(mat1+i) = data1[i][j];
	}
	/*int a=0;
	printf("1st Column: \n");
	while (a < count) {
          printf("%d ", *(mat1 + a)); //printing the separated array of the 1st column
            a++;
    }printf("\n\n\n");
    */
    for(i=0; i< count; i++){	//separating the 2nd column into an array
    	j=1;
		*(mat2+i) = data1[i][j];
	}
	/*int b=0;
	printf("2nd Column: \n");
	while (b < count) {
            printf("%.1f ", *(mat2  + b)); //printing the separated array of the 2nd column
            b++;
    }printf("\n");
    */
	
	for(i=0; i< count1; i++){	//separating the 2nd column into an array
    	j=1;
		*(mat12+i) = data2[i][j];
	}
	/* End of Separation of Columns of the Dataset in individual arrays in SM */
   
   	/* Start of Separation of Columns of the Dataset in individual arrays in PM */
   
	/*assigning values to humdyes array */
    for(i1 = 0; i1 < 600; i1++){
    	j1=1;
    	if(data[i1][j1] == 1){
    		*(humdyes + i1) = data[i1][0];
    		//printf("\n%f",*(humdyes+i));
   		}
	}
   
	/*assigning values to humdno array */
    for(i1 = 0; i1 < 600; i1++){
    	j1=1;
    	if(data[i1][j1] == 0){
    		*(humdno + i1) = data[i1][0];
    		//printf("\n%f",*(humdno+i));
   		}
	}
	/* End of Separation of Columns of the Dataset in individual arrays in PM */
   
   /*Calling Different Functions os Statistics Library in SM */

	/*Minimum and Maximum Values and Range of the Data */

	minimum1=minimum(mat2,count);
	maximum1=maximum(mat2,count);
		
	/*Median of the Data */
    median1 = median(mat2,count);
	
	/*Mean of the Data */
	mean1 = mean(mat2, count); 
	
	/* Variance of the Data */
	variance1 = variance(mat2, count);
	
	/*Standard Deviation of the Data */
	std1 = std(mat2,count);
	
	/*Kurtosis of the Data */
	kurt1 = kurt(mat2,count);
	
	/*Skewness of the Data */
	skew1 = skew(mat2,count);
	
//	mode(mat2,count);

	/* Calling Different Function in PM */
	avgyes = mean(humdyes,yes1); //mean of the yes class
	avgno = mean(humdno,no1); //mean of the no class
	stdevyes = std(humdyes,yes1); //standard deviation of the yes class
	stdevno = std(humdno,no1); // standard deviation of the no class
	varyes = variance(humdyes,yes1); //variance of the yes class
	varno = variance(humdno, no1); //variance of the no class
			
	switch (choice){
		case 1: {
			for(year=0;year<count;year++){
				if(data1[year][1]==minimum1){
				printf(" \nMinimum Rainfall takes place in the year %.0f which was recorded %.2f mm",data1[year][0] ,minimum1);	
				}
			}
			for(year=0;year<count;year++){
				if(data1[year][1]==maximum1){
				printf("\nMaximum Rainfall takes place in the year %.0f which was recorded %.2f mm",data1[year][0], maximum1);	
				}
			}
			
			printf("\nMedian of the Rainfall Data is %.2f",median1);
			printf("\nAverage Rainfall is %.2f mm", mean1);
			printf("\nVariance of the Rainfall Data is %.3f", variance1);
			printf("\nStandard Deviation of the Rainfall Data is %.3f", std1);
			if(kurt1 < 3.0){
			printf("\nKurtosis of the Data %.3f  : Distribution is Platykurtic", kurt1);
			} 
			else {
			printf("\nKurtosis of the Data %.3f  : Distribution is Leptokurtic", kurt1);
			}
			if(skew1 < 0.0){
			printf("\nSkewness of the Data %.3f  : Left Skewed", skew1);
			}
			else {
			printf("\nSkewness of the Data %.3f  : Right Skewed", skew1);
			}
			break;
		}
		case 2: {
			printf("\nEnter the expected humidity of the day\n (Idle Range of Humidity is between 40-100)\n");
 			scanf("%f",&x1);
 			if(x1 < 40){
 				printf("please enter value above 40 and below 100");
			 }
			 else{
 			denopart1_yes = 2*3.14*varyes; //denominator of part 1
    		part1_yes = (1/pow(denopart1_yes,0.5)); //part 1
			numpart2_yes = pow((x1-avgyes),2);
			denopart2_yes = 2*varyes; 
			part2_yes = pow(2.718,-(numpart2_yes/denopart2_yes));
			probabilityyes=part1_yes*part2_yes*10000;
       		denopart1_no = 2*3.14*varno; //denominator of part 1
    		part1_no = (1/pow(denopart1_no,0.5)); //part 1
			numpart2_no = pow((x1-avgno),2);
			denopart2_no = 2*varno; 
			part2_no = pow(2.718,-(numpart2_no/denopart2_no));
			probabilityno=part1_no*part2_no*10000;
    		//if(probabilityyes > probabilityno){
    		printf("On the Day with Humidity %.0f, The Chances of Rainfall is  = %f",x1,probabilityyes);
			//}
			//else{
			//printf("On the Day with Humidity %.0f, The Chances of Rainfall is = %f",x1,probabilityno);
			//}
		}
			break;
		}
		default:
			printf("Wrong Choice\n");	
	}
		
		
return 0 ;
}
