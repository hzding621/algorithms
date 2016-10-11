import java.util.*;

class MyQueue {

    private Stack<Integer> inStack, outStack;

    public MyQueue() {
        inStack = new Stack<Integer>();
        outStack = new Stack<Integer>();
    }

    // Push element x to the back of queue.
    public void push(int x) {
        inStack.push(x);
    }

    private void readyForPop() {
        if (outStack.empty()) {
            while (!inStack.empty())
                outStack.push(inStack.pop());
        }
    }

    // Removes the element from in front of queue.
    public void pop() {
        readyForPop();
        outStack.pop();
    }

    // Get the front element.
    public int peek() {
        readyForPop();
        return outStack.peek();
    }

    // Return whether the queue is empty.
    public boolean empty() {
        return inStack.empty() && outStack.empty();
    }
}

public class ImplementingQueueUsingStacks {
    public static void main(String[] args) {
        MyQueue q = new MyQueue();
        q.push(1);
        q.push(2);
        System.out.println(q.peek());
        q.pop();
        System.out.println(q.peek());
    }
}
