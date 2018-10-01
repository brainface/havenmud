// by Dahaka
// Aug 2004

#include <lib.h>
#include <vendor_types.h>
#include "../drazh.h"

inherit LIB_VENDOR;

static void create() {
  vendor::create();
  SetKeyName("morsk");
  SetId( ({"morsk","smith","skaven"}) );
  SetShort("Morsk the apprentice smith");
  SetLong(
    "This small skaven is short in height but his bulging "
    "muscles show that Morsk does have some strength. The "
    "tattered fur and burn marks show that Morsk has been "
    "around a  forge most of his life."
    );
  SetRace("skaven");
  SetGender("male");
  SetClass("fighter");
  SetSkill("bargaining",1,1);
  SetLevel(10);
  SetMorality(-1200);
  SetTown("Drazh");
  SetVendorType(VT_WEAPON|VT_ARMOUR);
  SetLocalCurrency("roni");
  SetStorageRoom(V_ROOM + "misc/str_smithy");
  SetAction(10, ({
    "!say Do not ask Thannika, he got lazy.",
    "!say I can sell you weapons.",
    "!spit.",
    }) );
  SetInventory( ([
  V_OBJ + "hammer" : "wield hammer",
  ]) );
}
