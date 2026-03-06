/*
 * File: college.c
 * Author: Lauren Kimura
 * Last updated: 3/6/2026
 * Description: has a main function that creates an array 
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "dataset.h"

#define MAX_STUDENTS 3000
#define MIN_AGE 18
#define MAX_AGE 30
#define AGE_RANGE (MAX_AGE - MIN_AGE + 1)

int main() {
        srand(time(NULL));
		LIST *studentList = createDataSet(3000);
		int randomID = 0;
		int randomAge = 0;
        for (int i = 1; i < 1000; i++) {
            randomID = randomID + rand()%2+1;
            randomAge = rand() % AGE_RANGE + MIN_AGE;
          	insertion(studentList, randomID, randomAge);
        }
		searchID(studentList, 130);
		deletion(studentList, 141);
		destroyDataSet(studentList);
}
