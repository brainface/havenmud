#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("rope belt");
   SetShort("a rope belt");
   SetId( ({ "rope","belt" }) );
   SetAdjectives( ({ "rope" }) );
   SetLong("This simple length of rope is just long enough "
           "to tie around someone's waist.  It is thin and looks "
           "comfortable.");
   SetMass(6);
   SetValue(11);
   SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
   SetArmourType(A_BELT);
   SetDamagePoints(230);
   SetMaterial( ({ "natural" }) );
   SetWarmth(0);
   SetRepairDifficulty(10);
   SetRepairSkills( ([
                       "natural working" : 1,
                       "armour smithing" : 1,
                  ]) );
}
