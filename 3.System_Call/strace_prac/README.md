# System Call Invocation Practice

## Compile _hello.c_
~~~
gcc hello.c -o hello
~~~

## Use _strace_
_strace_ is a tool to trace system calls and signals. Therefore, we can intercept and record the system calls which are called by a process and the signals which are recived by a process.
~~~
strace ./hello
strace ./hello 2>hello.strace		// in order to send result to _hello.strace_
~~~
Result:  
35 system calls are invoked  
(including _execve_, _openat_, _fstat_, _mmap_, _read_, _write_, _close_, etc.)
