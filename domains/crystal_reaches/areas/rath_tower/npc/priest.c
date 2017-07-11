
/*  Priest Guy for Rath's Tower.
 *  Will be a Leader for kicks.
 */
#include <lib.h>
#include <std.h>
#include "../rath.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("vengeful priest");
  SetShort("a priest of Rath's Cult");
  SetId( ({ "priest" }) );
  SetAdjectives( ({ "vengeful" }) );
  SetMorality(-600);
  SetRace("elf");
  SetUndead(1);
  SetUndeadType("skeleton");
  RemoveLanguage("Eltherian");
  SetLanguage("Archaic", 100, 1);
  SetAction(6, ({
      "!speak Join us!  Convert!",
      "!speak If you join us, I can teach you many things!",
      "!speak Rath Khan is the True Lord of Kailie!",
    	}) );
  SetCombatAction(20, ({ 
  		"!cast jolt",
      "!cast hellfire",
      "!cast aegis of the faithful",
      }) );
  SetUniqueSkills( ([
      ]) );
  SetLong("This priest is a large imposing figure that could easily "
          "be described as truly evil.  From the hideous gleam in his "
         "eyes, one can only hope he is in a good mood.");
  SetClass("priest");
  SetLevel(30);
  SetCurrency( ([
     "imperials" : 1000,
     ]) );
  SetInventory( ([
     TOWER_O + "/priest_mace" : "wield mace",
     TOWER_O + "/chain" : "wear chainmail",
    ]) );
  SetPlayerTitles( ([
     "newbie" : "the Supplicant of Rath Khan",
     "mortal" : "the Aspirant of Rath Khan",
     "hm"     : "the Faithful of Rath Khan",
     "avatar" : "the Vengence of Rath Khan",
    ]) );
  SetFreeEquipment( ([
    STD_POLE "staff" : 1,
    ]) );
  SetReligion("Rath Cult");
  SetGender("male");
  SetGlobalLeader(1);
  SetTown("all");
  SetFriends( ({ "guard","rath","elite guard","priest","diplomat" }) );
  SetSpellBook( ([
    "aegis of the faithful" : 100,
    "jolt"                  : 100,
    "hellfire"              : 100,
     ]) );
 }

void eventJoin(object who, string args) {
  ::eventJoin(who, args);
  if(who->ClassMember("priest"))
    who->SetLanguage("Archaic", 100);
}

