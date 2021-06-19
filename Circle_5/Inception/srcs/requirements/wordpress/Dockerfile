FROM	debian:buster

RUN		apt-get update
RUN		apt-get install -y \
		wget \
		php-fpm \
		php-mysql \
		vim \
		dumb-init

RUN		wget https://wordpress.org/latest.tar.gz \
		&& tar -xvf latest.tar.gz
RUN		chown -R www-data:www-data /wordpress/

COPY	conf/wp-config.php /wordpress/wp-config.php
COPY	conf/php-fpm.conf /etc/php/7.3/fpm/php-fpm.conf
COPY	conf/init.sh /tmp/init.sh

# ENTRYPOINT	["/usr/bin/dumb-init"]

CMD		["bash", "/tmp/init.sh"]

# CMD		["service", "php7.3-fpm", "start"]

# CMD		["php-fpm", "-F", "-R"]
