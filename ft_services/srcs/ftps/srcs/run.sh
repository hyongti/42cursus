#!/bin/bash

mkdir -p /ftps/hyeonkim
adduser --home=/ftps/hyeonkim -D hyeonkim

echo "hyeonkim:0000" | chpasswd
echo "hyeonkim" >> etc/vsftpd/vsftpd.userlist

touch /var/log/vsftpd.log

mkdir -p /etc/ssl/private
openssl req -x509 -nodes -days 365 -newkey rsa:4096 -keyout /etc/ssl/private/vsftpd.pem -out /etc/ssl/private/vsftpd.pem -config etc/ssl/private/openssl.conf

telegraf &
/usr/sbin/vsftpd /etc/vsftpd/vsftpd.conf