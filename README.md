# IntVector

A simple dynamic integer vector class implementation in C++.

## Description

IntVector is a dynamic integer array implementation that automatically grows its capacity when needed.

## Constructors

### `IntVector()`
Creates an empty vector that does not allocate memory and has a capacity of 0.

### `IntVector(std::size_t capacity)`
Creates a vector with the specified capacity, allocating space for the given number of elements.

## Destructor

### `~IntVector()`
Frees the dynamically allocated memory and resets the vector's attributes to zero.

## Methods

### `void zeros()`
Fills the entire vector with zeros and sets the size equal to the capacity.

### `void ones()`
Fills the entire vector with ones and sets the size equal to the capacity.

### `void range(int start)`
Fills the vector with consecutive numbers starting from the specified value.

### `void push_back(int elem)`
Adds an element to the end of the vector and automatically increases capacity if needed.

### `void insert_override(int index, int elem)`
Inserts an element at the specified index, overwriting the previous value and filling intermediate gaps with zeros if necessary.

### `std::size_t count(int elem)`
Returns the number of occurrences of the specified element in the vector.

### `int index(int elem)`
Returns the index of the first occurrence of the specified element, or -1 if not found.

### `void print()`
Prints to the console the vector's capacity, size, and all stored elements.

### `std::size_t get_size()`
Returns the current number of elements stored in the vector.

### `std::size_t get_capacity()`
Returns the vector's current capacity, meaning how many elements have allocated memory.

### `void resize(std::size_t new_capacity)`
Changes the vector's capacity to the new value, preserving existing elements or truncating them if the new capacity is smaller.

### `long int sum()`
Calculates and returns the sum of all elements stored in the vector.

### `int pop_back()`
Removes and returns the last element of the vector, decreasing the size by one.

## Usage
```cpp
iv::IntVector* v1 = new iv::IntVector(10);
v1->zeros();
v1->push_back(42);
v1->print();
delete v1;

```
