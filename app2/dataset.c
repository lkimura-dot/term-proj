/*
 * File: dataset.c
 * Author: Lauren Kimura
 * Last updated: 3/5/2026
 * Description:
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include "dataset.h"

/*
 * Define a student of a certain age with an ID pointing to next and prev
 */
typedef struct student
{
    int ID;
	int age;
} STUDENT;

/*
 * Defines an List where the ages are stored, with a max length and current student count.
 */
typedef struct list{
  STUDENT **array;
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
	lp->array = malloc(sizeof(AGES*) * maxElts;
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
	for(int i = 0; i < 13; i++) {
    free(lp->array[i]->head);
    free(lp->array[i]); 
	}
	free(lp->array);
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
void searchAge(LIST *lp, int age)
{	
	assert(lp != NULL);
	int startingVal = age-18;
	if (lp->array[startingVal]->count == 0) {
		printf("No students of age: %d\n", age);
		return;
	}
	printf("Students who are of age: %d\n", age);
	STUDENT *curr = lp->array[startingVal]->head->next;
	

	while (curr != lp->array[startingVal]->head) {
        printf("Student Id: %d\n", curr->ID);
        curr = curr->next;
    }
		return;
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
void insertion(LIST *lp, int newID, int newAge)
{
	assert(lp != NULL && lp->studentCount < lp->length);
	assert(newAge >= 18 && newAge <=30);
	STUDENT* newStudent = malloc(sizeof(STUDENT));
	assert(newStudent != NULL);
	newStudent -> age = newAge;
	newStudent ->ID = newID;
	lp->array[newAge-18]->head->next->prev = newStudent;
	newStudent->prev = lp->array[newAge-18]->head;
	newStudent->next = lp->array[newAge-18]->head->next;
	lp->array[newAge-18]->head->next = newStudent;
	lp->array[newAge-18]->count++;
	lp->studentCount++;
	printf("new student added: %d, who is %d \n", newStudent->ID, newStudent->age);
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
void deletion (LIST *lp, int delAge)
{
	assert(lp!= NULL);
	int startingVal = delAge-18;
	if (lp->array[startingVal]->count == 0) {
		printf("no student with age: %d \n", delAge);
		return;
	}
	STUDENT *delete = lp->array[startingVal]->head->next;
	printf("Students Deleted:\n");
	while (delete != lp->array[startingVal]->head) {
		STUDENT *saveNext = delete->next; 
		printf("Student Id: %d\n", delete->ID);
		delete->prev->next = delete->next;
		delete->next->prev = delete->prev;
		free(delete);
		lp->studentCount--;
		delete = saveNext;
	}
	return;
}


