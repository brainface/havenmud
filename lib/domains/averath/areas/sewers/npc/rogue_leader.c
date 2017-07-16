// Wedge Antilles
// Aerelus

#include <lib.h>
#include <domains.h>
#include "../sewers.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("Jorin the Devious");
  SetShort("a malnourished man");
  SetId( ({ "man", "jorin", "devious", "rogue" }) );
  SetAdjectives( ({ "jorin", "the", "malnourished" }) );
  SetGender("male");
  SetRace("human");
  SetRestrictRace(1);
  SetClass("rogue");
  SetBaseLanguage("Avera");
  SetLevel(35);
  SetLong(
    "Jorin the Devious is a nasty-looking fellow of "
    "thin build and shadowy demeanor. He has the appearance "
    "of someone who could \"describe rogues\" if he was "
    "asked, and also someone who would know how to "
    "\"join rogues\"."
  );
  SetMorality(-500);
  SetInventory( ([
    SEWERS_OBJ "jorin_knife" : "wield knife",
    SEWERS_OBJ "rogue_robe" : "wear robe",
  ]) );
  SetFreeEquipment( ([
    SEWERS_OBJ "newbie_knife" : 1,
    SEWERS_OBJ "rogue_robe" : 1,
  ]) );
  SetPlayerTitles( ([
    "newbie" : "the Young Hooligan",
    "mortal" : "the Reprobate",
    "high mortal" : "the Sneaky Bandit",
    "legend" : "the Shadow Stalker",
    "avatar" : "the Deadly Marauder",
    "demigod" : "the Ascendant of the Underground",
  ]) );
  SetTown("Averath");
  SetProperty("no bump", 1);
}