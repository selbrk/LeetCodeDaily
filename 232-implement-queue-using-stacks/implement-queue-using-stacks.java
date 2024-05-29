class MyQueue {
    Stack<Integer> firstStack, secondStack;
    public MyQueue() {
        firstStack = new Stack<>();
        secondStack = new Stack<>();
        /*
        push,peek,pop 
        */
    }
    
    public void push(int x) {
        firstStack.push(x);
    }
    
    public int pop() {    
        while(firstStack.size() > 1) {
            secondStack.push(firstStack.pop());
        }
        Integer frontElement = firstStack.pop();
        while(!secondStack.empty()) {
            firstStack.push(secondStack.pop());
        }
        return frontElement;
    }
    
    public int peek() {
        while(firstStack.size() > 1) {
            secondStack.push(firstStack.pop());
        }
        Integer frontElement = firstStack.peek();
        
        while(!secondStack.empty()) {
            firstStack.push(secondStack.pop());
        }
        return frontElement;
    }
    
    public boolean empty() {
        return firstStack.empty() && secondStack.empty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */