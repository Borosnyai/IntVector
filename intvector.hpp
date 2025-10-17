#ifndef INTVECTOR_HPP
#define INTVECTOR_HPP
#include<cstddef>
#include<iostream>


namespace iv{
    class IntVector{

    private:
        std::size_t capacity;   // Wie viel Platz reservieren
        std::size_t size;   // Wie viele elemente sind drinnen.
        int* array;             // Pointer auf dinamische array


    public:
        // Constructor
        IntVector();            // default Constructor
        IntVector(std::size_t capacity);


        // Destructor
        ~IntVector();

        void zeros();
        void ones();
        // size = 10; start = 5; 5,6,7,8,9,10,11,12,13,14
        void range(int start);
        // append 12345 6
        void push_back(int elem);
        void insert_override(int index, int elem);
        std::size_t count(int elem);
        int index(int elem);// if number doesn't exit then return - 1;
        void print(std::ostream& where);
        std::size_t get_size();
        std::size_t get_capacity();
        int get_elem(std::size_t index);
        void resize(std::size_t new_capacity);
        long int sum();
        
        int pop_back();
        

    };




}


#endif
