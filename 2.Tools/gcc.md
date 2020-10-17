# gcc: GNU Compiler Collection
Default compiler for C, C++, Object-C, etc.
![compile process](https://www.google.com/url?sa=i&url=https%3A%2F%2Fmedium.com%2F%40vietkieutie%2Fwhat-happens-when-you-type-gcc-main-c-2a136896ade3&psig=AOvVaw1rL1JjJwpodCy8yTZy1uZf&ust=1603004657507000&source=images&cd=vfe&ved=0CAIQjRxqFwoTCKCz-YWIu-wCFQAAAAAdAAAAABAD "compile process")

## Compiling (~.c --> ~.exe)
'''
gcc [~.c] -o [~.exe]
'''

## Preprocessing (~.c --> ~.i)
'''
gcc -E [~.c] -o [~.i]
'''

## Assembling (~.c --> ~.o)
'''
gcc -c [~.c]
'''

## Linking (~.o --> ~.exe)
'''
gcc [~.o] -o [~.exe]
'''
