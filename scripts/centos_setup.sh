#!/bin/bash

# Go to the /etc/yum.repos.d/ directory.
cd /etc/yum.repos.d/

# Run the below commands
sed -i 's/mirrorlist/#mirrorlist/g' /etc/yum.repos.d/CentOS-*
sed -i 's|#baseurl=http://mirror.centos.org|baseurl=http://vault.centos.org|g' /etc/yum.repos.d/CentOS-*

# Now run the yum update
yum update -y

# Go back
cd -

# Install tools
yum install cmake gcc sudo passwd wget

# Add user
useradd endurox
usermod -aG wheel endurox
