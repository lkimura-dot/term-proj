/*
 * File: dataset.h
 * Author: Lauren Kimura
 * Last Updated: 3/5/2026
 *
 * Description: This file contains the public function and type
 *              declarations for a list abstract data type for generic
 *              pointer types.
 */
# ifndef DATASET_H
# define DATASET_H

typedef struct student STUDENT;
typedef struct list LIST;

extern LIST *createDataSet(int maxElts);
extern void destroyDataSet(LIST *lp);
extern void searchID(LIST *lp, int id);
extern void insertion(LIST *lp, int newID, int newAge);
extern void deletion (LIST *lp, int age);


#endif
