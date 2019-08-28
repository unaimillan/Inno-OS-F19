#include <limits.h>
#include <float.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	int a = INT_MAX;
	float b = FLT_MAX;
	double c = DBL_MAX;
	printf("Integer size: %lu\nInteger max value: %d\n\n", sizeof(a), a);
	printf("Float size: %lu\nFloat max value: %f\n\n", sizeof(b), b);
	printf("Double size: %lu\nDouble max value: %lf\n\n", sizeof(c), c);
	return 0;
}
