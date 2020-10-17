# tmux: Terminal Multiplexer
It allows you to switch between programs in one terminal, detach them keeping running in the background and reattach them to a different terminal if needed
![Session, Window, Pane](https://snipcademy.com/img/articles/linux-command-line-tmux/sessions-windows-panes-01.svg "Session, Window, Pane")

## Session
### New Session
Makes a new session (= start tmux)
~~~
tmux
tmux new -s [session name]
~~~

### Kill Session
~~~
tmux kill-session -t [session name]
~~~

### Detach from Session
~~~
(ctrl+b) d
~~~

### Show Session List
~~~
tmux ls
~~~

### Attach to Session
~~~
tmux attach -t [session no. OR name]
~~~

## Window
### New Window
~~~
(ctrl+b) c
~~~

### Change Window
~~~
(ctrl+b) [window no.]
(ctrl+b) n
(ctrl+b) p
~~~

## Pane
### New Pane
~~~
(ctrl+b) %
(ctrl+b) "
~~~

### Maximize Pane
~~~
(ctrl+b) z
~~~

### Change Pane
~~~
(ctrl+b) [arrow key]
(ctrl+b) o
~~~

## Copy Mode
### Configure copy mode
~~~
vi ~/.tmux.conf
~~~
Add _set-window-option -g mode-keys vi_

### Operate Copy Mode
~~~
(ctrl+b) [			// scroll mode
(space bar)			// block mode
(enter)				// copy
(ctrl+b) ]			// paste
~~~
