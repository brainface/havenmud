//Selket@Haven
//2006
#include <lib.h>
#include "../lake.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("nekhonkh");
  SetShort("Nekhonkh the Ferryman");
  SetId( ({ "ferryman" }) );
  SetLong(
    "Nekhonkh is the honorable ferryman who takes people across "
    "the lake for a small fee. He grips his oars with the ease "
    "of an accomplished sailor, now retired to a simple task where "
    "he can still be away from dry land. "
  );
  SetLimit(1);
  SetSkill("sailing", 1, 1);
  SetClass("fighter");
  SetLevel(40);
  SetWanderSpeed(2);
  SetGender("male");
  SetRace("gnoll");
  SetBaseLanguage("Rehshai");
  SetCurrency("deben",random(1000));
  SetInventory( ([
       LAKE_OBJ + "oar" : "wield oar",
       LAKE_OBJ + "shenti" : "wear shenti",
         ]) );
  SetAction(6, ({
    "!say Don't make me put YOU on your mooring stakes.",
    "!say Would you like safe passage to the other side?",
    "!hum",
    "!say I could tell you tales of amazing places. I have "
    "sailed into Paradise itself.",

  }) );
  SetWanderPath( ({ "sail east", "sail east", "sail east", "sail east",
    "yell all aboard", "sail west", "sail west", "sail west", "sail west" }) );
  SetWanderRecurse(1);
  SetFirstCommands("board ferry");
}
