/*  A stunning sapphire for bane devils to have */
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("sapphire");
  SetShort("a stunning sapphire");
  SetId( ({ "sapphire", "gem" }) );
  SetAdjectives( ({ "stunning" }) );
  SetLong("This is a large and stunning blue gemstone of great value.");
  SetMass(4);
  SetValue(500);
  SetDamagePoints(3000);
  SetMaterial( ({ "natural" }) );
  SetVendorType(VT_GEM|VT_TREASURE);
  }
