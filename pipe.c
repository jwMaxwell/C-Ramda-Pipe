#include "pipe.h"
void *NULL;
void (**_funcs)(void*);

void* _func(void *x) {
  do {
    void* (*tempfunc)(void*) = (void*)(*_funcs);
    x = tempfunc(x);
  } while (*++_funcs != NULL);
  return x;
}

void* pipe(void (**funcs)(void*)) {
  _funcs = funcs;
  return &_func;
}
