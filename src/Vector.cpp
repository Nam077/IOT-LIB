#include "Vector.h"
#include <algorithm> // For std::copy, std::move
#include <stdexcept> // For std::out_of_range

template<typename T>
Vector<T>::Vector() : buffer(nullptr), mySize(0), myCapacity(0) {}

template<typename T>
Vector<T>::Vector(const Vector<T>& other) : mySize(other.mySize), myCapacity(other.myCapacity) {
    buffer = new T[myCapacity];
    std::copy(other.buffer, other.buffer + mySize, buffer);
}

template<typename T>
Vector<T>::Vector(Vector<T>&& other) noexcept : buffer(other.buffer), mySize(other.mySize), myCapacity(other.myCapacity) {
    other.buffer = nullptr;
    other.mySize = 0;
    other.myCapacity = 0;
}

template<typename T>
Vector<T>::~Vector() {
    delete[] buffer;
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
    if (this != &other) {
        T* newBuffer = new T[other.myCapacity];
        std::copy(other.buffer, other.buffer + other.mySize, newBuffer);
        delete[] buffer;
        buffer = newBuffer;
        mySize = other.mySize;
        myCapacity = other.myCapacity;
    }
    return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other) noexcept {
    if (this != &other) {
        delete[] buffer;
        buffer = other.buffer;
        mySize = other.mySize;
        myCapacity = other.myCapacity;
        other.buffer = nullptr;
        other.mySize = 0;
        other.myCapacity = 0;
    }
    return *this;
}

template<typename T>
void Vector<T>::push_back(const T& value) {
    if (mySize >= myCapacity) {
        reserve(myCapacity == 0 ? 8 : myCapacity * 2);
    }
    buffer[mySize++] = value;
}

template<typename T>
void Vector<T>::pop_back() {
    if (mySize > 0) {
        --mySize;
    }
}

template<typename T>
void Vector<T>::clear() {
    mySize = 0;
}

template<typename T>
bool Vector<T>::empty() const {
    return mySize == 0;
}

template<typename T>
size_t Vector<T>::size() const {
    return mySize;
}

template<typename T>
void Vector<T>::resize(size_t newSize) {
    if (newSize > myCapacity) {
        reserve(newSize);
    }
    mySize = newSize;
}

template<typename T>
void Vector<T>::reserve(size_t newCapacity) {
    if (newCapacity > myCapacity) {
        reallocate(newCapacity);
    }
}

template<typename T>
size_t Vector<T>::capacity() const {
    return myCapacity;
}

template<typename T>
T& Vector<T>::operator[](size_t index) {
    return buffer[index];
}

template<typename T>
const T& Vector<T>::operator[](size_t index) const {
    return buffer[index];
}

template<typename T>
T& Vector<T>::at(size_t index) {
    if (index >= mySize) {
        throw std::out_of_range("Index out of range");
    }
    return buffer[index];
}

template<typename T>
const T& Vector<T>::at(size_t index) const {
    if (index >= mySize) {
        throw std::out_of_range("Index out of range");
    }
    return buffer[index];
}

template<typename T>
T& Vector<T>::front() {
    return buffer[0];
}

template<typename T>
const T& Vector<T>::front() const {
    return buffer[0];
}

template<typename T>
T& Vector<T>::back() {
    return buffer[mySize - 1];
}

template<typename T>
const T& Vector<T>::back() const {
    return buffer[mySize - 1];
}

template<typename T>
void Vector<T>::insert(size_t index, const T& value) {
    if (index > mySize) {
        throw std::out_of_range("Index out of range");
    }
    if (mySize >= myCapacity) {
        reserve(myCapacity == 0 ? 8 : myCapacity * 2);
    }
    std::memmove(buffer + index + 1, buffer + index, (mySize - index) * sizeof(T));
    buffer[index] = value;
    ++mySize;
}

template<typename T>
void Vector<T>::erase(size_t index) {
    if (index >= mySize) {
        throw std::out_of_range("Index out of range");
    }
    std::memmove(buffer + index, buffer + index + 1, (mySize - index - 1) * sizeof(T));
    --mySize;
}

template<typename T>
void Vector<T>::swap(Vector<T>& other) {
    std::swap(buffer, other.buffer);
    std::swap(mySize, other.mySize);
    std::swap(myCapacity, other.myCapacity);
}

template<typename T>
void Vector<T>::reallocate(size_t newCapacity) {
    T* newBuffer = new T[newCapacity];
    std::copy(buffer, buffer + mySize, newBuffer);
    delete[] buffer;
    buffer = newBuffer;
    myCapacity = newCapacity;
}
