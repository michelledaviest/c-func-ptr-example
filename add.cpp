

extern "C" {
	
	// useless - is caught by DCE (some DFA)
	int no_use (int a, int b) { 
		return 0;
	}
	
	int add (int a,int b) {
		return a+b;
	}
	
	int sub (int a, int b) {
		return a-b; 
	}
	
	int mul (int a, int b) {
		return a*b;
	}
	
	int temp (int n1, int n2, int op) {
		
		int (*fn_ptr)(int, int); 
		
		//if (strcmp(op, "+") == 0) return 32; 
		/*
		if (strcmp(op, "+") == 0) fn_ptr = &add;
		else if (strcmp(op, "-") == 0) fn_ptr = &sub;
		else if (strcmp(op, "*") == 0) fn_ptr = &mul;
		return (*fn_ptr)(n1,n2);
		*/
		
		fn_ptr = &no_use; 
		
		if (op == 1) fn_ptr = &add;
		else if (op == 2) fn_ptr = &sub;
		else if (op == 3) fn_ptr = &mul;
		else fn_ptr = &add;
		
		return (*fn_ptr)(n1,n2);
		
	}
	
	//unused functions	
	int inc (int a) { return a+1; }
	
	int dec (int a) { return a-1; }
	 
}

// emcc add.cpp -o add.js --std=c++11 -s "EXPORTED_FUNCTIONS=['_add','_temp']"

//optimized = emcc add.cpp -Os -o add.js --std=c++11 -s "EXPORTED_FUNCTIONS=['_add','_temp']"


// o2 - see how large the wasm module is 
// see which functions are in there - only the functions that you name in 

//function pointers : make an add function, point to it / use it and see the outgoing wasm code

/*
int main() {
	int num1, num2, res; 
	
	cout<<"Num1: ";
	cin>>num1;
	cout<<"Num2: ";
	cin>>num2;
	
	res=add(num1,num2);
	cout<<"Result: "<<res<<endl;
	
	return 0;
}
*/

