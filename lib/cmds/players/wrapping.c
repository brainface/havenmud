#include <lib.h>

inherit LIB_DAEMON;
 
mixed cmd(string str)
{
  if (!sizeof(str))
    return "Wrapping is " + (this_player()->GetWrappingMode() ? "on." : "off.");

  str = lower_case(str);
  if (str != "on" && str != "off")
    return "You can only turn wrapping 'on' or 'off'";

  this_player()->SetWrappingMode((str == "on") ? 1 : 0);

  message("system", "Wrapping mode turned " +
    (this_player()->GetWrappingMode() ? "on." : "off."), this_player() );

  return 1;
}

string GetHelp()
{
  return "Syntax: wrapping [on|off]\n"
         "\n"

         "Allows the player to set whether line wrapping is done by the mud.";
}
