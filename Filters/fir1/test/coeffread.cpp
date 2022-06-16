#include "Fir1.h"
#include "assert_print.h"

#include <stdio.h>

int main (int,char**)
{
	// inits the filter
	Fir1 fir("coefficients.dat");

	// resets the delay line to zero
	fir.reset ();
      
	FILE *f = fopen("coefficients.dat","rt");
	assert_print(NULL != f, "Coefficients file doesn't exist.");
	double v;
	for(int i=0;i<30;i++) 
	{
		float a=0;
		if (i==10) a = 1;
		double b = fir.filter(a);
		if (i >= 10) {
			int r = fscanf(f,"%lf\n",&v);
			assert_print(r > 0, "coefficients read error.");
			assert_print(v == b,"Coefficient / output mismatch.");
		}
	}
	fclose(f);
}
