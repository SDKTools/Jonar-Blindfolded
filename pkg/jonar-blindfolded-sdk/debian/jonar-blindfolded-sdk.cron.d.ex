#
# Regular cron jobs for the jonar-blindfolded-sdk package.
#
0 4	* * *	root	[ -x /usr/bin/jonar-blindfolded-sdk_maintenance ] && /usr/bin/jonar-blindfolded-sdk_maintenance
