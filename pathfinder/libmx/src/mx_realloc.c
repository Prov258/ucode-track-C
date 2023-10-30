#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    if (!ptr && size > 0) {
        return malloc(size);
    }
    
    if (ptr && size <= 0) {
        free(ptr);
        return NULL;
    }

    size_t old_size = malloc_size(ptr);
    void *new_ptr = NULL;

    if (size < old_size) {
        size = old_size;
    }

    new_ptr = malloc(size);
    mx_memmove(new_ptr, ptr, old_size);
    free(ptr);

    return new_ptr;
}


