#include <stdio.h>
#include <math.h>

double y_function(double x){
   double y = sqrt(pow(x,3) - 3*x + 3);
   return y;
}

double distance(double x, double y){
   double distance = sqrt(pow(x,2) + pow(y,2));
   return distance;
}

double key_generation(double distance, double private_key){
   double public_key = private_key * distance;
   return public_key;
}