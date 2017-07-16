#include <lib.h>
#include <damage_types.h>
inherit LIB_NPC;
#include "../hiker.h"

static void create() {
   npc::create();
   SetProperty("hikernoleave",1);
   SetKeyName("boy swimmer");
   SetShort("a boy swimmer");
   SetId( ({ "boy","swimmer","male","human" }) );
   SetAdjectives( ({ "boy","male","human","swimming" }) );
   SetLong("The boy's skin is a little chill looking, and rather "
           "pasty.  He seems to have a slightly blue tinge around "
           "his lips, and his brown hair is matted down and dripping "
           "with water.");
   SetMorality(100);
   SetGender("male");
   SetRace("human");
   SetClass("valkyr");
   SetLevel(1+random(2));
   SetAction(1, ({ "!emote shivers with cold.","!emote brushes some "
                   "water off his face.","!emote shakes his hair "
                   "out, splattering drops of water around.",
                   "!emote ducks his head under the water, coming "
                   "up quickly.","!emote daringly sits down in the "
                   "cold water.","!emote splashes water around." }) );
   SetMeleeAttackString("fists");
   SetMeleeDamageType(BLUNT);
   SetInventory( ([
                    H_OBJ + "swim" : "wear trunks",
               ]) );
}
