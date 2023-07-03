#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

struct courseInfo {
  char dept[4] ;
  short number ;
  short section ;
  short limit ;
} ;

int main (int argv, char **argc) {
  int numCourses ;
  char tempDept[5] ;
  struct courseInfo uncaCourses[100] ;
  FILE *inFile = fopen(argc[1], "r") ;
  if (inFile == NULL) {
    fprintf(stderr, "%s.%e.%d\n", argc[1], strerror(errno)) ;
    return 1 ;
  }
  numCourses = 0 ;
  while (fscanf(inFile,
		"fill it in",
		tempDept,
		&uncaCourses[numCourses].number,
		&uncaCourses[numCourses].section,
		&uncaCourses[numCourses].limit) == 4) {
    strncpy(uncaCourses[numCourses].dept, tempDept, 4) ;
    numCourses++ ;
  }
  puts("As input") ;
  for (int i=0; i<numCourses; ++i) {
    printf("fill it in",
	   uncaCourses[i].dept,
	   uncaCourses[i].number,
	   uncaCourses[i].section,
	   uncaCourses[i].limit) ;
  }
}

