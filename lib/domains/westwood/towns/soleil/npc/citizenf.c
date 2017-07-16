// Amelia@Haven

#include <lib.h>
inherit LIB_SENTIENT;
#include "../soleil.h"

static void create() {
   sentient::create();
   SetProperty("soleilnoleave",1);
   SetKeyName("Soleil citizen");
   SetShort("a Soleil citizen");
   SetId( ({ "soleil citizen","citizen","female","muezzin" }) );
   SetLong("Small eyes peer out of the fur of this citizen of soleil, "
           "filled with mirth.  The female seems to be very sturdy and "
           "has probably gone through the military training that is " 
           "required of all muezzins.");
   SetRace("muezzin");
   SetClass("rogue");
   SetLevel(15+random(6));
   SetGender("female");
   SetCurrency("cuicui", random(50)+5);
   SetInventory( ([
      //S_OBJ + "/ironfist" : "wear fist on right hand"
      ]) );
   SetWander(39);
   SetMorality(120);
   SetReligion("Eclat","Eclat");
   SetFriends( ({ "Dulcae","Tia","Aegri Portare","Alamus","cemetary worker",
                  "Soleil citizen","Oppugno","shaggy dog","Sorgan",
                  "entrance guard","Iuvo","Fossis","Kiee","Miserum" }) );
}
