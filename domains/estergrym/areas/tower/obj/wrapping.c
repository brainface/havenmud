// Mummy wrapping cloned upon death (Just an item nothing more)

#include <lib.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("wrapping");
  SetId( ({ "mummy","mummy wrapping" }) );
  SetAdjectives( ({ "pile of", "white","pile"}) );
  SetShort( "a pile of white mummy wrapping" );
  SetLong( "It is made of paper thin cloth which has dust and dirt in "
           "various spots of its long length. It has multiple tears along "
           "the surface and some spots of chaffing.");
  SetMass(25);
  SetValue(25);
  SetVendorType(VT_TREASURE);
}