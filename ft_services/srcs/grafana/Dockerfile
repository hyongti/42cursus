FROM 	alpine:3.12

RUN     apk update
RUN     apk add wget


RUN     apk add libc6-compat
RUN     apk add supervisor
RUN     wget https://dl.grafana.com/oss/release/grafana-7.1.5.linux-amd64.tar.gz
RUN     tar -zxvf grafana-7.1.5.linux-amd64.tar.gz
RUN     mkdir -p /etc/telegraf

COPY    /srcs/telegraf.conf /etc/telegraf/
COPY    /srcs/run.sh        .
COPY    /srcs/grafana.db   /grafana-7.1.5/data/grafana.db

CMD     sh run.sh

EXPOSE  3000
