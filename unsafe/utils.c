#include "utils.h"

// Utils
void *moonbit_str_to_c_str(moonbit_string_t *ms) {
  int32_t len = Moonbit_array_length(ms);
  char *ptr = (char *)malloc(len + 1);
  uint16_t *data = ms->data;
  for (int i = 0; i < len; i++) {
    if (data[i] < 0x80) {
      ptr[i] = data[i];
    } else {
      ptr[i] = '?';
    }
  }
  ptr[len] = '\0';
  return ptr;
}

moonbit_string_t *c_str_to_moonbit_str(void *ptr) {
  char *cptr = (char *)ptr;
  int32_t len = strlen(cptr);
  moonbit_string_t *ms = moonbit_make_string(len, 0);
  for (int i = 0; i < len; i++) {
    ms[i] = (uint16_t)cptr[i];
  }
  // free(ptr);
  return ms;
}

struct moonbit_string *c_str_to_moonbit_str_with_length(void *ptr,
                                                        unsigned len) {
  char *cptr = (char *)ptr;
  moonbit_string_t *ms = moonbit_make_string(len, 0);
  for (int i = 0; i < len; i++) {
    ms[i] = (uint16_t)cptr[i];
  }
  // free(ptr);
  return ms;
}
