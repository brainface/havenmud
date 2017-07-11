/* Whoinvis */
#include <lib.h>
inherit LIB_DAEMON;
inherit LIB_HELP;

mixed cmd(string setting) {
  if (!setting) {
      message("system",
         "Your current WhoInvis setting is: " + 
          (this_player()->GetWhoInvis() ? "on" : "off") + ".", 
          this_player() );
        return 1;
    }
  switch(setting) {
    case "on":
        this_player()->SetWhoInvis(1);
        message("system", "You are now invis on who.", this_player() );
        break;
    case "off":
        message("system", "You are now vis on who.", this_player() );
        this_player()->SetWhoInvis(0);
        break;
    default:
          message("system", "You must \"whoinvis on\" or \"whoinvis off\".",
            this_player() );
          break;
      }
   return 1;
}

string GetHelp(string x) {
   return "Syntax:      \"whoinvis on|off|<none>\"\n\n"
          "This command shows your current whoinvis state with no args, "
          "or sets your whoinvis state.";
}
