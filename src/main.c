#include <stdio.h>
#include "linked-list.h"

void test_linked_list();

int main(int argc, char **argv)
{
    test_linked_list();
}

typedef struct {
    char *id;
} structured_data;

void test_linked_list()
{
    LL_List int_list = ll_make_list(sizeof(int));
    *(int *)int_list.head->data = 17;

    LL_Node *node = ll_make_node(sizeof(int));
    *(int *)node->data = 21;
    ll_append(node, &int_list);

    node = int_list.head;
    while(node != NULL) {
        printf("current int %d\n", *(int *)node->data);
        node = node->next;
    }

    structured_data data;
    data.id = "id1";

    LL_List data_list = ll_make_list(sizeof(structured_data));
    *(structured_data *)data_list.head->data = data;

    data.id = "id2";
    node = ll_make_node(sizeof(structured_data));
    *(structured_data *)node->data = data;
    ll_append(node, &data_list);

    data.id = "id3";
    node = ll_make_node(sizeof(structured_data));
    *(structured_data *)node->data = data;
    ll_append(node, &data_list);

    node = data_list.head;
    while(node != NULL) {
        printf("current id %s\n", ((structured_data *)node->data)->id);
        node = node->next;
    }
}
