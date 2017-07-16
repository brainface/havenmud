#~!/bin/bash

#AutoStart Mud and Check to do backups or not

MUDNAME="Haven-FluffOS"
MUDDIR="/home/haven/haven"

BACKUPDIR="/home/haven/backups"
BACKUPYEAR="$BACKUPDIR/yearly"
BACKUPMONTH="$BACKUPDIR/monthly"
BACKUPWEEK="$BACKUPDIR/weekly"

#Command Variables

#doBackup() {
#	echo "Tar File: "$BACKUPDIR/$MUDNAME"_backup_"`date +%Y%m%d`".tar.bz2"
#	echo "Tar Source: $MUDDIR"

#	tar cjvf "$BACKUPDIR/$MUDNAME"_backup_"`date +%Y%m%d`".tar.bz2 $MUDDIR
#
#}

#if [ "$(ls -A $BACKUPDIR)" ]
#	then
#		echo "We're not empty, let's roll"
#		doBackup
#	else
		#check if newest backup is older than a week
		if [ "$(find $BACKUPDIR -maxdepth 1 -type f -mtime -7)" ]
			then
				echo "We have a backup from less than a week ago. Not backing up."
			else
				echo "Newest backup is older than a week. We're backing up"
				#doBackup
				echo "Done"
		fi
#fi
		
# Start the Actual Mud and the addr_server

$MUDDIR/bin/addr_server 7374
$MUDDIR/bin/driver $MUDDIR/bin/haven


