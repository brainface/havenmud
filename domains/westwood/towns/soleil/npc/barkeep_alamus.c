#include <lib.h>
#include <std.h>
inherit LIB_BARKEEP;
#include "../soleil.h"

static void create() {
   barkeep::create();
   SetProperty("soleilnoleave",1);
   SetKeyName("Alamus");
   SetShort("Alamus, the barkeep");
   SetId( ({ "alamus","barkeep","barkeeper" }) );
   SetLong("Youthful dullness shows on the barkeeper's face as he "
           "looks on to his job, wiping up after his "
           "patrons and keeping their glasses full.  Alamus seems "
           "to not mind too greatly though, and stands tall and straight "
           "as one can.");
  
   SetRace("muezzin");
   SetClass("merchant");
   SetGender("male");
   SetLevel(15);
   SetLocalCurrency("cuicui");
   SetMenuItems( ([
                    "stew" : S_OBJ + "stew_rainbow_fish",
                    "beer" : DIR_STD + "meal/alcohol/" + "beer_basic",
                    "milk" : DIR_STD + "meal/drink/" + "milk",
                    "bread" : DIR_STD + "meal/food/" + "bhunk",
                    "cheese" : DIR_STD + "meal/food/" + "cheese",
                    "cheese wheel" : DIR_STD + "meal/food/" + "wheel",
               ]) );
   SetMorality(150);
   SetReligion("Eclat","Eclat");
   SetFriends( ({ "Dulcae","Tia","Aegri Portare","cemetary worker",
                  "Soleil citizen","Oppugno","shaggy dog","Sorgan",
                  "entrance guard","Iuvo","Fossis","Kiee","Miserum" }) );
}
