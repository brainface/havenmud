#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("dusty skull");
   SetShort("a dusty skull");
   SetId( ({ "skull" }) );
   SetAdjectives( ({ "dusty" }) );
   SetLong("Dusty is caked onto the skull as it fell upon the "
           "skin which used to cover these bones.  It crumbles "
           "slightly.");
   SetMass(15);
   SetValue(5);
   SetVendorType(VT_TREASURE);
   SetDamagePoints(15);
   SetMaterial( ({ "natural" }) );
   SetDestroyOnSell(1);
   SetProperty("history","This skull was stolen from the graves of the "
               "dead of Vale Castle.");
}