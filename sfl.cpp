#include <bits/stdc++.h>

struct subforwardlist
{
    int data;
    subforwardlist* next;
};

bool init(subforwardlist* sfl)
{
    sfl->next = NULL;
    sfl->data = 0;
    return true;
}

bool push_back(subforwardlist* sfl, int d)
{
    while (sfl->next != NULL)
    {
        sfl = sfl->next;
    }

    subforwardlist* new_elem = new subforwardlist;
    new_elem->data = d;
    new_elem->next = NULL;
    sfl->next = new_elem;
    
    return true;
}

int pop_back(subforwardlist* sfl)
{
    if (sfl->next == NULL)
        return false;

    while (sfl->next->next != NULL)
    {
        sfl = sfl->next;
    }

    int ans = sfl->next->data;
    delete sfl->next;
    sfl->next = NULL;

    return ans;
}

bool push_forward(subforwardlist* sfl, int d)
{
    subforwardlist* new_elem = new subforwardlist;
    new_elem->data = d;
    new_elem->next = sfl->next;
    sfl->next = new_elem;

    return true;
}

int pop_forward(subforwardlist* sfl)
{
    if (sfl->next == NULL)
        return false;

    subforwardlist* old_elem = sfl->next;
    sfl->next = sfl->next->next;
    int ans = old_elem->data;
    delete old_elem;
    return ans;
}

unsigned int size(subforwardlist* sfl)
{
    unsigned int ans = 0;
    while (sfl->next != NULL)
    {
        ans++;
        sfl = sfl->next;
    }

    return ans;
}

int get_element(subforwardlist* sfl, int index)
{
    for (int i = 0; i < index; i++)
    {
        sfl = sfl->next;
    }
    return sfl->next->data;
}

bool push_where(subforwardlist* sfl, unsigned int where, int d)
{
    if (where > size(sfl) + 1)
        return false;

    for (int i = 0; i < where; i++)
    {
        sfl = sfl->next;
    }

    return push_forward(sfl, d);
}

int erase_where(subforwardlist* sfl, unsigned int where)
{
    if (where > size(sfl) + 1)
        return false;

    for (int i = 0; i < where; i++)
    {
        sfl = sfl->next;
    }

    return pop_forward(sfl);
}

void clear(subforwardlist* sfl)
{
    subforwardlist* ptr_1 = sfl->next;
    while (ptr_1 != NULL)
    {
        subforwardlist* ptr_2 = ptr_1->next;
        delete ptr_1;
        ptr_1 = ptr_2;
    }

    sfl->next = NULL;
}
