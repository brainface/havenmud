#!/bin/bash
#
# haven:	Start/Stop HavenMud
#
# chkconfig:	345 25 90
# description:  Start HavenMud on boot and provide arguments for restarting
# 		in easy /etc/init.d/haven [start|stop|restart|status] capacity
#
export  MUDDIR=/home/haven/haven
#LOG="/var/log/mud/start.log"
LOG="/home/haven/start.log"

umask 0010
start() {
	if [ $(/sbin/pidof driver) ]
		then
			printf "HavenMud is already running with PID of $(/sbin/pidof driver).\nPlease restart or stop.\n"
#			echo -e "[`date`] HavenMud is already running with PID of $(/sbin/pidof driver).\n">>$LOG
			exit 1
		else
			if [ -z $(/sbin/pidof addr_server) ]
				then
				$MUDDIR/bin/addr_server 7374&
				sleep 1
				echo -e "[`date`] Starting Address Server with PID $(/sbin/pidof addr_server)." >>$LOG
			fi
            touch $MUDDIR/lib/log/runtime
			$MUDDIR/bin/driver $MUDDIR/bin/haven&
			sleep 1
			echo -e "[`date`] HavenMud started with PID $(/sbin/pidof driver).">>$LOG
			# check if backups need to be run
            # comment out for testmud
			#sh /home/haven/backup.sh&
		
	fi
	}

stop() {
	if [ -z $(/sbin/pidof driver) ]
		then
			printf "Cannot stop $0 as it is not running"
		else
			printf "Killing HavenMud\n"
			echo -e "[`date`] HavenMud shutdown by user $(/usr/bin/whoami)." >>$LOG
			kill $(/sbin/pidof driver)
	fi
	}

restart() {
	stop
	sleep 1
	start
	}
status() {
	if [ -z $(/sbin/pidof driver) ]
		then
		printf "HavenMud is not running.\n"
		else
		printf "HavenMud is Running with PID of $(/sbin/pidof driver)\n"
	fi
	}

case $1 in
	start)
		start
		;;
	stop)
		stop
		;;
	restart)
		stop
		start
		;;
	status)
		status
		;;
	*)
		printf $"Usage: `basename $0` {start|stop|restart|status}\n"
		exit 1
		;;
esac

exit 0

