#include <lib.h>
#include <vendor_types.h>
#include <loot.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("rock salt");
  SetShort("a chunk of rock salt");
  SetId( ({ "salt", "chunk", "rock" }) );
  SetAdjectives( ({ "chunk", "chunk of", "rock" }) );
  SetLong("A small chunk of rock salt, greyish white and rock solid.");
  SetMass(15);
  SetValue(100);
  SetDamagePoints(400);
  SetMaterial( ({ "natural" }) );
  SetVendorType(VT_FOOD|VT_TREASURE);
} 
