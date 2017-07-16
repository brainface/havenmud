/*    /cmds/player/spells.c
 *    From Nightmare LPMud
 *    created by Descartes of Borg 961028
 *    Version: @(#) spells.c 1.3@(#)
 *    Modified by Zedd@Haven on Jan17, 1999 to alphabetize the list of spells
 */

#include <lib.h>

inherit LIB_DAEMON;

mixed cmd(string args) {
  object who;
  string *spells = ({ });
  string tmp;
  int len;
  
  if( creatorp(this_player()) ) {
    if (!args) return "Show combat styles of whom?";
    who = find_living(args);
    if (!who) return "Cannot find that person.";
  }

  if(creatorp(who)) return "That person has no style.";
  tmp = "You know the following combat styles:\n";
  if(!creatorp(this_player())) who = this_player();


  foreach(string spell in sort_array(keys(who->GetCombatStyles()), 1)) {
    spells += ({ sprintf("%:-20s: %:-3d%%", spell, 
                 who->GetCombatStyleLevel(spell) ) });
  }

  if (!sizeof(spells)) {
    tmp += "You know no combat styles.";
  } else {
    foreach(string spell in spells) {
      int i = strlen(spell);
      if( i > len ) {
        len = i;
      }
    }
    len = (this_player()->GetScreen())[0]/(len+2);
    tmp += format_page(spells, len);
  }
  this_player()->eventPrint(tmp);
  return 1;
}

string GetHelp() {
    return ("Syntax: <styles>\n\n"
            "Lists all of the combat styles you specialize in, along with "
        "your proficiency in each. See <help set> to learn about how to "
        "use combat styles.\n\n"
            "See also: set, skills, stats, status");
}
