#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("boots");
   SetShort("a set of green boots");
   SetId( ({ "boots" }) );
   SetAdjectives( ({ "set of","two","dark","green" }) );
   SetLong("The boots are a nice, rich dark green color.  "
           "The style is simplistic; there are no laces or "
           "straps.  The leather looks tough and hard.");
   SetMass(25);
   SetValue(55);
   SetArmourClass(ARMOUR_CLOTH);
   SetSize(SIZE_MEDIUM);
   SetVendorType(VT_CLOTHING);
   SetArmourType(A_BOOT);
   SetDamagePoints(170);
   // SetProtection(BLUNT,5);
   // SetProtection(SLASH,4);
   // SetProtection(PIERCE,4);
   // SetProtection(COLD,5);
   // SetProtection(HEAT,2);
   SetWear("The boots resist being pulled on.");
   SetMaterial( ({ "leather" }) );
   SetWarmth(6);
   SetRepairDifficulty(17);
   SetRepairSkills( ([
                       "leather working" : 1,
                  ]) );
   SetProperty("history","It used to be the property of Alae, the Parva "
               "Ranger.");
}
