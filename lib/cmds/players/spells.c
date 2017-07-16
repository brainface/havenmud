/*    /cmds/player/spells.c
 *    From Nightmare LPMud
 *    created by Descartes of Borg 961028
 *    Version: @(#) spells.c 1.3@(#)
 *    Modified by Zedd@Haven on Jan17, 1999 to alphabetize the list of spells
 *    Sorted listing option added by Zaxan@Haven (25-Feb-2000)
 *    MOdified by Mahkefel@Haven on JanSom'n, 2011 to color
 */

#include <lib.h>
#include <daemons.h>
#include <magic.h>

inherit LIB_DAEMON;
int GetMaxSpellLevel(object, object);
int SortByLevel(string, string);
// bold here actually adds a lot to the command's output length, and
// that is bad. (command can runtime.)
string chealing = "%^GREEN%^";
string ccombat = "%^RED%^";
string cother = "%^CYAN%^";
string ctimed = "%^YELLOW%^";
string cdamage = "%^BOLD%^MAGENTA%^";

mixed cmd(string args) {
  object who;
  string *spells = ({ });
  mapping sorted = ([ ]);
  mapping colors = ([ ]);
  string tmp, spell_list;
  int len, bSort, bColor = 0;

  if (angelp(this_player())) return "You don't have any spells, weirdo.";

  if (args) {
  // handle flags
  if (member_array("-c",explode(args," ")) != -1) {
    bColor = 1;
    args = replace_string(args,"-c","");
  }
  if (member_array("-l",explode(args," ")) != -1) {
    bSort = 1;
    args = replace_string(args,"-l","");
  }
  args = replace_string(args," ","");
  }

  if( creatorp(this_player()) ) {
    if (!args) return "Show spell book of whom?";
    who = find_living(args);
    if (!who || who->GetInvis() > rank(this_player()))
      return "Cannot find that person or bad argument.";
  }
  if(creatorp(who)) return "That person can't spell.";
  if(!creatorp(this_player())) who = this_player();
  
  if (bColor) { 
    tmp = "You know the following " + sizeof(who->GetSpellBook())+" ";
    tmp += chealing +"Healing%^RESET%^, "+ccombat+"Combat%^RESET%^, "+cother+"Other%^RESET%^,\n";
    tmp += ctimed+"Timed Shield%^RESET%^ and "+cdamage+"Damage Shield%^RESET%^ spells:\n";
    tmp += "spell name (spell level) : mastery percent %%/ maximum %%\n";
  } else {
    tmp = "You know the following " + sizeof(who->GetSpellBook())+" spells:\n";
  }

  if (bSort) {
    spells = sort_array(keys(who->GetSpellBook()), (: SortByLevel :) , 1);
  } else {
    spells = sort_array(keys(who->GetSpellBook()),1);
  }
  foreach(string spell in spells)       {
    object obj = SPELLS_D->GetSpell(spell);
    string temp = base_name(obj);
    string sphere;
    string colorspell;

    if (undefinedp(obj)) continue;
    sphere = resolve_sphere(temp);

    // if we're doing colors, replace "spell name" with "[pell nam]".
    // this is necessary for finding & recoloring unique spell names.
    // (otherwise "poison sphere" will look funny due to grabbing "sphere's"
    // coloring
    if (bColor) {
      colorspell = sprintf("%:-20s","["+spell[1..<2]+"]");
      if(obj->GetSpellType() == SPELL_HEALING) {
        colors[colorspell] =
          chealing + sprintf("%:-20s",spell) + "%^RESET%^";
      } else if ( obj->GetSpellType() == SPELL_COMBAT ) {
        colors[colorspell] =
          ccombat + sprintf("%:-20s",spell) + "%^RESET%^";
      } else if ( obj->GetSpellType() == SPELL_OTHER ) {
        colors[colorspell] =
          cother + sprintf("%:-20s",spell) + "%^RESET%^";
      } else if ( obj->GetSpellType() == SPELL_DEFENSE ) {
        if ( obj->GetShieldType() == SHIELD_TIMED) {
          colors[colorspell] =
            ctimed + sprintf("%:-20s",spell) + "%^RESET%^";
        } else {
          colors[colorspell] =
            cdamage + sprintf("%:-20s",spell) + "%^RESET%^";
        }
      }
    } else {
        colorspell = spell;
    }
    if(!sorted[sphere]) {
      sorted[sphere] = ({ sprintf("%:-20s (%-3d): %:-3d/%-3d%%", colorspell,
        temp->GetSpellLevel(),
        who->GetSpellBook()[spell], GetMaxSpellLevel(who, load_object(temp))) });
    } else {
      sorted[sphere] += ({ sprintf("%:-20s (%-3d): %:-3d/%-3d%%", colorspell,
        temp->GetSpellLevel(),
        who->GetSpellBook()[spell], GetMaxSpellLevel(who, load_object(temp))) });
    }
  }

  // Mahkefel 2011: i split the command into several eventPrints, cuz the 
  // command, even before mods, had a real threat of runtimes due to output
  // size on chars with crazy spells (like test characters)
  this_player()->eventPrint(tmp);
  if(!sizeof(keys(sorted)))       {
    tmp = "You know no spells.";
    this_player()->eventPrint(tmp);
  } else {
    foreach(string sph in keys(sorted)) {
      tmp = "In the "+sph+" sphere:\n";
      foreach(string spe in sorted[sph]) {
        int i = strlen(spe);
        if(i > len) {
          len = i;
        }
      }
      len = ((this_player()->GetScreen())[0]+2)/(len+2);
      tmp += format_page(sorted[sph], len);
      if (bColor) {
        // this shit just got real
        foreach (string spell in keys(colors)) {
          tmp = replace_string(tmp, spell, colors[spell]);
        }
      }
      this_player()->eventPrint(tmp);
    }
  } 
  return 1;
}

string GetHelp() {
    return ("Syntax: <spells>\n\n"
            "Lists all of your spells in your spell book with your "
            "proficiency in each spell. These arguments are available:\n\n"
            " -c display color highlights on spells.\n\n"
            " -l sort spells by spell level.\n\n"
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

int SortByLevel(string spell1, string spell2) {
  object oSpell1 = SPELLS_D->GetSpell(spell1);
  object oSpell2 = SPELLS_D->GetSpell(spell2);

  // handle renamed spells w/o crashing
  if (!oSpell1) {
    return -1;
  } else if (!oSpell2) {
    return 1;
  }

  if (oSpell1->GetSpellLevel() > oSpell2->GetSpellLevel()) {
    return 1;
  } else if (oSpell1->GetSpellLevel() < oSpell2->GetSpellLevel()) {
    return -1;
  } else {
    return 0;
  }
}

