#include <lib.h>
inherit LIB_NPC;
#include "../castle.h"

static void create() {
   npc::create();
   SetKeyName("short maid");
   SetShort("a short maid");
   SetId( ({ "maid","human" }) );
   SetAdjectives( ({ "short","human" }) );
   SetLong("Shortly cropped hair crowns the face of the short human "
           "maid.  She wears a constant smile on her face, and her "
           "fingers twitch as if she wants to be doing something "
           "rather than just standing still.  She doesn't look to "
           "be much of a slouch.");
   SetRace("human");
   SetGender("female");
   SetClass("rogue");
   SetLevel(9+random(2));
   SetCurrency("nuggets",2 + random(12));
   SetMorality(150);
}
