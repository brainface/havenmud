//Illura@Haven
//Nov2010
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("ocean diamond");
  SetShort("an ocean blue diamond");
  SetId( ({ "diamond", "gem" }) );
  SetAdjectives( ({ "ocean", "blue"}) );
  SetLong(
    "Mine the depths of Glimmerdin for a lifetime and "
    "you would not uncover such a brilliant stone. It "
    "is naturally a blue-green hue, and sparkles "
    "more brilliantly than any other gem you have seen "
    "before. Surely it is worth a fortune.");
  SetMass(8);
  SetValue(4000);
  SetDamagePoints(10000);
  SetMaterial( ({ "natural" }) );
  SetVendorType(VT_TREASURE);
  }
