#include <stdio.h>
#include <stdlib.h>

// Function to compare integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Calculate mean of an array of integers
double calculate_mean(int *array, int size) {
    if (size == 0) return 0;
    
    long sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    
    return (double)sum / size;
}

// Calculate median of an array of integers
double calculate_median(int *array, int size) {
    if (size == 0) return 0;
    
    // Sort the array
    qsort(array, size, sizeof(int), compare);
    
    // Return the median
    if (size % 2 == 0) {
        // Even number of elements, average the middle two
        return (array[size/2 - 1] + array[size/2]) / 2.0;
    } else {
        // Odd number of elements, return the middle one
        return array[size/2];
    }
}

// Calculate mode of an array of integers
void calculate_mode(int *array, int size, int *mode_values, int *mode_count, int *unique_modes) {
    if (size == 0) {
        *unique_modes = 0;
        return;
    }
    
    // Sort the array to group identical values
    qsort(array, size, sizeof(int), compare);
    
    int max_frequency = 0;
    int current_frequency = 1;
    *unique_modes = 0;
    
    // Find the maximum frequency
    for (int i = 1; i <= size; i++) {
        if (i < size && array[i] == array[i-1]) {
            current_frequency++;
        } else {
            if (current_frequency > max_frequency) {
                max_frequency = current_frequency;
                *unique_modes = 1;
                mode_values[0] = array[i-1];
            } else if (current_frequency == max_frequency) {
                mode_values[*unique_modes] = array[i-1];
                (*unique_modes)++;
            }
            current_frequency = 1;
        }
    }
    
    *mode_count = max_frequency;
}

int main() {
    int size;
    printf("Enter the number of integers: ");
    scanf("%d", &size);
    
    if (size <= 0) {
        printf("Invalid size. Please enter a positive number.\n");
        return 1;
    }
    
    // Dynamically allocate memory for the array
    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    
    // Calculate statistics
    double mean = calculate_mean(array, size);
    double median = calculate_median(array, size);
    
    // For mode calculation
    int *mode_values = (int *)malloc(size * sizeof(int)); // Max possible unique values
    int mode_count = 0;
    int unique_modes = 0;
    
    calculate_mode(array, size, mode_values, &mode_count, &unique_modes);
    
    // Display results
    printf("\nStatistics:\n");
    printf("Mean: %.2f\n", mean);
    printf("Median: %.2f\n", median);
    
    printf("Mode: ");
    if (mode_count == 1) {
        printf("No mode (all values appear once)\n");
    } else {
        for (int i = 0; i < unique_modes; i++) {
            printf("%d ", mode_values[i]);
        }
        printf("(appears %d times)\n", mode_count);
    }
    
    // Free allocated memory
    free(array);
    free(mode_values);
    
    return 0;
}