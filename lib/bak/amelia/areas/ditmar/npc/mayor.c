#include <lib.h>
inherit LIB_MAYOR;
#include "ditmar.h"

static void create() {
   mayor::create();
   SetTown("Ditmar");
   SetKeyName("Ralactag");
   SetShort("Ralactag, mayor of Ditmar");
   SetId( ({ "ralactag","mayor","mayor of ditmar" }) );
   SetAdjectives( ({ "ditmar" }) );
   SetLong("Ralactag is the average-hieght average-fur average-life mar that "
           "happens to be the mayor of Ditmar.  He smiles a toothy grin a "
           "hefty percentage of the time, and his teeth haven't bee kept "
           "very well.  All in all, it gives a bad impression of the town.");
   SetGender("male");
   SetRace("mar");
   SetClass("valkyr");
   SetLevel(11);
   SetLocalCurrency("kuique");
   SetTax(29+random(80));
   SetMorality(-50);
   SetInventory( ([
                    D_OBJ + "/robe" : "wear robe",
               ]) );
}