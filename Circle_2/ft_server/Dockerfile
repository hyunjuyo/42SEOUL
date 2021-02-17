FROM	debian:buster

RUN		apt-get update && apt-get install -y \
		nginx \
		php-fpm \
		mariadb-server \
		php-mysql \
		wget \
		openssl \
		vim

# self-signed SSL
RUN		openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Gangnam-gu/O=42Seoul/OU=ft_server/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt \
		&& mv localhost.dev.crt /etc/ssl/certs/ \
		&& mv localhost.dev.key /etc/ssl/private/ \
		&& chmod 600 /etc/ssl/certs/localhost.dev.crt /etc/ssl/private/localhost.dev.key

# phpMyAdmin
RUN		wget https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-all-languages.tar.gz \
		&& tar -xvf phpMyAdmin-5.0.4-all-languages.tar.gz \
		&& mv phpMyAdmin-5.0.4-all-languages phpmyadmin \
		&& mv phpmyadmin/ /var/www/html/
COPY	srcs/config.inc.php /var/www/html/phpmyadmin/

# WordPress
RUN		wget https://wordpress.org/latest.tar.gz \
		&& tar -xvf latest.tar.gz \
		&& mv wordpress/ /var/www/html/ \
		&& chown -R www-data:www-data /var/www/html/wordpress/
COPY	srcs/wp-config.php /var/www/html/wordpress/

COPY	srcs/default /etc/nginx/sites-available/
COPY	srcs/run.sh /

EXPOSE	80 443

CMD		bash run.sh
