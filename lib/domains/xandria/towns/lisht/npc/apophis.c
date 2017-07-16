//Selket@Haven
//2006
#include <lib.h>
#include "../lisht.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("apophis");
  SetShort("Apophis the Necromancer");
  SetId( ({ "apophis", "necromancer" }) );
  SetRace("gnoll");
  SetBaseLanguage("Rehshai");
  SetGender("male");
  SetClass("necromancer");
  SetTown("Lisht");
  SetLong(
    "Apophis is a mage of unfathomable power, which he "
    "uses to bring forth the once-dead into the realm of "
    "the living. His eyes are like twin globes of fire, "
    "which burn endlessly with utter evil.");
  SetMorality(-300);
  SetLevel(40);
  SetSpellBook( ([
    "wound" : 100,
    "hunger" : 100,
    "chill touch" : 100,
    "splash" : 100,
    "wither" : 100,
    "asphyxiation" : 100,
    "planar shield" : 100,
    "dark flame" : 100,
    "hellfire" : 100,
    "reckoning" : 100,
    "spirit call" : 100,
    "mage's bane" : 100,
    "chaos bolt" : 100,
    "soultap" : 100,
    "wards of protection" : 100,
  ]) );
  SetPlayerTitles( ([
    "newbie" : "the Apprentice Necromancer of Lisht",
    "mortal" : "the Necromancer of Lisht",
    "hm" : "the Terrifying Necromancer of Lisht",
    "legend" : "the Master of Corpses",
    "avatar" : "the Bringer of the Dead",
  ]) );
  SetRestrictRace(1);
  SetFreeEquip( ([
    "/std/weapon/pole/staff" : 1,
  ]) );
  SetCurrency("deben", 5000);
  SetAction(5, ({
    "!cast wards of protection",
    "!cast planar shield",
    "!emote glares at you with baleful eyes.",
  }) );
  SetCombatAction(5, ({
    "!cast reckoning",
    "!cast wither",
    "!cast splash",
    "!cast wound",
    "!cast chill touch",
    "!cast reckoning",
    "!cast hunger",
    "!cast asphyxiation",
    "!cast planar shield",
    "!cast mages bane",
    "!cast hellfire",
    "!cast chaos bolt",
    "!cast dark flame",
    "!cast soultap",
    "!cast reckoning",
  }) );
  SetTaughtSpheres( ({"magical", "magical necromancy"}) );
  SetInventory( ([
    LISHT_OBJ "shenti" : "wear shenti",
  ]) );
}

