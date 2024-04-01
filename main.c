#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

double x_random(double minimum, double maximum, int x_length){
   double interval = (maximum - minimum) / (x_length - 1);
   srand(time(NULL));
   int random = rand() % x_length;
   double x = minimum + random*interval;
   return x;
}

double y_function(double x){
   double y = sqrt(pow(x,3) - 3*x + 3);
   return y;
}

double distance(double x, double y){
   double distance = sqrt(pow(x,2) + pow(y,2));
   return distance;
}

double key_generation(double distance, double private_key){
   double public_key = distance*private_key;
   return public_key;
}

int main(){
   double x = x_random(-2, 2, 1001);
   printf("%lf\n", x);
   return 0;
}