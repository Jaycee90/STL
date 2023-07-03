#include "cnPtrQueue.h"
#include <cassert>
using namespace std;

namespace CS3358_SP2023_A5P2
{
   cnPtrQueue::cnPtrQueue() : numItems(0){}
   
   bool cnPtrQueue::empty() const
   {
   	  //cnPtrQueue is empty if both stacks are empty
   	  return (inStack.empty() && outStack.empty());
   }
   
   cnPtrQueue::size_type cnPtrQueue::size() const
   {
   	  // returns # of items in queue
   	  return numItems;
   }
   
   CNode* cnPtrQueue::front()
   {
   	  //Check if stacks are not empty
   	  assert(!inStack.empty() || !outStack.empty());
   	  
	  //Move item from instack to outStack if outStack is
   	  //empty but instack is not empty
   	  if (outStack.empty())
   	  {
   	  	 while (!inStack.empty())
   	  	 {
   	  	    outStack.push(inStack.top());
   	  	    inStack.pop();
		 }
	  }
	  return outStack.top();
   }
   
   void cnPtrQueue::push(CNode* cnPtr)
   {
   	  //Add new item into inStack
   	  inStack.push(cnPtr);
   	  ++numItems;
   }
   
   void cnPtrQueue::pop()
   {
   	  //Check if stacks are not empty
   	  assert (!inStack.empty() || !outStack.empty());
   	  
   	  //Move item from instack to outStack if outStack is
   	  //empty but instack is not empty
   	  if (outStack.empty())
   	  {
   	     while(!inStack.empty())
   	     {
   	        outStack.push(inStack.top());
   	        //remove item from instack
   	        inStack.pop();  
		 }
	  }
	  //remove item from outstack
	  outStack.pop();      
	  --numItems;    
   }
}
