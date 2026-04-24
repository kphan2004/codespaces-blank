/**
 * The Bank - Banker's Algorithm Implementation
 */

public class BankImpl implements Bank
{
	private int n;			// the number of threads in the system
	private int m;			// the number of resources

	private int[] available; 	// the amount available of each resource 
	private int[][] maximum; 	// the maximum demand of each thread 
	private int[][] allocation;	// the amount currently allocated to each thread	
	private int[][] need;		// the remaining needs of each thread		

	/**
	 * Create a new bank with resources.
	 */
	public BankImpl(int[] resources) {
		// m is the number of resources
		m = resources.length;
		n = TestBankers.NUMBER_OF_CUSTOMERS;

		// initialize the resources array
		available = new int[m];
		System.arraycopy(resources, 0, available, 0, m);

		// create the array for storing the maximum demand by each thread
		maximum    = new int[TestBankers.NUMBER_OF_CUSTOMERS][];
		allocation = new int[TestBankers.NUMBER_OF_CUSTOMERS][];
		need       = new int[TestBankers.NUMBER_OF_CUSTOMERS][];
	}

	/**
	 * This method is invoked by a thread when it enters the system. It records
	 * its maximum demand with the bank.
	 */
	public void addCustomer(int threadNum, int[] maxDemand) {
		maximum[threadNum]    = new int[m];
		allocation[threadNum] = new int[m];
		need[threadNum]       = new int[m];

		System.arraycopy(maxDemand, 0, maximum[threadNum], 0, maxDemand.length);
		System.arraycopy(maxDemand, 0, need[threadNum],    0, maxDemand.length);
		// allocation is already zeroed by Java default
	}

	/**
	 * Outputs the state for each thread
	 */
	public void getState() {
		System.out.print("Available = \t[");
		for (int i = 0; i < m - 1; i++)
			System.out.print(available[i] + " ");
		System.out.println(available[m - 1] + "]");

		System.out.print("\nAllocation = ");
		for (int i = 0; i < n; i++) {
			System.out.print("\t[");
			for (int j = 0; j < m - 1; j++)
				System.out.print(allocation[i][j] + " ");
			System.out.print(allocation[i][m - 1] + "]");
		}

		// Max matrix
		System.out.print("\nMax = \t");
		for (int i = 0; i < n; i++) {
			System.out.print("\t[");
			for (int j = 0; j < m - 1; j++)
				System.out.print(maximum[i][j] + " ");
			System.out.print(maximum[i][m - 1] + "]");
		}

		// Need matrix
		System.out.print("\nNeed = \t");
		for (int i = 0; i < n; i++) {
			System.out.print("\t[");
			for (int j = 0; j < m - 1; j++)
				System.out.print(need[i][j] + " ");
			System.out.print(need[i][m - 1] + "]");
		}

		System.out.println();
	}


	/**
	 * Determines whether granting a request results in leaving
	 * the system in a safe state or not.
	 *
	 * @return  true  - the system is in a safe state.
	 * @return  false - the system is NOT in a safe state.
	 */
	private boolean isSafeState(int threadNum, int[] request) {
		System.out.print("\n Customer # " + threadNum + " requesting ");
		for (int i = 0; i < m; i++) System.out.print(request[i] + " ");

		System.out.print("Available = ");
		for (int i = 0; i < m; i++)
			System.out.print(available[i] + "  ");

		// First check: sufficient resources available?
		for (int i = 0; i < m; i++) {
			if (request[i] > available[i]) {
				System.err.println("INSUFFICIENT RESOURCES");
				return false;
			}
		}

		// Try to find a safe ordering
		boolean[] canFinish = new boolean[n];
		for (int i = 0; i < n; i++)
			canFinish[i] = false;

		// Working copy of available
		int[] avail = new int[m];
		System.arraycopy(available, 0, avail, 0, available.length);

		// Temporarily allocate the requested resources
		for (int i = 0; i < m; i++) {
			avail[i]              -= request[i];
			need[threadNum][i]    -= request[i];
			allocation[threadNum][i] += request[i];
		}

		/**
		 * Try to find an ordering of threads so that each thread can finish.
		 * Safety algorithm (Section 8.6.3.1).
		 */
		System.out.print("Trying to find a possible ordering: ");
		for (int i = 0; i < n; i++) {           // at most n passes
			for (int j = 0; j < n; j++) {        // find a thread that can finish
				if (!canFinish[j]) {
					boolean temp = true;
					for (int k = 0; k < m; k++) {
						if (need[j][k] > avail[k])
							temp = false;
					}
					if (temp) {                  // this thread can finish
						canFinish[j] = true;
						System.out.print(j + " ");
						for (int x = 0; x < m; x++)
							avail[x] += allocation[j][x];
					}
				}
			}
		}

		// Restore the temporary changes
		for (int i = 0; i < m; i++) {
			need[threadNum][i]       += request[i];
			allocation[threadNum][i] -= request[i];
		}

		// Check whether all threads could complete
		boolean returnValue = true;
		for (int i = 0; i < n; i++) {
			if (!canFinish[i]) {
				returnValue = false;
				break;
			}
		}

		return returnValue;
	}

	/**
	 * Make a request for resources. This is a synchronized method that returns
	 * only when the request can safely be satisfied.
	 *
	 * @return  true  - the request is granted.
	 * @return  false - the request is not granted.
	 */
	public synchronized boolean requestResources(int threadNum, int[] request) {
		// Check that request does not exceed declared need
		for (int i = 0; i < m; i++) {
			if (request[i] > need[threadNum][i]) {
				System.out.println("Request exceeds need");
				return false;
			}
		}

		if (!isSafeState(threadNum, request)) {
			return false;
		}

		// Safe: allocate the resources to threadNum
		for (int i = 0; i < m; i++) {
			available[i]             -= request[i];
			allocation[threadNum][i] += request[i];
			need[threadNum][i]       -= request[i];
		}
		return true;
	}


	/**
	 * Release resources.
	 *
	 * @param threadNum The customer releasing resources.
	 * @param release   The resources to be released.
	 */
	public synchronized void releaseResources(int threadNum, int[] release) {
		System.out.print("\n Customer # " + threadNum + " releasing ");
		for (int i = 0; i < m; i++) System.out.print(release[i] + " ");

		// Update available, allocation, and need
		for (int i = 0; i < m; i++) {
			available[i]             += release[i];
			allocation[threadNum][i] -= release[i];
			need[threadNum][i]       += release[i];
		}

		System.out.print("Available = ");
		for (int i = 0; i < m; i++)
			System.out.print(available[i] + "  ");

		System.out.print("Allocated = [");
		for (int i = 0; i < m; i++)
			System.out.print(allocation[threadNum][i] + "  ");
		System.out.print("]");

		// Notify waiting threads that resources have been freed
		notifyAll();
	}
}