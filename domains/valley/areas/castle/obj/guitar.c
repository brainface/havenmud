#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("plain guitar");
   SetShort("a plain guitar");
   SetId( ({ "guitar" }) );
   SetAdjectives( ({ "plain" }) );
   SetLong("Nothing in particular stands out about the guitar; "
           "it has no ornaments and appears to be in good repair.");
   SetMass(55);
   SetValue(40+random(10));
   SetVendorType(VT_TREASURE);
   SetDamagePoints(25+random(50));
   SetMaterial( ({ "wood","natural" }) );
}