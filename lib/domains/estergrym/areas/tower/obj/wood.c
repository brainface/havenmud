// A piece of wood (Just an item nothing more)

#include <lib.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("wood");
  SetId( ({ "wood" }) );
  SetAdjectives( ({ "long" ,"piece"}) );
  SetShort("a long piece of wood" );
  SetLong( "It appears to have been ripped from a tree or large branch. "
           "The overall wood is worn down from age and has been grinded "
           "down to be very blunt and it is almost the length of a small "
           "human childs body length.");
  SetMass(6);
  SetValue(3);
  SetVendorType(VT_TREASURE);
}