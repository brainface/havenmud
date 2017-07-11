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
  SetKeyName("wooden sandals");
  SetId(( { "sandals","sandal" } ));
  SetAdjectives( ({ "pair of","wooden" }) );
  SetShort("a pair of wooden sandals");
  SetLong("These sandals are intricately crafted from a dark wood.");
  SetMass(40);
   SetSize(SIZE_SMALL);
  SetValue(30);
  SetArmourClass(ARMOUR_NATURAL);
  SetDamagePoints(700);

  SetArmourType(A_BOOT);
  SetVendorType(VT_TREASURE | VT_ARMOUR);

  SetWear("The sandals fit snugly.");
  SetProperty("multiples", 1);

  SetMaterial( ({ "wood" }) );
  SetWarmth(3);
  SetRepairDifficulty(6);
  SetRepairSkills( ([
                      "armour smithing" : 1,
                      "wood working" : 4,
                 ]) );
}
