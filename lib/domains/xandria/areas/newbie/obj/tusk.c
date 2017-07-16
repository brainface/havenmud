//Selket@Haven
//2006
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("tusk");
  SetShort("a tusk");
  SetId( ({ "tusk" }) );
  SetAdjectives( ({ "hippo" "hippo's" }) );
  SetLong(
    "This is an ivory tusk, once belonging to a "
    "hippopotamus."
  );
  SetValue(10);
  SetDamagePoints(400);
  SetClass(5);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetVendorType(VT_WEAPON);
  SetMaterial( ({"natural"}) );
  }
