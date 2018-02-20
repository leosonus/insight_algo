#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGIT_LEN 1024

#define max(a, b) (((a)>(b))?(a):(b))
#define min(a, b) (((a)<(b))?(a):(b))

typedef struct {
    int sign;
    int digit_len;
    int int_len;
    char digit[MAX_DIGIT_LEN];
} number_t;

void add_number(number_t * a, number_t * b, number_t * c);
void sub_number(number_t * a, number_t * b, number_t * c);

void print_number(number_t * a)
{
    int i;

    if (a->sign < 0)
	printf("-");

    for (i = 0; i < a->int_len; i++)
	printf("%c", '0' + a->digit[i]);

    printf(".");

    for (; i < a->digit_len; i++)
	printf("%c", '0' + a->digit[i]);
}

void string_to_number(char *s, number_t * a)
{
    int slen;
    int i, p;

    if (s[0] == '-') {
	a->sign = -1;
	s++;
    } else {
	a->sign = 1;
    }

    slen = strlen(s);
    a->digit_len = slen - 1;

    for (i = 0, p = 0; i < slen; i++) {
	if (s[i] == '.') {
	    a->int_len = i;
	    continue;
	}
	a->digit[p] = s[i] - '0';
	p++;
    }
}

void make_zero(number_t * a)
{
    a->sign = 1;
    a->digit[0] = 0;
    a->digit[1] = 0;
    a->digit_len = 2;
    a->int_len = 1;
}

void make_exp(number_t * a, int k)
{
    /* 을 만든다. 10^k */
    int i;

    a->sign = 1;

    if (k >= 0) {
	a->digit[0] = 1;
	a->int_len = k + 1;
	for (i = 1; i < k; i++)
	    a->digit[i] = 0;

	a->digit[i] = 0;
	a->digit_len = k + 2;
    } else {
	a->digit[0] = 0;
	a->int_len = 1;
	for (i = 1; i < (-k); i++)
	    a->digit[i] = 0;

	a->digit[i] = 1;
	a->digit_len = (-k) + 1;
    }
}

int compare_number(number_t * a, number_t * b)
{
    /* sign of a-b */
    int i;

    if ((a->sign < 0) && (b->sign > 0))
	return -1;
    if ((a->sign > 0) && (b->sign < 0))
	return 1;

    if (a->int_len > b->int_len)
	return (a->sign);
    if (b->int_len > a->int_len)
	return (-b->sign);

    for (i = 0; i < min(a->digit_len, b->digit_len); i++) {
	if (a->digit[i] > b->digit[i])
	    return a->sign;
	if (b->digit[i] > a->digit[i])
	    return -a->sign;
    }

    if (a->digit_len > b->digit_len)
	return 1;
    if (a->digit_len < b->digit_len)
	return -1;

    return 0;
}

void remove_zeros(number_t * a)
{
    int i, p;

    for (i = a->digit_len - 1; i >= a->int_len + 1; i--)
	if (a->digit[i] != 0)
	    break;

    a->digit_len = i + 1;

    for (p = 0; p < a->int_len - 1; p++)
	if (a->digit[p] != 0)
	    break;

    for (i = 0; i < a->digit_len - p; i++)
	a->digit[i] = a->digit[i + p];

    a->digit_len -= p;
    a->int_len -= p;

    if (a->digit_len == 2 && a->digit[0] == 0 && a->digit[1] == 0)
	a->sign = 1;
}

void add_number(number_t * c, number_t * a, number_t * b)
{
    /* c = a+b */
    int sum;
    int carry;
    int i, m, t;

    make_zero(c);

    if (a->sign == b->sign)
	c->sign = a->sign;
    else {
	if (a->sign < 0) {
	    a->sign = 1;
	    sub_number(c, b, a);
	    a->sign = -1;
	} else {
	    b->sign = 1;
	    sub_number(c, a, b);
	    b->sign = -1;
	}
	return;
    }

    carry = 0;

    c->int_len = max(a->int_len, b->int_len) + 1;
    m = max(a->digit_len - a->int_len, b->digit_len - b->int_len);
    c->digit_len = c->int_len + m;

    for (i = c->digit_len - 1; i >= 0; i--) {
	sum = carry;

	t = i - c->int_len + a->int_len;
	if (t < a->digit_len && t >= 0)
	    sum += a->digit[t];

	t = i - c->int_len + b->int_len;
	if (t < b->digit_len && t >= 0)
	    sum += b->digit[t];

	c->digit[i] = sum % 10;
	carry = sum / 10;
    }

    remove_zeros(c);
}

