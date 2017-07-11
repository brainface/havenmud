#include <lib.h>
#include <vendor_types.h>
#include "../rook.h"

inherit LIB_ITEM;
 
static void create() {
  item::create();
  SetKeyName("painting");
  SetId( ({ "painting" }) );
  SetShort("an oil on canvas painting");
  SetLong("This is a painting of a lady standing on "
    "a white cloud.  It is painted with an oil based "
    "paint on a small canvas.  The frame is made of "
    "an exotic dark wood and is very valuable alone.");
  SetAdjectives( ({"oil","canvas"}) );
  SetMass(25);
  SetValue(3500);
  SetMaterial("natural");
  SetVendorType(VT_TREASURE);
}
