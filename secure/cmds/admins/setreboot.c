#include <lib.h>
#include <daemons.h>

inherit LIB_DAEMON;

int cmd(string str) {
    int x;
message("system", "This command doesn't actually do anything.  K thx bye", this_player() );
return 1;
    if(!str || !archp(previous_object())) return 0;
    sscanf(str, "%d", x);
    x = (int)EVENTS_D->SetRebootInterval(x);
    message("info", "Reboot interval set to "+x+" hours.", this_player());
    return 1;
}

void help() {
    message("help", "Syntax: <setreboot [interval]>\n\n"
      "This command doesn't do anything anymore.  To change the "
      "reboot interval edit the REBOOT_D.",
      this_player()
    );
}
