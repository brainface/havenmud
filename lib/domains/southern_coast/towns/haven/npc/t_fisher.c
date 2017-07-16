#include <lib.h>
#include "../haven.h"
#include <std.h>
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("talis");
  SetShort("Talis of the Wharf");
  SetRace("elf");
  SetGender("male");
  SetId( ({ "talis", "fisher", "fisherman" }) );
  SetAdjectives( ({ "master", }) );
  SetTown("Haven");
  SetLevel(1);
  SetMorality(250);
  SetTrainingSkills( ({ 
    "fishing", 
    "knife combat",
    "cooking",
    }) );
  SetLong("Talis is an older elf who spends all his time fishing and relaxing "
          "at the Haven Town wharf.  He's always willing to teach someone who "
          "wants to learn.");
  SetAction(4, ({
    "!fish with pole",
    "!speak Here... fishy fishy fishy...",
    "!speak I'd teach you if you asked me.",
    "!speak So.  Fine day for fishing, yes?",
    }) );
  SetLimit(1);
  SetInventory( ([
    STD_FISH "pole" : "wield pole",
    ]) );
}
