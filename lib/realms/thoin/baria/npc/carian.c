//
//  the shopkeep
//  kyla 11-97
//  Modified by Rhakz - Angel Cazares
//  Date: 10/13/98
//
#include <lib.h>
#include "../jungle.h"
#include <vendor_types.h>
inherit LIB_VENDOR;
  
static void create() {
  vendor::create();
  SetKeyName("Carian");
  SetShort("Carian the Trader");
  SetId( ({"carian","man","carian the trader","trader"}) );
  SetGender("male");
  SetAdjectives( ({ "burly", "short"}) );
  SetMorality(-20);
  SetLong("This short and burly man is responsible for the mercantile "
          "business of Baria. He trades, sells and buys goods and "
          "wares from barians and also from inhabitants of other "
          "towns and villages. He would gladly sell his "
          "goods for their value in chits.");
  SetRace("human");
  SetClass("merchant");
  SetLevel(30);
  SetTown("Baria");
  SetLocalCurrency("chits");
  SetStorageRoom(BARIA_ROOM + "str_sh");
  SetMaxSingleItem(15);
  RemoveLanguage("Enlan");
  SetLanguage("Barian", 100, 1);
  SetVendorType(VT_ALL);
}
