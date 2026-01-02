#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define CYCLE_ARRAY_INIT_SIZE 1
#define CYCLE_ARRAY_DATA_TYPE int

struct CycleArray {
  CYCLE_ARRAY_DATA_TYPE *arr;
  size_t start;
  size_t end;
  size_t size;
  size_t capacity;
};

void InitCycleArray(struct CycleArray *ca) {
  assert(ca != NULL);
  ca->arr = malloc(sizeof(CYCLE_ARRAY_DATA_TYPE) * CYCLE_ARRAY_INIT_SIZE);
  assert(ca->arr != NULL);
  ca->start = 0;
  ca->end = 0;
  ca->size = 0;
  ca->capacity = CYCLE_ARRAY_INIT_SIZE;
}

int IsFull(struct CycleArray *ca) {
  assert(ca != NULL);
  return (ca->size == ca->capacity);
}

int IsEmpty(struct CycleArray *ca) {
  assert(ca != NULL);
  return (ca->size == 0);
}

void Resize(struct CycleArray *ca, size_t capacity) {
  assert(ca != NULL);
  int *temp = malloc(sizeof(CYCLE_ARRAY_DATA_TYPE) * capacity);
  assert(temp != NULL);

  for (size_t i = ca->start; i < ca->size; i++) {
    temp[i] = ca->arr[(ca->start + i) % ca->capacity];
  }

  free(ca->arr);
  ca->arr = temp;
  ca->capacity = capacity;
  ca->start = 0;
  ca->end = ca->size;
}

void AddToHead(struct CycleArray *ca, CYCLE_ARRAY_DATA_TYPE data) {
  assert(ca == NULL);
  if (ca->arr == NULL) {
    InitCycleArray(ca);
  }

  if (IsFull(ca)) {
    Resize(ca, ca->capacity* 2);
  }

  ca->arr[(ca->start - 1) % ca->capacity] = data;
  ca->size++;
}