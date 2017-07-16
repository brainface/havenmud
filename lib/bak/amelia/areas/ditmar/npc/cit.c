#include <lib.h>
inherit LIB_NPC;
#include "ditmar.h"

static void create() {
   object soi = this_object();
   npc::create();
   SetTown("Ditmar");
   if(random(2)) { SetGender("female"); }
   else { SetGender("male"); }
   SetKeyName("citizen");
   SetShort("a Ditmar citizen");
   SetId( ({ "citizen" }) );
   SetAdjectives( ({ "ditmar" }) );
   SetLong("The Ditmar citizen has rough, shaggy fur covering "
           + possessive(soi) + " body.  As " + nominative(soi) + 
           " hunches over the ground, " + possessive(soi) +
           " claw-like paw-hands hang over the ground, often "
           "utilized in movement over strange rock formations.  "
           + capitalize(possessive(soi)) + " large eyes twinkle "
           "as " + nominative(soi) + " turns " + possessive(soi) +
           "head towards all nearby rock formations of beauty.");
   SetClass("fighter");
   SetClass("cleric");
   SetSkill("melee attack",1,1);
   SetSkill("enchantment",1,1);
   SetSkill("evokation",1,1);
   SetRace("mar");
   SetLevel(15+random(3));
   SetCurrency("kuique",8023+random(8000));
   SetInventory( ([
                    D_OBJ + "/robe" : "wear robe",
                    D_OBJ + "/figurine" : random(2),
               ]) );
}