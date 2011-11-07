/* 
 * Copyright 2011 ClinRisk Ltd.
 * 
 * This file is part of QCancer(Lung)-2011 (http://qcancer.org/lung).
 * 
 * QCancer(Lung)-2011 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * QCancer(Lung)-2011 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with QCancer(Lung)-2011.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * The initial version of this file, to be found at http://qcancer.org/lung, faithfully implements QCancer(Lung)-2011.
 * We have released this code under the GNU Lesser General Public License to enable others to implement the algorithm faithfully.  
 * However, the nature of the GNU Lesser General Public License is such that we cannot prevent, for example, someone randomly permuting the coefficients. 
 * We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://qcancer.org/lung.
 * Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "lifetimeRisk.h"

#define SIZE_OF_TIME_FILE 24000

unsigned long arrayNumberOfRows;
double *timeTable;

double *resultArray;

int sage=30;
int lage=95; // This will be overwritten in loadTable

void loadTable(char *timeFilename) {
	char timeFile[256];

	unsigned long timeTableSize = sizeof(double)*SIZE_OF_TIME_FILE*3;
	unsigned long resultTableSize = sizeof(double)*SIZE_OF_TIME_FILE*2;
	double a,b,c;
	int d;
	double *index;
	FILE *in;
	char tmp[512];
	int ret;

	strcpy(timeFile, "./");
	strcat(timeFile, timeFilename);
	strcat(timeFile, ".csv");

	timeTable = malloc(timeTableSize);
	if (timeTable==NULL) {
		printf("alloc of %lu bytes failed\n", timeTableSize);
		exit(1);
	}
	resultArray = malloc(resultTableSize);
	if (resultArray==NULL) {
		printf("alloc of %lu bytes failed\n", resultTableSize);
		exit(1);
	}

	index=timeTable;
	in=fopen(timeFile,"r");
	if (in==NULL) {
		printf("%s not found!\n", timeFile);
		exit(1);
	}
	arrayNumberOfRows=0;
	// Comments begin with "# ", and must be at the start of the file.  The line of code below gets rid of them.
	while ( (ret=fscanf(in, "#%[^\n]\n",tmp)) > 0) ;
	fscanf(in,"%*s\r\n");
	while (!feof(in)) {
		fscanf(in, "%*d,%lf,%lf,%lf,%d\r\n", &a, &b, &c, &d);
		*(index++)=a;
		*(index++)=b;
		*(index++)=c;
		arrayNumberOfRows++;
		if (arrayNumberOfRows >= SIZE_OF_TIME_FILE) {
			printf("Time file too big: need to recompile!\n");
			exit(1);
		}
	}
	fclose(in);

        lage = 30 + d + 1;
        // printf("lage set to %d\n", lage);
}

void printFloatArray(double *array, int dimension, int numberOfRows) {
	double *index=array;
	int i;
	for (i=0; i< numberOfRows*dimension; i++,index++) {
		if ((i+1) % dimension) 
			printf("%e : ", *index);
		else
			printf("%e\n", *index);
	}
}

int find_biggest_t_below_number_in_array(int number, double *array, int arrayNumberOfRows) {
	double *index=array;
	int i;
	int found=0;
	// First check the first number in the table
	// If that's bigger than the number we seek, return -2
	if (*index >= number) {
		return -2;
	}
	for (i=0; i< arrayNumberOfRows; i++) {
		if (*index >= number) {
			found=1;
			break;
		}
		index+=3;
	}
	if (found) {
		i--;
	}
	else {
		i=-1;
	}
	return i;
}

void printRow(int i, double *array) {
	printf("Row %d: %e, %e, %e\n", i, *(array+i*3), *(array+i*3+1), *(array+i*3+2));
}

// Create new array
// & form the product and sum as we go
// return the array
// NB need to multiply cif by 100 to get percentage

double *produceLifetimeRiskTable(double *timeTable, int from, int to, double a_cvd, double a_death) {
	int i;
	// S_1, sum(S_1[n-1] * basehaz_cvd_1) 
	double *lifetimeRiskTable = resultArray;
	double *lifetimeRiskIndex = lifetimeRiskTable;

	// do the first S_1, cif_cvd_1
	double *timeTableIndex = timeTable + from*3;
	double basehaz_cvd_0 = *(timeTableIndex+2);
	double basehaz_death_0 = *(timeTableIndex+1);
	double basehaz_cvd_1 = basehaz_cvd_0 * exp(a_cvd);
	double basehaz_death_1 = basehaz_death_0 * exp(a_death);
	double a = 1 - basehaz_cvd_1 - basehaz_death_1; 
	// printf("_t = %f : basehaz_cvd_0 = %e : basehaz_death_0 = %e : a = %e\n", *(timeTableIndex), basehaz_cvd_0, basehaz_death_0, a); 
	// S_1
	*(lifetimeRiskIndex++)=a; 
	// cif_cvd_1
	*(lifetimeRiskIndex++)=0;
	// next index
	timeTableIndex+=3;
	// do the rest
	for (i=1; i < (to-from+1); i++, timeTableIndex+=3, lifetimeRiskIndex+=2) {
		basehaz_cvd_0 = *(timeTableIndex+2);
		basehaz_death_0 = *(timeTableIndex+1);
		basehaz_cvd_1 = basehaz_cvd_0 * exp(a_cvd);
		basehaz_death_1 = basehaz_death_0 * exp(a_death);
		a = 1 - basehaz_cvd_1 - basehaz_death_1; 
		// S_1
		*lifetimeRiskIndex=*(lifetimeRiskIndex-2)*a;
		// cif_cvd
		*(lifetimeRiskIndex+1) = *(lifetimeRiskIndex-1) + *(lifetimeRiskIndex-2) * basehaz_cvd_1;
	}

	return lifetimeRiskTable;
}

void lifetimeRiskInit(char *timeFilename) {
	loadTable(timeFilename);
}

void lifetimeRiskClose(void) {
	free(resultArray);
	free(timeTable);
}

void lifetimeRisk(int cage, double a_cvd, double a_death, int noOfFollowupYears, double *result) {
	int startRow;
	int finishRow;
	int resultArraySize;
	double lifetimeRisk;
	int followupIndex;
	double nYearRisk;

	// start row is the one with the first _t >= cage-sage
	startRow=find_biggest_t_below_number_in_array(cage-sage, timeTable, arrayNumberOfRows)+1;
	// last row in table has index arrayNumberOfRows -1
	finishRow=arrayNumberOfRows-1;
	resultArraySize = finishRow-startRow+1;

	resultArray = produceLifetimeRiskTable(timeTable, startRow, finishRow, a_cvd, a_death);

	// get lifetime risk
	// this is the last entry in the table!
	lifetimeRisk = *(resultArray + 2*(resultArraySize-1) + 1);	

	// get n-year risk
	// NB followupIndex is one greater than that in the STATA code
	// NB we need some error checking to ensure that this does not go "out of bounds"!!

	followupIndex = cage-sage+noOfFollowupYears;

	// if too big, use lifetime risk instead!
	if (followupIndex >= lage-sage) {
		nYearRisk = lifetimeRisk;
	}
	else {
		int followupRow = find_biggest_t_below_number_in_array(followupIndex, timeTable, arrayNumberOfRows);
		nYearRisk = *(resultArray + 2*(followupRow-startRow) + 1);	
	}

	// printf("%d-year : %5.3f, lifetime: %5.3f\n", noOfFollowupYears, nYearRisk*100, lifetimeRisk*100);
	// printf("%d-year : %f, lifetime: %f\n", noOfFollowupYears, nYearRisk*100, lifetimeRisk*100);

	*result = nYearRisk;
	*(result+1) = lifetimeRisk;

	return; 
}

/*
int main(int argc, char *argv[]) {
	lifetimeRiskInit("timeFilename_0.csv");

	int cage=56;
	double a_cvd=.2264286;
	double a_death=.0106139;
	int noOfFollowupYears = 10;
	double result[2];

	lifetimeRisk(cage, a_cvd, a_death, noOfFollowupYears, &result[0]);
	printf("%d-year : %f, lifetime: %f\n", noOfFollowupYears, result[0] * 100, result[1] * 100);

	lifetimeRiskClose();
}
*/
