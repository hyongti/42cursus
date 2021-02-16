FROM alpine:latest
RUN apk update
RUN apk add mysql mysql-client openrc

# 생성된 컨테이너 안에서 지속적으로 실행해줘야하는 애들을 도커파일에 적으면 안되는 것 같다
# 7~17번 줄을 도커파일에 적었을 때와, setting.sh파일에 적어서 실행했을 때의 결과가 다르다.
# https://wiki.alpinelinux.org/wiki/Mysql 알파인 위키 참고
# RUN /usr/bin/mysql_install_db
# RUN /etc/init.d/mariadb setup
# RUN /etc/init.d/mariadb start 를 경로를 알아서 찾아서 실행해주는 명령어가 rc-service인가 보다.
# RUN openrc 
# # rc-service 명령을 실행하기 위해 openrc를 설치하고 실행해줘야 함
# RUN touch /run/openrc/softlevel
# # 위 파일을 만들어 줘야 rc-service mariacb " "가 실행이 된다.
# RUN mysql_install_db --user=root
# RUN rc-service mariadb setup
# # RUN rc-service mariadb start

COPY /srcs/my.cnf /etc/
COPY /srcs/setting.sh /


# /lib/rc/sh/openrc-run.sh: line 279: can't create /sys/fs/cgroup/cpu/tasks: Read-only file system
# 위와 같은 오류를 방지하기 위해 볼륨 설정
VOLUME ["/sys/fs/cgroup"]

EXPOSE 3306

ENTRYPOINT ["sh", "/setting.sh"]