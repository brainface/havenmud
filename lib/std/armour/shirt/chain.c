#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("chainmail shirt");
  SetId( ({ "shirt", "chainmail", "mail" }) );
  SetAdjectives( ({ "chainmail", "mail", "chain" }) );
    SetShort("a chainmail shirt");
  SetLong("This is a fine shirt of chainmail.  It is made of interlocking "
           "links of metal that help to fend off damage to the wearer.");
    SetVendorType(VT_ARMOUR);
    SetMass(375);
    SetArmourClass(ARMOUR_CHAIN);
    SetValue(325);
    SetSize(SIZE_MEDIUM);
    SetDamagePoints(1200);
    SetArmourType(A_ARMOUR);
  SetRepairSkills( ([
    "armour smithing" : 1,
    "metal working" : 1,
  ]) );
  SetRepairDifficulty(10);
  SetMaterial( ({ "metal" }) );
  SetWarmth(0);
  }
