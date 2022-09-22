#include <assert.h>

template<typename type>
struct qnode
{
    type value;
    qnode* next;
};

template <typename type>
class queue{
private:
    size_t length;

    qnode<type> *tp;
    qnode<type> *bt;
public:
    queue()
    {
        length = 0;
        tp = bt = NULL;
    }
    ~queue()
    {
        qnode<type>* aux;

        while(length)
        {
            aux = tp -> next;
            length--;

            delete tp;

            tp = aux;
        }

        delete aux;
    }
    bool empty()
    {
        return !length;
    }
    void push(type value)
    {
        qnode<type>* tmp = new qnode<type>;

        tmp -> next = NULL;
        tmp -> value = value;

        if(!length)
            tp = bt = tmp;
        else
        {
            tp -> next = tmp;
            tp = tmp;
        }

        length++;

        delete tmp;
    }
    void pop()
    {
        assert(length);

        bt = bt -> next, length--;
    }
    type front()
    {
        assert(length);

        return bt -> value;
    }
    size_t size()
    {
        return length;
    }
};
