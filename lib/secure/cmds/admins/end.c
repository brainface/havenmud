/*    /secure/cmds/adm/end.c
 *    from the Dead Souls LPC Library
 *    the command to reboot the MUD
 *    created by Descartes of Borg 950526
 */

#include <lib.h>
#include <daemons.h>

inherit LIB_DAEMON;

mixed cmd(string args) {
    int x;
    int nobackup = 0;

    if( !args || args == "" || trim(args) == "-n") return "You must specify a delay in minutes.";

    if (args[0..1] == "-n")
    {
	nobackup = 1;
	args = args[3..];
    }
    
    if( !(x = to_int(args)) ) return "You must specify a delay in minutes.";
    if( x < 1 ) return "The delay must be at least 1 minutes.";
    REBOOT_D->SetNextReboot(x, nobackup);
    message("system", "Reboot sequence initiated.", this_player());
    return 1;
}

void help() {
    message("help", "Syntax: <end (-n) [delay]>\n\n"
	    "Initiates a reboot sequence which will end in a reboot after "
	    "the specified delay period.  The delay must be specified in "
	    "minutes. The MUD will automatically come back up after using "
	    "this command. Using the '-n' option will cause the backup "
	    "step to be skipped and therefore the MUD will come up much "
	    "quicker.\n\n"
	    "See also: nextreboot, setreboot, shutdown", this_player());
}
