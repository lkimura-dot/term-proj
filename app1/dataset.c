/*
 * File: dataset.c
 * Author: Lauren Kimura
 * Last updated: 2/22/2026
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
    struct student *next;
    struct student *prev;
} STUDENT;

/*
 * Defines ages in which the list will have that had a dummy head and count of amount of students
 */
typedef struct ages
{
    int count;
	STUDENT *head;
} AGES;


/*
 * Defines an List where the ages are stored, with a max length and current student count.
 */
typedef struct list{
  AGES **array;
  int studentCount;
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
    LIST *lp= malloc(sizeof(LIST));
    assert(lp != NULL);
    lp->studentCount = 0;
	lp->length = maxElts;
	lp->array = malloc(sizeof(AGES*) * 13);
	assert(lp->array != NULL);
	for(int i = 0; i < 13; i++) {
		lp->array[i] = malloc(sizeof(AGES));
		assert(lp->array[i] != NULL);
		lp->array[i]->count = 0;
		lp->array[i]->head = malloc(sizeof(STUDENT)); 
		assert(lp->array[i]->head != NULL);
		lp->array[i]->head->next = lp->array[i]->head;
		lp->array[i]->head->prev = lp->array[i]->head;
	}    
	return lp;
}

/*
 * Big-O: O(m)
 *
 * Average: O(1)
 *
 * Worst case: O(1)
 *
 * The destroyQueue function takes in one pq as an argument. It free the data then frees the pointer iteself and returns nothing.
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

void maxAgeGap(LIST *lp)
{
	assert(lp != NULL);
	int lowAge = 0;
	int topAge = 12;
	while (lowAge < 13 && lp->array[lowAge]->count == 0) {
		lowAge++;
	}
	while (topAge >= 0 && lp->array[topAge]->count == 0) {
		topAge--;
	}	
	if (lowAge > topAge) {
        printf("No students in dataset\n");
        return;
    }
	printf("the age range is from %d and %d\n", lowAge+18, topAge+18);
	assert(lp != NULL);
	return;
}
