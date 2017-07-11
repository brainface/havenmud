// A piece of parchment (Just an item nothing more)

#include <lib.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("parchment");
  SetId( ({ "piece", "of", "shredded" }) );
  SetAdjectives( ({ "small"}) );
  SetShort("a piece of shredded parchment" );
  SetLong( "This parchment does not contain any writing or engravings on "
           "surface or backside. It is square in shape and has an old look "
           "to it, as if stored away some time ago and forgotten. Its "
		   "overall function is useless and the surface would not hold "
		   "anything legible if someone wrote on it.");
  SetMass(1);
  SetValue(1);
  SetVendorType(VT_TREASURE);
}