class StatisticsCalculator:
    """
    A class to calculate basic statistics for a list of integers.
    Demonstrates object-oriented programming principles.
    """
    
    def __init__(self, data=None):
        """
        Initialize the calculator with optional data.
        
        Args:
            data (list): Optional list of integers
        """
        self.data = data if data is not None else []
    
    def set_data(self, data):
        """
        Set or update the data for calculations.
        
        Args:
            data (list): List of integers
        """
        if not isinstance(data, list):
            raise TypeError("Data must be a list")
        self.data = data.copy()  # Create a copy to prevent external modifications
    
    def get_data(self):
        """
        Return a copy of the current data.
        
        Returns:
            list: Copy of the current data
        """
        return self.data.copy()
    
    def calculate_mean(self):
        """
        Calculate the mean (average) of the data.
        
        Returns:
            float: Mean value, or 0 if data is empty
        """
        if not self.data:
            return 0
        return sum(self.data) / len(self.data)
    
    def calculate_median(self):
        """
        Calculate the median (middle value) of the data.
        
        Returns:
            float: Median value, or 0 if data is empty
        """
        if not self.data:
            return 0
        
        # Create a sorted copy of the data
        sorted_data = sorted(self.data)
        n = len(sorted_data)
        
        # Handle both even and odd lengths
        if n % 2 == 0:
            # Even length - average the middle two values
            return (sorted_data[n//2 - 1] + sorted_data[n//2]) / 2
        else:
            # Odd length - return the middle value
            return sorted_data[n//2]
    
    def calculate_mode(self):
        """
        Calculate the mode (most frequent value(s)) of the data.
        
        Returns:
            tuple: (list of mode values, count of occurrences)
                   Returns ([], 0) if there is no mode (all values appear once)
        """
        if not self.data:
            return [], 0
            
        # Count occurrences of each value
        counts = {}
        for value in self.data:
            if value in counts:
                counts[value] += 1
            else:
                counts[value] = 1
                
        # Find the maximum frequency
        max_count = max(counts.values())
        
        # If all values appear only once, there is no mode
        if max_count == 1:
            return [], 0
            
        # Get all values that appear with the maximum frequency
        modes = [key for key, value in counts.items() if value == max_count]
        
        return modes, max_count
    
    def print_statistics(self):
        """
        Calculate and print all statistics.
        """
        mean = self.calculate_mean()
        median = self.calculate_median()
        modes, mode_count = self.calculate_mode()
        
        print("\nStatistics:")
        print(f"Mean: {mean:.2f}")
        print(f"Median: {median:.2f}")
        
        print("Mode: ", end="")
        if mode_count == 0:
            print("No mode (all values appear once)")
        else:
            print(f"{modes} (appears {mode_count} times)")


# Demonstration of the StatisticsCalculator class
if __name__ == "__main__":
    # Create an instance of the calculator
    calculator = StatisticsCalculator()
    
    # Get input from the user
    try:
        user_input = input("Enter integers separated by spaces: ")
        data = [int(x) for x in user_input.split()]
        
        # Set the data and calculate statistics
        calculator.set_data(data)
        calculator.print_statistics()
        
    except ValueError:
        print("Error: Please enter valid integers separated by spaces.")