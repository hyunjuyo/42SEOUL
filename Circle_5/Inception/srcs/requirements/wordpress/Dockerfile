FROM	debian:buster

RUN		apt-get update
RUN		apt-get install -y \
		wget \
		php-fpm \
		vim \
		dumb-init

RUN		wget https://wordpress.org/latest.tar.gz \
		&& tar -xvf latest.tar.gz
RUN		chown -R www-data:www-data /wordpress/

COPY	requirements/wordpress/conf/wp-config.php /wordpress/wp-config.php

# ENTRYPOINT	["/usr/bin/dumb-init"]
