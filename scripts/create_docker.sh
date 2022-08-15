#!/bin/bash

docker pull centos

docker run -itd --privileged -v ~/Projects/balance_db:/opt/baldb --name="EnduroX" centos:latest /usr/sbin/init
