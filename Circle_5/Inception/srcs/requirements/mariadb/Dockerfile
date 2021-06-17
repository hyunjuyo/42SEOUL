FROM	debian:buster

RUN		apt-get update
RUN		apt-get install -y \
		mariadb-server \
		php-mysql \
		vim \
		dumb-init

RUN		service mysql start

COPY	requirements/mariadb/conf/init.sh /tmp/init.sh

# ENTRYPOINT	["/usr/bin/dumb-init"]

CMD		["/bin/bash", "-c", "bash tmp/init.sh"]
