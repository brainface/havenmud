/*    /cmds/player/screen.c
 *    from the Foundation II LPC Library
 *    sets width and height for player terminals
 *    created by Descartes of Borg 950328
 */

#include <lib.h>

inherit LIB_DAEMON;

int cmd(string args)
{
  object who = this_player();
  int w = who->GetScreen()[0];
  int h = who->GetScreen()[1];

  if (!args)
  {
    who->eventPrint(sprintf("%d, %d", w, h));
    return 1;
  }
  if (sscanf(args, "%d %d", w, h) != 2)
  {
    who->eventPrint("You need to specify both width and height.");
    return 1;
  }
  who->SetScreen(w, h);
  message("system", "Screen set to " + w + " by " + h + ".", who);
  return 1;
}

void help()
{
    message("help", "Syntax: <screen [width] [height]>\n\n"
	    "Sets the dimensions of your computer screen so that " +
	    mud_name() + " knows how to send information to your screen.\n\n"
	    "See also: brief, terminal", this_player());
}
