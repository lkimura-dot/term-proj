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
 * Defines ages in which the list will have that had a dummy head and count of amount of students
 */
typedef struct ages
{
    int count;
	STUDENT *head;
} AGES;

/*
 * Define a student of a certain age with an ID pointing to next and prev
 */
typedef struct student
{
    int ID;
	int age;
    struct node *next;
    struct node *prev;
} STUDENT;


/*
 * Defines an List where the ages are stored, with a max length and current student count.
 */
typedef struct list{
  AGES **array;
  int studentCount;
  int length;
} LIST;

LIST *createDataSet(int maxElts)
{
    LIST *lp= malloc(sizeof(LIST));
    assert(lp != NULL);
    lp->studentCount = 0;
	lp->length = maxElts;
	for(int i=0; i<13; i++) {
		lp->array[i] = malloc(sizeof(AGES));
		assert(lp->array[i]!= NULL);
		lp->array[i]->count = 0;
		lp->array[i]->head = malloc(sizeof(STUDENT));
		assert(lp->array[i]->head != NULL);
		lp->array[i]->head->next = lp->array[i]->head;
		lp->array[i]->head->prev = lp->array[i]->head;
	}
    return lp;
}

//o complexity: O(m)
void destroyDataSet(LIST *lp)
{
	for(int i = 0; i < 13; i++) {
		free(lp->array[i]);
	}
	free(lp)
	return;
}
int* searchAge(LIST *lp, int age)
{
	int startingVal = age-18
	int *agesFound[lp->array[startingVal]->count];
	while(int i = 0; i < lp->array[startingVal]->count; i++){
		agesFound[i] = lp->array[startingVal]->head->next;
		printf("Student Id: %d\n", lp->array[startingVal]->head->next);

	}


	return agesFound;
}
void insertion(LIST *lp, int newID, int newAge)
{
	assert(lp != NULL && lp->studentCount < lp->length);
	STUDENT* newStudent = malloc(sizeof(STUDENT));
	assert(newStudent != NULL);
	newStudent -> age = newAge;
	newStudent ->ID = newID;
	lp->array[age-18]->head->next->prev = newStudent;
	newStudent->prev = head;
	newStudent->next = lp->array[age-18]->next;
	lp->array[age-18]->head->next = newStudent;
	lp->studentCount++;
	printf("new student added: %d, who is %d ", newStudent->ID, newstudent->age);
	return;
}

void deletion (LIST *lp)
{
	return;
}

void maxAgeGap(LIST *lp)
{
	return;
}
