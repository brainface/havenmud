#include <lib.h>
#include <damage_types.h>
inherit LIB_NPC;
#include "../hiker.h"

static void create() {
   npc::create();
   SetProperty("hikernoleave",1);
   SetKeyName("blueberry picker");
   SetMorality(300);
   SetShort("a young blueberry picker");
   SetId( ({ "picker","girl","female","human" }) );
   SetAdjectives( ({ "young","blueberry","female" }) );
   SetLong("The girl has carefully eaten some blueberries so as only "
           "to stain her tongue with the tell-tale signs.  Her "
           "fingers are, nevertheless, stained by the picking.");
   SetGender("female");
   SetClass("valkyr");
   SetRace("human");
   SetLevel(2+random(2));
   SetMeleeAttackString("fingernails");
   SetMeleeDamageType(PIERCE|SLASH);
   SetAction(2, ({ "!emote sneaks a bite from some blueberries.",
                   "!emote gently pulls off another handfull from the "
                   "bushes.","!put first berries in pail" }) );
   SetInventory( ([
                    H_OBJ + "blueberries" : 4+random(3),
                    H_OBJ + "pail" : 1,
                    H_OBJ + "strawhat" : "wear hat on head",
               ]) );
}
