#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *list, bool (*cmp)(void *a, void *b)) {
    if (list == NULL || cmp == NULL) {
        return list;
    }

    int size = mx_list_size(list);
    void *temp;

    for(int i = 0; i < size; i++) {
        t_list *current = list;

        for(int j = 0; j < size - i - 1; j++) {
            if(cmp(current->data, current->next->data)) {
                temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
            }

            current = current->next;
        }
    }

    return list;
}

