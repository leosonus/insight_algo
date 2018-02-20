#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592

double rand_real(double a, double b)
{
    return a + (b - a) * ((double) rand() / RAND_MAX);
}

void pick_circle_point()
{
    double x, y;

    x = rand_real(-1, 1);
    y = sqrt(1 - x * x);
    if (rand() % 2)
        y *= -1;
    printf("%lf %lf\n", x, y);
}

void pick_circle_point2()
{
    double x, y, theta;

    theta = rand_real(0, 2 * PI);
    x = cos(theta);
    y = sin(theta);
    printf("%lf %lf\n", x, y);
}

void pick_disk_point()
{
    double x, y, h;

    x = rand_real(-1, 1);
    h = sqrt(1 - x * x);
    y = rand_real(-h, h);
    printf("%lf %lf\n", x, y);
}

void pick_disk_point2()
{
    double x, y, r, theta;

    r = rand_real(0, 1);
    theta = rand_real(0, 2 * PI);
    x = r * cos(theta);
    y = r * sin(theta);
    printf("%lf %lf\n", x, y);
}

void pick_disk_point3()
{
    double x, y;

    do {
        x = rand_real(-1, 1);
        y = rand_real(-1, 1);
    } while (x * x + y * y > 1);
    printf("%lf %lf\n", x, y);
}

void pick_disk_point4()
{
    double x, y, r, theta;

    r = sqrt(rand_real(0, 1));
    theta = rand_real(0, 2 * PI);
    x = r * cos(theta);
    y = r * sin(theta);
    printf("%lf %lf\n", x, y);
}

void pick_sphere_point()
{
    double x, y, z;
}

int main()
{
    int n, i;

    printf("input n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        pick_circle_point();
    return 0;
}
