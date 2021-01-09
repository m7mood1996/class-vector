//
// Created by mahmood on 1/8/21.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H


#include <cstddef>
#include <cstring>
#include <stdexcept>
#include <exception>

const size_t BASIC_SIZE = 1;

template<typename T>
class Vector {
public:

    Vector();
    ~Vector();
    Vector<T>& operator=(Vector<T>& other);


    inline size_t size() const;
    inline size_t max_size() const;
    inline size_t capacity() const;
    inline bool empty() const;
    void resize();
    void reserve (size_t n);

    T& operator[](size_t index);
    T& at(size_t index);
    inline T& front();
    inline T& back();
    inline T* data();


    void assign (size_t n, const T& val);
    void push_back(T &d);
    inline void pop_back();

    inline void swap(Vector<T> & other);
    inline void clear();

    template<typename G>
    friend Vector<G> operator+(Vector<G> &this_ve, Vector<G> & other);
    Vector<T> & operator+=(Vector<T> & other);

    class iterator;
    iterator begin() { return iterator(0, this); }
    iterator end() { return iterator(m_size, this); }
private:
    size_t m_size;
    size_t m_max_size;
    T* m_vector;


};


template<typename T>
class Vector<T>::iterator{
public:
    iterator(size_t pos, Vector<T> *vector):m_pos(pos),m_vector(vector){

    }
    inline iterator &operator++(int){
        ++m_pos;
        return *this;
    }
    inline T& operator*(){
        return (m_vector->at(m_pos));
    }
    inline bool operator!=(const iterator& other) const{
        return m_pos != other.m_pos;
    }
    inline bool operator==(const iterator& other) const{
        return m_pos == other.m_pos;
    }

private:
    size_t m_pos;
    Vector<T> *m_vector;
};


template<typename T>
Vector<T>::Vector():m_size(0)
{
    m_max_size = BASIC_SIZE;
    m_vector = (T*)::operator new(sizeof(T) * BASIC_SIZE );
}

template<typename T>
Vector<T>::~Vector()
{
    ::operator delete (m_vector);
}


template<typename T>
void Vector<T>::push_back(T &d)
{
    if (m_size == m_max_size)
        resize();

    std::memcpy(m_vector+m_size,&d, sizeof(T));
    ++m_size;

}

template<typename T>
void Vector<T>::resize()
{
    size_t newSize = m_max_size * 2;
    T* newV =  (T*)::operator new(sizeof(T) * newSize );
    memcpy(newV, m_vector, m_max_size * sizeof(T));
    m_vector = newV;
    m_max_size = newSize;
}

template<typename T>
size_t Vector<T>::size() const
{
    return m_size;
}

template<typename T>
size_t Vector<T>::max_size() const
{
    return m_max_size;
}

template<typename T>
size_t Vector<T>::capacity() const
{
    return m_max_size;
}

template<typename T>
Vector<T> &Vector<T>::operator=(Vector<T> &other)
        {
    memccpy(m_vector, other.m_vector,sizeof(T) * other.m_max_size);
    m_size = other.m_size;
    m_max_size = other.m_max_size;
    return *this;
}

template<typename T>
bool Vector<T>::empty() const
{
    return m_size == 0;
}

template<typename T>
void Vector<T>::reserve(size_t n)
{
    if (n <= m_max_size)
        return;

    T* newV =  (T*)::operator new(sizeof(T) * n );
    memcpy(newV, m_vector, m_max_size * sizeof(T));
    m_vector = newV;
    m_max_size = n;

}

template<typename T>
T &Vector<T>::operator[](size_t index)
{
    // does not check for bounds.
    T* object = m_vector + index;
    return *object;
}

template<typename T>
T &Vector<T>::at(size_t index)
{
    if (index > m_size || index < 0)
        throw std::exception(); // index out of range exciption out_of_range

    T* object = m_vector + index;
    return *object;
}

template<typename T>
T &Vector<T>::front()
{
    return *m_vector;
}

template<typename T>
T &Vector<T>::back()
{
    return *(m_vector+m_size-1);
}

template<typename T>
T *Vector<T>::data()
{
    return m_vector;
}

template<typename T>
void Vector<T>::assign(size_t n, const T &val)
{
    size_t i = 0;
    if (n > m_max_size)
        reserve(n);

    for (i;i<n;++i)
    {
        memccpy(m_vector + i, &val,sizeof(T));
    }
    if (m_size < n)
        m_size = n;

}

template<typename T>
void Vector<T>::pop_back()
{
    if (empty())
        return;
    --m_size;
}

template<typename T>
void Vector<T>::swap(Vector<T> &other)
{
    size_t temp_size = other.m_size;
    size_t temp_max_size = other.m_max_size;
    T* temp_v = other.m_vector;

    other.m_vector = m_vector;
    other.m_size = m_size;
    other.m_max_size = m_max_size;

    m_vector = temp_v;
    m_size = temp_size;
    m_max_size = temp_max_size;

}

template<typename T>
void Vector<T>::clear() {
    m_size = 0;
}

// Extintion 1



template<typename T>
Vector<T> &Vector<T>::operator+=(Vector<T> &other) {
    if (m_size + other.m_size > m_max_size)
        reserve(m_size + other.m_size);
    memcpy(m_vector + m_size, other.m_vector, other.m_size * sizeof(T));
    m_size = m_size + other.m_size;

    return *this;
}
template<typename T>
Vector<T> operator+(Vector<T> &this_ve, Vector<T> &other)
{
    Vector<T> v;
    v.reserve(this_ve.m_size + other.m_size);
    memcpy(v.m_vector, this_ve.m_vector, this_ve.m_size * sizeof(T));
    memcpy(v.m_vector + this_ve.m_size, other.m_vector, other.m_size * sizeof(T));
    v.m_size = this_ve.m_size + other.m_size;
    return v;

}





#endif //VECTOR_VECTOR_H
