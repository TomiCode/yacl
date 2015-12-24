#ifndef YACL_H
#define YACL_H

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef int32_t yacl_handle;
typedef int32_t yacl_var;

typedef enum {
  yacl_integer,
  yacl_boolean,
  yacl_number,
  yacl_string
} yacl_type;

typedef struct {
  yacl_var  id;
  int       size;
  void*     value;
  yacl_type type;
} yacl_variable;

typedef struct {
  yacl_var  id;
  char      label[32];
  yacl_type type;
} yacl_field;

typedef struct {
  char          label[32];
  yacl_field    fields[];
} yacl_descriptor;

yacl_handle yacl_create(FILE* config_file, yacl_descriptor* config_desc);
bool yacl_getfield(yacl_handle handle, void* field, int* size);

void yacl_free(yacl_handle handle);
#endif // YACL_H