// Amelia@Haven

#include <lib.h>
inherit LIB_SAGE;
#include "../soleil.h"

static void create() {
   sage::create();
   SetProperty("soleilnoleave",1);
   SetKeyName("Miserum");
   SetShort("Miserum, the muezzin language teacher");
   SetId( ({ "miserum","teacher" }) );
   SetAdjectives( ({ "muezzin","male","language" }) );
   SetLong("Miserum looks sad and old, bent over like an old man.  "
           "His fur is gray, and gray eyes peer out from under that fur.  "
           "He is very intelligent looking, however, and seems to " 
           "be willing to teach people.");
   SetRace("muezzin");
   SetLocalCurrency("cuicui");
   SetCharge(700);
   SetGender("male");
   SetClass("valkyr");
   SetLevel(7);
   SetLanguage("Runic", 100);
   SetLanguage("Enlan", 100);
   SetMorality(175);
   SetReligion("Eclat","Eclatish");
   SetFriends( ({ "Dulcae","Tia","Aegri Portare","Alamus","cemetary worker",
                  "Soleil citizen","Oppugno","shaggy dog","Sorgan",
                  "entrance guard","Iuvo","Fossis","Kiee",}) );
}
