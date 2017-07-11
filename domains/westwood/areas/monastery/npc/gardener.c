#include <lib.h>
inherit LIB_NPC;

static void create() {
   npc::create();
   SetTown("Soleil");
   SetProperty("monasterynoleave",1);
   SetKeyName("Eclatish gardener");
   SetShort("an Eclatish gardener");
   SetId( ({ "gardener","eclat","muezzin" }) );
   SetAdjectives( ({ "eclatish","shaggy" }) );
   SetLong("The shaggy muezzin has a keen eye that looks right through "
           "the people of this world and straight at the plants and "
           "growing things.  He is quite tall, an asset that probably "
           "facilates his ability to tend taller plants.  He is middle "
           "aged and seems very happy with the life he leads.");
   SetRace("muezzin");
   SetClass("fighter");
   SetSkill("melee combat",1,2);
   SetLevel(20);
   SetGender("male");
   SetAction(1,({ "!emote tends some plants.","!emote climbs up a "
                  "wall partway to examine some of the bushes.",
                  "!emote covers his hands in the dirt.",
                  "!emote peers into  some of the "
                  "roots.","!emote digs a small hole in the dirt and "
                  "plants a young seedling.","!emote pokes his finger "
                  "into the ground and drops a little seed into it."  }) );
   SetMorality(500);
}
