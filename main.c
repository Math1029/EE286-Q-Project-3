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

double get_distance(double x, double y){
   double distance = sqrt(pow(x,2) + pow(y,2));
   return distance;
}

double generate_key(double distance, int private_key){
   double public_key = distance*private_key;
   return public_key;
}

int main(){
   double x = x_random(-2, 2, 1001);
   double y = y_function(x);
   double distance = get_distance(x, y);

   int key_a = 30;
   int key_b = 40;

   double key_one = generate_key(distance, key_a);
   double key_two = generate_key(distance, key_b);

   printf("distance: %lf\n", distance);
   printf("key_a:    %d\n", key_a);
   printf("key_one:  %lf\n", key_one);
   printf("key_b:    %d\n", key_b);
   printf("key_two:  %lf\n", key_two);
   return 0;
}