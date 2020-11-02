# Pipe
Pipe is simplex FIFO communication channel that may be used for one-way IPC  
- doesn't have its name = anonymous pipe
- provides only __one-way communication__
  - Data written to the write end of the pipe is buffered by OS until it is read from the read end of the pipe
  - parent program: opens anonymous pipes & creates new process that inherits the other ends of the pipes or creates several new processes and arranges them in a pipeline
  - Full-duplex (two-way) communication normally requires __two__ (anonymous) pipes
- it's one of the message passing IPCs
![Pipe](https://t1.daumcdn.net/cfile/tistory/99B096385C4C756932 "message passing vs memory sharing")

## Pipeline
Pipeline is a mechanism for IPC using message passing. It's a set of processes __chained together by their standard streams__, so that the output text of each process (stdout) is passed directly as input (stdin) to the next one; the second process is started as the first process is still executing, and they are executed concurrently.
~~~
ls -l | grep key | less
~~~
This example code lists files in the current directory, retain only the lines of ls output containing the string "key", and view the result in a scrolling page.
~~~
ps -ef | grep hurryon
cat file.txt | more
cat song-list.txt | sort
~~~

## Pipe Creation: _pipe()_
_pipe()_ allows a process to write data to a file descriptor and read it back from another.  
Pipes become useful by exploiting the fact that file descriptors are inherited through _fork()_
~~~
./pipe1
./pipe2
./pipe3
~~~
Pipes can be used to exchange data between the parent and child. (BUT it's still one-way (half-duplex) communication for IPC)  
- In the parent: _close(pfd[0])_
- In the child: _close(pfd[1])_
- Parent can send data to the child with _write(pfd[1], ...)_, while the child can receive data from the parent with _read(pfd[0], ...)_
![After _pipe()_ and _fork()_](https://t1.daumcdn.net/cfile/tistory/99AEDE345A44D3431A "After _pipe()_ and _fork()_")![After _pipe()_, _fork()_, and then _close()_](https://t1.daumcdn.net/cfile/tistory/99EEE2435A44D34302 "After _pipe()_, _fork()_, and then _close()_")

- Reading from a pipe whose the write end is already closed will get __0__
  - returning 0 is a standard way of _read()_ to signal the end-of-file
- Writing to a pipe whose the read end is already closed will get __-1__ with _errno_ set to _EPIPE_; additionally the signal _SIGPIPE_ is sent to the writing process

### Full-duplex Communication Pipes
- _pipe(p2c)_, _pipe(c2p)_
- _fork()_
- In the parent: _close(p2c[0])_, _close(c2p[1])_
- In the child: _close(p2c[1])_, _close(c2p[0])_
- Parent can send data to the child with _write(p2c[1], ...)_, while the child can send data to the parent with _write(c2p[1], ...)_

## Pipes with Filter
Filter is a program that gets (most of) its input from stdin and writes (most of) its output to stdout  
(https://www.linux.com/news/pipes-and-filters/)  
ex) _awk_, _sed_, _cat_, _cut_, _grep_, _less_, ...
~~~
./filter1 testfile.c
cat testfile.c | more     // they result the same
~~~
Shell Redirection   
ex) _ps -ef > ps.txt_  
ex) _cat song-list.txt > song-list-copy.txt_

## Named Pipe
Named pipe is implemented through a file instead of the standard input and output. (= FIFO)  
Compared to a pipe, a named pipe has a (file) name.  
With a named pipe, multiple processes can read and write to the file as a buffer for IPC data.  
The named pipe allows that no related processes can exchange data via the file. 
~~~
./fifo-writer
./fifo-reader
~~~
