//
//  mayor
//  Kyla 11-2-97
//  Modified by Rhakz - Angel Cazares
//  Date: 10/14/98
//
#include <lib.h>
#include "../jungle.h"
inherit LIB_MAYOR;

static void create() {
  mayor::create();
  SetKeyName("Mianin");
  SetId( ({ "man", "mianin","chief","cazique","chief mianin",
            "cazique of baria","chief mianin the cazique of baria"
       }) );
  SetShort("Chief Mianin the Cazique of Baria");
  SetGender("male");
  SetRace("human");
  SetClass("hunter");
  SetLevel(40);
  SetLong("Chief Mianin is the cazique of this town, that is, the "
          "major. He is a very strong man and also a very skilled "
          "hunter. Mianin is also in charge of the citizenship "
          "requests for Baria."
         );
  SetTown("Baria");
  RemoveLanguage("Enlan");
  SetLanguage("Barian", 100, 1);
  SetLocalCurrency("chits");
  SetTax(10);
  SetAction(5, ({
                 "!say Thanks to our new Lord, Baria is growing.",
                 "!say You want to be a citizen of Baria?",
                 "!say Be careful not to upset any citizen of Baria."
           }) );
  SetCurrency( ([
                 "chits" : 150+random(50),
             ]) );
  SetMorality(100);
}
