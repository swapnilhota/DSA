import java.io.*;
import java.util.*;

class code {
	public static void main(String[] args) {
		Stack<Integer> stack = new Stack<Integer>();

		stack.push(1);
		stack.push(2);
		stack.push(3);
		stack.push(4);

		System.out.println(stack.peek());
	}
}