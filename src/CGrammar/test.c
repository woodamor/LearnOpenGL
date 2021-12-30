#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

int a = 1;
int b = 2;

typedef struct s {
  int a;
  int b;
  // int *b;
} s;

typedef struct simple {
  // unsigned int tmp : 1;
  // BOOL tmp : 1;
  int a : 8;
  int b : 2;
  int c : 6;
  // int d : 1;
  // int e : 1;
  // int f : 1;
} simple;

enum Day {mon=1, tue, wed, thu, fri, sat, sun};

void printDay(Day day) {
  switch (day)
  {
  case mon:
    printf("it's monday\n");
    break;
  case tue:
    printf("it's tuesday\n");
  case fri:
    printf("it's friday\n");
  default:
    break;
  }
}

int main() {
  // if (!a) {
  //   printf("it's true that a is zero! %f   %f\n", a, b);
  // } else {
  //   printf("it's false that a is not zero %f   %f\n", a, b);
  // }

  // char str[80];
  // strcpy(str, "these ");
  // strcat(str, "strings ");
  // strcat(str, "are ");
  // strcat(str, "concatenated.");
  // char buffer[20];
  // itoa(a, buffer, 10);
  // strcat(str, buffer);
  // puts(str);

  // s *s_instance = (s*)calloc(1, sizeof(s));
  // s_instance->b = (int*)calloc(1, sizeof(int));
  // *(s_instance->b) = 2;
  // // printf("b is %d", *(s_instance->b));
  // int *b_ptr = s_instance->b;

  // if(b_ptr==NULL){
  //   printf("NULL\n");
  // } else {
  //   printf("address of b is 0X%p, b is %d before free struct\n", s_instance->b, *(s_instance->b));
  // }

  // free(s_instance);

  // if(b_ptr==NULL){
  //   printf("NULL after free struct\n");
  // } else {
  //   printf("address of b is 0X%p, b is %d after free struct\n", s_instance->b, *(s_instance->b));
  // }

  // // int tmp = *b_ptr;

  // // printf("b_ptr is %d", *b_ptr);

  // printf("sizeof(int) is %d, sizeof(ptr) is %d\n", sizeof(int), sizeof(int*));


  // printf("sizeof(bool) is %d\n", sizeof(bool));

  // const char *s = "China\n";

  // if(strncmp(s, "prefix", 6) != 0) {
  //   printf(s);
  // } else {
  //   printf(&s[7]);
  // }

  // // char *i = strstr(s, "a");
  // // if(i == NULL) {
  // //   printf("finds nothing");
  // // } else {
  // //   printf(i + 1);
  // // }

  // Day day = mon;
  // printf("day is %d\n", day);

  // printDay(day);

  printf("sizeof struct s is %d\n", sizeof(s));
  printf("sizeof struct simple is %d\n", sizeof(simple));

  int errnum;
  FILE *pf;
  pf = fopen("unexist.txt", "rb");

  int divisor = 0;
  // if(pf == NULL) {
  //   errnum = errno;
  //   fprintf(stderr, "errno: %d\n", errno);
  //   fprintf(stderr, "open file error: %s\n", strerror(errnum));
  // }

  assert(divisor == 0);

  return 0;
}