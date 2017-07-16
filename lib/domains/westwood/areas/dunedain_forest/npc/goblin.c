#include <lib.h>
#include "../forest.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("goblin");
  SetShort("an angry looking goblin");
  SetLong("This is an angry looking goblin.  He has a scowl on his face "
          "that suggests that he has no fear of battle.");
  SetId( ({ "goblin", "angry looking goblin" }) );
  SetAdjectives( ({ "angry", "angry looking" }) );
  SetClass("fighter");
  SetMorality(-300);
  SetLevel(random(3)+11);
  SetEncounter(1);
  SetGender("male");
  SetRace("goblin");
  SetCurrency("imperials",random(25));
  SetInventory( ([
  			F_OBJ "shield"     : "wear shield on right arm",
        F_OBJ "broadsword" : "wield broadsword",
        ]) );
}