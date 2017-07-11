#include <lib.h>
#include <std.h>
#include <daemons.h>
#include "../wood.h"
inherit LIB_TRAINER; 

static void create() {
  ::create();   
  SetKeyName("Rilly");
  SetTown("Havenwood");
  SetShort("Rilly the Ironworker");
  SetId( ({"rilly","ironworker"}) );
  SetAdjectives( ({ "rilly", "the", "ironworker" }) );
  SetRace("wild-elf");           
  SetClass("fighter");            
  SetLevel(48);
  SetMorality(400);
  SetCurrency("imperials",random(100) + 1);
  SetLong("Rilly is a stout wild-elf with soot-stained clothes "
    "and calloused hands. "
    "She's known for her ability to repair most anything broken and "
    "is one of the few wild-elves with the knowledge of metal working."
  );
  SetAction(15, ({
    "!say Do you need armour repaired? "
      "I can teach you how to do it yourself!",
    "!say Broken armour means broken bones!",
    "!emote looks around for something to fix.",
  }) );
  SetGender("female");
  SetInventory( ([
    HWD_OBJ "/hammer" : "wield hammer",
    HWD_OBJ "/nail" : "wield nail",
    ]) );
  SetTrainingSkills( ({
    "bargaining",
    "armour smithing",
    "weapon smithing",
    "mithril working",
    "metal working",
    "leather working",
    "natural working",
    "wood working",
    "skinning",
  }) );
}


