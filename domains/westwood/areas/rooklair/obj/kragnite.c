#include <lib.h>
#include <vendor_types.h>
#include "../rook.h"

inherit LIB_ITEM;
 
static void create() {
  item::create();
  SetKeyName("kragnite");
  SetId( ({ "kragnite","gem" }) );
  SetShort("a pale metallic gem");
  SetLong("Kragnite is a precious gemstone that is "
    "a pale metallic color and opaque.  The stone is "
    "cut into a small circle pattern with fine cuts.");
  SetAdjectives( ({"small","kragnite","gem","pale","metallic"}) );
  SetMass(5);
  SetValue(2500);
  SetMaterial("natural");
  SetVendorType(VT_TREASURE);
}
