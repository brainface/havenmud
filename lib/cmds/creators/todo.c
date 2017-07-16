// Proximo@Via Imperialis
// 06/02/2003

#include <lib.h>
#include <daemons.h>

inherit LIB_DAEMON;

static void Todo();

static void create() {
  daemon::create();
  SetNoClean(1);
}


mixed cmd() {
  Todo();
  return 1;
}

static void Todo() {
  string file;
  file = "/realms/" + (string)this_player()->GetKeyName() + "/todo";

     message("", "Todo Editing Initiated. When done, enter a period "
          "on a line by itself.", this_player());
     this_player()->eventEdit(file);
  return;
}

string GetHelp(string str) {
  string tmp;

  tmp = "Syntax: <todo>\n";
  tmp += "\n";
  tmp += "This command is used for putting the user into an editing mode of "
     "their \"Todo\" file. ";
  return tmp;
}
