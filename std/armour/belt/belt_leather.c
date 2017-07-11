#include <lib.h> 
#include <damage_types.h>
#include <size.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
 
inherit LIB_ARMOUR;
 
static void create()
{
  armour::create();
  SetKeyName("leather belt");
  SetId(( { "belt" } ));
  SetAdjectives( ({ "leather" }) );
  SetShort("a leather belt");
  SetLong("The leather is un-dyed and makes for an un-remarkable belt.");
  SetMass(5);
  SetValue(10);
  SetArmourClass(ARMOUR_LEATHER);
  SetSize(SIZE_MEDIUM);

  SetDamagePoints(300);
 
 
  SetArmourType(A_BELT);
  SetVendorType(VT_TREASURE | VT_ARMOUR | VT_FUR);
 
  SetWear("The belt fits snugly");

  SetMaterial( ({ "leather" }) );
   SetWarmth(1);
  SetRepairDifficulty(1);
  SetRepairSkills( ([
                      "leather working" : 1,
                      "armour smithing" : 1,
                 ]) );
}
