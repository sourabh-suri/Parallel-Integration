![](image23.png "horizontal line")

## Numerically integrate cos(x)

1st March 2021

#### OVERVIEW

```
Considering a function f (x) = cos(x) in the interval [− pi/2 , pi/2 ].
Writing serial and OpenMP parallel codes to numerically integrate the
function using the
(a) Trapezoidal Rule
(b) Montecarlo Method

```
#### GOALS 

```
1.  To perform a convergence study, using different numbers of divisions
    (or sampling points), by comparing the integral obtained through the
    numerical methods with the analytical integral.
2.  To perform a timing study using 2, 4, 6 and 8 OpenMP threads and
    reporting average times of at least 5 runs of the code.

```

## Solving Integration 


Analytical integral 
Integrating cos(x) in the interval [− pi/2 , pi/2 ] as follows,

![](image1.png)\
![](image2.png)\
![](image3.png)\
 =   2


![](image23.png "horizontal line")
## Trapezoidal Rule 


Let we partition ![](image4.png) into n equal subintervals, each
of width ![](image5.png)

The Trapezoidal Rule for approximating ![](image6.png)is given
by,

![](image7.png)  …….……………(1)

where ![](image8.png) is the sampling point.

#### Algorithm


-   Initialise the number of divisions/samples points for the
    Trapezoidal Rule.
-   Initialise the starting of the current sample as
    ![](image9.png).
-   Initialise the step size, ![](image10.png) as
    ![](image11.png).
-   Iterate the current sample point as ![](image12.png) for all
    sample points till  ![](image13.png).
-   Compute the result by accumulating the value of
    ![](image14.png) for every sample point such that
    ![](image15.png) according to equation (1).
-   Storing the result of integration as the multiplication of step size
    ![](image10.png) and the accumulation of
    function![](image16.png).
-   To parallelise the code, use \#pragma omp parallel for
    reduction(+:![](image16.png)) before the iteration loop in
    step 4.


#### Conclusions

```
-   As the number of sampling points increases, the error reduces as
    shown in Figure1.
-   As the number of cores increases, the time to solve reduces as shown
    in  Figure2.

```
![](image24.png)
![](image21.png)
![](image23.png "horizontal line")
## Monte-carlo Method 

```
In the trapezoidal rule of numerical integration, a deterministic
approach is used. However, Montecarlo integration employs a
non-deterministic approach where each realization provides a different
outcome.

```
#### Algorithm


-   Initialise the number of samples points for the Montecarlo Method.
-   Initialise ![](image17.png).
-   Initialise the total area as the multiplication of
    ![](image18.png).
-   Initialise the seed for random function generation i.e.
    rand\_r(&seed).
-   Iterate a loop for the number of sample points and using the random
    number generator function call find the number of x and y-axis
    samples with-in the range corresponding to ![](image17.png).
-   Compute and accumulate a variable called, hits if the cos(x) \> y
    for all samples generated in the above step. Also, compute and
    accumulate all the iterations as all\_samples\_count.
-   Calculate the ratio of hits as ![](image19.png) , The result
    of integration will be ![](image20.png).
-   To parallelise the code, use \#pragma omp parallel for private
    (iterator, seed) reduction(+:hits, all\_samples\_count) before the
    iteration loop in step 5.


#### Conclusions

```
-   As the number of sampling points increases, error reduces 
-   As the number of cores increases, the time to solve reduces as shown
    in  Figure 3&4.
-   With the thread-safe variant i.e rand\_r(), we are making seed as a
    private variable amongst threads to ensure the state is not shared
    between threads. It makes the sequences independent of each other.
    If we start them with private seeds, we will get different sequences
    in all threads. This is the reason why we are observing different
    results for the different number of threads.

```
![](image26.png) 
![](image25.png) 
![](image23.png "horizontal line")

