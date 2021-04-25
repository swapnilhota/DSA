import java.util.Stack;

class code {

	static int Prec(char c) {
		switch(c) {
			case '+':
			case '-':
				return 1;
			case '*':
			case '/':
				return 2;
			case '^':
				return 3;			
		}
		return -1;
	}

	static void infixToPrefix(String s) {
		String result = new String("");

		Stack<Character> stack = new Stack<>();

		for(int i=0; i<s.length(); i++) {
			char c = s.charAt(i);

			if((c>='a' && c<='z')||(c>='A' && c<='Z')||(c>='0' && c<='9')) {
				result+=c;
			}
			else if(c=='(') {
				stack.push(c);
			}
			else if(c==')') {
				while(!stack.isEmpty() && stack.peek()!='(') {
					result += stack.pop();
				}
				stack.pop();
			}
			else {
				while(!stack.isEmpty() && Prec(c)<=Prec(stack.peek())) {
					result += stack.pop();
				}
				stack.push(c);
			}
		}

		while(!stack.isEmpty()) {
			result+=stack.pop();
		} 

		System.out.println(result);
	}

	public static void main(String[] args) {

		String exp = "a+b*(c^d-e)^(f+g*h)-i";
		infixToPrefix(exp);
		
	}
}