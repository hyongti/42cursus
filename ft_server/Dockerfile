FROM debian:buster

# UPDATE
RUN apt-get update && apt-get upgrade

# INSTALL
RUN apt-get -y install nginx \
						mariadb-server \
						php7.3-fpm \ 
						php7.3-mysql \
						php-mbstring \
						openssl \
						wget

# COPY FILES
COPY ./srcs ./tmp

# EXPOSE PORT
EXPOSE 80 443

# SET SERVER
CMD bash ./tmp/setting.sh