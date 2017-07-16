// Amelia@Haven

#include <lib.h>
inherit LIB_SENTIENT;
#include "../soleil.h"

static void create() {
   sentient::create();
   SetProperty("soleilnoleave",1);
   SetKeyName("Soleil citizen");
   SetShort("a Soleil citizen");
   SetId( ({ "soleil citizen","citizen","muezzin","male" }) );
   SetLong("Small eyes peer out of the fur of this citizen of soleil, "
           "filled with mirth.  The male seems to be very sturdy and "
           "has probably gone through the military training that is " 
           "required of all muezzins.");
   SetLevel(15+random(6));
   SetRace("muezzin");
   SetClass("valkyr");
   SetGender("male");
   SetCurrency("cuicui", random(50)+50);
   SetInventory( ([
/*
                    S_OBJ + "ironfist" : "wear fist on left hand"
*/
               ]) );
   SetWander(41);
   SetMorality(120);
   SetReligion("Eclat","Eclatish");
   SetFriends( ({ "Dulcae","Tia","Aegri Portare","Alamus","cemetary worker",
                  "Soleil citizen","Oppugno","shaggy dog","Sorgan",
                  "entrance guard","Iuvo","Fossis","Kiee","Miserum" }) );
}
