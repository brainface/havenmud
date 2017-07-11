// Amelia@Haven
#include <lib.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("boots");
   SetShort("a pair of dusty boots");
   SetId( ({ "boots" }) );
   SetAdjectives( ({ "pair of","dusty" }) );
   SetLong("Durable leather was sewn tightly together with "
           "strong string to make these boots.  They are "
           "a dark brown in color, but are covered with a "
           "light brown dust.");
   SetMass(40);
   SetValue(105);
  SetProperty("multiples", 1);
   SetSize(SIZE_MEDIUM);
   SetArmourClass(ARMOUR_CLOTH);
   SetVendorType(VT_CLOTHING);
   SetArmourType(A_BOOT);
   SetDamagePoints(340);
   // SetProtection(BLUNT,3);
   // SetProtection(SLASH,3);
   // SetProtection(PIERCE,3);
   // SetProtection(COLD,3);
   // SetProtection(HEAT,1);
   SetWear("The boots resist your attempts to pull them on.");
   SetMaterial( ({ "leather" }) );
   SetWarmth(5);
   SetRepairDifficulty(15);
   SetRepairSkills( ([
                       "leather working" : 1,
                  ]) );
   SetProperty("history","A Parvan citizen used to own these boots.");
}
