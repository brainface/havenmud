#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("gold fragment");
   SetShort("a gold fragment");
   SetId( ({ "gold","fragment","gold fragment","golden fragment" }) );
   SetAdjectives( ({ }) );
   SetLong("Cracks have formed in this fragment of gold; all are "
           "filled with dust.");
   SetMass(3);
   SetValue(20);
   SetVendorType(VT_TREASURE);
   SetDamagePoints(80+random(20));
   SetMaterial( ({ "metal" }) );
}