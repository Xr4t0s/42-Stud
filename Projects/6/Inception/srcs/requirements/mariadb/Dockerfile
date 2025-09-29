FROM debian:stable-slim

RUN apt-get update && apt-get upgrade -y

RUN apt install mariadb-server -y

RUN mkdir -p /run/mysqld
RUN chown -R mysql:mysql /run/mysqld

COPY ./tools/init.sh /tmp
RUN bash /tmp/init.sh

# CMD ["tail", "-f"]
CMD ["mariadbd", "--user=mysql", "--datadir=/var/lib/mysql", "--socket=/run/mysqld/mysqld.sock", "--bind-address=0.0.0.0"]