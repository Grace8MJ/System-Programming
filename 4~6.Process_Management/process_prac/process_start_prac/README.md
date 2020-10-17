# Process Start Practice

## function _main()_
_main()_ is the first point to start the program.  
Before executing _main()_, there is a __startup routine__, which is inserted by the linker at the compile time.  
__Startup Routine__fills the followings:
- _argc_, _argv_ of _main()_
- Environment variables

## Arguments
### Use of _argc_, _argv_
~~~
gcc arg.c -o arg
./arg choi min ji
~~~
_./arg.result_ is the result of _./arg choi min ji_.

## Environment Variables
Environment variables, which are the lists of (key, value), are passed to a process when the process starts.  
Thoses variables are the global variables:
~~~
extern char **environ;
~~~
![environment variable](https://notes.shichao.io/apue/figure_7.5.png "environment variable")

### Showing key-value
_getenv()_ does a key-value lookup

### Adding key-value
_putenv()_ adds a key-value pair with the "key=value"

### Accessing the entire environment variables
~~~
extern char **environ
~~~
Example:
~~~
gcc env.c -o env
export
~~~
