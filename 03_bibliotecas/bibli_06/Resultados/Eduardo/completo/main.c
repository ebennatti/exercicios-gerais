#include <stdio.h>
#include "temperature_conversor.h"

int main() {
    float temperature;
    char current, wanted;

    scanf("%f %c %c", &temperature, &current, &wanted);

    if(current == 'c' && wanted == 'k') {
        printf("Temperature: %.2fK", convert_celsius_to_kelvin(temperature));
    } else if(current == 'c' && wanted == 'f') {
        printf("Temperature: %.2fFº", convert_celsius_to_fahrenheit(temperature));
    } else if(current == 'k' && wanted == 'f') {
        printf("Temperature: %.2fFº", convert_kelvin_to_fahrenheit(temperature));
    } else if(current == 'k' && wanted == 'c') {
        printf("Temperature: %.2fCº", convert_kelvin_to_celsius(temperature));
    } else if(current == 'f' && wanted == 'c') {
        printf("Temperature: %.2fCº", convert_fahrenheit_to_celsius(temperature));
    } else if(current == 'f' && wanted == 'k') {
        printf("Temperature: %.2fK", convert_fahrenheit_to_kelvin(temperature));
    }

    return 0;
}