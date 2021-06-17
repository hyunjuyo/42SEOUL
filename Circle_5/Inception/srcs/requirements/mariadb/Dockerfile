FROM	debian:buster

RUN		apt-get update
RUN		apt-get install -y \
		mariadb-server \
		php-mysql \
		vim \
		dumb-init

# COPY	conf/init.sh /tmp/init.sh
COPY	requirements/mariadb/conf/init.sh /tmp/init.sh

ENTRYPOINT	["/usr/bin/dumb-init"]

CMD		["bash", "tmp/init.sh"]
