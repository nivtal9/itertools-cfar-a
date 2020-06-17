//
// Created by nivtal9 on 13.6.2020.
//
#include "range.hpp"
#include "doctest.h"
TEST_CASE("assert constructor"){
    for (int j=0;j<100;j++){
        for (int i: itertools::range(5,6))
            CHECK(i==5);
    }
}