#include <lib.h>
#include <daemons.h>
#include <armour_types.h>
#include <size.h>
#include "../vamp.h"
inherit LIB_SENTIENT;

static void create() {
  ::create();
 
  SetKeyName("sapling");
  switch(random(3)) {
    case 0:
      SetShort("a sinister oak sapling");
      SetAdjectives(({"oak","lumbering","sinister"}));
      SetId( ({"sapling", "oak", "vamp_wander"}) );
      break;
    case 1:
      SetShort("a baleful willow sapling");
      SetAdjectives(({"lumbering","willow","baleful"}));
      SetId( ({"sapling", "willow", "vamp_wander"}) );
      break;
    case 2:
      SetShort("a corrupt fir sapling");
      SetAdjectives(({"lumbering","fir","corrupt"}));
      SetId( ({"sapling", "fir", "vamp_wander"}) );
      break;
}
  SetLong(
     "Foxfire lights form the semblance of eyes and jagged mouth behind "
     "a crudely carved, baleful mask placed in the upper reaches of the "
     "tree. Dead and leafless limbs reach out menacingly with branches "
     "like twisted claws. The corrupted trunk of this lumbering sapling "
     "is littered with deep gashes and long-embedded broken blades left "
     "behind by foolhardy woodcutters and unfortunate adventurers. "
     );
  SetRace("tree");

  // tree race doesn't support armouor.
  DestLimb("head");
  AddLimb("head", "trunk", 1, ({A_HELMET}));

  SetSize(SIZE_LARGE);
  
  SetClass("fighter");
  SetSkill("natural magic",1);
  SetSkill("evokation",1);
  SetLevel(210);
  SetMorality(-500);
  SetWander(20);
  SetInventory( ([
     VAMP_OBJ "/sap_mask" : "wear mask",
     VAMP_OBJ "/sap_axe" : 3,
  ]) );
  SetAction(5, ({
    "!emote creaks ominously.",
    "!emote lurches towards you.",
    "!emote digs into the ground with its roots.",
  }) );
  SetCombatAction(10, ({
    "!emote howls inhumanly.",
    "!emote shakes the ground as it charges!",
    "!cast tangle",
  }) );
  SetFirstCommands( ({"wield axes"}) );
}
