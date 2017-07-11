/*
 * bell.c
 * Sends a beep to the given player's computer
 * Created by Zaxan@Haven
 */

#include <lib.h>

inherit LIB_DAEMON;

int cmd(string str)
{
   if(!str)
   {
      message("system", "Bell whom?", this_player());
      return 1;
   }
   if(!find_living(str) || (find_living(str)->GetInvis() && !archp(this_player())))
   {
      message("system", "Unable to find a player by that name.", this_player());
      return 1;
   }
   message("system", this_player()->GetName()+" throws a bell at you. Bing!\a",
           find_living(str));
   message("system", "You bell "+find_living(str)->GetName()+".", this_player());
   return 1;
}

string GetHelp(string blah)
{
   return "Syntax: <bell [user]>\n\n"
          "This command sends a short beep to the specified user.\n"
          "Do not abuse this command.\n\n"
          "See also: wizhelp";
}
