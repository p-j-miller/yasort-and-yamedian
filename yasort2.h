/* yasort2.h */
#ifndef __YASORT2_H
 #define __YASORT2_H
 #if defined(elem_type_sort2) 
  #error "attempt to redefine elem_type_sort2"  
 #endif
 /* the line below is the only line in this file you should edit ! */
 #define elem_type_sort2 double /* type of array to process - should be an standard type for which compares are defined eg int,unsigned, float, double etc */
 #ifdef __cplusplus
  extern "C" {
 #endif 
 void yasort2(elem_type_sort2 *x,elem_type_sort2 *y, size_t n); /* general purpose sort for x, with y reordered at the same time so x,y pairs stay at the same array index*/
 #ifdef __cplusplus
    }
 #endif
#endif
