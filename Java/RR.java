/**
 * Non-preemptive priority scheduling algorithm using RR.
 *
 * This algorithm will run tasks according to round-robin scheduling.
 */
 
import java.util.*;

//IMPLEMENT THE RR ALGORITHM BELOW
//TAKE A LOOK AT PRIORITYRR.JAVA TO SEE WHAT YOU CAN REUSE HERE
public class RR implements Algorithm
{
    // Time slice for each task
    public static final int QUANTUM = 10;
    // List of tasks
    private List<Task> queue;
    // Current running task
    private Task currentTask;

    public RR(List<Task> queue) {
        this.queue = queue; // Initialize queue
    }

    // Scheduling
    public void schedule() {
        // Print title
        System.out.println("RR Scheduling \n");

        // Continue until all tasks finish
        while (!queue.isEmpty()) {
            currentTask = pickNextTask(); // Always pick first task

            int burst;  // Amount of time to run this round

            // If remaining burst is less than quantum
            if (currentTask.getBurst() < QUANTUM)
                burst = currentTask.getBurst(); // Run remaining time
            else
                burst = QUANTUM;    // Otherwise run full quantum

            // Execute the task for calculated time slice
            CPU.run(currentTask, burst);
            // Reduce remaining burst time
            currentTask.setBurst(currentTask.getBurst() - burst);
            
            // If task finished
            if (currentTask.getBurst() == 0) {
                // Print completion message
                System.out.println("Task " + currentTask.getName() + " finished. \n");
                queue.remove(currentTask);  // Remove from queue
            }
            else {
                // If not finished to move task to back of queue
                queue.remove(currentTask);
                queue.add(currentTask);
            }
       }
    }
    // RR picks first task in queue
    public Task pickNextTask() {
        return queue.get(0);
    }
}
