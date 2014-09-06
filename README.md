Alfalfa is a research project to build a videoconferencing system
that works well over cellular wireless networks. It uses the same
SSP protocol as Mosh, the mobile shell.

See http://alfalfa.mit.edu for instructions.

## Prerequisites (Debian/Ubuntu):
```
build-essential
autotools-dev
libboost-math1.50-dev 
libboost-math1.50.0 
libprotobuf7 
libprotobuf-dev 
```
## Runtime requisites:
```
uml-utilities
```

## How to build (Linux):
```
./autogen.sh
./configure --enable-examples
LANG=C make -j3
```

## Build client/server
```
cd source/examples
make sproutbt2
```

## How to build (OS X):
```
cd macosx
./buildsh
```

This fails, SO_BINDTODEVICE does not exist on OS X

## How to run:

Server
```
./src/examples/sproutbt2 qdisc interface_name client_mac
```

Client
```
./src/examples/sproutbt2 ip port qdisc interface_name client_mac
```
