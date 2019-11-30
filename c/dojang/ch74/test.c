struct NODE *findNode(struct NODE *node, int data)
{
if (node == NULL)
    return NULL;

struct NODE *curr = node->next;
while (curr != NULL)
{
    if (curr->data == data)
        return curr;

    curr = curr->next;
}

return NULL
}
