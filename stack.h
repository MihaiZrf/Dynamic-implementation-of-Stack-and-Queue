#include <assert.h>

template<typename type>
struct node
{
    type value;
    node* next;
};

template<typename type>
class stack{
private:
    size_t length;

    node<type>* tp;
public:
    stack()
    {
        length = 0;
        tp = NULL;
    }
    ~stack()
    {
        node<type>* aux;

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
        node<type>* tmp = new node<type>;

        tmp -> next = tp;
        tmp -> value = value;

        tp = tmp;
        length++;

        delete tmp;
    }
    void pop()
    {
        assert(length);

        tp = tp -> next, length--;
    }
    type top()
    {
        assert(length);

        return tp -> value;
    }
    size_t size()
    {
        return length;
    }
};
