#include <lib.h>
#include <std.h>
#include <daemons.h>
#include "../parva.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetId( ({ "aeron", "priest", "greyjoy" }) );
  SetAdjectives( ({ "high", "priest", "aeron", "damhair" }) );
  SetKeyName("Aeron Greyjoy");
  SetShort("High Priest Aeron Greyjoy of Damhair");
  SetLong(
    "Aeron Greyjoy, solemn priest of the drowned god, "
    "tends this shrine with alacrity and seriousness. His "
    "dark, passionless eyes seem to hold within them all "
    "those secrets hidden beneath the ocean's waves."
  );
  SetGender("male");
  SetMorality(-200);
  SetTown("Parva");
  SetRace("human");
  SetReligion("Damhair");
  SetClass("priest");
  SetLevel(70);
  SetLimit(1);
  SetUniqueSkills( ([
    "navigation" : 2,
    "swimming"   : 2,
    "sailing"    : 2,
    ]) );
   SetPlayerTitles( ([
    "newbie"  : "the Newly Drowned",
    "mortal"  : "the Bringer of Tides",
    "hm"      : "the Rider of the Waves",
    "legend"  : "the Storm of the Seas",
    "avatar"  : "Grand Storm $N the Thundercloud of Damhair",
    "fighter" : "the Breaker of Hulls",
    "rogue"   : "the Stalker of Shores",
    "acrobat" : "the Wave-Borne Waif",
    ]) );
  SetFreeEquip( ([
    STD_WEAPON "blunt/war-hammer" : 1,
    ]) );
  SetInventory ( ([
    STD_WEAPON "blunt/war-hammer" : "wield hammer",
    ]) );
  SetSpellBook( ([
    "protective storm" : 100,
    ]) );
  SetAction(5, ({
    "!say the Drowned God protects Parva",
    "!say Join the Order of the Drowned God!",
    }) );
  SetCombatAction(20, ({
    }) );
  SetFirstCommands( ({
    "cast protective storm",
    "cast protective storm",
    "cast protective storm",
    "cast protective storm",
    "cast protective storm",
  }) );
}

void heart_beat() {
  ::heart_beat();
  if (sizeof(GetMagicProtectionNames()) < 5) {
    eventForce("cast protective storm");
  }
}

