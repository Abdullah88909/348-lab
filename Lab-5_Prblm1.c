//Muhammad Abdullah
//Date: Oct 13 2024


#include <stdio.h>
#include <stdlib.h>

// Function declarations
void printMonthlySalesReport(float sales[], const char *months[], int size);
void printSalesSummary(float sales[], const char *months[], int size);
void printSixMonthMovingAverage(float sales[], const char *months[], int size);
void printSalesReportHighestToLowest(float sales[], const char *months[], int size);
void sortSales(float sales[], const char *months[], int size);

int main() {
    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    float sales[12];

    // Open the file to read sales data
    FILE *file = fopen("/Users/muhammadabdullah/Downloads/sales.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read sales data from the file
    for (int i = 0; i < 12; i++) {
        fscanf(file, "%f", &sales[i]);
    }
    fclose(file); // Close the file after reading

    // Generate and display reports
    printMonthlySalesReport(sales, months, 12);
    printSalesSummary(sales, months, 12);
    printSixMonthMovingAverage(sales, months, 12);
    printSalesReportHighestToLowest(sales, months, 12);

    return 0;
}

// Function to print the Monthly Sales Report
void printMonthlySalesReport(float sales[], const char *months[], int size) {
    printf("\nMonthly Sales Report for 2024\n");
    printf("Month      Sales\n");
    for (int i = 0; i < size; i++) {
        printf("%-10s $%.2f\n", months[i], sales[i]);
    }
    printf("\n");
}

// Function to print the Sales Summary (min, max, average)
void printSalesSummary(float sales[], const char *months[], int size) {
    float min = sales[0], max = sales[0], total = 0.0;
    int minIndex = 0, maxIndex = 0;

    for (int i = 0; i < size; i++) {
        if (sales[i] < min) {
            min = sales[i];
            minIndex = i;
        }
        if (sales[i] > max) {
            max = sales[i];
            maxIndex = i;
        }
        total += sales[i];
    }

    float average = total / size;
    printf("Sales summary report:\n");
    printf("Minimum sales: $%.2f (%s)\n", min, months[minIndex]);
    printf("Maximum sales: $%.2f (%s)\n", max, months[maxIndex]);
    printf("Average sales: $%.2f\n\n", average);
}

// Function to print the Six-Month Moving Average Report
void printSixMonthMovingAverage(float sales[], const char *months[], int size) {
    printf("Six-Month Moving Average Report:\n");
    for (int i = 0; i <= size - 6; i++) {
        float sum = 0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        float average = sum / 6;
        printf("%s-%s $%.2f\n", months[i], months[i+5], average);  // Fixed this part to use months array
    }
    printf("\n");
}

// Function to print the Sales Report from Highest to Lowest
void printSalesReportHighestToLowest(float sales[], const char *months[], int size) {
    // Create a copy of sales and months arrays to sort them without modifying the original data
    float salesCopy[12];
    const char *monthsCopy[12];
    for (int i = 0; i < size; i++) {
        salesCopy[i] = sales[i];
        monthsCopy[i] = months[i];
    }

    // Sort the copied arrays
    sortSales(salesCopy, monthsCopy, size);

    printf("Sales Report (Highest to Lowest):\n");
    printf("Month      Sales\n");
    for (int i = 0; i < size; i++) {
        printf("%-10s $%.2f\n", monthsCopy[i], salesCopy[i]);
    }
}

// Function to sort the sales and months arrays in descending order
void sortSales(float sales[], const char *months[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (sales[i] < sales[j]) {
                // Swap sales
                float tempSales = sales[i];
                sales[i] = sales[j];
                sales[j] = tempSales;

                // Swap corresponding months
                const char *tempMonth = months[i];
                months[i] = months[j];
                months[j] = tempMonth;
            }
        }
    }
}
