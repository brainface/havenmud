#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <armour_types.h>
#include <vendor_types.h>
 
inherit LIB_ARMOUR;
 
static void create()
{
  armour::create();
  SetKeyName("leather glove");
  SetId(( { "glove","leather glove"} ));
  SetShort("a leather glove");
  SetLong("The soft leather glove looks like it will just fit.");
  SetMass(15);
  SetValue(17);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_LEATHER);
  SetDamagePoints(300);
 
 
  SetArmourType(A_GLOVE);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
 
  SetWear("The glove feels soft and supple.");

  SetMaterial( ({ "leather" }) );
  SetWarmth(5);
  SetRepairDifficulty(1);
  SetRepairSkills( ([
                      "leather working" : 1,
                      "armour smithing" : 1,
                 ]) );
}
