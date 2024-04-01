#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

double x_generation(double minimum, double maximum, int x_length){
   double x_array[x_length];
   double interval = (maximum - minimum) / (x_length - 1);
   for (int i = 0; i < x_length; i++){
      x_array[i] = minimum + i*interval;
   }
   srand(time(NULL));
   int index = rand() % x_length;
   double x = x_array[index];
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
   double x = x_generation(-2, 2, 1001);
   printf("%lf\n", x);
   return 0;
}