# c-func-ptr-example

Compile `add.cpp` using ``emcc add.cpp -Os -o add.wasm --std=c++11 -s "EXPORTED_FUNCTIONS=['_add','_temp']"``
This creates a minified Wasm module and marks the `add` and `temp` functions as exported so that these functions can be called from a JS.

You can inspect `add.wasm` by running `wasm2wat add.wasm -o add.wat` which gives you a textual representation of the Wasm file in `add.wat`. You can see that the module defines a table which is populated with the `add`, `sub`, `mul` functions and function 2 in the module is the `temp` function in `add.cpp` (and is also exported as "temp"), and contains a `call_indirect` instruction. 

This example also has `main.html` which defines a simple calculator and calls the `temp` function with user provided values. On your terminal run `python3 servewasm.py` and open `main.html` on port 8000 of localhost. You can then interact with the calculator which does all its calculations in the backend! 

