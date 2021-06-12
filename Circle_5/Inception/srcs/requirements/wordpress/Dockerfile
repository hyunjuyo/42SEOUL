FROM	debian:buster

RUN		apt-get update
RUN		apt-get install -y \
		wget \
		php-fpm \
		vim

RUN		wget https://wordpress.org/latest.tar.gz \
		&& tar -xvf latest.tar.gz
RUN		chown -R www-data:www-data /wordpress/
