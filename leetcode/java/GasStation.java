public class GasStation {

	public static int canCompleteCircuit(int[] gas, int[] cost) {
		if (gas.length != cost.length)
			return -1;
		int[] diff = new int[gas.length];
		for (int i=0; i<gas.length; i++)
			diff[i] = gas[i] - cost[i];
		int i=0;
		int j = gas.length-1;
		int sum = 0;

		while (true) {
			do {
				sum += diff[i];
				if (i == j) {
					if (sum >= 0)
						return (j+1) % (gas.length);
					else
						return -1;
				} 
				i++;					
			} while (sum > 0)

			do {
				sum += diff[j];
				if (i == j) {
					if (sum >= 0)
						return j;
					else
						return -1;
				} 
				j--;
			} while (sum < 0);
		}
	}

	public static void main(String[] args) {
		int[] gas = {1,2};
		int[] cost = {2,1};
		System.out.println(canCompleteCircuit(gas, cost));
	}
}