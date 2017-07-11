// Mahkefel 2010
// trade skill trainer for arcanith

#include <lib.h>
#include "../ruins.h"
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("artzil");
  SetId( ({ "artzil","miner","kobold" }) );
  SetAdjectives( ({ "artzil", "miner", "a", "kobold" }) );
  SetShort("artzil, a kobold miner");
  SetLong(
    "This stout little kobold's fur is stained grey with rubble "
    "and grime. His eyes shine with a clarity of purpose as he merrily "
    "swings his pickaxe at the offending rubble."
  );
  SetRace("kobold");
  SetClass("merchant");
  SetGender("male");
  SetLevel(10);
  SetMorality(25);
  SetAction(10, ({
    "!mine with pickaxe",
    "!say Artzil can teach digging, if this one helps artzil!",
    "!emote inspects a shiny bit of quartz.",
  }) );
  SetInventory( ([
      OBJ "/pickaxe" : "wield pickaxe",
  ]) );
  SetDie("Artzil reaches longily for his a the uncleared rubble "
    "one last time, then goes still.");
  SetTown("Arcanith");
  SetTrainingSkills( ({
    "mining",
    "farming",
    "stealth",
    "bargaining",
    "stealing",
    "cooking",
  }) );
}

