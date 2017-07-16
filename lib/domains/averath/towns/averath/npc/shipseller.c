#include <lib.h>
#include <vehicle.h>
#include "../averath.h"
inherit LIB_SHIPSELLER;

static void create() {
  ::create();
  SetKeyName("Count Mortain");
  SetId( ({ "mortain", "magnate", "count", "averath_person" }) );
  SetShort("Count Mortain the Shipping Magnate");
  SetLong(
    "Count Mortain of Averath is a wealthy shipping magnate. He is known also "
    "for selling vessels and supplies to other potential captains and "
    "shippers. He is an average sized man, and looks reasonably friendly."
    );
  SetAdjectives( ({ "count", "shipping" }) );
  
  SetRace("human");
  SetGender("male");
  SetBaseLanguage("Avera");
  SetLocalCurrency("ducats");
  
  SetMorality(750);
  SetClass("merchant");
  SetLevel(30);
  AddCurrency("ducats", random(100));
  
  SetWharf(AVERATH_ROOM "wharf");
  SetLargestShip(VS_CRUISER);
  SetLimit(1);
}
