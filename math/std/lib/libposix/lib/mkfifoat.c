/* This is free and unencumbered software released into the public domain. */

#include "mkfifoat.h"

#include <errno.h> /* for ENOSYS, errno */

int
mkfifoat(const int dirfd,
         const char* const pathname,
         const mode_t mode) {
  return errno = ENOSYS, -1; // TODO
}
