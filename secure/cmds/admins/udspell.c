/* Spells reloading command */
#include <lib.h>
#include <dirs.h>
#include <daemons.h>
inherit LIB_DAEMON;

mixed cmd(string useless) {
  string *dirs = ({ });
  string *spells = ({ });
  
  dirs = get_dir(DIR_SPELLS + "/");
  
  foreach(string dir in dirs) {
    this_player()->eventPrint("Reloading DIR_SPELLS /" + dir + "/*");
    spells = get_dir(DIR_SPELLS + "/" + dir + "/");
    foreach(string spell in spells) {
      object sp;
      spell = spell[0..<3];
      sp = find_object(DIR_SPELLS + "/" + dir + "/" + spell);
      if (!sp) continue;
      sp->eventDestruct();
      this_player()->eventPrint("Destructed object " + DIR_SPELLS + "/" + dir + "/" + spell);
    }
  }
  SPELLS_D->eventReloadSpells();
  this_player()->eventPrint("Reloaded Spells");
  return 1;
}

string GetHelp(string s) {
  return "Reloads the spells.  Woot.";
}
