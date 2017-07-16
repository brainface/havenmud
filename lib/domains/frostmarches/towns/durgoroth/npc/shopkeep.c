#include <lib.h>
#include "../durgoroth.h"
#include <vendor_types.h>
inherit LIB_VENDOR;

static void create() {
  ::create();
  SetKeyName("Borxtl");
  SetId( ({ "borxtl","scavenger" }) );
  SetShort("Borxtl the Scavenger");
  SetLong("Borxtl is not an overly powerful daemon"
          " but his intelligence has kept him alive"
          " thusfar. He has carved a niche for himself"
          " by selling various items to the other"
          " survivors in the Ruins of Durogorth.");
  SetMorality(-1500);
  SetRace("daemon");
  SetClass("merchant");
  SetSkill("melee combat",1,1);
  SetLevel(180);
  SetGender("male");
  SetVendorType(VT_ALL);
  SetLocalCurrency("crystals");
  SetStorageRoom(DURG_ROOM "store_storage");
  SetMaxSingleItem(12);
  SetMaxItems(500);
}
