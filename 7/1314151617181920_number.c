#include <stdio.h>

#define max(a, b) (((a)>(b))?(a):(b))
#define min(a, b) (((a)<(b))?(a):(b))

#define MAX_DIGIT_LEN 1024 

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
    number_t result;
    int i, p;

    if (s[0] == '-') {
        result.sign = -1;
        s++;
    } else {
        result.sign = 1;
    }

    for (i = 0, p = 0; s[i] != '\0'; i++) {
        if (s[i] == '.') {
            result.int_len = i;
            continue;
        }
        result.digit[p] = s[i] - '0';
        p++;
    }
    result.digit_len = p;
    return result;
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

char digit_at(number_t a, int d)
{
    int pos = a.int_len - 1 - d;
    if (pos < a.digit_len && pos >= 0)
        return a.digit[pos];
    return 0;
}

number_t remove_zeros(number_t a)
{
    number_t result;
    int s, t, i;

    for (s = 0; s < a.int_len - 1; s++)
        if (a.digit[s] != 0)
            break;

    for (t = a.digit_len - 1; t > a.int_len; t--)
        if (a.digit[t] != 0)
            break;

    result.digit_len = t - s + 1;
    result.int_len = a.int_len - s;
    result.sign = a.sign;

    for (i = s; i <= t; i++)
        result.digit[i - s] = a.digit[i];

    if (result.digit_len == 2 && result.digit[0] == 0 && result.digit[1] == 0)
        result.sign = 1;

    return result;
}

number_t add_number(number_t a, number_t b)
{
    number_t result;
    int sum, carry, i;

    if (a.sign != b.sign) {
        b.sign *= -1;
        return sub_number(a, b);
    }

    result.sign = a.sign;
    result.int_len = max(a.int_len, b.int_len) + 1;
    result.digit_len = result.int_len + max(a.digit_len - a.int_len, b.digit_len - b.int_len);

    carry = 0;
    for (i = result.digit_len - 1; i >= 0; i--) {
        sum = carry + digit_at(a, result.int_len - i - 1) + digit_at(b,	result.int_len - i - 1);
        result.digit[i] = sum % 10;
        carry = sum / 10;
    }
    return remove_zeros(result);
}

number_t sub_number(number_t a, number_t b)
{
    number_t result;
    int borrow, dif, i;

    if (a.sign != b.sign) {
        b.sign *= -1;
        return add_number(a, b);
    }

    if (a.sign < 0 && b.sign < 0) {
        a.sign = b.sign = 1;
        return sub_number(b, a);
    }

    if (compare_number(a, b) < 0) {
        result = sub_number(b, a);
        if (! (result.digit_len == 2 && result.digit[0] == 0 && result.digit[1] == 0))
            result.sign = -1;
        return result;
    }

    result.sign = 1;
    result.int_len = max(a.int_len, b.int_len);
    result.digit_len = result.int_len + max(a.digit_len - a.int_len, b.digit_len - b.int_len);

    borrow = 0;
    for (i = result.digit_len - 1; i >= 0; i--) {
        dif = -borrow + digit_at(a, result.int_len - i - 1) - digit_at(b, result.int_len - i - 1);

        if (dif < 0) {
            borrow = 1;
            dif += 10;
        } else
            borrow = 0;

        result.digit[i] = dif % 10;
    }
    return remove_zeros(result);
}

number_t mult_one(char d, number_t a)
{
    number_t result;
    int carry, s, i;

    result.digit_len = a.digit_len + 1;
    result.int_len = a.int_len + 1;
    result.sign = a.sign;

    carry = 0;
    for (i = a.digit_len - 1; i >= 0; i--) {
        s = a.digit[i] * d + carry;
        result.digit[i + 1] = s % 10;
        carry = s / 10;
    }

    result.digit[0] = carry;
    return remove_zeros(result);
}

number_t mult_number(number_t a, number_t b)
{
    number_t result;
    int i, k;

    result = string_to_number("0.0");
    for (i = 0; i < b.digit_len; i++) {
        result = mult_one(10, result);
        result = add_number(result, mult_one(b.digit[i], a));
    }

    k = b.digit_len - b.int_len;
    if (result.int_len > k) {
        result.int_len -= k;
    } else {
        for (i = result.digit_len - 1; i >= 0; i--)
            result.digit[i + k] = result.digit[i];
        for (i = 0; i < k; i++)
            result.digit[i] = 0;
        result.digit_len += k;	
    }

    result.sign *= b.sign;
    return remove_zeros(result);
}

int test()
{

    number_t s, t, u, v, w, y, z, zero;
    s = string_to_number("1357.935");
    t = string_to_number("-30000.00009");
    u = string_to_number("99999.13579");
    v = string_to_number("-8765789.9900899");
    w = string_to_number("-1.00001");
    y = string_to_number("0.0001");
    z = string_to_number("-0.0000000001");
    zero = string_to_number("0.0");

    print_number(add_number(s, t));
    printf("\n");
    print_number(add_number(t, u));
    printf("\n");
    print_number(add_number(s, u));
    printf("\n");
    print_number(add_number(t, w));
    printf("\n");
    print_number(sub_number(s, t));
    printf("\n");
    print_number(sub_number(t, u));
    printf("\n");
    print_number(sub_number(t, t));
    printf("\n");
    print_number(sub_number(t, t));
    printf("\n");
    print_number(add_number(v, v));
    printf("\n");
    print_number(sub_number(v, s));
    printf("\n");
    print_number(mult_number(w, w));
    printf("\n");
    print_number(mult_number(z, w));
    printf("\n");
    print_number(mult_number(w, y));
    printf("\n");
    print_number(mult_one(3, w));
    printf("\n");
    print_number(add_number(zero, z));
    printf("\n");
    print_number(mult_number(w, w));

    int i;
    scanf("%d", &i);
}

int test2()
{
    char x[128], y[128];

    while(1) 
    {
        scanf("%s", x);
        scanf("%s", y);
        print_number(mult_number(string_to_number(x), string_to_number(y)));
        printf("\n");
    }
}

//test2();
#if 0
number_t a, r, x;
int i;

x = string_to_number("0.1");
number_t one = string_to_number("1.0");

//===================
r = string_to_number("1.0");
number_t n = string_to_number("1.0");
for (i = 1; i <= 100; i++) {
    r = mult_number(r, n);
    n = add_number(n, one);
}

print_number(r);
printf("\n");
//===================

r = string_to_number("0.0");
a = string_to_number("0.1");
//===================       
for (i = 0; i < 1000000; i++) {
    r = add_number(r, a);
}
print_number(r);
printf("\n");
//===================



scanf("%d", &i);
#endif

int main() 
{
    number_t a, result, two, x;
    int i;

    result = string_to_number("0.0");
    two = string_to_number("2.0");

    x = string_to_number("0.1");
    a = string_to_number("1");

    for (i = 0; i <= 100; i++) {
        while (1) {
            if (compare_number(mult_number(result, result), two) > 0) {
                result = sub_number(result, a);
                break;
            }
            result = add_number(result, a);
        }
        a = mult_number(a, x);
    }
    print_number(result);
    printf("\n");

    return 1;
}

