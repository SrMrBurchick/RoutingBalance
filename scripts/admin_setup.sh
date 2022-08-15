#!/bin/bash

sudo -s << EOF
    # Increase OS limits
    cat << EOF >> /etc/security/limits.conf

    # Do not limit message Q Count.
    # Some Linux 3.x series kernels have a bug, that limits 1024
    # queues for one system user.
    # In 2.6.x and 4.x this is fixed, to have
    # unlimited count of queues (memory limit).
    # ealrier and later Linuxes have fixed this issue.
    *               soft    msgqueue        -1
    *               hard    msgqueue        -1

    # Increase the number of open files
    *               soft    nofile  1024
    *               hard    nofile  65536

    EOF

    # Setting Posix queue limits
    cat << EOF >> /etc/sysctl.conf

    # Max Messages in Queue
    fs.mqueue.msg_max=10000

    # Max message size, to pass unit tests, use 1M+1K
    fs.mqueue.msgsize_max=1049600

    # Max number of queues system-wide
    fs.mqueue.queues_max=10000

    EOF

    # Setting System V queue limits
    cat << EOF >> /etc/sysctl.conf

    # max queues system wide, 32K should be fine
    # If more is required, then for some Linux distributions such as Ubuntu 20.04
    # kernel boot parameter ipcmni_extend shall be set.
    kernel.msgmni=32768

    # max size of message (bytes), ~1M should be fine
    kernel.msgmax=1049600

    # default max size of queue (bytes), ~10M should be fine
    kernel.msgmnb=104960000

    EOF
EOF

# Apply changed parameters
sudo sysctl -f /etc/sysctl.conf
