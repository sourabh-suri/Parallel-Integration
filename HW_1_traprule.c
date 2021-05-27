/******************************************************************************

                            Trapezoidal rule to to numerically 
                            integrate the cosine function 
                            in the interval of [-pi/2,pi/2].

*******************************************************************************/

#include <stdio.h>
#include <math.h>
#define PI 3.141592654
int main()
{
    int no_of_samples=1e3;  
    double result=0; 
    double integration=0, start_sample;
    int iter;
    double step_size = PI/no_of_samples;
    start_sample = -0.5*PI; 
     #pragma omp parallel for reduction(+:integration)
	    for(iter=0;iter<no_of_samples;iter++)
	    {
		integration += cos(start_sample + iter*step_size );
	    }
    result = step_size*integration;
    printf("\n Result of trapezoidal rule to numerically integrate cos in interval [-pi/2,pi/2] is = %f and error = %f", result, 2.0000-result);

    return 0;
}

