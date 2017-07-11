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
  SetKeyName("leather boots");
  SetId(( { "boots","boot" } ));
  SetAdjectives( ({ "pair of","leather" }) );
  SetShort("a pair of leather boots.");
  SetLong(
    "The boots are well broken in. "
    "They appear to be made on a scale suitable "
    "for the smaller races."
  );
  SetMass(25);
  SetValue(15);
  SetArmourClass(ARMOUR_LEATHER);
  SetDamagePoints(400);
  SetSize(SIZE_SMALL);
 
 
  SetArmourType(A_BOOT);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
 
  SetWear("The boot slips on your foot comfortably.");
  SetProperty("multiples",1);

  SetMaterial( ({ "leather" }) );
  SetWarmth(8);
  SetRepairDifficulty(2);
  SetRepairSkills( ([
                      "armour smithing" : 1,
                      "leather working" : 1,
                 ]) );
}
