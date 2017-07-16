#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("shiny red ribbon");
   SetShort("a shiny red ribbon");
   SetId( ({ "ribbon" }) );
   SetAdjectives( ({ "red","shiny" }) );
   SetLong("The ribbon looks just like the type tied in the hair "
           "of little girls to try and keep them look nice and "
           "neat.  Its red color shines smoothly.");
   SetMass(1);
   SetValue(1);
  SetArmourClass(ARMOUR_CLOTH);
   SetVendorType(VT_TREASURE|VT_ARMOUR);
   SetArmourType(A_HELMET);
   SetDamagePoints(29);
   // SetProtection(PIERCE,1);
   // SetProtection(SLASH,1);
   // SetProtection(BLUNT,1);
   // SetProtection(ACID,1);
   SetMaterial( ({ "textile" }) );
   SetRepairDifficulty(1);
   SetRepairSkills( ([
                       "textile working" : 1,
                  ]) );
   SetSize(SIZE_SMALL);
}
