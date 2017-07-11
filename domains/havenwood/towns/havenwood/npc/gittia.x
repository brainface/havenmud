/*  Druid leader
 *  Duuktsaryth
 */
#include <lib.h>
#include <std.h>
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("gittia");
  SetTown("Havenwood");
  SetRace("wild-elf");
  SetClass("druid");
  SetReligion("Eclat");
  SetSpellBook( ([
    "tangle"       : 100,
    "plant strike" : 100,
    "vine wall"    : 100,
    ]) );
  SetShort("Gittia the Druid of the HavenWood");
  SetMorality(500);
  SetId( ({ "gittia", "druid" }) );
  SetAdjectives( ({ }) );
  SetLong(
    "Gittia is a druid, one of the forest loving class of "
    "people that tend the wood with loving care to make it "
    "the magical place that it is."
    );
  SetGender("female");
  SetPlayerTitles( ([
     "newbie" : "the Caretaker of the Havenwood",
     "mortal" : "the Druid of the Havenwood",
     "hm"     : "the Spirit-Keeper of the Havenwood",
     "avatar" : "the Hierophant of the Havenwood",
     ]) );
  SetFreeEquip( ([
    STD_POLE "staff" : 1,
  ]) );
  SetLevel(48);
  SetCurrency("imperials", random(400) + 1);
  SetCombatAction(10, ({ 
     "!cast tangle", "!cast plant strike", "!cast tangle", "!cast vine wall", "!cast plant strike"  
   }) );
  SetFirstCommands( ({ "cast vine wall", "cast vine wall", "cast vine wall", "cast vine wall" }) );
}
