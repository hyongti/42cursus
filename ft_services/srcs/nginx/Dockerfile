FROM alpine:latest

RUN apk update 
RUN apk add --no-cache nginx
RUN apk add openssl
RUN adduser -D -g 'www' www
RUN mkdir /www
RUN chown -R www:www /var/lib/nginx
RUN chown -R www:www /www

RUN openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Gon/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
RUN mv localhost.dev.crt etc/ssl/certs/
RUN mv localhost.dev.key etc/ssl/private/
RUN chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

COPY /srcs/nginx.conf /etc/nginx/nginx.conf
COPY /srcs/index.html /www/index.html
# COPY /srcs ./tmp

ENTRYPOINT ["nginx"]

EXPOSE 80 443

CMD ["-g", "daemon off;"]

# CMD sh setting.sh