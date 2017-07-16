#include <lib.h>
#include <damage_types.h>
inherit LIB_NPC;
#include "../hiker.h"

static void create() {
   npc::create();
   SetProperty("hikernoleave",1);
   SetKeyName("blueberry picker");
   SetMorality(200);
   SetShort("a blueberry picker");
   SetId( ({ "picker" }) );
   SetAdjectives( ({ "blueberry","picker" }) );
   SetLong("This adult is somberly into the task of picking "
           "blueberries.  " + capitalize(possessive(this_object())) + 
           " mouth and teeth have no signs of blueberry eating, but "
           + capitalize(possessive(this_object())) + " fingers and "
           "hands are blue all over.  " + 
           capitalize(nominative(this_object())) + " stands tall, "
           "and seems used to not resting for long periods of time.");
   switch(random(2)) {
      case 0:
      SetGender("male");
      break;
      case 1:
      SetGender("female");
      break;
   }
   SetRace("human");
   SetClass("valkyr");
   SetLevel(10+random(3));
   SetMeleeAttackString("fists");
   SetMeleeDamageType(BLUNT);
   SetAction(2, ({ "!emote bends over for some low blueberries.",
                   "!emote straightens for a moment and stretches "
                   "to the sky.","!emote smiles happily.",
                   "!emote pushes back some branched to find more "
                   "berries.","!put first berries in first pail",
                   "!put first berries in second pail" }) );
   SetInventory( ([
                    H_OBJ + "blueberries" : 5+random(8),
                    H_OBJ + "pail" : 2,
               ]) );
}
