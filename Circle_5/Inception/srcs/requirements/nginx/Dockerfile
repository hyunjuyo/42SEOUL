FROM	debian:buster

RUN		apt-get update
RUN		apt-get install -y nginx
RUN		apt-get install -y openssl
RUN		apt-get install -y vim
RUN		apt-get install -y dumb-init

RUN		openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Gangnam-gu/O=42Seoul/OU=ft_server/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
RUN		mv localhost.dev.crt /etc/ssl/certs/ && mv localhost.dev.key /etc/ssl/private/ \
		&& chmod 600 /etc/ssl/certs/localhost.dev.crt /etc/ssl/private/localhost.dev.key

COPY	conf/default /etc/nginx/sites-available/default
COPY	conf/init.sh /tmp/init.sh

# RUN		echo "/ndaemon off;" >> /etc/nginx/nginx.conf

# ENTRYPOINT	["/usr/bin/dumb-init"]

EXPOSE	443

# CMD		["nginx", "-g", "daemon off;"]

CMD		["bash", "/tmp/init.sh"]
