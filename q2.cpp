	
	//need to create neccesary header file. Abstract Iplementation below
	// 0 represents epsilon

	void Push(char chInput)							
	{
 	// Create two states 	
  	State *s0 = new State(++NextStateID);
	State *s1 = new State(++NextStateID);
	 
	  // Add the transition from s0->s1 on input character
	  s0->AddTransition(chInput, s1);
	 
	  // Create a NFA from states created
	  NFA_TABLE NFATable;						// need to create appropriate data structure
	  NFATable.push_back(s0);
	  NFATable.push_back(s1);
	 
	  // Push it onto the operand stack
	  OperandStack.push(NFATable);
	 
	  // Add this character to the input character set
	  InputSet.insert(chInput);
	}




	bool Concat()
	{
	  // Pop two elements
	  NFA_TABLE A, B;
	  if(!Pop(B) || !Pop(A))
	    return false;
	 
	  //to concate add epsilon transition from end of A to beg of B
	  A[A.size()-1]->AddTransition(0, B[0]);
	  //insert b begin to end at A end
	  A.insert(A.end(), B.begin(), B.end());
	 
	  // Push the result onto the stack
	  OperandStack.push(A);
	 
	  return true;
	}



	bool Star()
	{
	  // Pop one element
	  NFA_TABLE A, B;
	  if(!Pop(A))
	    return FALSE;
	 
	  // for A* : add 2 states. one starts and has epsilon transition to the end state
	  // the end state epsilon transitions to the first state of A. This in essence creates A*

	  State *pStartState = new State(++NextStateID);
	  State *pEndState   = new State(++NextStateID);
	  pStartState->AddTransition(0, pEndState);
	 
	  // Add an epsilon transition from start state to the first state of A
	  pStartState->AddTransition(0, A[0]);
	 
	  // Add an epsilon transition from A last state to end state
	  A[A.size()-1]->AddTransition(0, pEndState);
	 
	  // From A last to A first state
	  A[A.size()-1]->AddTransition(0, A[0]);
	 
	  // Construct a new DFA and store it onto the stack
	  A.push_back(pEndState);
	  A.push_front(pStartState);
	 
	  // Push the result onto the stack
	  OperandStack.push(A);
	 
	  return true;
	}


	bool Union()
	{
	  // Pop two elements
	  NFA_TABLE A, B;
	  if(!Pop(B) || !Pop(A))
	    return FALSE;
	 
	  //two created states function as dummy start and end states
	 //epsilon transition from start state to both start state and similarly for end
	  State *pStartState = new State(++NextStateID);
	  State *pEndState   = new State(++NextStateID);
	  pStartState->AddTransition(0, A[0]);
	  pStartState->AddTransition(0, B[0]);
	  A[A.size()-1]->AddTransition(0, pEndState);
	  B[B.size()-1]->AddTransition(0, pEndState);
	 
	  // Create a new NFA from A
	  B.push_back(pEndState);
	  A.push_front(pStartState);
	  A.insert(A.end(), B.begin(), B.end());
	 
	  // Push the result onto the stack
	  OperandStack.push(A);
	 
	  return true;
	}


