#!/bin/bash

cat << EOF >> ~/.bashrc
export PS1="[\u@\h] (\W)
> "

# Aliases
alias ll='ls -al'
alias gb='cd /opt/baldb'
EOF
