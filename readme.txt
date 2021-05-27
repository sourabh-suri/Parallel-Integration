To run serial code
Complie: $ gcc HW_1_traprule.c -lm
Output: $ time ./a.out


To run for parallel code
Set no. of threads: $ export OMP_NUM_THREADS=<No. of threads>
Complie: $ gcc -fopenmp HW_1_traprule.c -lm
Output: $ time ./a.out


