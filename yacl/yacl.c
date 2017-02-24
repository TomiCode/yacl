#include "yacl.h"

#define YACL_CURRENT_NONE      0x01
#define YACL_CURRENT_NAMESPACE 0x02
#define YACL_CURRENT_VARIABLE  0x04

struct yacl_varlist {
  yacl_variable *pnext;
  yacl_variable *pprev;
};

struct yacl_namespace {
  yacl_var      handle;
  yacl_varlist* first;

  struct yacl_namespace* next;
};

struct yacl_namespace *pg_yacl_namespace = NULL;

yacl_handle yacl_allocate_next(struct yacl_namespace ** p_namespace)
{
  struct yacl_namespace *current;
  struct yacl_namespace *new_namespace = new struct yacl_namespace;
  new_namespace->first = NULL;
  new_namespace->next  = NULL;
  *p_namespace = new_namespace;

  if (pg_yacl_namespace == NULL) {
    new_namespace->handle = 1;
  }
  else {
    for (current = pg_yacl_namespace; current->next != NULL; current = current->next);
    new_namespace->handle = current->handle++;
    current->next = new_namespace;
  }
  return new_namespace->handle;
}

yacl_handle yacl_create(FILE* config_file, yacl_descriptor* config_desc)
{
  struct yacl_namespace* current_namespace = NULL;
  char yacl_parser_current    = YACL_CURRENT_NONE;
  char yacl_parser_array[128] = {0};
  int  yacl_parser_position   = 0;

  yacl_handle handle = yacl_allocate_next(&current_namespace);
  printf("Create new handle: %d.\n", handle);

  for (char r = '\0'; fread(&r, sizeof(char), 1, config_file) == 1;) {

  }
  return handle;
}