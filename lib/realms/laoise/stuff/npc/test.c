// Fucking pirate invasion
// Fucking invasions in general

#include <lib.h>
inherit LIB_INVADER;

static void create() {
   invader::create();

   SetKeyName("bob");
   SetShort("bob the wonder pirate");
   SetId( ({ "pirate", "bob", "pirate_inv" }) );
   SetAdjectives( ({ "pirate" }) );
   SetLong(
     "This is Bob. Bob has bitch-tits and wants you to "
     "hug him."
   );
   SetRace("human");
   SetGender("male");
   SetClass("rogue");
   SetLevel(50);
   SetInventory( ([
   ]) );
   SetFriends( ({ "pirate_inv" }) );
}
