public class Solution {
	public int maximalRectangle(char[][] matrix) {
		
		if (matrix.length == 0)
			return 0;
		if (matrix[0].length == 0)
			return 0;
		int minX=Integer.MAX_VALUE/2;
		int maxX=Integer.MIN_VALUE/2;
		int minY=Integer.MAX_VALUE/2;
		int maxY=Integer.MIN_VALUE/2;
			
		for (int i=0; i<matrix.length; i++) {
			for (int j=0; j<matrix[0].length; j++) {
				if (matrix[i][j] == '1') {
					if (i < minX) minX = i;
					if (j < minY) minY = j;
					if (i > maxX) maxX = i;
					if (j > maxY) maxY = j;
				}
			}
		}
		

		System.out.println("maxX="+maxX+"maxY="+maxY+"minX="+minX+"minY"+minY);
		int height = maxX-minX+1;

		if (height <= 0)
			return 0;
		int width = maxY-minY+1;
		if (width <= 0)
			return 0;
		return height*width;
	}
}