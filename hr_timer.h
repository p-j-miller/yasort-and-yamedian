/* hr_timer.h

  header file for windows high resolution timer functions
  
  Peter Miller 10/7/2016
  See hr_timer.c for details.
  
*/
#ifndef __HR_TIMER
#define __HR_TIMER
#include <windows.h>
#include <stdint.h>
typedef uint32_t time_us ; // all time calcs should use this type, note overflows in ~ 36 mins with in32 and 1 hr 12 mins with uint32, so code should allow for this
					/* warning if this is a signed type then the behaviour is not guaranteed by the C standard
					   the behaviour for unsigned types is defined see eg http://stackoverflow.com/questions/3679047/integer-overflow-in-c-standards-and-compilers
					   the gcc option -fwrapv is probably required to use a signed type with gcc
					   this code is designed to work with unsigned 32 bit (uint32_t)
					  */   
#define ms *1000  /* scaling factors for times to us */
#define us *1
#define sec *1000000
#ifdef __cplusplus
extern "C" {
#endif
void init_HR_Timer( void) ; // initialise the high resolution timer
double read_HR_Timer( void) ;  // read the timer , returns the time (secs) between last reset and now to ~ uS resolution
time_us read_HR_Timer_ms( void) ; // read the timer, result in ms as an integer
time_us read_HR_Timer_us( void) ; // read the timer, result in us as an integer, overflows in ~ 1.2 hours
int32_t diff_time(time_us a, time_us b); // returns a-b valid if a, b with 2^31 of each other
										 // note returns an int32_t as time_us may be unsigned and the result has to be signed
#ifdef __cplusplus
}
#endif										 
#endif
