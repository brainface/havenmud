#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("shirt");
   SetShort("a dark brown shirt");
   SetId( ({ "shirt" }) );
   SetAdjectives( ({ "dark","brown" }) );
   SetLong("The brown shirt is made of a rough, scratchy textile.  "
           "It couldn't be too comfortable for anyone with soft, "
           "sensitive skin, to wear, but it would offer some "
           "minimal protection from attacks.");
   SetMass(5);
   SetValue(35);
   SetVendorType(VT_CLOTHING);
   SetArmourClass(ARMOUR_CLOTH);
   SetArmourType(A_SHIRT);
   SetDamagePoints(75);
   // SetProtection(BLUNT,2);
   // SetProtection(SLASH,2);
   // SetProtection(PIERCE,2);
   // SetProtection(COLD,4);
   // SetProtection(HEAT,1);
   SetWear("The shirt is rough.");
   SetMaterial( ({ "textile" }) );
   SetWarmth(10);
   SetSize(SIZE_SMALL);
   SetRepairDifficulty(10);
   SetRepairSkills( ([
                       "textile working" : 1,
                  ]) );
   SetProperty("history","It used to be the property of Inimicii, "
               "the Parva Hunter.");
}
