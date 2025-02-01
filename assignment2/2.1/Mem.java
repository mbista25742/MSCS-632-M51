import java.util.ArrayList;

public class Mem {
    public static void main(String[] args) {
        // Create a list to store dynamically allocated objects
        ArrayList<String> stringList = new ArrayList<>();
        
        // Simulate memory allocation in a loop
        for (int i = 0; i < 1000000; i++) {
            // Allocate a new string dynamically
            String x = new String("Hello, Java! " + i);
            stringList.add(x); // Store the reference to prevent garbage collection

            // Simulate some additional operations to increase memory usage
            if (i % 100000 == 0) {
                System.out.println("Allocated: " + i + " objects");
            }
        }

        // After the loop, you may want to let some time for garbage collection
        try {
            System.out.println("Simulating long-running process...");
            Thread.sleep(5000); // Sleep for 5 seconds to allow garbage collection
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // Simulate memory release
        stringList.clear(); // Clear the list, making all referenced objects eligible for GC

        // Give time for garbage collection to occur
        System.gc();
        try {
            Thread.sleep(2000); // Sleep for 2 seconds to allow GC to finish
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // Final output to show the program is done
        System.out.println("Finished memory-intensive operations.");
    }
}
