/*
 * File: dataset.c
 * Author: Lauren Kimura
 * Last updated: 3/5/2026
 * Description: This 
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include "dataset.h"

/*
 * Defines a student of a certain age with an ID pointing to next and prev
 */
typedef struct student
{
    int id;
	int age;
} STUDENT;

/*
 * Defines an List where the ages are stored, with a max length and current student count.
 */
typedef struct list{
  STUDENT **slp;
  int count;
  int length;
} LIST;

/*
 * Big-O: O(m) m is the differant types of ages in array
 *
 * Average: O(m)
 *
 * Worst case: O(m)
 *
 * The createDataSet function takes in the max array size called maxElts as an  argument. It creates the lp, setting studentCount to 0, the length of maxElts, and distributes memory to the array in lp that size of 13 (18-30). In the lp there is a list of AGES with a dummy head pointer. each node is a STUDENT that is doubly linked. It returns the list lp
 */
LIST *createDataSet(int maxElts)
{
	LIST *lp = malloc(sizeof(LIST));
    assert(lp != NULL);
	lp->length = maxElts;
	lp->count = 0;
	lp->slp = malloc(sizeof(STUDENT*)*maxElts);
	assert(lp != NULL);
	for(int i = 0; i < maxElts; i++) {
		lp->slp[i] = malloc(sizeof(STUDENT));
		assert(lp->slp[i] != NULL);
	}
	return lp;
}

/*
 * Big-O: O(m), m is the differant types of ages in array
 *
 * Average: O(m)
 *
 * Worst case: O(m)
 *
 * The destroyDataSet function takes in one lq as an argument. It frees each of the age heads and AGES in the array, then frees the array itself, and finally the lp. This returns nothing.
 *
 */
void destroyDataSet(LIST *lp)
{
	assert(lp != NULL);
	for(int i = 0; i < lp->length; i++) {
		free(lp->slp[i]); 
	}
	free(lp->slp);
	free(lp);
	printf("Successfully deleted list\n");
}

/*
 * Big-O: O(m) m is the differant types of ages in array
 *
 * Average: O(m), getting age O(1), but returning each ID is O(m)
 *
 * Worst Case: O(m)
 *
 * The searchAge function takes one lp and an age as arguments. If there is not student with that age, it returns. Else, it prints out all the student's ID's with that age and reutns nothing
 *
 */
int searchID(LIST *lp, int findId)
{	
	assert(lp != NULL);
	if (lp->slp[findId]->id != findId) {
		printf("No student with id: %d\n", findId);
		return -1;
	}
	printf("Student %d found!\n", findId);
	return lp->slp[findId]->id;
}


/*
 * Big-O: O(1)
 *
 * Average: O(1)
 *
 * Worst Case:O(1)
 *
 * The insertion function takes in one LIST lp, and int newId and one int newAge as arguments. It creates memory for the new stuent, then sets the students age to the newAge, and well as the ID to newId. It then adds the new student to the beginngin of the double linked list right after the head, incrementing count by 1. It prints out the new student, then returns nothing.
 *
 */
void insertion(LIST *lp, int newId, int newAge)
{
	assert(lp != NULL && lp->count < lp ->length);
	lp->slp[newId]->id = newId;
	lp->slp[newId]->age = newAge;
	printf("New student added with ID: %d\n", newId);
	lp->count++;
	return;
}

/*
 * Big-O: O(m), m is the differant types of ages in array 
 * 
 * Average: O(m)
 *
 * Worst Case: O(n), if all student have the same age, it will delete every STUDENT node
 *
 * The deletion function takes in one list of lp and one delAge as arguments. It checks the count of student with that AGE, and if none, returns. If there is a list of STUDENTS, there is a new created STUDENT that points to the first student in the list, and while the next pointer is not the head (reached end) will save the next pointer, then delete the student at first, setting the new student to the next saved. This returns nothing
 */
void deletion (LIST *lp, int delId)
{
	assert(lp!= NULL);
	if (lp->slp[delId] == NULL || lp->slp[delId]->id != delId) {
		printf("Student %d could not be deleted, not in list\n", delId);
		return;
	}
	free(lp->slp[delId]);
	lp->slp[delId] = NULL;
	lp->count--;
	printf("deleted student %d\n", delId);
	return;
}


