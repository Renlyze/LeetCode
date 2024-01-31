class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int[] results =  new int[temperatures.length];
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < temperatures.length; i++) {
            while (!stack.isEmpty() && temperatures[stack.peek()] < temperatures[i]){
                results[stack.peek()] = i - stack.pop();
            }
            stack.push(i);
        }

        return results;
    }
}


/*Initialize an array results to store the number of days until a warmer day for each day's temperature.
Initialize an empty stack to keep track of indices.
Iterate through each temperature in the array.
While the stack is not empty and the current temperature is greater than the temperature at the index on the top of the stack:
Update the result for the index at the top of the stack with the difference between the current index and the index on the top of the stack.
Pop the index from the stack.
Push the current index onto the stack.
After the iteration, the results array contains the number of days until a warmer day for each given day.*/