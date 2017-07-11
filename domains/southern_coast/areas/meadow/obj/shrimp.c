// A dead shrimp for fishing(yes this works irl)
// For Platypus Bay
// Urien@Haven 06JUL08

#include <lib.h>
#include <vendor_types.h>
inherit LIB_BAIT_WITH;
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("shrimp");
   SetShort("a lifeless shrimp");
   SetId( ({ "shrimp" }) );
   SetAdjectives( ({ "lifeless" }) );
   SetLong(
           "This shrimp is lifeless, and gives off a fresh shrimp "
           "smell. It would make great bait."
           );
   SetMass(1);
   SetValue(5);

   SetVendorType(VT_FISHING);
   SetBaitStrength(3);
   SetMaterial( ({ "natural" }) );
   SetDamagePoints(1);
}

static mixed AddSave(mixed *vars) {
   return item::AddSave(vars);
}

