public class CourseSchedule {


	static int visit(int[] nodes, boolean[][] matrix, int i) {
        nodes[i] = 1;
        for (int j=0; j<matrix[i].length; j++) {
            if (matrix[i][j] == true) {
                if (nodes[j] == 1) {
                    return -1;
                } else if (nodes[j] == 0) {
                    int ret = visit(nodes, matrix, j);
                    if (ret == -1)
                        return -1;
                }
            }
        }
        nodes[i] = 2;
        return 0;
    }
    
    public static boolean canFinish(int numCourses, int[][] prerequisites) {
        boolean[] notStart = new boolean[numCourses];
        boolean[][] matrix = new boolean[numCourses][numCourses];
        for (int i=0; i<prerequisites.length; i++) {
            int m = prerequisites[i][0];
            int n = prerequisites[i][1];
            matrix[m][n] = true;
            notStart[n] = true;
        }
        int[] nodes = new int[numCourses]; // 0 not_visited, 1 pre_visited, 2 post_visited
        for (int i = 0; i < numCourses; i++) {
            if (notStart[i] == false) {
                int ret = visit(nodes, matrix, i);
                if (ret == -1)
                    return false; 
            }
        }
        return nodes[0] == 2;
        
    }

	public static void main(String[] args) {
		int[][] pre = {{0,1}};
		System.out.println(canFinish(2, pre));
	}
}