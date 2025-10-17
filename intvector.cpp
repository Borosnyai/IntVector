#include "intvector.hpp"


namespace iv
{

IntVector::IntVector()
{
    capacity = 0;
    size = 0;
    array = nullptr;
}

IntVector::IntVector ( std::size_t capacity )
{
    this->capacity = capacity;
    size = 0;
    array = new int[capacity];
}
IntVector::~IntVector()
{
    delete[] array;
    capacity = 0;
    size = 0;
    array = nullptr;
}

void IntVector::zeros()
{
    for ( size_t i = 0; i < capacity; i++ ) {
        array[i] = 0;


    }
    size = capacity;

}
void IntVector::print(std::ostream& where=std::cout){
    
    for(size_t i = 0; i < size; i++){
        where << array[i] << " ";
    }
    where << std::endl; 
}

void IntVector::ones()
{
    for ( size_t i = 0; i < capacity; i++ ) {
        array[i] = 1;


    }
    size = capacity;
}

void IntVector::range ( int start )
{
    for(size_t i = 0; i < capacity; i++){
        array[i] = start;
        start++;
    }
    size = capacity;
}
// append elem to end of the list
// if not enogh place, change the size.
void IntVector::push_back ( int elem )
{   
    // 0    1   2   3   4   5   6
    // 12, 34, 56, 88, 12, 123, 22 
    // size = 7 
    // capacity = 7
    //
    if(size < capacity){
        array[size] = elem;
        size++;
    }else{
       int* new_array = new int[capacity + 1];
       for(size_t i = 0; i < capacity; i++){
           new_array[i] = array[i];
        }
        new_array[size] = elem;
        size++;
        capacity++;
        delete[] array;
        array = new_array;
        
    }
    
    
}
    void IntVector::insert_override(int index, int elem){
        // 0    1   2   3   4   5   6
        // 12, 34,  0,  0,  0,  42,  _
        // size = 2 
        // capacity = 7
        // elem = 42
        // index = 5
        
        // if this index exist
        if(index < capacity){
            array[index] = elem;
            // if we are faraway from the actuall size.
            // fill the gaps with zeros.
            if(index >= size){
                for(size_t i = size; i < index; i++){
                    array[i] = 0;
                }
                size = index + 1;
            }
        }
    // 0, 1
    // 1, _,
    // cap = 2
    // size = 1
    // insert_override(0, 1)
        
        
        
    
    }
    std::size_t IntVector::count (int elem){
        size_t c = 0;
        for(size_t i = 0; i < size; i++){
            if(array[i] == elem){
                c++;
            }
        }
        return c;
        
    }
    
  int IntVector::index(int elem){
        // 0    1   2   3   4   5   6
        // 12, 34,  0,  0,  0,  42, _
        // Result = 4
        // elem = 0
        
        int result = -1;
        for(int i = 0; i < size; i++){
            if(elem == array[i]){
                result = i;
                break;
            }
        }
        return result;
        
    }
    std::size_t IntVector::get_size(){
        return size;
    }
    
    std::size_t IntVector::get_capacity(){
    
        return capacity;
    }
    
    int IntVector::get_elem ( std::size_t index ){
    
        return array[index];
}

        
        
    
    
    void IntVector::resize(std::size_t new_capacity){
        
        if(new_capacity == capacity){
            return;
        }
        else if(new_capacity > capacity){
            int* new_array = new int[new_capacity];
            for(size_t i = 0; i < capacity; i++){
                new_array[i] = array[i];
            }
            delete[] array;
            array = new_array;
            capacity = new_capacity;
        }
        else if(new_capacity < capacity){
            int* new_array = new int[new_capacity];
            if(new_capacity < size){
                for(size_t i = 0; i < new_capacity; i++){
                new_array[i] = array[i];
                }
                size = new_capacity;
            }else{
                for(size_t i = 0; i < size; i++){
                    new_array[i] = array[i];
                }
            }
            delete[] array;
            array = new_array;
            capacity = new_capacity;
            
            
        }
    }
    
    long IntVector::sum(){
        long s = 0;
        for(size_t i = 0; i < size; i++){
            s += array[i];
        }
        return s;
        
    }
    // Delete the last element and returns it.
        // 0
        // size--, 
        
        // Egy mondato összefoglalot irjon kiterve a return ertekekre!
        // szelsö ertek ami függvenyekre veszelyes!

        
    int IntVector::pop_back(){
        if(capacity == 0 || size == 0){
            return 0;
        }
        int last_num = array[size - 1];
        // Removing the last number
        size--;
        return last_num;
        
    }
    
    
    
} // end of namespace
