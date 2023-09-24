#include "../inc/libmx.h"

void mx_pop_back(t_list **list) {
    if (*list == NULL || list == NULL) {
        return;
    }

    t_list *temp = *list;

    if (temp->next == NULL) {
        free(temp);
        *list = NULL;
        return;
    }

    while(temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

