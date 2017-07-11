//      /bin/dev/_invis.c
//      from the Dead Souls mudlib
//      created by Descartes of Borg october 1992
// Modified for Ranks.  Duuk@Haven

#include <lib.h>

inherit LIB_DAEMON;

varargs mixed cmd(string str)
{
  string msg = this_player()->GetMessage("invis");
  int level = to_int(str);
  if (!str) { 
    if (this_player()->GetInvis() == 0) {
      this_player()->eventPrint("You're visible.");
      return 1;
      }
    this_player()->eventPrint("Current invis level is: "  
       + string_rank(this_player()->GetInvis()) + " (" + this_player()->GetInvis() + ")." );
    return 1;
  }
  this_player()->SetInvis(level);
  this_player()->eventPrint("Invis level set to " + string_rank(this_player()->GetInvis()) + " (" + this_player()->GetInvis() + ").");
  environment(this_player())->eventPrint(msg, this_player());
   return 1;
}

string GetHelp(string blah) {
  return "Syntax: <invis>\n"
         "        <invis [level]>\n\n"
         "Without argument, this command will show you your current "
         "invis level. With argument, this command will make you invis "
         "to that level. The levels you are able to use are determined "
         "by your immortal ranking. Avaliable levels:\n"
         "Duuk - 9       Admin - 8      Secure - 7       Assist - 6\n"
         "Sage - 5       Spirit - 4     Imm - 3          Angel - 2\n"
         "You can chose any numerical level avaliable to you and will "
         "be visible on people to anyone of that rank or higher. You "
         "will remain visible on who as 'a presence', unless you use "
         "whoinvis. Note invis level 1 is used for mortal skills.\n\n"
         "See also: whoinvis, vis";
}
