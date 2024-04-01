#include <stdio.h>
#include <math.h>
#include <string.h>

double x_generation(double minimum, double maximum){
   int x_length = 1000;
   double x_array[x_length];
   double interval = (maximum - minimum) / x_length;
   for (int i = 0; i < x_length + 1; i++){
      x_array[i] = minimum + i*interval;
      printf("%lf\n", x_array[i]);
   }
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
   double test = x_generation(-2, 2);
   return 0;
}