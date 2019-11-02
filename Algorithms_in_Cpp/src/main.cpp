/*
 * Main file to call Divide-and-Conquer algorithms 
 *
 */
#include "../include/karatsuba.h"
#include <iostream>
#define BIG_NUM_1 3141592653589793238462643383279502884197169399375105820974944592_mpz
#define BIG_NUM_2 2718281828459045235360287471352662497757247093699959574966967627_mpz

using namespace std;
int main(){
	//mpz_t a = 31415926535897932ULL;
	mpz_class a, b;
	a = BIG_NUM_1;
	b = BIG_NUM_2;
//       	mpz_init_set_str(a, "BIG_NUM_1");
//	//mpz_t b = 27182818284590452ULL;
//	mpz_init_set_str(b, "BIG_NUM_2");
	mpz_class answer;
        answer	= karatsuba(a,b);
	cout << a << " times " << b << "=" << answer << endl;	
}
