#include <lib.h>
#include <std.h>
#include <daemons.h>
#include "haven.h"
inherit LIB_LEADER;
 
static void create() {
  leader::create();
  SetKeyName("Isaac");
  SetFriends( ({ "slave" }) );
  SetRace("elf");
  SetBaseLanguage("Alatherian");
  SetClass("priest");
  SetLevel(25);
  SetGender("male");
  SetShort("Isaac of Lisht, a Priest of Anteky");
  SetId( ({ "isaac", "priest" }) );
  SetLong(
    "Isaac is a wisened old elf, a priest of a religion that has been abused and "
    "oppressed since the conquest of the elves by the Xandrian Kingdom. His greying "
    "hair is nearly unique among the elves, and his ancient age is at once "
    "daunting and inspiring."
    );
  SetUniqueSkills( ([
	"blunt combat" : 0,
	"pole combat"  : 1,
    ]) );
  SetSpellBook( ([
    "divine cataclysm" : 100,
     ]) );
  SetAction(10, ({
     "!speak Some day, the Lord will hear the cries of his people!",
     "!speak The Lord watches over us, and he weeps with our pain.",
     "!speak There is no god but Duuktsaryth!",
     "!speak A divine cataclysm is coming for the gnolls!",
     "!say Our faith is tested, but the Lord does not forget.",
   }) );
  SetReligion("Anteky");
  SetTown("Lisht");
  SetPlayerTitles( ([
     "newbie" : "the Supplicant of the One God",
     "mortal" : "the Priest of Anteky",
     "hm"     : "the High Priest of Anteky",
     "legend" : "the Bishop of the One God",
     "avatar" : "the Prophet of the One God",
    ]) );
  SetFreeEquip( ([
    STD_ARMOUR "shirt/studded_leather" : 1,
    "/std/weapon/pole/staff" : 1,
    ]) );
  SetInventory( ([
    "/std/weapon/pole/staff" : "wield staff",
     ]) );
  }
