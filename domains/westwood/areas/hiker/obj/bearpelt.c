#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;
inherit LIB_SMELL;
inherit LIB_TOUCH;

static void create() {
   armour::create();
   SetKeyName("bear pelt");
   SetShort("a large bear pelt");
   SetId( ({ "pelt" }) );
   SetAdjectives( ({ "large","bear","adult" }) );
   SetLong("The bear pelt must have come from an adult bear; it is "
           "quite large.  The hide is tough and heavy and the fur "
           "on it is coarse and rough, though thick.");
   SetMass(300);
   SetValue(200);
   SetArmourClass(ARMOUR_LEATHER);
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_CLOAK);
   SetDamagePoints(450);
   // SetProtection(PIERCE,9);
   // SetProtection(SLASH,8);
   // SetProtection(BLUNT,8);
   // SetProtection(COLD,7);
   // SetProtection(ACID,3);
   // SetProtection(WATER,3);
   // SetProtection(HEAT,3);
   SetMaterial( ({ "natural"}) );
  SetWarmth(25);
   SetRepairDifficulty(13);
   SetRepairSkills( ([
      "natural working" : 2,
      "armour smithing" : 2,
      ]) );
   SetSmell("The pelt smells dirty and rank.");
   SetTouch("The fur is very rough to the touch, but the hide is "
            "smooth in comparison.");
   SetSize(SIZE_LARGE);
}

mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}
