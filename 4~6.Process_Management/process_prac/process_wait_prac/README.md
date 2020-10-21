# Process Status Change Practice
Linux provides a communication mechanism how a process terminates to its parent.
- Normal Termination: _exit(status)_
- Abnormal Termination: kernel prepares a termination status
	- When parent dies before the child dies, then __kernel__ becomes the parent of the child processes = ___systemd___ becomes parent for the __orphan children__

## _wait()_ function
_wait()_ searches a __termination status of a child process__
- return value = child PID (-1 on error)
- if no child has recently terminated, then it __blocks__ until one child process terminates
- if a child has terminated and its status has not been collected yet, __*wstatus__ is filled
	~~~
	pid_t wait(init *wstatus)
	~~~
- if the calling process has no child, it returns an error
### _wait()_ function's macros
- _WIFEXITED(status)_
	- TRUE on normal termination
	- can be used to search the exit status
- _WIFSIGNALED(status)_
	- TRUE on abnormal termination due to uncatched signal
	- can be used to get the signal number
~~~
gcc wait.c -o wait
~~~

### zombie process
A process that has terminated but whose termination status has not yet been collected.  
Large amounts of zombie processes: consume resources
~~~
gcc zombie.c -o zombie
~~~
