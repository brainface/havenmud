// a strap from a pair of boots

#include <lib.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("strap");
  SetId( ({ "strap" }) );
  SetAdjectives( ({ "long","leather","thin"}) );
  SetShort("a long thin leather strap" );
  SetLong( "This leather strap is made of a plush brown leather. Roughly "
           "a yard in length this strap shows evidence of have been used "
           "elsewhere. Some chaffing and mold is displayed on the surface "
           "and hones a somewhat useless quality to it.");
  SetMass(1);
  SetValue(1);
  SetVendorType(VT_TREASURE);
}