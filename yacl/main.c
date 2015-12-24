#include <stdio.h>
#include "yacl.h"

enum someFields {
  Username,
  Age
};

yacl_descriptor someDescriptor{
  "Propeties", {
    { someFields::Username, "Username", yacl_string },
    { someFields::Age, "Age", yacl_integer }
  }
};

int main(int argc, char **argv)
{
  FILE* confile = fopen("testfile.yacl", "rt");
  if (confile == NULL) {
    printf("can not open file.\n");
    return 0;
  }

  yacl_handle config = yacl_create(confile, &someDescriptor);
  fclose(confile);
  /* Still needs more work. */
  return 0;
}