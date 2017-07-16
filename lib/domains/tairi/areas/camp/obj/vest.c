#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("leather vest");
  SetRepairDifficulty(13);
  SetRepairSkills( ([
    "leather working" : 1,
    "armour smithing" : 1,
    ]) );
  SetMaterial( ({ "leather" }) );

  SetWarmth(15);
  SetShort("a full leather vest");
  SetId( ({ "vest", "leather vest", "full leather vest" }) );
  SetLong("This is a vest of leather armour designed for use by "
          "medium sized creatures.");
  SetAdjectives( ({ "leather", "full" }) );
  SetArmourType(A_VEST);
  // SetProtection(SLASH, 6);
  // SetProtection(PIERCE, 4);
  // SetProtection(BLUNT, 5);
  // SetProtection(COLD, 3);
  SetDamagePoints(600);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_LEATHER);
  SetMass(120);
  SetValue(random(400));
 }
