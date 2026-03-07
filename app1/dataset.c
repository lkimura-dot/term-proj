/*
 * File: dataset.c
 * Author: Lauren Kimura
 * Last updated: 3/5/2026
 * Description: a list of size 12, students sorted by age with a dummy head for ages 18-30. In each age there is a node pointer student that is doubly linked using ADT's: createDataSet, destoryDataSet, SearchAge, Insertion, Deletion, and maxAgeGroup
 *
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
 * Big-O: O(1) 
 *
 * Average: O(1) constant because number 13 is constant
 *
 * Worst case: O(1)
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
 * Big-O: O(n), n is the number of students
 *
 * Average: O(n)
 *
 * Worst case: O(n)
 *
 * The destroyDataSet function takes in one lq as an argument. It frees each of the age heads and AGES in the array, then frees the array itself, and finally the lp. This returns nothing.
 *
 */
void destroyDataSet(LIST *lp)
{
	assert(lp != NULL);
	for(int i = 0; i < 13; i++) {
		if(lp->array[i]->count > 0) {
		STUDENT *nextStudent = lp->array[i]->head->next;
		while (nextStudent != lp->array[i]->head){
			STUDENT *curr = nextStudent;
			nextStudent = nextStudent->next;
			free(curr);
		}
		free(lp->array[i]); 
		}
	}
	free(lp->array);
	free(lp);
	printf("Successfully deleted list\n");
}

/*
 * Big-O: O(m) m is the students in doubly linked array
 *
 * Average: O(m), getting age O(1), but returning each ID is O(m)
 *
 * Worst Case: O(m)
 *
 * The searchAge function takes one lp and an age as arguments. If there is not student with that age, it returns. Else, it prints out all the student's ID's with that age and reutns nothing
 *It makes a copy of the elements in the list and returns the copy of items.

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
 * Big-O: O(m), m is the students in the doubly linked list 
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
	printf("Students Deleted with the age %d:\n", delAge);
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

/*
 * Big-O: O(1) 
 *
 * Average: O(1)
 *
 * Worst Case: O(1)
 *
 * The maxAgeGap function takes in one list of lp as arguments. It checks for the lowest age and the top age. then prints the range of the two. Ths returns nothing.
 */
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
