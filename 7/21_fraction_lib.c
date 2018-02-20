#include <stdio.h>

typedef struct {
	int numerator;
	int denominator;
} fraction_t;

void print_fraction(fraction_t a)
{
	printf("%d/%d\n", a.numerator, a.denominator);
}

fraction_t add_fraction(fraction_t a, fraction_t b)
{
	fraction_t r;

	r.numerator = a.numerator * b.denominator
		+ b.numerator * a.denominator;
	r.denominator = a.denominator * b.denominator;
	return r;
}

#if 0
fraction_t sub_fraction(fraction_t a, fraction_t b)
{
}

fraction_t mult_fraction(fraction_t a, fraction_t b)
{
}

fraction_t div_fraction(fraction_t a, fraction_t b)
{
}

fraction_t simple_fraction(fraction_t a, fraction_t b)
{
}
#endif

int main()
{
	print_fraction(add_fraction((fraction_t) {
				1, 3}, (fraction_t) {
				1, 2}));
	return 0;
}
