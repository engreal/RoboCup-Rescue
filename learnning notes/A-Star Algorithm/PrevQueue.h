#ifndef PREVQUEUE_H
#define PREVQUEUE_H

#include <algorithm>
#include <vector>

template <typename T,
        typename Container = std::vector<T>,
        typename Compare = std::less<typename Container::value_type> >
struct PrevQueue
{
    typedef T value_type;
    typedef typename Container::iterator iterator;
    Compare comp;
    Container c;

    PrevQueue(const Compare &cmp = Compare(),
              const Container &cont = Container())
    : comp(cmp), c(cont)
    {
        std::make_heap(c.begin(), c.end(), comp);
    }
    void push(const value_type &x)
    {
        c.push_back(x);
        std::push_heap(c.begin(), c.end(), comp);
    }
    void pop()
    {
        std::pop_heap(c.begin(), c.end(), comp);
        c.pop_back();
    }
    const value_type &top() const
    {
        return c.front();
    }
    bool empty() const
    {
        return c.empty();
    }
    size_t size() const
    {
        return c.size();
    }
    iterator begin()
    {
        return c.begin();
    }
    iterator end()
    {
        return c.end();
    }
};

#endif // PREVQUEUE_H
