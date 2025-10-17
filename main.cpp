#include "intvector.hpp"
#include<iostream>


int main(){
    // CONSTRUCTORS
    iv::IntVector* v1 = new iv::IntVector(7);
    iv::IntVector* v2 = new iv::IntVector(10);
    /*************************************************/
    // FUNCTIONS
    v2->zeros();
    v2->print();
    v2->ones();
    v2->print();
    v2->range(6);
    v2->print();
    // push_back
    v1->push_back(12);
    v1->push_back(34);
    v1->insert_override(5, 42);
    v1->print();
    /*****************************************************/
    /*COUNT*/
    size_t result = v1->count(0);
    std::cout << "Count of zeros: " << result << std::endl;
    /*****************************************************/
    /*INDEX*/
    int result2 = v1->index(0);
    if(result2 == -1){
        std::cout << "No result of index" << std::endl;
    }else{
         std::cout << "First zero index: " << result2 << std::endl;
    }
    /**************************************************/
    int result3 = v1->get_size();
    std::cout << "The size of the v1_array: " << result3 << std::endl;
    /*****************************************************/
    int result4 = v1->get_capacity();
    std::cout << "The capacity of the v1_array: " << result4 << std::endl;
    // Make it smaller the array
    v1->resize(2);
    /****************************************************/
    int result5 = v1->get_capacity();
    std::cout << "The capacity of the new resized v1_array: " << result5 << std::endl;
    v1->print();
    /****************************************************/
    // make it bigger the array
    v1->resize(4);
    int result6 = v1->get_capacity();
    std::cout << "The capacity of the new resized v1_array: " << result6 << std::endl;
    v1->print();
    /*****************************************************/
    /*SUM*/
    result6 = v1->sum();
    std::cout << "The sum of of array is: " << result6 << std::endl;
    /*****************************************************/
    /*POP_BACK*/
    int result7 = v1->pop_back();
    std::cout << "The last number of array is: " << result7 << std::endl;
    delete v1;
    delete v2;
    

    return 0;
}
// class = osztaly => tervrajz
// v1 = peldany/objektum => instance/object
// v2 = peldany/objektum => instance/object
