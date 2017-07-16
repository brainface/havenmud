#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>
 
inherit LIB_ARMOUR;
 
static void create()
{
  armour::create();
  SetKeyName("open helm");
  SetId( ({ "helm", "helmet" }) );
  SetAdjectives( ({ "large", "open" }) );
  SetShort("a large open helm");
  SetLong(
     "The face of this large iron helm is entirely open, making it an "
     "easy helmet to see out of. This helmet looks to be rather sturdy, "
     "if not a very well made piece of armour. "
  );
  SetMass(30);
  SetValue(80);
  SetArmourClass(ARMOUR_PLATE);
  SetDamagePoints(950);
  SetSize(SIZE_LARGE);
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
