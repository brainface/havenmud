/*    /cmds/player/spells.c
 *    From Nightmare LPMud
 *    created by Descartes of Borg 961028
 *    Version: @(#) spells.c 1.3@(#)
 *    Modified by Zedd@Haven on Jan17, 1999 to alphabetize the list of spells
 *    Sorted listing option added by Zaxan@Haven (25-Feb-2000)
 */

#include <lib.h>
#include <daemons.h>

inherit LIB_DAEMON;
int GetMaxSpellLevel(object, object);

mixed cmd(string args) {
    object who;
    string *spells = ({ });
    mapping sorted = ([ ]);
    string tmp, spell_list;
    int len, sort_flag = 0;

    if (angelp(this_player())) return "You don't have any spells, weirdo.";

  if( creatorp(this_player()) ) {
	if (!args) return "Show spell book of whom?";
	who = find_living(args);
	if (!who || who->GetInvis() > rank(this_player())) 
	    return "Cannot find that person.";
    }
  if(creatorp(who)) return "That person can't spell.";
  if(!creatorp(this_player())) who = this_player();
  tmp = "You know the following " + sizeof(who->GetSpellBook()) + " spells:\n"; 
  tmp += "spell name (spell level) : mastery percent %%/ maximum %%\n";    
	foreach(string spell in sort_array(keys(who->GetSpellBook()), 1))	{
	    string temp = base_name(SPELLS_D->GetSpell(spell));
	    string sphere;
	    
	    if (undefinedp(SPELLS_D->GetSpell(spell))) continue;
	    sphere = resolve_sphere(temp);
	    if(!sorted[sphere]) {
		    sorted[sphere] = ({ sprintf("%:-20s (%-3d): %:-3d/%-3d%%", spell, temp->GetSpellLevel(), who->GetSpellBook()[spell], GetMaxSpellLevel(who, load_object(temp))) });
	      } else {
		    sorted[sphere] += ({ sprintf("%:-20s (%-3d): %:-3d/%-3d%%", spell, temp->GetSpellLevel(), who->GetSpellBook()[spell], GetMaxSpellLevel(who, load_object(temp))) });
	    }
	}
	if(!sizeof(keys(sorted)))	{
	  tmp += "You know no spells.";
	  }	else {
	  foreach(string sph in keys(sorted)) {
		  tmp += "In the "+sph+" sphere:\n";
		  foreach(string spe in sorted[sph]) {
		    int i = strlen(spe);
		    if(i > len) {
			    len = i;
		      }
		    }
		len = (this_player()->GetScreen())[0]/(len+2);
		tmp += format_page(sorted[sph], len);
		tmp += "\n";
	    }
	}
    this_player()->eventPrint(tmp);
    return 1;
}

string GetHelp() {
    return ("Syntax: <spells>\n\n"
	    "Lists all of your spells in your spell book with your "
	    "proficiency in each spell. \n\n"
	    "See also: skills, stats, status");
}

int GetMaxSpellLevel(object who, object spell) {
  int x = 100;
  int y;
  foreach(string skill in spell->GetSkills()) {
     y = 5 * (who->GetSkillLevel(skill) - spell->GetRequiredSkill(skill)) + 5; 
     if (y < x) x = y;
  }
  return x;
}