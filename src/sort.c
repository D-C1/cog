#include "sort.h"
#include "utils.h"


static inline void swap_ptr(void **arr, size_t index_1, size_t index_2)
{
    void *tmp = arr[index_1];
    arr[index_1] = arr[index_2];
    arr[index_2] = tmp;
}

void selection_sort(
    void **arr,
    size_t len,
    int (*cmp)(const void *, const void *)
)
{
    size_t i;
    size_t j;
    size_t min;

    for (i = 0; i < len - 1; i++) {
        min = i;
        for (j = i + 1; j <= len - 1; j++) {
            if (cmp(arr[j], arr[min]) < 0) {
                min = j;
            }
        }
        swap_ptr(arr, i, min);
    }
}

void insertion_sort(
    void **arr,
    size_t len,
    int(*cmp)(const void *, const void *)
)
{
    size_t i;
    size_t j;

    for (i = 1; i <= len - 1; i++) {
        j = i;

        while (j > 0 && cmp(arr[j - 1], arr[j]) > 0) {
            swap_ptr(arr, j - 1, j);
            j--;
        }
    }
}

/* size_t partition( */
/*     void **arr, */
/*     size_t pivot_index, */
/*     size_t start, */
/*     size_t end, */
/*     int(*cmp)(const void *, const void *) */
/* ) */
/* { */
/*     size_t i; */
/*     size_t store; */
/*  */
/*     #<{(| move pivot element to the end of the array |)}># */
/*     swap_ptr(arr, pivot_index, end); */
/*  */
/*     #<{(| values <= pivot_value, move to front of array */
/*      * values > pivot_value, insert after pivot index |)}># */
/*     store = start; */
/*     for (i = start; i < end; i++) { */
/*         if (cmp(arr[i], arr[pivot_index]) <= 0) { */
/*             swap_ptr(arr, i, store); */
/*             store++; */
/*         } */
/*     } */
/*     swap_ptr(arr, end, store); */
/*  */
/*     return store; */
/* } */
/*  */
/* int quick_select( */
/*     void *arr, */
/*     size_t el_sz, */
/* 	int k_th, */
/* 	int start, */
/* 	int end, */
/* 	int (*cmp)(const void *, const void *) */
/* ) */
/* { */
/*     int i = (start - end == 0) ? start : randnum_i(start, end); */
/*     int pivot_index = partition(arr, el_sz, i, start, end, cmp); */
/*  */
/*     if ((start + k_th - 1) == pivot_index) { */
/*         return pivot_index; */
/*     } */
/*  */
/*     #<{(| continue loop, narrowing range as appropriate. |)}># */
/*     #<{(| if within LHS of pivot then k_th remain the same |)}># */
/*     if ((start + k_th - 1) < pivot_index) { */
/*         return quick_select( */
/*             arr, */
/*             el_sz, */
/*             k_th, */
/*             start, */
/*             pivot_index - 1, */
/*             cmp */
/*         ); */
/*     } else { */
/*         return quick_select( */
/*             arr, */
/*             el_sz, */
/*             k_th - (pivot_index - start + 1), */
/*             pivot_index + 1, */
/*             end, */
/*             cmp */
/*         ); */
/*     } */
/* } */

/* void median_sort( */
/*     void *arr, */
/*     size_t el_sz, */
/*     int left, */
/*     int right, */
/* 	int(*cmp)(const void *, const void *) */
/* ) */
/* { */
/*     #<{(| if subarray has 1 (or fewer!) elements, its done! |)}># */
/*     if (right <= left) { */
/*         return; */
/*     } */
/*  */
/*     #<{(| get midpoint and median element position |)}># */
/*     int middle = (right - left + 1) / 2; */
/*     quick_select(arr, el_sz, middle + 1, left, right, cmp); */
/*  */
/*     median_sort(arr, el_sz, left, left + middle - 1, cmp); */
/*     median_sort(arr, el_sz, left + middle + 1, right, cmp); */
/* } */
/*  */
/* void quick_sort( */
/*     void *arr, */
/*     size_t el_sz, */
/*     int left, */
/*     int right, */
/* 	int(*cmp)(const void *, const void *) */
/* ) */
/* { */
/*     #<{(| if subarray has 1 (or fewer!) elements, done! |)}># */
/*     if (right <= left) { */
/*         return; */
/*     } */
/*  */
/*     #<{(| determin pivot point and partition |)}># */
/*     int pivot_index = randnum_i(left, right); */
/*     pivot_index = partition(arr, el_sz, pivot_index, left, right, cmp); */
/*  */
/*     #<{(| quick sort left of pivot |)}># */
/*     if (pivot_index - 1 - left <= SORT_MIN_SIZE) { */
/*         insertion_sort(arr, el_sz, left, pivot_index - 1, cmp); */
/*     } else { */
/*         quick_sort(arr, el_sz, left, pivot_index - 1, cmp); */
/*     } */
/*  */
/*     #<{(| quick sort right of pivot |)}># */
/*     if (right - pivot_index - 1 <= SORT_MIN_SIZE) { */
/*         insertion_sort(arr, el_sz, pivot_index + 1, right, cmp); */
/*     } else { */
/*         quick_sort(arr, el_sz, pivot_index + 1, right, cmp); */
/*     } */
/* } */
/*  */
/* void heapify( */
/*     void *arr, */
/*     size_t el_sz, */
/*     int index, */
/*     int max, */
/* 	int(*cmp)(const void *, const void *) */
/* ) */
/* { */
/*     int l = 2 * index + 1;  #<{(| left |)}># */
/*     int r = 2 * index + 2;  #<{(| right |)}># */
/*     int largest; */
/*  */
/*     #<{(| find largest element of arr[index], arr[left], and arr[right] |)}># */
/*     if (l < max && cmp(arr + (el_sz * l), arr + (el_sz * index)) > 0) { */
/*         largest = l; */
/*     } else { */
/*         largest = index; */
/*     } */
/*  */
/*     if (r < max && cmp(arr + (el_sz * r), arr + (el_sz * largest)) > 0) { */
/*         largest = r; */
/*     } */
/*  */
/*     #<{(| if largest is not already the parent then swap and propagate |)}># */
/*     if (largest != index) { */
/*         swap_el(arr, el_sz, largest, index); */
/*         heapify(arr, el_sz, largest, max, cmp); */
/*     } */
/* } */
/*  */
/* void build_heap( */
/*     void *arr, */
/*     size_t el_sz, */
/*     int n, */
/* 	int(*cmp)(const void *, const void *) */
/* ) */
/* { */
/*     int i; */
/*     for (i = (n / 2) - 1; i >= 0; i--) { */
/*         heapify(arr, el_sz, i, n, cmp); */
/*     } */
/* } */
/*  */
/* void heap_sort( */
/*     void *arr, */
/*     size_t el_sz, */
/*     int n, */
/* 	int(*cmp)(const void *, const void *) */
/* ) */
/* { */
/*     int i; */
/*  */
/*     build_heap(arr, el_sz, n, cmp); */
/*     for (i = n - 1 ; i >= 1; i--) { */
/*         swap_el(arr, el_sz, 0, i); */
/*         heapify(arr, el_sz, 0, i, cmp); */
/*     } */
/* } */
