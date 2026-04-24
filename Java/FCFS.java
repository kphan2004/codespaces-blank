/**
 * FCFS scheduling algorithm.
 */
 
import java.util.*; // Import Java utility classes (List, ArrayList, etc)

public class FCFS implements Algorithm
{
    // List that stores all tasks to be scheduled
    private List<Task> queue;
    // The task currently being executed
    private Task currentTask;

    // Total number of tasks 
    private int tasksRun;

    public FCFS(List<Task> queue) {
        this.queue = queue; // Assign the passed-in task list to local queue
        // Store initial number of tasks
        tasksRun = queue.size();
    }

    public void schedule() {
        // Print algorithm name
        System.out.println("FCFS Scheduling \n");

        // Continue until all tasks are processed
        while (!queue.isEmpty()) {
            currentTask = pickNextTask();
            
            // Run for the full duration of its burst
            CPU.run(currentTask, currentTask.getBurst());

            // Task is finished, remove it
            queue.remove(currentTask);
        }
    }

    //IMPLEMENT HOW YOU PICK THE NEXT TASK USING FCFS HERE
    public Task pickNextTask() {
        // Returns first task in the list
        return queue.get(0);
    }
}
