#
# Regular cron jobs for the jonar-blindfolded-runtime package.
#
0 4	* * *	root	[ -x /usr/bin/jonar-blindfolded-runtime_maintenance ] && /usr/bin/jonar-blindfolded-runtime_maintenance
