#! bin/sh
 
# https://wiki.alpinelinux.org/wiki/Mysql 알파인 위키 참고
# /usr/bin/mysql_install_db
# /etc/init.d/mariadb setup
# /etc/init.d/mariadb start 를 경로를 알아서 찾아서 실행해주는 명령어가 rc-service인가 보다.
openrc 
# rc-service 명령을 실행하기 위해 openrc를 설치하고 실행해줘야 함
touch /run/openrc/softlevel
# 위 파일을 만들어 줘야 rc-service mariacb " "가 실행이 된다.
mysql_install_db --user=root
rc-service mariadb setup
# RUN rc-service mariadb start

rc-service mariadb start
# restart를 하지 않으면 mysql -u root가 실행이 안 된다. 이유는 모르겠다ㅠㅠ.

echo "FLUSH PRIVILEGES;" | mysql -u root

echo "CREATE DATABASE wordpress;" | mysql -u root

echo "CREATE USER 'hyeonkim'@'%' identified by '0000';" | mysql -u root

echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'hyeonkim'@'%';" | mysql -u root

echo "FLUSH PRIVILEGES;" | mysql -u root

mysqld