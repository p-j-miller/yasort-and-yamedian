# yasort-and-yamedian
C functions to sort and find medians of arrays

This directory contains a collection of C functions for sorting and finding medians. 
An extensive set of test programs is also present to verify their correct operation.

These functions were created as the default functions supplied in the libraries of some compilers can take time of O(n\*n) to complete a sort or find a median (with particular patterns of data) which can be extremely slow compared to the expected O(n\*log(n)) for sorting or O(n) for selection/median functions. For example with n = 1,000,000 , O(n\*n) is ~ 70,000 times slower than O(n\*log(n)) - i.e. what should take 1 second could take 20 hours! The functions in this library have guaranteed worse case run times of O(n\*log(n)) for sorting and O(n) for median. 

yasort(), yasort2() and qsort() also can use tasks to use all available processors when running under Windows or Linux,BSD etc. which can also significantly improve the execution speed on modern hardware.

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
 
 If you use Windows and Dev-C++ the a project file is included - this assumes TDM-GCC 10.3.0 is installed.
 You can select to use either native Windows threads or pthreads under Windows, Linux, BSD, etc to use all available processors.
 You can run without threads if required.
 
 To use threads at the top of ya-sort.c (and also qsort.c and ya-sort2.c - you can set each one individually) :
 ```
 #define PAR_SORT
 ```
 and then to use pthreads also define
 ```
 #define USE_PTHREADS
 ```
 
 To compile the test program from the command line on Linux etc:
 ```
 gcc -O3 *.c -lpthread
 ./a.out
 ```
 ## Examples of use
 The test programs in yasort.c and yasort2.c show how to use all these functions.
 
 csvgraph ( https://github.com/p-j-miller/csvgraph ) uses yasort2() and ya_median(), while nsort ( https://github.com/p-j-miller/nsort ) uses qsort().
 
 The qsort() function conforms to ISO/IEC 9899:1990	("ISO C90"), and heapsort() is from the BSD Standard C Library.
 
 If you want to sort numbers (int, float, double etc) then yasort() (using parallel tasks) is the fastest way to do this.
 Enabling threads gives an average 1.4\* speedup and a 1.6\* speedup of the slowest sort in the test program with a two core processor, while on an 8 core processor the speedups were 3.3\* and 3.8\* respectively.
 
 If you just want to replace the qsort() function in your standard library then use the qsort here and benefit from better performance guarantees and the ability to transparently use all the available processors to speed up sorting. nsort (https://github.com/p-j-miller/nsort ) shows how to do this (no changes to existing code are needed, the qsort here is a drop in replacement). 
 
