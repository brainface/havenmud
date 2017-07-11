/*  Plain Bracelet - Kobold Women - Level #1 Caverns */

#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h> 
#include <size.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("bracelet");
  SetId( ({ "plain bracelet", "bracelet" }) );
  SetAdjectives( ({ "plain", "metal", "tarnished" }) );
  SetShort("a plain bracelet");
  SetLong(
    "This is a plain metal bracelet. It isn't a very noteworthy piece "
    "of jewelry, and it is tarnished."
  );
  SetVendorType(VT_TREASURE|VT_ARMOUR);
  SetArmourType(A_GLOVE);
  SetArmourClass(ARMOUR_CHAIN);
  SetMass(5);
  SetValue(200);
  SetDamagePoints(50);
  SetSize(SIZE_SMALL);
  SetMaterial("metal");
  SetWarmth(0);
  SetRepairSkills( ([ "metal working" : 1,
  ]) );
  SetRepairDifficulty(3);
}
