#include <lib.h>
inherit LIB_ITEM;
#include <vendor_types.h>
 
static void create() {
   item::create();
   SetKeyName("small toy");
   SetAdjectives( ({ "small" }) );
   SetId( ({ "toy" }) );
   SetShort("a small toy");
   SetLong("This is an all-purpose little toy, which becomes whatever "
           "nice toy you want just by thinking of that toy.  It is nearly "
           "weightless.");
   SetMass(1);
   SetValue(9999);
   SetVendorType(VT_TREASURE);
   SetMaterial("natural");
   SetDamagePoints(9999999);
   SetDestroyOnSell(1);
}
