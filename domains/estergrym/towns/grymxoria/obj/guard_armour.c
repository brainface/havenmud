#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("blood red chainmail shirt");
  SetId( ({ "chainmail", "mail", "shirt" }) );
  SetAdjectives( ({ "chain", "mail", "blood", "red", "mail" }) );
  SetShort("a shirt of blood red chainmail");
  SetLong(
    "This shirt of chainmail is stained to a deep crimson "
    "color, which prevents any light from reflecting off the "
    "metal rings which are tightly wound to protect the wearer."
  );
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_SHIRT);
  SetArmourClass(ARMOUR_CHAIN);
  SetSize(SIZE_MEDIUM);
  SetMass(350);
  SetValue(350);
  SetDamagePoints(1600);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([ 
    "armour smithing" : 15,
    "metal working"   : 15,
     ]) );
  SetRepairDifficulty(15);
  // SetProtection(BLUNT,   8);
  // SetProtection(SLASH,  15);
  // SetProtection(PIERCE, 15);
}

