#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("boots");
   SetShort("a pair of black boots");
   SetId( ({ "boots" }) );
   SetAdjectives( ({ "pair of","black" }) );
   SetLong("The boots are a deep black color.  Faded black "
           "laces are used to hold them on one's feet tightly.  "
           "They look fuzzy, like the leather used to make the "
           "boots was covered with cloth.");
   SetMass(15);
   SetValue(95);
   SetVendorType(VT_CLOTHING);
  SetProperty("multiples", 1);
   SetArmourClass(ARMOUR_CLOTH);
   SetArmourType(A_BOOT);
   SetDamagePoints(450);
   // SetProtection(BLUNT,5);
   // SetProtection(SLASH,5);
   // SetProtection(PIERCE,5);
   SetProperty("magic","The boots have a slight magical protection "
               "on them.");
   SetProperty("history","These boots used to belong to Minkin, the "
               "owner of the inn in Parva.");
   SetMaterial( ({ "textile","leather" }) );
   SetWarmth(6);
   SetSize(SIZE_SMALL);
}
