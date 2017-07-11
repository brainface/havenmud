#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("belt");
   SetShort("a black belt");
   SetId( ({ "belt" }) );
   SetAdjectives( ({ "black" }) );
  SetLong(
    "The belt is a shiny black color with a simple metal buckle. "
    "The front of the buckle is painted black, which serves to "
    "prevent any reflection from the metal. This is useful for "
    "those who want to be able to move through the night "
     "undetected."
  );
   SetMass(2);
   SetValue(45);
   SetArmourClass(ARMOUR_CLOTH);
   SetVendorType(VT_CLOTHING);
   SetArmourType(A_BELT);
   SetDamagePoints(450);
   // SetProtection(BLUNT,3);
   // SetProtection(SLASH,3);
   // SetProtection(PIERCE,3);
   SetProperty("magic","The belt has a slight magical protection "
               "on them.");
   SetProperty("history","The belt used to belong to Minkin, the "
               "owner of the inn in Parva.");
   SetMaterial( ({ "leather" }) );
   SetWarmth(1);
   SetSize(SIZE_SMALL);
}
