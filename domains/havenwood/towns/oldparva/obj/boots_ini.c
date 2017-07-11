#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("boots");
   SetShort("a pair of dark brown boots");
   SetId( ({ "boots" }) );
   SetAdjectives( ({ "pair of","dark","brown" }) );
   SetLong("The brown boots were made from a hard leather, and "
           "don't look to be formed for any normal feet, or the "
           "appendages of any race in particular.");
   SetMass(25);
   SetValue(65);
   SetVendorType(VT_CLOTHING);
   SetArmourClass(ARMOUR_CLOTH);
   SetArmourType(A_BOOT);
   SetDamagePoints(125);
   // SetProtection(BLUNT,3);
   // SetProtection(SLASH,3);
   // SetProtection(PIERCE,3);
   // SetProtection(COLD,2);
   // SetProtection(HEAT,1);
   SetWear("The boots pinch your feet.");
   SetMaterial( ({ "leather" }) );
   SetWarmth(5);
   SetSize(SIZE_SMALL);
   SetRepairDifficulty(15);
   SetRepairSkills( ([
                       "leather working" : 1,
                  ]) );
   SetProperty("history","It used to be the property of Inimicii, "
               "the Parva Hunter.");
}
