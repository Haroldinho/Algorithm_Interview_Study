/*
 * Implementation of Karatsuba algorithm for Binary multiplication
 * Karatsuba's algorithm is a recursive multiplication that uses 3 binary multiplications on numbers that are half of the original length
 * For Stanford's Algorithm class on Coursera
 * Date: 7/23/2019
 */
#include "../include/karatsuba.h"
using namespace std;
size_t count_digit(mpz_class n){
	return mpz_sizeinbase(n.get_mpz_t(), 10);
}

/*
 * Karatsuba multiplication on two numbers with the same number of digits
 * @int* number_a: a pointer to the first multiplier
 * @int* number_b: a pointer to the second multiplier
 * @int m: the length of each multiplier
 * Output: int* number_c, a pointer to the result of the operation
 */
mpz_class karatsuba(mpz_class number_a, mpz_class number_b, int m){
	if(m <= 2){
		mpz_class result;
		result =  number_a * number_b;
		return result;
	}
	// cout << "(function1) "<< "a= " << number_a << " b= " << number_b <<endl;
	mpz_class a, b, c, d;
	mpz_class nb_1, nb_2, nb_3, nb_4, temp1, temp2, temp3;
	mpz_class final_answer;
	int p = int(ceil(m/2));
	// power of 10 (10^x) can be implemented with (x<<3)*(x<<1)
	mpz_class pow_10_p = pow(10,p);
	//mpz_pow_ui(pow_10_p, 10, p);
	a = number_a/pow_10_p;
	b = number_a%pow_10_p;
//	mpz_cdiv_q(a, number_a, pow_10_p);
//	mpz_cdiv_r(b, number_a, pow_10_p);
//	mpz_cdiv_q(c, number_b, pow_10_p);
//	mpz_cdiv_r(d, number_b, pow_10_p);
	c = number_b/pow_10_p;
	d = number_b%pow_10_p;
	cout << "original[a]= " << number_a << " parts: "<< a << " " << b << endl; 
	cout << "original[b]= " << number_b << " parts: "<< c << " " << d << endl << endl; 

	nb_1 = karatsuba(a, c);
	nb_2 = karatsuba(b, d);
	nb_3 = karatsuba(a+b, c+d);
//	mpz_add(temp1, a, b);
//	mpz_add(temp2, c, d);
//	nb_3 = karatsuba(temp1, temp2);

	nb_4 = nb_3 - nb_2 - nb_1;
//	mpz_add(temp3, nb_2, nb_1);
//	mpz_sub(nb_4, nb_3, temp3);
//	mpz_mul(temp1, nb_1, 2*pow_10_p);
//	mpz_mul(temp2, nb_4, pow_10_p);
//	mpz_add(temp3, temp_1, temp2);
//	mpz_add(final_answer, temp3, nb_2);
	final_answer = nb_1*pow_10_p*pow_10_p + nb_4*pow_10_p + nb_2;
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
mpz_class karatsuba(mpz_class number_a, mpz_class number_b, int m, int n){
	if(m==n){
		return karatsuba(number_a, number_b, m);
	}
	if(m <= 2 || n <=2){
		mpz_class result;
//		mpz_mul(result, number_a, number_b);
		return number_a * number_b;
	}else if(n>m){
		mpz_class temp=number_a;
		number_a = number_b;
		number_b= temp;
		int temp2 = m;
		m = n;
		n= temp2;
	}

	mpz_class a, b, c, d;
	mpz_class nb_1, nb_2, nb_3, nb_4;
	mpz_class temp1, temp2, temp3;
	int p = int(ceil(m/2));
	int q = m-p;
	int k = int(ceil(n/2));
	int l = n-k;
	mpz_class pow_10_p = pow(10,p);
	// power of 10 (10^x) can be implemented with (x<<3)*(x<<1)
	if(p>=n){
		a = number_a / pow_10_p;
		b = number_a % pow_10_p;
//		mpz_cdiv_q(a, number_a, pow_10_p);
//		mpz_cdiv_r(b, number_a, pow_10_p);
		cout << "original[a]= " << number_a << " parts: "<< a << " " << b << endl << endl; 
		nb_1 = karatsuba(a, number_b);
		nb_2 = karatsuba(b, number_b);
		nb_4 = nb_1*pow_10_p + nb_2;
		return nb_4;
	}else{
		k =p;
		l = n-p;
		a = number_a/pow_10_p;
		b = number_a % pow_10_p;
		cout << "original[a]= " << number_a << " parts: "<< a << " " << b << endl; 
		c = number_b / pow_10_p;
		d = number_b % pow_10_p;
//		mpz_cdiv_q(c, number_b, pow_10_p);
//		mpz_cdiv_r(d, number_b, pow_10_p);
		cout << "original[c]= " << number_b << " parts: "<< c << " " << d << endl << endl; 

		nb_1 = karatsuba(a, c, q, l);
		nb_2 = karatsuba(b, d, p);

//		mpz_add(temp1, a, b);
//		mpz_add(temp2, c, d);
		nb_3 = karatsuba( a+b, c+d);
//		mpz_add(temp3, nb_2, nb_1);
//		mpz_sub(nb_4, nb_3, temp3);
		nb_4 = nb_3 - nb_2 - nb_1;
		mpz_class final_answer;
		final_answer = nb_1*pow_10_p*pow_10_p + nb_4*pow_10_p + nb_2;
		//cout << number_a << " times " << number_b << " gives " << final_answer << endl;
		return final_answer;
	}
}

/*
 * Call Karatsuba algorithm for undefined number of digits for the two numbers
 */

mpz_class karatsuba(mpz_class number_a, mpz_class number_b){
	int number_digits_a = count_digit(number_a);
	int number_digits_b = count_digit(number_b);
	mpz_class sol = karatsuba(number_a, number_b, number_digits_a, number_digits_b);
 
	cout << "Multiplying "<< number_a << " (" << number_digits_a << ") by " << number_b << " (" << number_digits_b << ") gives "<< sol << endl;
	return sol;
}
