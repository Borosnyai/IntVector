#include "intvector.hpp"


namespace iv
{

IntVector::IntVector()
{
    capacity_ = 0;
    size_ = 0;
    array_ = nullptr;
}

IntVector::IntVector ( std::size_t capacity )
{
    this->capacity_ = capacity;
    size_ = 0;
    array_ = new int[capacity];
}
IntVector::~IntVector()
{
    delete[] array_;
    capacity_ = 0;
    size_ = 0;
    array_ = nullptr;
}

void IntVector::zeros()
{
    for ( size_t i = 0; i < capacity_; i++ ) {
        array_[i] = 0;


    }
    size_ = capacity_;

}
void IntVector::print(std::ostream& where=std::cout){
    
    for(size_t i = 0; i < size_; i++){
        where << array_[i] << " ";
    }
    where << std::endl; 
}

void IntVector::ones()
{
    for ( size_t i = 0; i < capacity_; i++ ) {
        array_[i] = 1;


    }
    size_ = capacity_;
}

void IntVector::range ( int start )
{
    for(size_t i = 0; i < capacity_; i++){
        array_[i] = start;
        start++;
    }
    size_ = capacity_;
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
    if( size_ < capacity_ ){
        array_[size_] = elem;
        size_++;
    }else{
       int* new_array = new int[capacity_ + 1];
       for(size_t i = 0; i < capacity_; i++){
           new_array[i] = array_[i];
        }
        new_array[size_] = elem;
        size_++;
        capacity_++;
        delete[] array_;
        array_ = new_array;
        
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
        if(index < capacity_ ){
            array_[index] = elem;
            // if we are faraway from the actuall size.
            // fill the gaps with zeros.
            if(index >= size_ ){
                for(size_t i = size_; i < index; i++){
                    array_[i] = 0;
                }
                size_ = index + 1;
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
        for(size_t i = 0; i < size_; i++){
            if( array_[i] == elem){
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
        for(int i = 0; i < size_; i++){
            if(elem == array_[i]){
                result = i;
                break;
            }
        }
        return result;
        
    }
    std::size_t IntVector::get_size(){
        return size_;
    }
    
    std::size_t IntVector::get_capacity(){
    
        return capacity_;
    }
    
    int IntVector::get_elem ( std::size_t index ){
    
        return array_[index];
}

        
        
    
    
    void IntVector::resize(std::size_t new_capacity){
        
        if(new_capacity == capacity_ ){
            return;
        }
        else if(new_capacity > capacity_ ){
            int* new_array = new int[new_capacity];
            for(size_t i = 0; i < capacity_; i++){
                new_array[i] = array_[i];
            }
            delete[] array_;
            array_ = new_array;
            capacity_ = new_capacity;
        }
        else if(new_capacity < capacity_ ){
            int* new_array = new int[new_capacity];
            if(new_capacity < size_ ){
                for(size_t i = 0; i < new_capacity; i++){
                new_array[i] = array_[i];
                }
                size_ = new_capacity;
            }else{
                for(size_t i = 0; i < size_; i++){
                    new_array[i] = array_[i];
                }
            }
            delete[] array_;
            array_ = new_array;
            capacity_ = new_capacity;
            
            
        }
    }
    
    long IntVector::sum(){
        long s = 0;
        for(size_t i = 0; i < size_; i++){
            s += array_[i];
        }
        return s;
        
    }
    // Delete the last element and returns it.
        // 0
        // size--, 
        
     

        
    int IntVector::pop_back(){
        if( capacity_ == 0 || size_ == 0){
            return 0;
        }
        int last_num = array_[size_ - 1];
        // Removing the last number
        size_--;
        return last_num;
        
    }
    
    
    
} // end of namespace
