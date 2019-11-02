/*
 * Code to test the matrix multiplication procedures using catch for unit testing
 *
 *
 */
#include <catch2/catch.hpp>
#include "../include/karatsuba.h"

TEST_CASE("Simple multiplications are performed", "[mulitplication]"){
	REQUIRE( karatsuba(2,1) == 2);
	REQUIRE( karatsuba(124, 2) == 248);
	REQUIRE( karatsuba(10000, 43) == 430000);
	REQUIRE( karatsuba(1245, 464) == 577680);
	REQUIRE( karatsuba(-2,4) == -8);
	REQUIRE( karatsuba(-2,-4)==8);
}
