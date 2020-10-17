# gcc: GNU Compiler Collection
Default compiler for C, C++, Object-C, etc.
![compile process](https://miro.medium.com/max/769/1*J5fqmdDTjrmZaZO7Ctd6sg.png "compile process")

## Compiling (~.c --> ~.exe)
~~~
gcc [~.c] -o [~.exe]
~~~

## Preprocessing (~.c --> ~.i)
~~~
gcc -E [~.c] -o [~.i]
~~~

## Assembling (~.c --> ~.o)
~~~
gcc -c [~.c]
~~~

## Linking (~.o --> ~.exe)
~~~
gcc [~.o] -o [~.exe]
~~~
