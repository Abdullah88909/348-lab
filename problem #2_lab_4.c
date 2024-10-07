#include <stdio.h>

// Conversion functions
float celsius_to_fahrenheit(float celsius) {
    return (9.0 / 5.0) * celsius + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32);
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

// Categorize and give weather advisory
void categorize_temperature(float celsius) {
    printf("Temperature category: ");
    if (celsius < 0) {
        printf("Freezing\n");
        printf("Weather advisory: Wear a heavy coat.\n");
    } else if (celsius < 10) {
        printf("Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    } else if (celsius < 25) {
        printf("Comfortable\n");
        printf("Weather advisory: You should feel comfortable.\n");
    } else if (celsius < 35) {
        printf("Hot\n");
        printf("Weather advisory: Stay cool and hydrated.\n");
    } else {
        printf("Extreme Heat\n");
        printf("Weather advisory: Stay indoors and stay hydrated.\n");
    }
}

// Main program to handle input and conversion
int main() {
    float temperature, converted_temp;
    int input_scale, target_scale;

    // Input: Temperature and scales
    printf("Enter the temperature: ");
    scanf("%f", &temperature);

    printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &input_scale);

    printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &target_scale);

    // Validate input and perform the appropriate conversion
    if (input_scale == 1) { // Celsius
        if (target_scale == 1) {
            printf("Invalid conversion: Celsius to Celsius\n");
            return 1;
        } else if (target_scale == 2) {
            converted_temp = celsius_to_fahrenheit(temperature);
        } else if (target_scale == 3) {
            converted_temp = celsius_to_kelvin(temperature);
        }
    } else if (input_scale == 2) { // Fahrenheit
        if (target_scale == 1) {
            converted_temp = fahrenheit_to_celsius(temperature);
        } else if (target_scale == 2) {
            printf("Invalid conversion: Fahrenheit to Fahrenheit\n");
            return 1;
        } else if (target_scale == 3) {
            converted_temp = fahrenheit_to_kelvin(temperature);
        }
    } else if (input_scale == 3) { // Kelvin
        if (temperature < 0) {
            printf("Error: Temperature in Kelvin cannot be negative.\n");
            return 1;
        }
        if (target_scale == 1) {
            converted_temp = kelvin_to_celsius(temperature);
        } else if (target_scale == 2) {
            converted_temp = kelvin_to_fahrenheit(temperature);
        } else if (target_scale == 3) {
            printf("Invalid conversion: Kelvin to Kelvin\n");
            return 1;
        }
    } else {
        printf("Invalid scale choice.\n");
        return 1;
    }

    // Output the converted temperature
    printf("Converted temperature: %.2f\n", converted_temp);

    // Convert the temperature to Celsius for categorization
    if (target_scale == 1) {
        categorize_temperature(converted_temp);
    } else if (target_scale == 2) {
        categorize_temperature(fahrenheit_to_celsius(converted_temp));
    } else if (target_scale == 3) {
        categorize_temperature(kelvin_to_celsius(converted_temp));
    }

    return 0;
}
