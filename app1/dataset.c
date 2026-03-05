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

//o complexity: O(m)
void destroyDataSet(LIST *lp)
{
	for(int i = 0; i < 13; i++) {
    free(lp->array[i]->head);
    free(lp->array[i]); 
	}
	free(lp->array);
	free(lp);
}

void searchAge(LIST *lp, int age)
{	
	assert(lp != NULL);
	int startingVal = age-18;
	if (lp->array[startingVal]->count == 0) {
		printf("No students of age: %d", age);
		return;
	}
	printf("Students who are of age: %d", age);
	for(int i = 0; i < lp->array[startingVal]->count; i++){
		printf("Student Id: %d\n", lp->array[startingVal]->head->next->ID);
	}
	return;
}

void insertion(LIST *lp, int newID, int newAge)
{
	assert(lp != NULL && lp->studentCount < lp->length);
	STUDENT* newStudent = malloc(sizeof(STUDENT));
	assert(newStudent != NULL);
	newStudent -> age = newAge;
	newStudent ->ID = newID;
	lp->array[newAge-18]->head->next->prev = newStudent;
	newStudent->prev = lp->array[newAge-18]->head;
	newStudent->next = lp->array[newAge-18]->head->next;
	lp->array[newAge-18]->head->next = newStudent;
	lp->studentCount++;
	printf("new student added: %d, who is %d \n", newStudent->ID, newStudent->age);
	return;
}

void deletion (LIST *lp, int delAge)
{
	assert(lp!= NULL);
	int startingVal = delAge-18;
	if (lp->array[startingVal]->count == 0) {
		printf("no student with age: %d", delAge);
		return;
	}
	for (int i = 0; i < lp->array[startingVal]->count; i++) {
		printf("Students who were deleted:");
		printf("Student Id: %d\n", lp->array[startingVal]->head->next->ID);
		free(lp->array[startingVal]->head->next);
		lp->studentCount--;
	}
	lp->array[startingVal]->count = 0;
	lp->array[startingVal]->head->next = lp->array[startingVal]->head;
	lp->array[startingVal]->head->prev = lp->array[startingVal]->head;
	return;
}

void maxAgeGap(LIST *lp)
{
	int lowAge = 0;
	int topAge = 13;
	while (lp->array[lowAge]->count == 0) {
		lowAge++;
	}
	while (lp->array[topAge]->count ==0) {
		topAge--;
	}
	printf("thr age range is from %d and %d", lowAge+18, topAge+18);
	assert(lp != NULL);
	return;
}
