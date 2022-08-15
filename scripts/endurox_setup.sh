#!/bin/bash

# Help info
HELP="Attantion! Run this script as not root user. Because you may not acces provision from endurox or postgres users"

echo $HELP

# Download EnduroX
wget https://www.endurox.org/attachments/download/endurox-8.0.4-1.centos6_9_GNU_epoll.x86_64.rpm

# Install enduro
sudo rpm -i endurox-8.0.4-1.centos6_9_GNU_epoll.x86_64.rpm

# Generate provision
xadmin provision -d \
    -v qprefix=baldb \
    -v installQ=n  \
    -v eventSv=n \
    -v cpmSv=n \
    -v configSv=n \
    -v bridge=n \
    -v addubf=bank.fd
