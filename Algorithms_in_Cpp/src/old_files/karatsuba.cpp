/*
 * Implementation of Karatsuba algorithm for Binary multiplication
 * Karatsuba's algorithm is a recursive multiplication that uses 3 binary multiplications on numbers that are half of the original length
 * For Stanford's Algorithm class on Coursera
 * Date: 7/23/2019
 */
#include "../include/karatsuba.h"
using namespace std;
int count_digit(mpz_t n){
	if(n <=1){
		return 1;
	}
	return ceil(log10(n));
}

/*
 * Karatsuba multiplication on two numbers with the same number of digits
 * @int* number_a: a pointer to the first multiplier
 * @int* number_b: a pointer to the second multiplier
 * @int m: the length of each multiplier
 * Output: int* number_c, a pointer to the result of the operation
 */
mpz_t karatsuba(mpz_t number_a, mpz_t number_b, int m){
	if(m==1){
		return number_a*number_b;
	}
	// cout << "(function1) "<< "a= " << number_a << " b= " << number_b <<endl;
	mpz_t a, b, c, d;
	mpz_t nb_1, nb_2, nb_3, nb_4;
	mpz_t final_answer;
	int p = int(ceil(m/2));
	// power of 10 (10^x) can be implemented with (x<<3)*(x<<1)
	a = (mpz_t)((number_a)/pow(10, p));
	b = number_a - a*pow(10,p);
	cout << "original[a]= " << number_a << " parts: "<< a << " " << b << endl; 
	c = (mpz_t)((number_b)/pow(10,p));
	d = number_b - c*pow(10,p);
	cout << "original[b]= " << number_b << " parts: "<< c << " " << d << endl << endl; 

	nb_1 = karatsuba(a, c);
	nb_2 = karatsuba(b, d);
	nb_3 = karatsuba(a+b, c+d);
	nb_4 = nb_3 - nb_2 - nb_1;
	final_answer =   nb_1*pow(10,2*p) + nb_4*pow(10,p) + nb_2;
	//cout << number_a << " times " << number_b << " gives " << final_answer << endl;
	return final_answer;
}

/*
 * Karatsuba multiplication on two numbers with different numbers of digits
 * @int* number_a: a pointer to the first multiplier
 * @int* number_b: a pointer to the second multiplier
 * @int m: the length of each multiplier
 * Output: int* number_c, a pointer to the result of the operation
 */
mpz_t karatsuba(mpz_t number_a, mpz_t number_b, int m, int n){
	if(m==n){
		return karatsuba(number_a, number_b, m);
	}
	if(m==1 || n==1){
		return number_a*number_b;
	}else if(n>m){
		mpz_t temp=number_a;
		number_a = number_b;
		number_b= temp;
		int temp2 = m;
		m = n;
		n= temp2;
	}

	mpz_t a, b, c, d;
	mpz_t nb_1, nb_2, nb_3, nb_4;
	int p = int(ceil(m/2));
	int q = m-p;
	int k = int(ceil(n/2));
	int l = n-k;
	// power of 10 (10^x) can be implemented with (x<<3)*(x<<1)
	if(p>=n){
		a = (mpz_t)((number_a)/pow(10, p));
		b = number_a - a * pow(10,p);
		cout << "original[a]= " << number_a << " parts: "<< a << " " << b << endl << endl; 
		return karatsuba(a,number_b)*pow(10,p) + karatsuba(b,number_b);

	}else{
		k =p;
		l = n-p;
		a = (mpz_t)((number_a)/pow(10, p));
		b = number_a - a * pow(10,p);
		cout << "original[a]= " << number_a << " parts: "<< a << " " << b << endl; 
		c = (mpz_t)((number_b)/pow(10,p));
		d = number_b -c*pow(10,p);
		cout << "original[c]= " << number_b << " parts: "<< c << " " << d << endl << endl; 

		nb_1 = karatsuba(a, c, q, l);
		nb_2 = karatsuba(b, d, p);
		nb_3 = karatsuba(a+b, c+d);
		nb_4 = nb_3 - nb_2 - nb_1;
		mpz_t final_answer = nb_1*pow(10, 2*p) + nb_4*pow(10, p) + nb_2;
		//cout << number_a << " times " << number_b << " gives " << final_answer << endl;
		return final_answer;
	}
}

/*
 * Iniital Karatsuba algorithm for undefined numbers digits
 */

mpz_t karatsuba(mpz_t number_a, mpz_t number_b){
	int number_digits_a = count_digit(number_a);
	int number_digits_b = count_digit(number_b);
	mpz_t sol = karatsuba(number_a, number_b, number_digits_a, number_digits_b);
 
	cout << "Multiplying "<< number_a << " (" << number_digits_a << ") by " << number_b << " (" << number_digits_b << ") gives "<< sol << endl;
	return sol;
}
