/*
 * File: dataset.c
 * Author: Lauren Kimura
 * Last updated: 3/5/2026
 * Description: This file uses an array of students with an ID and age. It is an ADT wih functions createDataset, destroyDataset, Insertion, Deletion, and SearchID
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include "dataset.h"

/*
 * Defines a student with an age and id
 */
typedef struct student
{
    int id;
	int age;
} STUDENT;

/*
 * Defines a list with an array, each slot is pointing to a student. Has a count for how amny student and max length.
 */
typedef struct list{
  STUDENT **sp;
  int count;
  int length;
} LIST;

/*
 * Big-O: O(n) n is the number of max elements in array
 *
 * Average: O(n)
 *
 * Worst case: O(n)
 *
 * The createDataSet funcion takes in the max array size called maxElts as an  argument. It creates the lp, setting max length to maxElts and current count to 0. It gives memory to the lp for sp (student pointer), then gives sp memory to each of those slots. This returns the lp.
 */
LIST *createDataSet(int maxElts)
{
	LIST *lp = malloc(sizeof(LIST));
    assert(lp != NULL);
	lp->length = maxElts;
	lp->count = 0;
	lp->sp = malloc(sizeof(STUDENT*)*maxElts);
	assert(lp != NULL);
	for(int i = 0; i < maxElts; i++) {
		lp->sp[i] = malloc(sizeof(STUDENT));
		assert(lp->sp[i] != NULL);
	}
	return lp;
}

/*
 * Big-O: O(n), n is the number of max elements in the array
 *
 * Average: O(n)
 *
 * Worst case: O(n)
 *
 * The destroyDataSet function takes in one lp as an argument. It frees each of the points in the sp, then frees the sp itself, then the lp. This returns nothing.
 *
 */
void destroyDataSet(LIST *lp)
{
	assert(lp != NULL);
	for(int i = 0; i < lp->length; i++) {
		free(lp->sp[i]); 
	}
	free(lp->sp);
	free(lp);
	printf("Successfully deleted list\n");
}

/*
 * Big-O: O(1)
 * 
 * Average: O(1)
 *
 * Worst Case: O(1)
 *
 * The searchID function takes one lp and an Id as arguments. If there is not student with that id, it returns -1. Else, it prints the student's ID's and returns the id
 *
 */
int searchID(LIST *lp, int findId)
{	
	assert(lp != NULL);
	if (lp->sp[findId]->id != findId) {
		printf("No student with id: %d\n", findId);
		return -1;
	}
	printf("Student %d found!\n", findId);
	return lp->sp[findId]->id;
}


/*
 * Big-O: O(1)
 *
 * Average: O(1)
 *
 * Worst Case:O(1)
 *
 * The insertion function takes in one LIST lp, and int newId and one int newAge as arguments. It uses the student Id to insert the new student in that index in lp. It sets that point's id to the newId, the age to the new age, and increments count. This returns nothing
 * 
 */
void insertion(LIST *lp, int newId, int newAge)
{
	assert(lp != NULL && lp->count < lp ->length);
	lp->sp[newId]->id = newId;
	lp->sp[newId]->age = newAge;
	printf("New student added with ID: %d\n", newId);
	lp->count++;
	return;
}

/*
 * Big-O: O(1)
 * 
 * Average: O(1)
 *
 * Worst Case: O(1)
 *
 * The deletion function takes in one list of lp and one delId as arguments. It checks if that slot is NULL or if the current Id is not the id intending to delete, and if so returns. Else, it frees that Id point in lp, sets that point to NULL, and decrements count. This returns nothing
 */
void deletion (LIST *lp, int delId)
{
	assert(lp!= NULL);
	if (lp->sp[delId] == NULL || lp->sp[delId]->id != delId) {
		printf("Student %d could not be deleted, not in list\n", delId);
		return;
	}
	free(lp->sp[delId]);
	lp->sp[delId] = NULL;
	lp->count--;
	printf("deleted student %d\n", delId);
	return;
}