void sub_number(number_t * c, number_t * a, number_t * b)
{
    /* c = a-b */
    int borrow;
    int dif;
    int i, t;
    int m;

    make_zero(c);

    if ((a->sign < 0) || (b->sign < 0)) {
	b->sign *= -1;
	add_number(a, b, c);
	b->sign *= -1;
	return;
    }

    if (compare_number(a, b) < 0) {
	sub_number(c, b, a);
	c->sign = -1;
	return;
    }

    c->int_len = max(a->int_len, b->int_len);
    m = max(a->digit_len - a->int_len, b->digit_len - b->int_len);
    c->digit_len = c->int_len + m;

    borrow = 0;

    for (i = c->digit_len - 1; i >= 0; i--) {
	dif = -borrow;

	t = i - c->int_len + a->int_len;
	if (t < a->digit_len && t >= 0)
	    dif += a->digit[t];

	t = i - c->int_len + b->int_len;
	if (t < b->digit_len && t >= 0)
	    dif -= b->digit[t];

	if (dif < 0) {
	    borrow = 1;
	    dif += 10;
	} else
	    borrow = 0;

	c->digit[i] = dif % 10;
    }

    remove_zeros(c);
}

void mult_one(number_t * c, char b, number_t * a)
{
    /* a * b = c */
    int i;
    int carry;
    int s;

    make_zero(c);
    c->digit_len = a->digit_len + 1;
    c->int_len = a->int_len + 1;

    carry = 0;

    for (i = a->digit_len - 1; i >= 0; i--) {
	s = a->digit[i] * b + carry;
	c->digit[i + 1] = s % 10;
	carry = s / 10;
    }

    c->digit[0] = carry;

    c->sign = a->sign;
    remove_zeros(c);
}

void digit_shift(number_t * c, int d, number_t * a)
{
    /* c = a * 10^d, where d >= 0 */
    int i;

    *c = *a;
    c->int_len += d;

    if (c->int_len >= c->digit_len) {
	for (i = c->digit_len; i < c->int_len + 1; i++)
	    c->digit[i] = 0;
	c->digit_len = c->int_len + 1;
    }
}

void mult_num(number_t * c, number_t * a, number_t * b)
{
    /* c = a * b */
    number_t tmp;
    number_t tmp2;
    number_t c_tmp;
    int i, j, t;

    make_zero(c);

    t = b->digit_len - b->int_len;

    for (i = b->digit_len - 1, j = 0; i >= 0; i--, j++) {
	mult_one(&tmp, b->digit[i], a);
	digit_shift(&tmp2, j, &tmp);

	c_tmp = *c;
	add_number(c, &c_tmp, &tmp2);
    }
    c->int_len -= t;

    c->sign = a->sign * b->sign;

    remove_zeros(c);
}

int main()
{
    number_t a;
    number_t two;
    number_t temp;
    number_t r;
    int i;

    i = 0;
    string_to_number("0.0", &r);
    string_to_number("2.0", &two);

    while (1) {
	make_exp(&a, i);
	while (1) {
	    mult_num(&temp, &r, &r);
	    if (compare_number(&temp, &two) > 0) {
		sub_number(&temp, &r, &a);
		r = temp;
		break;
	    }
	    add_number(&temp, &r, &a);
	    r = temp;
	}
	print_number(&r);
	printf("\n");
	i--;
    }
    return 0;
}

#if 0
int main()
{
    number_t a, b, c;
    string_to_number("14.142", &a);
    string_to_number("1.414", &b);

    print_number(&a);
    printf("\n");
    print_number(&b);
    printf("\n");
    //add_number(&c, &a, &b);
    make_exp(&c, 3);

//    mult_num(&c, &a, &b);
    print_number(&c);
    printf("\n");

    return 0;
}
#endif
