// mahkefel 2011: made armour work.
#include <lib.h>
#include "../lodge.h"
#include <armour_types.h>
inherit LIB_NPC;         

static void create() {
  npc::create();      
  SetKeyName("Rztsual");
  SetRace("nosferatu"); 
  SetShort("Rztsual the defender");
  SetId( ({"rztsual","guard","nosferatu","guardroom_blocker","defender"}) );
  SetAdjectives( ({"nosferatu","big","robust","the","defender","rztsual"}) );
  SetClass("cavalier");
  SetLevel(26);
  SetGender("male");
  SetMorality(-110);
  SetCurrency("crystals", 25 + random(150));
  SetLong(
     "This nosferatu is very big and robust with broad shoulders "
     "and his dark, alert eyes seems to glare down at everything. His razor "
     "sharp teeth display against his pale skin while the grin on his serious "
     "face shows no defeat in his history.  With corrected stance and crossed "
     "arms, he looks ready to defend himself at any given time.");

  SetAction(9, ({
     "!emote darts his eyes in your direction.",
     "!emote glares suspicously at you.",
     "!say You are not wanted here. Leave now!",
      }) );
  SetCombatAction(9, ({
     "!say There is nothing for you to see here!",
     "!say I said you are not wanted here!",
     "!disarm",
     }) );
  SetInventory( ([
     L_OBJ + "ribcage" : "wear armour on torso and right arm and left arm",
     L_OBJ + "sword" : "wield sword",
     ]) );
}


/* Approved by Duuktsaryth on Sat Feb 19 16:36:02 2000. */

