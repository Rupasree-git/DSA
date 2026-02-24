class Solution {
    public String convert(String s, int numRows) {
        
        // Edge case
        if (numRows == 1 || s.length() <= numRows) {
            return s;
        }

        // Create rows
        StringBuilder[] rows = new StringBuilder[numRows];
        for(int i=0;i<numRows;i++){
            rows[i] = new StringBuilder();
        }

        int currentRow = 0;
        boolean goingDown = false;

        // Traverse string
        for(char c : s.toCharArray()){
            
            rows[currentRow].append(c);
            
            // Change direction
            if(currentRow == 0 || currentRow == numRows-1){
                goingDown = !goingDown;
            }
            
            if(goingDown){
                currentRow++;
            } else {
                currentRow--;
            }
        }

        // Combine rows
        StringBuilder result = new StringBuilder();
        
        for(StringBuilder row : rows){
            result.append(row);
        }

        return result.toString();
    }
}