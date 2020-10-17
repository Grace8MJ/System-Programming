# Process Practice

## Memory Layout on Linux
![memory layout](https://gabrieletolomei.files.wordpress.com/2013/10/program_in_memory2.png "Memory Layout on Linux")

### User Space
1. Stack
	- dynamic
	- local variables and others for functions
1. Heap
	- dynamic
	- dynamically allocated memory (by _malloc()_)
1. BSS (Uninitialized data)
	- Uninitialized array and static and global variables
1. Data (Initialized data)
	- Initialized array and static and global variables
1. Text
	- Program Code

## Compile _mem-layout.c_
~~~
gcc mem-layout.c -o mem-layout
~~~
By seeing the result of _./mem-layout_, we can recognize that BSS segment is above Data segment; Heap segment is above BSS segment; Stack segment is above Heap segment.

## Use _size_
_size_ allows you to check the sizes of Text, Data, BSS segment.
~~~
size ./mem-layout
~~~
