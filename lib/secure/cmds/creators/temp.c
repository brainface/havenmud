#include <lib.h>
#include <std.h>

mixed cmd(string args) {
  string templ = STD_ROOM "template.c";
  object who = this_player();
  
  if (!args) {
    who->eventPrint("Copy a template room to which file in this directory?");
    return 1;
  }
  args = who->query_cwd() + "/" + args;
  if (strsrch(args, "domains") == -1) {
    who->eventPrint("Can't copy files to a non-domains dir.");
    return 1;
  }
  cp(templ, args);
  if (file_size(args) > -1) {
    who->eventPrint("Created file " + args + " from a template room.");
    return 1;
  }
  who->eventPrint("You managed to fuck that up somehow.");
  who->eventPrint("Failed to create file " + args + " from a template room.");
  return 1;
}

string GetHelp(string u) {
 return "Syntax:   temp <string args>\n\n"
        "Copies the STD_ROOM template.c to <args> in your current working directory.";
}