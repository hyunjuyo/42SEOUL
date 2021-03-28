#include <math.h>
#include <stdio.h>

#define EPSILON 0.000001

int	main(void)
{
	double	th;
	double	c;
	double	s;
	double	t;

	th = 90.0001 * M_PI / 180.0;
	c = cos(th);
	s = sin(th);
	t = tan(th);
	printf("M_PI : %f, M_PI_2 : %f\n", M_PI, M_PI_2);
	printf("cos(th) : %f\nsin(th) : %f\ntan(th) : %f\n", c, s, t);
	return (0);
}
