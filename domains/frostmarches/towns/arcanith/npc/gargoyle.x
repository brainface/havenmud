/* Small cemetery gargoyle */

#include <lib.h>
#include "../ruins.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("gargoyle");
  SetId( ({ "gargoyle" }) );
  SetAdjectives( ({ "small" }) );
  SetShort("a small gargoyle");
  SetLong("The small gargoyle looks like the part of a tombstone come to "
          "life.  While it looks fearsome, its small fists and size make it "
          "look fairly harmless.");

  
  SetRace("gargoyle");
  SetClass("rogue");
  SetGender("male");
  SetLevel(1);
  SetMorality(-50);

  SetAction(5, ({ 
    "!growl", "!snarl", "The gargoyle stretches its wings.",
     }) );
  SetDie("The wings of the gargoyle give a final flap as it crumbles to dust.");
  SetNoCorpse(1);
}
