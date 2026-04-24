/**
 * Non-preemptive priority scheduling algorithm.
 *
 * A higher numerical priority indicates a higher relative priority.
 */
 
import java.util.*;

//IMPLEMENT THE PRIORITY ALGORITHM BELOW
//TAKE A LOOK AT PRIORITYRR.JAVA TO SEE WHAT YOU CAN REUSE HERE
public class Priority implements Algorithm
{
    // List of tasks
    private List<Task> queue;
    // Keeps track of current task being executed
    private Task currentTask;

    public Priority(List<Task> queue) {
        this.queue = queue; // Initialize queue
    }

    // Scheduling func.
    public void schedule() {
        // Print title
        System.out.println("Priority Scheduling \n");

        // Continues until all tasks are completed
        while (!queue.isEmpty()) {
            // Selects next task based on highest priority
            currentTask = pickNextTask();
            // Run task completely
            CPU.run(currentTask, currentTask.getBurst());
            // Task is finished, remove it
            queue.remove(currentTask);
        }
    }

    // Selects task with highest priority value
    public Task pickNextTask() {
        // Assume first task is highest
        int highestIndex = 0;
        // Store its priority
        int highestPriority = queue.get(0).getPriority();

        // Loop through all tasks to find highest priority
        for (int i = 1; i < queue.size(); i++) {
            // If current task has higher priority
            if (queue.get(i).getPriority() > highestPriority) {
                highestIndex = i;   // Update index
                highestPriority = queue.get(i).getPriority();   // Update value
            }
        }
        // Returns task with highest priority
        return queue.get(highestIndex);
    }
}
