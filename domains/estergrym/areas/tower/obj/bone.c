// Some bones from a traveller perhaps..

#include <lib.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("bone");
  SetId( ({ "bone" }) );
  SetAdjectives( ({ "white","bleached","leg"}) );
  SetShort("a white bleached leg bone" );
  SetLong( "It holds the characteristics of a human bone. Rounded "
           "on the ends with bite marks all over the surface this bone is "
           "bleached from old age. There is an abrasion along the middle "
           "of the bone exposing the inside, which displays no marrow or "
           "insides to it.");
  SetMass(8);
  SetValue(1);
  SetVendorType(VT_TREASURE);
}