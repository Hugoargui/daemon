# daemon
Daemon tcp server that gives you cpu load and Ram ussage information on demand

## Build:
This project uses CMake, just run this command once:
```cmake -S . build -G "Unix Makefiles"```

To generate build directory and from then you can use:
```(cd build && make)```
Anytime to build

**For convenience, I have wrapped those two commands in the .build.sh script**

## Dependencies
The only dependency is a linux system and CMake.

This project uses asio (the standalone version, to avoid depending on the whole boost libraries). For convenience, I have packaged asio
in the /lib subfolder.

## Usage:

to run the daemon in the background, after building the project, use:
```sudo -b ./build/server```

to run a client
```./build/client```

to terminate client just use <C-c>
to terminate the daemon, if it's in the background, you'll have to use a kill signal.

## TODO:

Due to tiem constraints I have left this as todo:

- the server currently only supports one client at a time, to use a second client the first one has to be closed.
- the ram is not exactly calculated as per the assignment
- the cpu is not exactly calculated as per the assignment



