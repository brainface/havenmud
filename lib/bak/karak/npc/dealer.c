#include <lib.h>
#include "../karak.h"
inherit LIB_MAYOR;

static void create() {
  mayor::create();
  SetKeyName("dealer");
  SetFriends( ({ "rommel" }) );
  SetShort("Dealer, WarBoss of Karak Varn");
  SetId( ({ "dealer", "warboss", "mayor" }) );
  SetLong("This enormous creature before you looks like a one orc "
          "army.  His massive frame is covered with muscle and scars "
          "as well as a healthly selection of armor and wargear. "
          "All petitions for citizenship are brought before him.");
  SetRace("orc");
  SetGender("male");
  SetClass("fighter");
  SetLevel(30 + random(10));
  SetInventory( ([ K_OBJ + "/runes" : "wield sword",
                   K_OBJ + "/runea" : "wear armor" ]) );

  SetTown("Karak");
  SetLocalCurrency("orcteef");
  SetTax(5);

}
