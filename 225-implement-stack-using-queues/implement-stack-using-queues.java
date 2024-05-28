class MyStack {
    Queue<Integer> firstQueue, secondQueue;
    public MyStack() {
        firstQueue = new LinkedList<>();
        secondQueue = new LinkedList<>();
    }
    
    public void push(int x) {
        if(secondQueue.isEmpty())
            firstQueue.add(x);
        else
            secondQueue.add(x);
    }
    
    public int pop() {
        if(secondQueue.isEmpty()) {
            while(firstQueue.size() > 1) {
                secondQueue.add(firstQueue.poll());
            }
            return firstQueue.poll().intValue();
        }
        else {
            while(secondQueue.size() > 1) {
                firstQueue.add(secondQueue.poll());
            }
            return secondQueue.poll().intValue();
        }
    }
    
    public int top() {
        if(secondQueue.isEmpty()) {
            while(firstQueue.size() > 1) {
                secondQueue.add(firstQueue.poll());
            }
            Integer x = firstQueue.poll();
            secondQueue.add(x);
            return x.intValue();
        }
        else {
            while(secondQueue.size() > 1) {
                firstQueue.add(secondQueue.poll());
            }
            Integer x = secondQueue.poll();
            firstQueue.add(x);
            return x.intValue();
        }
    }
    
    public boolean empty() {
        return firstQueue.isEmpty() && secondQueue.isEmpty();
    }


}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */