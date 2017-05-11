#pragma once

#include <string>
#include <vector>
#include <iostream>

/*

TLDR; Do not use Union.

Author note: I'm very skeptical of the usage of this keyword. In a normal context, do not
use it. It basically create a struct where the size of the struct is the biggest max size of
all the variables in it. Only 1 variable is alive at any given time.

When to use it?
This post explains parts of it:
http://stackoverflow.com/questions/4788965/when-would-anyone-use-a-union-is-it-a-remnant-from-the-c-only-days


*/

namespace Union
{
	struct my_variant_t {
		enum
		{
			VAR_CHAR,
			VAR_SHORT,
			VAR_INT,
			VAR_LONG,
			VAR_FLOAT,
			VAR_DOUBLE,
			VAR_PTR
		} type;
		union {
			char char_value;
			short short_value;
			int int_value;
			long long_value;
			float float_value;
			double double_value;
			void* ptr_value;
		};
	};

	

	/* construct a new float variant instance */
	void init_float(struct my_variant_t* v, float initial_value) {
		v->type = my_variant_t::VAR_FLOAT;
		v->float_value = initial_value;
	}

	/* Increments the value of the variant by the given int */
	void inc_variant_by_int(struct my_variant_t* v, int n) {
		switch (v->type) {
		case my_variant_t::VAR_FLOAT:
			v->float_value += n;
			break;

		case my_variant_t::VAR_INT:
			v->int_value += n;
			break;
		default:
			break;
		}
	}

	void printVariant(const my_variant_t& s)
	{
		switch (s.type)
		{
		case my_variant_t::VAR_CHAR:	std::cout << s.char_value << '\n'; break;
		case my_variant_t::VAR_SHORT:	std::cout << s.short_value << '\n'; break;
		case my_variant_t::VAR_INT:		std::cout << s.int_value << '\n'; break;
		case my_variant_t::VAR_LONG:	std::cout << s.long_value << '\n'; break;
		case my_variant_t::VAR_FLOAT:	std::cout << s.float_value << '\n'; break;
		case my_variant_t::VAR_DOUBLE:	std::cout << s.double_value << '\n'; break;
		default:
			break;
		}
	}


	inline void start()
	{
		my_variant_t val;
		init_float(&val, 5);
		inc_variant_by_int(&val, 1);

		printVariant(val);
	}
}
