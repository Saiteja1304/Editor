#ifndef CONTAINER_HPP
#define CONTAINER_HPP
#include <cstring>
#include <iostream>
template <typename T> struct Container {
    // index -> Do not access or change index directly
    // size -> Count of elements
    // elements -> array of elements. The actual data
    unsigned short int index = 0, size = 0;
    T *elements;
    // adds element at the end of the container
    void add(T object) {
#ifdef EVALUATION_ENABLED
        if (index > size) {
            std::cerr << "[WARNING][Container][Container full]\n";
        }
#endif
        elements[index] = object;
        index += 1;
    }

    // removes elemnt at the index and returns the element
    T rremove(int _index) {
#ifdef EVALUATION_ENABLED
        if (_index > index) {
            std::cerr << "[ERROR][Container][index out of bound]\n";
        }
#endif
        T t = *elements[_index];
        *elements[_index] = *elements[index - 1];
        index -= (index > 0) * 1;
        return t;
    }

    // removes elemet at the index
    void remove(int _index) {
#ifdef EVALUATION_ENABLED
        if (_index > index) {
            std::cerr << "[ERROR][Container][index out of bound]\n";
        }
#endif
        *elements[_index] = *elements[index - 1];
        index -= (index > 0) * 1;
    }

    int cfind(T t) {
        int i = 0, j = 0;
        for (i = 0; i < index; i++) {
            j = (!strcmp(elements[i], t)) * i + j * (j != 0);
        }
#ifdef EVALUATION_ENABLED
        if (j == 0)
            std::cerr << "[Check][Container][element not found]\n";
#endif
        return j;
    }

    // returns the element index if found
    int find(T t) {
        int i = 0, j = 0;
        for (i = 0; i < index; i++) {
            j = (elements[i] == t) * i + j * (j != 0);
        }
#ifdef EVALUATION_ENABLED
        if (j == 0)
            std::cerr << "[Check][Container][element not found]\n";
#endif
        return j;
    }

    // resizes the container
    void resize(unsigned short int _size) {
#ifdef EVALUATION_ENABLED
        if (_size < size) {
            std::cerr << "[WARNING][Container][cannot decrease the size]\n";
        }
#endif
        T *t = new T[_size];
        for (int i = 0; i < size; i++) {
            t[i] = elements[i];
        }
        size = _size;
        delete[] elements;
        elements = new T[size];
        for (int i = 0; i < size; i++) {
            elements[i] = t[i];
        }
        delete[] t;
    }
    Container() {}
    Container(unsigned short int _size) {
#ifdef EVALUATION_ENABLED
        if (_size < 1) {
            std::cerr << "[WARNING][Container][Size cannot be less than 1]\n";
        }
#endif
        size = _size;
        elements = new T[_size];
    }
    ~Container() { delete[] elements; }
};

#endif