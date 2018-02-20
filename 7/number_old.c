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

number_t add_number(number_t a, number_t b);
number_t sub_number(number_t a, number_t b);

void print_number(number_t a)
{
    int i;

    if (a.sign < 0)
        printf("-");
    for (i = 0; i < a.int_len; i++)
        printf("%c", '0' + a.digit[i]);
    printf(".");
    for (; i < a.digit_len; i++)
        printf("%c", '0' + a.digit[i]);
}

number_t string_to_number(char *s)
{
    number_t r;
    int slen, i, p;

    if (s[0] == '-') {
        r.sign = -1;
        s++;
    } else 
        r.sign = 1;
    slen = strlen(s);
    r.digit_len = slen - 1;

    for (i = 0, p = 0; i < slen; i++) {
        if (s[i] == '.') {
            r.int_len = i;
            continue;
        }
        r.digit[p] = s[i] - '0';
        p++;
    }
    return r;
}

number_t zero()
{
    number_t r;

    r.sign = 1;
    r.digit_len = 2;
    r.int_len = 1;
    r.digit[0] = 0;
    r.digit[1] = 0;
    return r;
}

number_t make_exp(int k)
{
    number_t r;
    int i;

    r.sign = 1;
    if (k >= 0) {
        r.int_len = k + 1;
        r.digit_len = k + 2;
        r.digit[0] = 1;
        for (i = 1; i < r.digit_len; i++)
            r.digit[i] = 0;
    } else {
        r.int_len = 1;
        r.digit_len = (-k) + 1;
        for (i = 0; i < r.digit_len; i++)
            r.digit[i] = 0;
        r.digit[r.digit_len - 1] = 1;
    }
    return r;
}

int compare_number(number_t a, number_t b)
{
    int i;

    if ((a.sign < 0) && (b.sign > 0))
        return -1;
    if ((a.sign > 0) && (b.sign < 0))
        return 1;
    if (a.int_len > b.int_len)
        return (a.sign);
    if (b.int_len > a.int_len)
        return (-b.sign);
    for (i = 0; i < min(a.digit_len, b.digit_len); i++) {
        if (a.digit[i] > b.digit[i])
            return a.sign;
        if (b.digit[i] > a.digit[i])
            return -a.sign;
    }
    if (a.digit_len > b.digit_len)
        return 1;
    if (a.digit_len < b.digit_len)
        return -1;
    return 0;
}

number_t remove_zeros(number_t a)
{
    number_t r;
    int i, p;

    r = a;
    for (i = r.digit_len - 1; i >= r.int_len + 1; i--)
        if (r.digit[i] != 0)
            break;
    r.digit_len = i + 1;
    for (p = 0; p < r.int_len - 1; p++)
        if (r.digit[p] != 0)
            break;
    for (i = 0; i < r.digit_len - p; i++)
        r.digit[i] = r.digit[i + p];
    r.digit_len -= p;
    r.int_len -= p;
    if (r.digit_len == 2 && r.digit[0] == 0 && r.digit[1] == 0)
        r.sign = 1;
    return r;
}

number_t add_number(number_t a, number_t b)
{
    number_t r;
    int sum, carry, i, m, t;

    r = zero();
    if (a.sign == b.sign)
        r.sign = a.sign;
    else {
        if (a.sign < 0) {
            a.sign = 1;
            r = sub_number(b, a);
        } else {
            b.sign = 1;
            r = sub_number(a, b);
        }
        return r;
    }

    carry = 0;
    r.int_len = max(a.int_len, b.int_len) + 1;
    m = max(a.digit_len - a.int_len, b.digit_len - b.int_len);
    r.digit_len = r.int_len + m;

    for (i = r.digit_len - 1; i >= 0; i--) {
        sum = carry;
        t = i - r.int_len + a.int_len;
        if (t < a.digit_len && t >= 0)
            sum += a.digit[t];
        t = i - r.int_len + b.int_len;
        if (t < b.digit_len && t >= 0)
            sum += b.digit[t];
        r.digit[i] = sum % 10;
        carry = sum / 10;
    }
    return remove_zeros(r);
}

number_t sub_number(number_t a, number_t b)
{
    number_t r;
    int borrow, dif, i, t, m;

    r = zero();
    if ((a.sign < 0) || (b.sign < 0)) {
        b.sign *= -1;
        r = add_number(a, b);
        return r;
    }
    if (compare_number(a, b) < 0) {
        r = sub_number(b, a);
        r.sign = -1;
        return r;
    }

    r.int_len = max(a.int_len, b.int_len);
    m = max(a.digit_len - a.int_len, b.digit_len - b.int_len);
    r.digit_len = r.int_len + m;

    borrow = 0;

    for (i = r.digit_len - 1; i >= 0; i--) {
        dif = -borrow;

        t = i - r.int_len + a.int_len;
        if (t < a.digit_len && t >= 0)
            dif += a.digit[t];

        t = i - r.int_len + b.int_len;
        if (t < b.digit_len && t >= 0)
            dif -= b.digit[t];

        if (dif < 0) {
            borrow = 1;
            dif += 10;
        } else
            borrow = 0;

        r.digit[i] = dif % 10;
    }
    return remove_zeros(r);
}

number_t mult_one(char b, number_t a)
{
    number_t r;
    int carry, s, i;

    r = zero();
    r.digit_len = a.digit_len + 1;
    r.int_len = a.int_len + 1;

    carry = 0;

    for (i = a.digit_len - 1; i >= 0; i--) {
        s = a.digit[i] * b + carry;
        r.digit[i + 1] = s % 10;
        carry = s / 10;
    }

    r.digit[0] = carry;
    r.sign = a.sign;
    return remove_zeros(r);
}

number_t digit_shift(int d, number_t a)
{
    number_t r;
    int i;

    r = a;
    r.int_len += d;

    if (r.int_len >= r.digit_len) {
        for (i = r.digit_len; i < r.int_len + 1; i++)
            r.digit[i] = 0;
        r.digit_len = r.int_len + 1;
    }
    return r;
}

number_t mult_num(number_t a, number_t b)
{
    number_t r, tmp;
    int i, j, t;

    r = zero();

    t = b.digit_len - b.int_len;

    for (i = b.digit_len - 1, j = 0; i >= 0; i--, j++) {
        tmp = mult_one(b.digit[i], a);
        tmp = digit_shift(j, tmp);

        r = add_number(r, tmp);
    }
    r.int_len -= t;
    r.sign = a.sign * b.sign;

    return remove_zeros(r);
}

#if 1
int main()
{
    number_t a, r, two;
    int i;

    r = string_to_number("0.0");
    two = string_to_number("5.0");

    for (i = 0; i <= 100; i++) {
        a = make_exp(-i);
        while (1) {
            if (compare_number(mult_num(r, r), two) > 0) {
                r = sub_number(r, a);
                break;
            }
            r = add_number(r, a);
        }
        print_number(r);
        printf("\n");
    }
    return 0;
}

#endif

#if 0
int main()
{
    number_t a, b, c;
    int i;

    a = string_to_number("-1.7171");
    b = string_to_number("-17.17");
    c = zero();

    print_number(a);
    printf("\n");
    print_number(b);
    printf("\n");
    c = sub_number(a, b);
    /*
       for(i=-10; i<10; i++) {
       c = make_exp(i);
       print_number(c);
       printf("\n");
       }
       */

    c = mult_num(a, b);
    print_number(c);
    printf("\n");

    return 0;
}
#endif
