#ifndef __SORT_H__
#define __SORT_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* DEFAULTS */
#ifndef QSORT_MIN_SIZE
  #define QSORT_MIN_SIZE 50
#endif


/* FUNCTIONS */
void selection_sort(
    void **arr,
    size_t len,
    int (*cmp)(const void *, const void *)
);
void insertion_sort(
    void **arr,
    size_t len,
    int (*cmp)(const void *, const void *)
);
size_t partition(
    void **arr,
    size_t pivot_index,
    size_t start,
    size_t end,
    int (*cmp)(const void *, const void *)
);
int quick_select(
    void *arr,
    size_t el_sz,
    int k_th,
    int start,
    int end,
    int (*cmp)(const void *, const void *)
);
void median_sort(
    void *arr,
    size_t el_sz,
    int left,
    int right,
    int (*cmp)(const void *, const void *)
);
void quick_sort(
    void *arr,
    size_t el_sz,
    int left,
    int right,
    int (*cmp)(const void *, const void *)
);
void heapify(
    void *arr,
    size_t el_sz,
    int index,
    int max,
    int (*cmp)(const void *, const void *)
);
void build_heap(
    void *arr,
    size_t el_sz,
    int n,
    int (*cmp)(const void *, const void *)
);
void heap_sort(
    void *arr,
    size_t el_sz,
    int n,
    int (*cmp)(const void *, const void *)
);
#endif
