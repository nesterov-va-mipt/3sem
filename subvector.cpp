

struct subvector
{
    int* mas;
    unsigned int top;
    unsigned int capacity;
};

bool init(subvector* qv)
{
    qv->mas = 0;
    qv->capacity = 0;
    qv->top = 0;

    return true;
}

bool resize(subvector* qv, unsigned int new_capacity)
{
    int* old = qv->mas;
    qv->mas = new int[new_capacity];
    for (int i = 0; i < qv->top; i++)
    {
        *(qv->mas + i) = *(old + i);
    }
    qv->capacity = new_capacity;
    delete[] old;

    return false;
}

bool push_back(subvector* qv, int d)
{
    if (qv->top == qv->capacity)
    {
        resize(qv, qv->capacity * 2 + 1);
        push_back(qv, d);
    }
    else
    {
        *(qv->mas + qv->top) = d;
        qv->top++;
    }

    return false;
}

int pop_back(subvector* qv)
{
    if (qv->top == 0)
        return 0;
    qv->top--;
    return *(qv->mas + qv->top);
}

bool push_forward(subvector* qv, int d)
{
    int* old = qv->mas;
    if (qv->top == qv->capacity)
        resize(qv, qv->capacity * 2 + 1);
    else
        resize(qv, qv->capacity);

    *(qv->mas) = d;
    for (int i = 0; i < qv->top; i++)
    {
        *(qv->mas + i + 1) = *(old + i);
    }
    qv->top++;

    return true;
}

int pop_forward(subvector* qv)
{
    if (qv->top == 0)
        return 0;

    int ans = *(qv->mas);
    for (int i = 0; i < qv->top - 1; i++)
    {
        *(qv->mas + i) = *(qv->mas + i + 1);
    }
    qv->top--;

    return ans;
}

int get_element(subvector* qv, int index)
{
    return *(qv->mas + index);
}

void shrink_to_fit(subvector* qv)
{
   resize(qv, qv->top);
}

void clear(subvector* qv)
{
    qv->top = 0;
}

void destructor(subvector* qv)
{
    delete[] qv->mas;
    init(qv);
}
