/* yasort.h */
#ifndef __YASORT_H
 #define __YASORT_H
 #if defined(elem_type_sort) 
  #error "attempt to redefine elem_type_sort"  
 #endif
 /* the line below is the only line in this file you should edit ! */
 #define elem_type_sort double /* type of array to process - should be an standard type for which compares are defined eg int,unsigned, float, double etc */
 #ifdef __cplusplus
  extern "C" {
 #endif 
 void yasort(elem_type_sort *x, size_t n); /* general purpose sort  */
 #ifdef __cplusplus
    }
 #endif
#endif
