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

typedef struct list LIST;

extern LIST *createDataSet(int (*compare)());
extern void destroyDataSet(LIST *lp);
extern int *searchAge(LIST *lp);
extern void insertion(LIST *lp);
extern void deletion (LIST *lp);
extern void maxAgeGap(LIST *lp);
