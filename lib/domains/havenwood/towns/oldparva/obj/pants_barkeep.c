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
   SetKeyName("pants");
   SetShort("a pair of black pants");
   SetId( ({ "pants" }) );
   SetAdjectives( ({ "pair of","black" }) );
   SetLong("The dark pants are a shiny, shallow black.  "
           "They were made for a small person with a large stomach  "
           "The textile used to make them was thin and "
           "smooth.");
   SetMass(10);
   SetValue(125);
   SetArmourClass(ARMOUR_CLOTH);
   SetVendorType(VT_CLOTHING);
   SetArmourType(A_PANTS);
   SetDamagePoints(450);
   // SetProtection(BLUNT,3);
   // SetProtection(SLASH,3);
   // SetProtection(PIERCE,3);
   SetProperty("magic","The pants have a slight magical protection "
               "on them.");
   SetProperty("history","These pants used to belong to Minkin, the "
               "owner of the inn in Parva.");
   SetMaterial( ({ "textile" }) );
   SetWarmth(15);
   SetSize(SIZE_SMALL);
}
