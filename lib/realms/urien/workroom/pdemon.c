// Made him when Duuk made the purge daemon
// Nifty due to mem lossage and spam on Haven
// Spruced up the "purge daemon"
// Urien@Haven 10.26.12

#include <lib.h>
#include <daemons.h>

#define WORKROOMDIR "/realms/urien/workroom/"

inherit LIB_SENTIENT;

static void create() {
 ::create();
 SetKeyName("daemon");
 SetShort("the purge daemon");
 SetId( ({ "daemon" }) );
 SetAdjectives( ({ "purge"}) );
 SetRace("daemon");
 SetGender("female");
 SetClass("horror");
 SetLevel(30);
 SetLanguage("Blaodric",100,1);
 SetMorality(-1000);
 SetLong(
    "This is the very famous purge daemon. She looks very fat as if she "
    "does not work out very often. Two horns have crept out and spiral "
    "upward almost shielding the top of her head. Her skin is a dark "
    "red and her eyes are a bright yellow...as are her teeth."
  );
 SetInventory( ([
        WORKROOMDIR "pdering" : "wear ring on right hand",
        WORKROOMDIR "pdecigar": 3,
  ]) );
 SetFirstCommands( ({
    "light my first cigar",
    "smoke my first cigar",
    "say It's been a while since someone visited me!",
    }) );
 SetAction(3, ({
    "!say I may be out of shape, but I run every nine hours.",
    "!say Let's kill some players today!",
    "!say I hate it here, it's so chilly...",
    "!say Please don't dest me....",
    "!smoke my first cigar",
  }) );
 SetCombatAction(50, ({
    "!scream",
    "!disarm",
    "!disorient",
    "!scream",
  }) );
 }