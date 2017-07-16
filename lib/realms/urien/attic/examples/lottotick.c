// A lottery ticket
// Only redeemed for imperials
// Since paid for by imperials


#include <lib.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("ticket");
  SetId( ({ "ticket" }) );
  SetAdjectives( ({ "lottery","lotto" }) );
  SetShort( "a lottery ticket" );
  SetLong( "This lottery ticket is a square parchment with some "
           "dried mud on its surface. It is possible to scratch "
           "the surface, but the commands do this file do not "
           "exist yet.");
  SetMass(1);
  SetValue(1);
  SetVendorType(VT_TREASURE);
}