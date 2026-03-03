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
 * Defines an ageList where the ages are stored, with a max length and current student count.
 */
typedef struct ageList{
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
		assert(lp->aray[i]->head != NULL);
		lp->array[i]->head->next = lp->array[i]->head;
		lp->array[i]->head->prev = lp->array[i]->head;
	}
    return lp;
}
void destroyDataSet(LIST *lp)
{
	return;
}
int *searchAge(LIST *lp)
{
	return;
}
void insertion(LIST *lp()
{
	return;
}

void deletion ((LIST *lp)
{
	return;
}

void maxAgeGap((LIST *lp)
{
	return;
}
