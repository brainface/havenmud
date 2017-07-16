// Amelia May 01
#include <lib.h>
#include <domains.h>
inherit LIB_TELLER;

static void create() {
   ::create();
   SetTown("Averath");
   SetKeyName("guard");
   SetShort("a guard of the First Averath Bank");
   SetId( ({ "guard","bank" }) );
   SetAdjectives( ({ "guard","of","the","first","averath","bank" }) );
   SetGender(({ "male","female" })[random(2)]);
   SetLong("Blessed with tough skin and a small brain, this guard "
           "holds " + possessive(this_object()) + " ground in the "
           "First Averath Bank.  As a "
           "sworn protector of Orris, the teller and owner of the "
           "bank, " + nominative(this_object()) + " would die to "
           "save this repository of ducats.");
   SetRace("human");
   SetClass("fighter");
  SetLevel(20);
   SetCurrency("ducats",5);
   SetInventory( ([
                    AVERATH_OBJ + "banksword" : "wield sword",
               ]) );
   SetAction(2, ({ "!growl","!snort", }) );
//   SetFriends( ({ "orris","guard" }) );
   SetMorality(50);
}
