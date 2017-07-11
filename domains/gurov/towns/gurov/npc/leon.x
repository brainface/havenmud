#include <lib.h>
#include <std.h>
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("leon");
  SetShort("Leon of Gurov (Gurov human)");
  SetId( ({ "leon" }) );
  SetAdjectives( ({ }) );
  SetLong(
    "Leon of Gurov is in charge of teaching young members of the Guild how "
    "to do their jobs well. For those interested, he can <describe> rogues, "
    "and for those VERY interested, he can be asked to <join rogues>."
    );
  SetRace("human");
  SetBaseLanguage("Gurovian");
  SetGender("male");
  SetClass("rogue");
  SetLevel(50);
  SetInventory( ([
    STD_KNIFE "stiletto" : 2,
    ]) );
  SetFirstCommands("wield all");
  SetFreeEquipment( ([
    STD_KNIFE "freeknife" : 2,
    DIR_STD "lockpicks/newbiepicks" : 1,
    ]) );
  SetLimit(1);
  SetTown("Gurov");
  SetMorality(-300);
}

  