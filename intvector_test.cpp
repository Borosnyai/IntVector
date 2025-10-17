#include "catch_amalgamated.hpp"
#include "intvector.hpp"
#include <climits>


using namespace iv;

TEST_CASE("Empty Test", "[empty]"){
    IntVector* v = new IntVector;
    SECTION("Constructor without parameter"){
        CHECK(v->get_capacity() == 0);
        CHECK(v->get_size() == 0);
        CHECK(v->sum() == 0);
        CHECK(v->count(7) == 0);
        CHECK(v->index(9) == - 1);
    }
   
}


TEST_CASE("Empty Test_2", "[empty_2]"){
    IntVector* v = new IntVector(6);
    SECTION("Constructor with parameter"){
        CHECK(v->get_capacity() == 6);
        CHECK(v->get_size() == 0);
        CHECK(v->sum() == 0);
        CHECK(v->count(7) == 0);
        CHECK(v->index(9) == -1);
    }
   
}

TEST_CASE("Zeros", "[zeros]"){
    IntVector* v = new IntVector(6);
    v->zeros();
    SECTION("Zeros"){
        CHECK(v->get_capacity() == 6);
        CHECK(v->get_size() == 6);
        CHECK(v->sum() == 0);
        CHECK(v->count(7) == 0);
        CHECK(v->count(0) == 6);
        CHECK(v->index(0) == 0);
    }
   
}

TEST_CASE("ONES", "[ones]"){
    IntVector* v = new IntVector(6);
    v->ones();
    SECTION("Ones"){
        CHECK(v->get_capacity() == 6);
        CHECK(v->get_size() == 6);
        CHECK(v->sum() == 6);
        CHECK(v->count(7) == 0);
        CHECK(v->count(0) == 0);
        CHECK(v->index(0) == -1);
    }
   
}


TEST_CASE("Range", "[range]"){
    IntVector* v = new IntVector(6);
    v->range(0);
    SECTION("Range"){
        CHECK(v->get_capacity() == 6);
        CHECK(v->get_size() == 6);
        CHECK(v->sum() == 15);
        CHECK(v->count(2) == 1);
        CHECK(v->count(0) == 1);
        CHECK(v->index(2) == 2);
  
    }
   
}


TEST_CASE("PUSH_BACK, enough space", "[push]"){
    IntVector* v = new IntVector(3);
    v->push_back(2);
    SECTION("Push_back"){
        CHECK(v->get_capacity() == 3);
        CHECK(v->get_size() == 1);
        CHECK(v->sum() == 2);
        CHECK(v->count(2) == 1);
        CHECK(v->index(2) == 0);
    }
   
}

TEST_CASE("PUSH_BACK, not enough space", "[push_full]"){
    IntVector* v = new IntVector(1);
    v->push_back(2);
    v->push_back(3);
    SECTION("Push_back"){
        CHECK(v->get_capacity() == 2);
        CHECK(v->get_size() == 2);
        CHECK(v->sum() == 5);
        CHECK(v->count(2) == 1);
        CHECK(v->index(3) == 1);
    }
   
}



TEST_CASE("PUSH_BACK ALL NUMBERS", "[push_all]"){
    IntVector* v = new IntVector(201);
    for(int i = -100; i <= 100; i++){
        v->push_back(i);
        //std::cout << i << std::endl;
    }
    SECTION("Push_back"){
        
        // -2... +2
        // -2, -1, 0, 1, 2
        CHECK(v->get_capacity() == 201);
        CHECK(v->get_size() == 201);
        CHECK(v->sum() == 0);
        CHECK(v->index(0) == 100);
    }
   
}

TEST_CASE("INSERT_OVERRIDE", "[insert_override]"){
    IntVector* v = new IntVector(1);
    v->push_back(2);
    v->insert_override(0, 3);
    SECTION("Insert_override"){
        CHECK(v->get_capacity() == 1);
        CHECK(v->get_size() == 1);
        CHECK(v->sum() == 3);
        CHECK(v->count(2) == 0);
        CHECK(v->count(3) == 1);
        CHECK(v->index(2) == -1);
        CHECK(v->index(3) == 0);
    }
   
}

TEST_CASE("INSERT_OVERRIDE_FARAWAY", "[insert_override_faraway]"){
    IntVector* v = new IntVector(10);
    v->push_back(1);
    v->push_back(1);
    v->insert_override(5, 1);
    SECTION("Insert_override"){
        // 1, 1, 0, 0, 0, 1, _, _, _, _, 
        CHECK(v->get_capacity() == 10);
        CHECK(v->get_size() == 6);
        CHECK(v->sum() == 3);
        CHECK(v->count(1) == 3);
        CHECK(v->count(0) == 3);
        CHECK(v->get_elem(5) == 1);
    }
   
}

TEST_CASE("COUNT", "[count]"){
    IntVector* v = new IntVector(2);
    v->insert_override(0, 1);
    v->insert_override(1, 1);
    SECTION("Insert_override"){
        CHECK(v->count(2) == 0);
        CHECK(v->count(1) == 2);
    }
   
}


TEST_CASE("RESIZE", "[resize]"){
    IntVector* v = new IntVector(3);
    v->insert_override(0, 1);
    v->insert_override(1, 1);
    v->insert_override(2, 1);
    SECTION("Resize_DOWN"){
        v->resize(1);
        CHECK(v->get_capacity() == 1);
        CHECK(v->get_size() == 1);
        CHECK(v->sum() == 1);
    }
    SECTION("Resize_UP"){
        v->resize(5);
        CHECK(v->get_capacity() == 5);
        CHECK(v->get_size() == 3);
        CHECK(v->sum() == 3);
    }
   
}

TEST_CASE("PRINT", "[print]"){
    IntVector* v = new IntVector(2);
    v->insert_override(0, 1);
    v->insert_override(1, 1);
    SECTION("print"){
        std::ostringstream temp;
        v->print(temp);
        CHECK(temp.str() == "1 1 \n");
    }
   
}

TEST_CASE("POP_BACK", "[pop_back]"){
    IntVector* v = new IntVector(2);
    v->insert_override(0, 1);
    v->insert_override(1, 2);
    SECTION("pop_back"){
        int temp = v->pop_back();
        CHECK(temp == 2);
        CHECK(v->get_capacity() == 2);
        CHECK(v->get_size() == 1);
        CHECK(v->sum() == 1);
    }
   
}
