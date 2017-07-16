#include <lib.h>
inherit LIB_HEALER;
#include "../hospital.h"

static void create() {
   healer::create();
   SetProperty("noleavehospital",1);
   SetKeyName("Zoa");
   SetShort("Zoa, a healer");
   SetId( ({ "healer","zoa","human" }) );
   SetAdjectives( ({ "healer","human" }) );
   SetLong("Zoa is neither muezzin nor Eclat, but holds no allegiance "
           "to any religion.  Free from all bias and willing to help all, "
           "she came to this hospital first as a patient and then, when "
           "realizing the need to have someone to help those who come "
           "in need to faster healing who also have money.  The "
           "human healer does not have the kind look to her that the "
           "doctors and nurses here do; instead, she looks cold and "
           "hungry for money.  She is strong enough to protect her "
           "money from all the greedy paws that might wish it from her, "
           "except perhaps the strongest of them all, and stands ready "
           "to protect her coins with her melee skills.");
   SetClass("valkyr");
   SetRace("human");
   SetGender("female");
   SetLevel(53);
   SetLocalCurrency("cuicui");
/*
   SetCharge(77);
*/
  SetFees( ([
    "resurrect" : 100,
    "magic" : 10,
    "stamina" : 1,
    "health" : 3,
    "restore" : 50,
  ]) );
   SetMorality(-55);
   SetLanguage("Oiseau",100);
   SetLanguage("Eltherian",100,1);
   SetLanguage("Enlan",100);
   SetLanguage("Runic",100);
   SetLanguage("Uruk",100);
   SetLanguage("Gobyshkin",100);
   SetLanguage("Blaodric",100);
   SetAction(5, ({ "!speak in oiseau Come here to get healing quick!",
                   "!speak in eltherian I can heal you for a little "
                      "price.",
                   "!speak in enlan Come all, come all!  Just a little "
                      "healing, that's all you need, just make you "
                      "feel a little better.",
                   "!speak in runic This is a hospital, and there are "
                      "many, many in line to be healed by the great "
                      "doctors.  I can do it now and you can be out, "
                      "adventuring, once more!",
                   "!speak in uruk Healing here!",
                   "!speak in gobyshkin Come here to get your healing "
                      "comrades!",
                   "!speak in blaodric Your travels have been long and "
                      "hard on your body, I can see, come, come, be "
                      "healed by I!", }) );
}

