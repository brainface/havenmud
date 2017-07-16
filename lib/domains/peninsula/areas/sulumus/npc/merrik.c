// Proximo@Via Imperialis
// 06/02/2003

#include <lib.h>
#include <std.h>
#include <vendor_types.h>
#include "../sulumus.h"

inherit LIB_VENDOR;

static void create() {
  ::create();
  SetKeyName("merrik");
  SetId( ({ "merrik", "trader" }) );
  SetAdjectives( ({ "sulumus" }) );
  SetShort("Merrik the Sulumus Trader");
  SetLong(
     "This tall, thin young man is one of the many merchants who have "
     "come and gone from this trading post. He has settled himself here, "
     "deciding against traveling to far off and dangerous lands. He seems "
     "to be a free spirit, speaking his mind when given the opportunity. "
  );
  SetRace("human"); SetBaseLanguage("Imperial");
  RemoveLanguage("Human");
  SetLanguage("Imperial", 100, 1);
  SetGender("male");
  SetClass("merchant");
  SetMorality(15);
  SetVendorType(VT_ALL);
  SetSkill("knife combat", 1, 2);
  SetSkill("bargaining", 1, 2);
  SetInventory( ([
     STD_WEAPON + "small_knife" : "wield knife in right hand",
     STD_OBJ + "storage/pouch" : "wear pouch",
  ]) );
  SetLevel(10);
  SetStorageRoom(S_ROOM "str_sh");
  SetLimit(1);
  SetLocalCurrency("imperials");
}
