/*  Rm's an error log
 */
#include <lib.h>
inherit LIB_DAEMON;
inherit LIB_HELP;

static void create() {
  daemon::create();
  help::create();
}

mixed cmd(string args) {
  string file;
  if (!sagep(this_player()) && args) {
  args = 0;
   return "Only sages may specify a file.";
  }
  if (!args) {
    file = "/log/errors/" + this_player()->GetKeyName();
    }
  else {
    file = "/log/errors/" + args;
   }
  if (!unguarded( (: file_exists, file :) )) {
    return ("No such file: " + file);
    }
  unguarded( (: rm, file :) );
  message("system", "File removed", this_player());
  return 1;
 }

string GetHelp(string arg) {
  return "Syntax:  rlog <args> \n\n"
          "Removes an error log file.  Only arches may specify an "
          "arg to this, but rlog with no arguments deletes your "
          "realms error log.";
  }
