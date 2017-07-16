/*
 * clear.c
 * Clears a player's terminal
 * Created by Zaxan@Haven
 */

#include <lib.h>

inherit LIB_DAEMON;

int cmd()
{
   message("system", "%^INITTERM%^", this_player());
   return 1;
}

string GetHelp()
{
   return ("Syntax: <clear>\n\n"
           "Clears all text from your terminal screen.");
}

