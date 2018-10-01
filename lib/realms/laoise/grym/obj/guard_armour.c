#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("blood red chainmail shirt");
  SetShort("a shirt of blood red chainmail");
  SetLong(
    "This shirt of chainmail is stained to a deep crimson "
    "color, which prevents any light from reflecting off the "
    "metal rings which are tightly wound to protect the wearer."
  );
  SetId( ({ "chainmail", "mail", "shirt" }) );
  SetAdjectives( ({ "chain", "mail", "blood", "red", }) );
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_SHIRT);
  SetMass(350);
  SetValue(350);
  SetDamagePoints(1600);
  SetSize(SIZE_MEDIUM);
  SetProtection(BLUNT,   8);
  SetProtection(SLASH,  15);
  SetProtection(PIERCE, 15);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([ 
    "armour smithing" : 15,
    "metal working"   : 15,
  ]) );
  SetRepairDifficulty(15);
}

