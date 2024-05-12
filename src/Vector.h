#ifndef VECTOR_H
#define VECTOR_H

template<typename T>
class Vector {
public:
    Vector();
    Vector(const Vector<T>& other);
    Vector(Vector<T>&& other) noexcept;
    ~Vector();

    Vector<T>& operator=(const Vector<T>& other);
    Vector<T>& operator=(Vector<T>&& other) noexcept;

    void push_back(const T& value);
    void pop_back();
    void clear();
    bool empty() const;
    size_t size() const;
    void resize(size_t newSize);
    void reserve(size_t newCapacity);
    size_t capacity() const;

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    T& at(size_t index);
    const T& at(size_t index) const;

    T& front();
    const T& front() const;
    T& back();
    const T& back() const;

    void insert(size_t index, const T& value);
    void erase(size_t index);

    void swap(Vector<T>& other);

private:
    T* buffer;
    size_t mySize;
    size_t myCapacity;

    void reallocate(size_t newCapacity);
};

#include "Vector.cpp"

#endif // VECTOR_H
