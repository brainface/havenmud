/*  trans cmd
 */
#include <lib.h>
inherit LIB_DAEMON;
inherit LIB_HELP;
mixed eventTrans(object, object);

mixed cmd(string args) {
  string *words;
  object ob, dest;

  if (angelp(this_player())) { return 0; }
  if (!args) { return "Trans who?  to who?  or where?"; }
  words = explode(args, " ");
  if (!sizeof(words)) {
     return "Trans who to where?";
    }
  if (sizeof(words) == 1) {
    if (!(ob = find_living(words[0]))) {
     return "Unable to find such a person!";
     }
   if (rank(ob) > rank(this_player())) return "You can't trans that.";
   return eventTrans(ob, environment(this_player()));
  }
  if (sizeof(words) == 3) {
    if (!(ob = find_living(words[0]))) {
     return "Unable to find such a person!";
      }
    if (!(dest = find_living(words[2])))
     if (!(dest = find_object(words[2]))) {
       if (!(dest = load_object(words[2]))) {
          return "Unable to find/load such an object.";
          }
        }
     if (living(dest)) dest = environment(dest);
     return eventTrans(ob, dest);
    }
  return "General failure in mixed cmd() in trans.c";
  }

mixed eventTrans(object who, object where) {
   if (who->eventMoveLiving(where)) {
    message("system", "Trans successful.", this_player() );
    return 1;
  }
 return "Failure to move specified object in eventTrans in trans.c";
  }

string GetHelp(string args) {
  return "Syntax:  trans WHO to WHAT \n"
         "         trans WHO \n"
         "         trans WHO to WHO \n"
         "Moves a specified target to a new location (by filename), "
         "person (by name), or with no args, to yourself.";
    }
