void solve(int x,stack<int>& myStack){
    if(myStack.empty()){
        myStack.push(x);
        return;
    }
    
    int temp = myStack.top();
    myStack.pop();
    solve(x,myStack);
    myStack.push(temp);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(x,myStack);
    return myStack;
}

