/* Zeratul@Haven */

#include <lib.h>
#include <domains.h>
#include "../undead.h"

inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("priest");
  SetId( ({ "priest","guard_shrine" }) );
  SetShort("a priest of the shrine");
  SetLong(
     "This dark looking figure is the caretaker and religious leader of this shrine. "
     "He waits patiently for the next potential to convert and show them the "
     "ways of his faith "
  );
  SetLevel(20);
  SetReligion("Zeran");
  SetSkill("blunt combat", 70, 1);
  SetSkill("necromancy", 70, 1);
  SetSkill("faith", 70, 1);
  SetRace("human");
  SetClass("priest");
  SetGender("male");
  SetMorality(-250);
  SetProperty("no bump", 1);
  SetTaughtSpheres( ({ "faith" }) );
  SetInventory( ([
     UNDEAD_OBJ + "mace" : "wield mace",
  ]) );
  SetFreeEquipment( ([
     UNDEAD_OBJ + "noobmace" : 1,
  ]) );
  SetPlayerTitles( ([
     "newbie"         : "the Potential Zeran Priest",
  ]) );
  SetAction(1, ({
     "!say This island has been corrupted with non-believers!",
     "!sigh",
     "!say If only they could understand.",
     "!say can they not see past their own hands?",
     "!nod",
     "!say The time will come...",
     "!say We will have our day...",
  }) );
  SetCombatAction(10,({
     "!cast chaos bolt",
     "!cast cloak of darkness",
     "!cast poison explosion",
  }) );
  SetSpellBook( ([
     "chaos bolt" : 100,
     "cloak of darkness" : 100,
     "poison explosion" : 100,
  ]) );
  }
