#include <lib.h>
inherit LIB_NPC;
#include "../hiker.h"

static void create() {
   npc::create();
   SetProperty("hikernoleave",1);
   SetKeyName("lost hiker");
   SetShort("a lost hiker");
   SetId( ({ "hiker" }) );
   SetAdjectives( ({ "lost" }) );
   SetLong("The hiker is tired and confused.  He glances about, "
           "nervous, trying to figure out where he went wrong on "
           "his navigation of the woods.  Short and thin, he "
           "looks like he wishes he were anywhere else and that "
           "he had never agreed to go on this hike.");
   SetGender("male");
   SetRace("human");
   SetClass("rogue");
   SetLevel(14);
   SetAction(2,({ "!emote trips on a low branch.",
                  "!emote bangs his foot on a root.",
                  "!emote whimpers.",
                  "!emote starts to cry.",
                  "!emote looks around for his mommy.",
             }) );
   SetCurrency("cuicui",50);
}
