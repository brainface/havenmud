#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>
 
inherit LIB_ARMOUR;
 
static void create()
{
  armour::create();
  SetKeyName("open helm");
  SetId( ({ "helm","helmet" }) );
  SetAdjectives( ({ "open" }) );
  SetShort("an open helm");
  SetLong(
    "The face of this iron helm is entirely open, making it much "
    "easier to see. This appears to be of a small size."
  );
  SetMass(30);
  SetValue(80);
  SetSize(SIZE_SMALL);
  SetArmourClass(ARMOUR_CHAIN);
  SetDamagePoints(450);
  SetArmourType(A_HELMET);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
  SetWear("The metal chills your ears as you slide the helmet on.");
  SetMaterial( ({ "metal" }) );
  SetWarmth(0);
  SetRepairDifficulty(3);
  SetRepairSkills( ([
                 "metal working" : 1,
                 "armour smithing" : 1,
               ]) );
}
