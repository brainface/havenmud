/*  A stunning sapphire for bane devils to have */
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("sapphire");
  SetShort("a stunning sapphire");
  SetId( ({ "sapphire" }) );
  SetAdjectives( ({ "stunning" }) );
  SetLong("This is a large and stunning blue gemstone of great value.");
  SetMass(10);
  SetValue(1200);
  SetDamagePoints(10);
  SetMaterial( ({ "natural" }) );
  SetVendorType(VT_GEM);
  }
