/******************************************************************************

                            Montecarlo Method to to numerically 
                            integrate the cosine function 
                            in the interval of [-pi/2,pi/2].

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592654
void main()
{
    float xlim_1 = -0.5*PI, xlim_2= 0.5*PI;
    float ylim_1=0, ylim_2=1;
    int count=0, samples= 1e7, seed;
    int all_samples=0, hits_for_func=0;
    float area,ratio;
    area = (float)(xlim_2 - xlim_1)*(ylim_2 - ylim_1);
    #pragma omp parallel for private(count, seed) reduction(+:all_samples,hits_for_func)
    for (count=0; count < samples; count++)
    {	
    	float x_uniform = ((xlim_2 - xlim_1)*((float)rand_r(&seed)/(float)RAND_MAX)) + xlim_1;
	float y_uniform = ((ylim_2 - ylim_1)*((float)rand_r(&seed)/(float)RAND_MAX)) + ylim_1;
	float val = cos(x_uniform);
	hits_for_func+=(int)(val > y_uniform);
	all_samples++;
    }
    ratio = (float)hits_for_func/all_samples;
    printf("\n Result of Montecarlo Method to numerically integrate cos in interval of [-pi/2,pi/2] is = %f", area*ratio);
}



