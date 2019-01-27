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
int ResolveType(string);
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
  int len, bSort, bColor, bAccessible = 0;
  int minLevel, maxLevel;
  int onlyMastered = 0; // -1 nonmastered only, 0 normal, 1 mastered only
  string onlySphere = "";
  string type = "";
  int nType = 0;


  if (angelp(this_player())) return "You don't have any spells, weirdo.";

  if( creatorp(this_player()) ) {
    if (!args) return "Show spell book of whom?";
    who = find_living(explode(args," ")[0]);
    if (!who || who->GetInvis() > rank(this_player()))
      return "Cannot find that person or bad argument.";
  }
  if(creatorp(who)) return "That person can't spell.";
  if(!creatorp(this_player())) who = this_player();

  // assume accessibility mode if command's USER, not TARGET,
  // is in accessibility mode.
  if(this_player()->GetProperty("accessibility_mode")) {
    bAccessible = 1;
  }

  // handle arguments    
  if (args) {
    // handle simple flags
    if (strsrch(args,"-c",) != -1) bColor = 1;
    if (strsrch(args,"-l",) != -1) bSort = 1;
    if (strsrch(args,"-m",) != -1) onlyMastered = 1;
    if (strsrch(args,"-n",) != -1) onlyMastered = -1;
    if (strsrch(args,"-v",) != -1) bAccessible = 0;
    if (strsrch(args,"-a",) != -1) bAccessible = 1;    
    //args = replace_string(args," ","");
    // handle complex arguments
    foreach(string argument in explode(args, "--")) {
      sscanf(argument, "minlevel %d", minLevel);
      sscanf(argument, "maxlevel %d", maxLevel);    
      sscanf(argument, "sphere %(([a-z]+ [a-z]+)|([a-z]+))",onlySphere);     
      if (sscanf(argument, "type %([a-z]+)",type)) {
        nType = ResolveType(type);
        if (!nType) {
          return type + " is not a valid spell type\n" 
            "Valid types are: healing, combat, other, or defense";
        }
      }
    }
  }    

  if (!bAccessible) {
    tmp = "You know the following " + sizeof(who->GetSpellBook())+" ";
    if (bColor) {
      tmp += chealing +"Healing%^RESET%^, "+ccombat+"Combat%^RESET%^, "+cother+
        "Other%^RESET%^,\n";
      tmp += ctimed+"Timed Shield%^RESET%^ and "+cdamage+
        "Damage Shield%^RESET%^ spells:\n";
      tmp += "spell name (spell level) : mastery percent %%/ maximum %%\n";
    } else {
      tmp += " spells:\n";
    }
  } else {
    tmp = "Spells known:\n"; 
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
    
    // handle sphere argument
    if (onlySphere != "") {
      if (resolve_sphere(temp) != onlySphere) {
        continue;
      }
    } else { 
      sphere = resolve_sphere(temp);
    }

    // handle type argument
    if (nType) {
      if(obj->GetSpellType() != nType) continue;        
    }
    
    // handle minlevel argument
    if (minLevel) {
      if(obj->GetSpellLevel() < minLevel) continue; 
    }
    
    // handle maxlevel argument
    if (maxLevel) {
      if(obj->GetSpellLevel() > maxLevel) continue;  
    }
    
    // handle onlyMastered flag
    if (onlyMastered == 1 && who->GetSpellLevel(spell) < 100) {
      continue;
    } else if (onlyMastered == -1 && who->GetSpellLevel(spell) >= 100) {
      continue; 
    }
    
    // if we're doing colors, replace "spell name" with "[pell nam]".
    // this is necessary for finding & recoloring unique spell names.
    // (otherwise "poison sphere" will look funny due to grabbing "sphere's"
    // coloring
    if (bColor) {
      // accessible output can skip table complexity.
      if (bAccessible) { 
        colorspell = spell;
      } else {
        colorspell = sprintf("%:-20s","["+spell[1..<2]+"]");        
      }
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
      if (bAccessible) {
        sorted[sphere] = ({ colorspell }); 
      } else {
        sorted[sphere] = ({ sprintf("%:-20s (%-3d): %:-3d/%-3d%%", colorspell,
          temp->GetSpellLevel(),
          who->GetSpellBook()[spell], GetMaxSpellLevel(who, load_object(temp)))
        });
      }
    } else {
      if (bAccessible) {
        sorted[sphere] += ({ colorspell }); 
      } else {      
        sorted[sphere] += ({ sprintf("%:-20s (%-3d): %:-3d/%-3d%%", colorspell,
          temp->GetSpellLevel(),
          who->GetSpellBook()[spell], GetMaxSpellLevel(who, load_object(temp)))
        });
      }
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
      if (sph) {
        tmp = "In the "+sph+" sphere:\n";
      } else {
        tmp = "In the "+onlySphere+" sphere:\n";        
      }
      // accessible? output
      // skip a lot of stuff, just output text 1 spell/line
      if (bAccessible) {
        this_player()->eventPrint(tmp);
        foreach(string spe in sorted[sph]) {
          if (bColor) {
            spe = colors[spe];
          }
          this_player()->eventPrint(spe);  
        }
        continue;
      }
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
            " -m show only mastered spells (100% trained.)\n\n"
            " -n show only unmastered spells (less than 100% trained.)\n\n"
            " -a force accessible output.\n\n"
            " -v force nonaccessible output.\n\n"
            " --sphere [sphere] show only spells of a certain sphere.\n\n"
            " --type [healing, combat, defense, other]\n"
            "   show only spells of a certain type.\n\n"
            " --minlevel [#} do not show spells below given level.\n\n"
            " --maxlevel [#} do not show spells above given level.\n\n"            
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

// turn plain english spell types
// into haven parsible spell enums
// returns 0 if someone tries to get spelltype fruit or whatever
int ResolveType(string spelltype) {
  if (spelltype == "healing") {
    return SPELL_HEALING;
  } else if (spelltype == "defense") {
    return SPELL_DEFENSE;
  } else if (spelltype == "combat") {
    return SPELL_COMBAT;
  } else if (spelltype == "other") {
    return SPELL_OTHER;      
  } else {
    return 0; 
  } 
}
