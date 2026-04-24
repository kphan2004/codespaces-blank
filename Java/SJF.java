/**
 * SJF scheduling algorithm.
 */
 
import java.util.*;

public class SJF implements Algorithm
{
    // List of tasks
    private List<Task> queue;
    // Current task being executed 
    private Task currentTask;

    private int tasksRun;   // Tracks total tasks

    public SJF(List<Task> queue) {
        // Initialize queue
        this.queue = queue;
        // Store initial size
        tasksRun = queue.size();
    }

    public void schedule() {
        // Print title
        System.out.println("SJF Scheduling\n");

        //  Continue until all tasks complete
        while (!queue.isEmpty()) {
            currentTask = pickNextTask();   // Get shortest
            // Run task fuylly
            CPU.run(currentTask, currentTask.getBurst());
    
            // remove completed task
            queue.remove(currentTask);
        }
    }

    //IMPLEMENT HOW YOU PICK THE NEXT TASK USING SJF HERE
    public Task pickNextTask() {
        int shortestIndex = 0;  // Assume first task is shortest
        int shortestBurst = queue.get(0).getBurst();    // Store its burst

        // Loop through all tasks
        for (int i =1; i < queue.size(); i++) {
            // If smaller burst found
            if (queue.get(i).getBurst() < shortestBurst) {
                shortestIndex = i;  // Update index
                shortestBurst = queue.get(i).getBurst();  // Update burst 
            }
        }
        // Returns shortest
        return queue.get(shortestIndex);
    }
}
