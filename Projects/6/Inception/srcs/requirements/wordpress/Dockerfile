FROM debian:stable-slim


RUN apt-get update && apt-get upgrade -y

RUN apt-get install php-fpm php-mysql php-mbstring php-xml php-gd php-curl php-zip procps iproute2 wget zip -y

WORKDIR /var/www/
RUN wget https://wordpress.org/latest.zip
RUN unzip latest.zip -d ./html
RUN mv ./html/wordpress/* ./html
COPY ./conf/wp-config.php ./html/wp-config.php
RUN rm -rf latest.zip ./html/wordpress

WORKDIR /
COPY ./conf/php-fpm/www.conf /etc/php/8.4/fpm/pool.d/
COPY ./conf/php-fpm/php-fpm.conf /etc/php/8.4/fpm/

RUN chown -R www-data:www-data /var/www/html/

CMD [ "php-fpm8.4", "-F" ]