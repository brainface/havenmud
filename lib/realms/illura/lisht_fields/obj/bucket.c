//Illura@Haven
//Sept 2009
//bucket
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
item::create();
  SetKeyName( "bucket" );
  SetId( ({ "bucket" }) );
  SetAdjectives( ({ "small" }) );
  SetShort( "a small bucket" );
  SetLong( "This wooden bucket is used to gather fruits "
    "and vegetables. Alas, it is empty. This may be "
    "because of the enormous hole in the bottom." );
  SetMass(1);
  SetValue(1);
  SetVendorType(VT_TREASURE);
}
