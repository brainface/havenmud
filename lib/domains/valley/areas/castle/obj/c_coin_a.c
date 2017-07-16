#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("ancient coin");
   SetShort("an ancient coin");
   SetId( ({ "coin" }) );
   SetAdjectives( ({ "ancient" }) );
   SetLong("Scratches mark the surface of the ancient coin, making the "
           "face imprinted upon it difficult to make out.  It looks like "
           "whoever is on it is not left alive today.");
   SetMass(2);
   SetDamagePoints(5);
   SetMaterial( ({ "natural" }) );
   SetValue(2);
   SetVendorType(VT_TREASURE);
   SetProperty("history","The ancient coin was the currency of "
               "some old dynasty that has long since fallen.");
}