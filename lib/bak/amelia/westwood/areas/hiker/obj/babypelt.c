#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;
inherit LIB_SMELL;
inherit LIB_TOUCH;

static void create() {
   armour::create();
   SetKeyName("baby bear pelt");
   SetShort("a baby bear pelt");
   SetId( ({ "pelt" }) );
   SetAdjectives( ({ "baby","bear","small" }) );
   SetLong("The fur is coarse and rough, and the hide is thick and "
           "tough.  The pelt itself, however, is small.");
   SetMass(75);
   SetValue(30);
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_CLOAK);
   SetDamagePoints(300);
   SetProtection(SLASH,5);
   SetProtection(PIERCE,7);
   SetProtection(BLUNT,5);
   SetProtection(HEAT,1);
   SetProtection(COLD,5);
   SetProtection(ACID,1);
   SetProtection(WATER,1);
   SetMaterial( ({ "natural","leather" }) );
  SetWarmth(15);
   SetRepairDifficulty(8);
   SetRepairSkills( ([
                       "leather working" : 1,
                       "natural working" : 1,
                       "armour smithing" : 1,
                  ]) );
   SetSmell("The hide smells of blood and rank death.");
   SetTouch("The hide is rough and leathery, but the fur on it is "
            "rougher yet.");
}

mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}
