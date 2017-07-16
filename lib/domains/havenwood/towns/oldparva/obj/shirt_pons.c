#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("shirt");
   SetShort("an orange sun shirt");
   SetId( ({ "shirt" }) );
   SetAdjectives( ({ "orange","sun" }) );
   SetLong("A few decorative and garish suns freckle this "
           "red shirt.  It was made for someone who was very, "
           "very fat.  Red and orange buttons go up the front.  "
           "The shirt seems a little damp, especially on the "
           "back.");
   SetMass(10);
   SetValue(15);
   SetSize(SIZE_MEDIUM);
   SetArmourClass(ARMOUR_CLOTH);
   SetVendorType(VT_CLOTHING);
   SetArmourType(A_SHIRT);
   SetDamagePoints(35);
   // SetProtection(BLUNT,1);
   // SetProtection(SLASH,1);
   // SetProtection(PIERCE,1);
   // SetProtection(COLD,3);
   // SetProtection(HEAT,1);
   SetWear("The shirt is slightly damp, especially on its back.");
   SetMaterial( ({ "textile" }) );
   SetRepairDifficulty(8);
   SetRepairSkills( ([
                       "textile working" : 1,
                  ]) );
   SetProperty("history","This shirt used to be the property "
               "of Pons, a Parva storekeeper, or Snop, his twin brother.");
}
