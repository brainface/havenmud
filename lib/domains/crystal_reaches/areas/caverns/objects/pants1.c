/*  Pants - Gnome - Level #1 Caverns  */

#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h> 
#include <size.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("pants");
  SetId( ({ "comfortable pants", "pants" }) );
  SetAdjectives( ({ "comfortable" }) );
  SetShort("some comfortable pants");
  SetLong(
    "These pair of comfortable pants provide enough room for one to do "
    "almost anything in. This pair of pants are the color of freshly "
    "plowed soil and has small metallic buttons in the front."
  );
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_PANTS);
  SetArmourClass(ARMOUR_CLOTH);
  SetMass(35);
  SetValue(30);
  SetDamagePoints(175);
  SetSize(SIZE_SMALL);
  SetMaterial("textile");
  SetWarmth(10);
  SetRepairSkills( ([ "textile working" : 2,
  ]) );
  SetRepairDifficulty(5);
}
