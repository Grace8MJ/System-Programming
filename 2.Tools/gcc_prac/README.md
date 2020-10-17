# gcc Practice

## Compile _hello.c_
~~~
gcc hello.c -o hello
~~~

## Linking _hi.o_ and _func.o_
~~~
gcc -c hi.c func.c				// _hi.c_ and _func.c_ become object file
gcc hi.o func.o -o hi-exec		// link _hi.o_ and _func.o_
~~~
