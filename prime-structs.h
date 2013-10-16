#ifndef PRIME_STRUCTS_H
#define PRIME_STRUCTS_H

typedef struct node_s {
  int val_int;
  int val_flag;
  int result;
  struct node_s *next;
} node_s;

#endif
