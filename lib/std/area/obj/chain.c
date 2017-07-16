#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>

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
    SetValue(325);
    SetDamagePoints(1200);
  SetArmourType(A_ARMOUR);
  SetArmourClass(ARMOUR_CHAIN);
  SetRepairSkills( ([
    "armour smithing" : 1,
    "metal working" : 1,
  ]) );
  SetRepairDifficulty(10);
  SetMaterial( ({ "metal" }) );
  }
