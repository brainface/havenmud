/*    /daemon/spells.c
 *    From Nightmare LPMud
 *    created by Descartes of Borg 961027
 *    Version: @(#) spells.c 1.2@(#)
 *    Last modified: 96/10/28
 */

#include <lib.h>
#include <magic_protection.h>
#include <dirs.h>
#include <std.h>
#include <magic.h>
#include <daemons.h>

inherit LIB_DAEMON;

private mapping Spells = ([]);
private string *DamagingShields = ({});

void eventReloadSpells();

static void create() {
    daemon::create();
    SetNoClean(1);
    eventReloadSpells();
    SPELL_LIST_D->eventReport();
}

void eventReloadSpells() {
    string *dirs = ({ });
    string *spells = ({ });

    Spells = ([]);
    DamagingShields = ({});
    dirs = get_dir(DIR_SPELLS + "/");
    foreach(string dir in dirs) {
      spells = get_dir(DIR_SPELLS + "/" + dir + "/*.c");
        foreach(string spell in spells) {
      object ob = find_object(DIR_SPELLS + "/" + dir + "/" + spell);
	
	if( ob ) {
	    ob->eventDestruct();
	}
  if (ob = load_object(DIR_SPELLS + "/" + dir + "/" + spell) ) {
	    spell = ob->GetSpell();
	    if( spell ) {
		Spells[spell] = ob;
                if (ob->GetDamagingShield()) {
                    DamagingShields += ({ spell });
                   }
	    }
	}
    }
  }
}

object GetSpell(string spell) {
    if( !Spells[spell] ) {
	eventReloadSpells();
    }
    return Spells[spell];
}

string *GetSpells() {
   return (keys(Spells));
   }


string *GetDamagingShields() {
  return DamagingShields;
}

int GetDamagingShield(object who) {
   foreach(class MagicProtection shield in who->GetMagicProtection() ) {
    if (member_array(shield->name, GetDamagingShields()) != -1) return 1;
     }
  return 0;
}

string GetSpellSphere(string spell) {
  if (!GetSpell(spell)) { return 0; }
  return (resolve_sphere(base_name(GetSpell(spell))));
}

string *GetSphereSpells(string sphere) {
  string dir = unresolve_sphere(sphere);
  string *tmp = ({ }), *ret = ({});

  tmp = get_dir(dir + "/");
  if (!tmp) tmp = ({ });
  foreach(string spell in tmp) {
      if(spell[<2..] != ".c") continue;
    if (!(string)(dir + "/" + spell)->GetUniqueSpell()) 
       ret += ({ (dir + "/" + spell)->GetSpell()  });
     }
  return ret;
}

string *GetSpheres() {
	string *tmp = get_dir(DIR_SPELLS + "/");
	
	tmp -= ({ "test_spells", "obj" });
	return tmp;
}


