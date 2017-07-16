/*  Leather Armour - Koboldish - Level #1 Caverns  */

#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h> 
#include <size.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("koboldish leather");
  SetId( ({ "koboldish leather", "leather", "leather armour" }) );
  SetAdjectives( ({ "leather", "koboldish", "orange", "bright" }) );
  SetShort("koboldish leather armour");
  SetLong(
    "The leather armour is considered koboldish, because of it's "
    "color... a bright orange.  The armour looks as if it would provide "
    "little protection, but it's better than nothing."
  );
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_ARMOUR);
  SetArmourClass(ARMOUR_LEATHER);
  SetMass(175);
  SetValue(100);
  SetDamagePoints(250);
  SetSize(SIZE_SMALL);
  SetMaterial("leather");
  SetWarmth(15);
  SetRepairSkills( ([ 
    "leather working" : 1,
  ]) );
  SetRepairDifficulty(8);
}
