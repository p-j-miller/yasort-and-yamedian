# yasort-and-yamedian
C functions to sort and find medians of arrays

This directory contains a collection of C functions for sorting and finding medians. 
An extensive set of test programs is also present to verify their correct operation.

These functions were created as the default functions supplied in the libraries of some compilers can take time of O(n\*n) to complete a sort or find a median (with particular patterns of data) which can be extremely slow compared to the expected O(n\*log(n)) for sorting or O(n) for selection/median functions. For example with n = 1,000,000 , O(n\*n) is ~ 70,000 times slower than O(n\*log(n)) - i.e. what should take 1 second could take 20 hours!

yasort(), yasort2() and qsort() also can use tasks to use all available processors when running under Windows which can also significantly improve the execution speed on modern hardware.

## Functions
```C
void yasort(elem_type_sort *x, size_t n); /* numeric sort with guaranteed O(N*log(N)) execution time */
void yasort2(elem_type_sort2 *x,elem_type_sort2 *y, size_t n); /* numeric sort for x, with y reordered at the same time so x,y pairs stay at the same array index. Guaranteed O(N*log(N)) execution time*/
void qsort(void *a, size_t n, size_t es, int (*compar)(const void *, const void *));/* general purpose sort with with guaranteed O(N*log(N)) execution time */
int heapsort(void *vbase, size_t nmemb, size_t size,int (*compar)(const void *, const void *));/* general purpose sort with with guaranteed O(N*log(N)) execution time */
void yaselect(elem_type_median* r, size_t n, size_t length); // select or nth_element . Places the n th element of a sequence in the position that it would be if the array was sorted. Changes array r. Execution time is O(N)
 elem_type_median yaMedian(elem_type_median *a, size_t s); // return median of array a using above code. As a side effect this changes array a. This is faster than ya_median(). Execution time is O(N)
 elem_type_median ya_median(elem_type_median *m, const size_t n);// calculates median without changing array m. Uses free memory (via malloc) if available to speed process up - but will work with no free memory. This is slower than yaMedian().
 void ya_msort(elem_type_median *a,size_t n); // sort based on yaMedian. Guaranteed O(n*log(n)) execution speed but ~ 50% slower than yasort() on test program 
 ```
 ## Installation
 Copy these files to a directory of your choice.
 
 yasort.c contains the main test program - which is built if YASORT_MEDIAN_TEST_PROGRAM is defined.
 
 yasort2.c contains its own test program - which is built if YA2SORT_TEST_PROGRAM is defined.
 
 If you use Dev-C++ the a project file is included - this assumes TDM-GCC 10.3.0 is installed.
 
 ## Examples of use
 The test programs in yasort.c and yasort2.c show how to use all these functions.
 
 csvgraph uses yasort2() and ya_median(), while nsort uses qsort().
 
 The qsort() function conforms to ISO/IEC 9899:1990	("ISO C90"), and heapsort() is from the BSD Standard C Library.
 
 If you want to sort numbers (int, float, double etc) then yasort() is the fastest way to do this.
 
 
