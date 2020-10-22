# Fork Inheritance Practice
Memory copy has an effect on __buffers__ that are stored in memory.  
Standard I/O buffers and also any other user-space buffer layer you might be using.
~~~
gcc buffer.c -o buffer
~~~

## Finding Error Location
16byte stack BUT input string is 17byte  
This causes error, especially __Stack Overflow__
~~~
gcc -g stack.c -o stack
~~~
If the input is over 16byte, then it shows 'stack smashing detected. Aborted (core dumped)' error message. By this result, it is able to know stack overflow happened.
~~~
gdb stack
~~~
_b *[func or addr]_: set breakpoint (ex. b \*main+0)
_info breakpoints_: show list of breakpoints
_del [num]_: delete num-th breakpoint (based on _info breakpoints_)
_disass [func]_: print assembly code of the certain function
_run [argv]..._: execute program (with argument)
_c_: continue until meeting next breakpoint
_n_: execute next line and stop
_list_: show code
_info local_: print value of variables
_print [var]_: print value of the certain variable
