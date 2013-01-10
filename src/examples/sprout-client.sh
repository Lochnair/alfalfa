#! /bin/bash

if [ $# -lt 2 ] ; then
  echo "Enter address and port of relay "
  exit;
fi
relay_address=$1
relay_port=$2

set -x
sudo tunctl -t tap0
sudo ifconfig tap0 10.0.0.1 netmask 255.255.255.0 up
sudo route add default gw 10.0.0.2 metric 2 # ensure eth0 is preferred to tap0
sudo ./sproutbt2 $relay_address $relay_port
