/*
 *Doesn't contain any crucial information except a few function prototypes and others
 *
 */
#ifndef RECURSIVE_ALGS_H
#define RECURSIVE_ALGS_H

#include<iostream>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <gmpxx.h>

// FUNCTION PROTOTYPES
size_t count_digit(mpz_class n);


mpz_class karatsuba(mpz_class number_a, mpz_class number_b, int m);

mpz_class karatsuba(mpz_class number_a, mpz_class number_b, int m, int n);

mpz_class karatsuba(mpz_class number_a, mpz_class number_b);
#endif
