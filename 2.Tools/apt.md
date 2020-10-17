# apt: Advanced Package Tool

## Updating info
Updates package repository information
~~~
sudo apt-get update
~~~
Configured repositories in /etc/apt/sources.list



## Upgrading
Upgrades installed packages (to latest version)
~~~
sudo apt-get dist-upgrade
~~~



## Searching by name
Searches packages by name
~~~
sudo apt-cache search [pkg name]
~~~



## Showing info
Showes the package information
~~~
sudo apt-cache show [pkg name]
~~~



## Installing
Installes packages
~~~
sudo apt-get install [pkg name] [pkg name] ...
~~~



## Removing
Removes packages
~~~
sudo apt-get remove [pkg name] [pkg name] ...
~~~



## Showing dependencies
Showes package dependencies
~~~
sudo apt-cache showpkg [pkg name]
~~~
