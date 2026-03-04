/*
 * File: dataset.h
 * Author
 * Last Updated: 2 March 2026
 *
 * Description: This file contains the public function and type
 *              declarations for a list abstract data type for generic
 *              pointer types.
 */
# ifndef DATASET_H
# define DATASET_H

typedef struct student STUDENT;
typedef struct ages AGES;
typedef struct list LIST;

extern LIST *createDataSet(int maxElts);
extern void destroyDataSet(LIST *lp);
extern void searchAge(LIST *lp, int age);
extern void insertion(LIST *lp, int newID, int newAge);
extern void deletion (LIST *lp, int age);
extern void maxAgeGap(LIST *lp);


#endif
