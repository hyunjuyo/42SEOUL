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
COPY	requirements/wordpress/conf/init.sh /tmp/init.sh

ENTRYPOINT	["/usr/bin/dumb-init"]

CMD		["bash", "/tmp/init.sh"]
