/* A scriptic helm */
#include <lib.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("kabuto");
  SetShort("a huge and crested helmet");
  SetId( ({ "helmet", "kabuto" }) );
  SetAdjectives( ({ "huge", "crested" }) );
  SetLong("This large helmet is the decorative marking of a samurai "
          "warrior.  Made of metal and sculpted rather than tempered, "
          "this is the helmet of a true warrior, one designed with its "
          "appearance in mind as well as functionality.");
  SetArmourType(A_HELMET);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_PLATE);
  SetValue(800);
  SetMass(100);
  SetDamagePoints(2500);
  // SetProtection(SLASH, 25);
  // SetProtection(PIERCE, 25);
  // SetProtection(BLUNT, 25);
  SetMaterial( ({ "metal" }) );
  SetWarmth(0);
  SetRepairSkills( ([
    "metal working" : 15,
    "armour smithing" : 15,
    ]) );
  SetRepairDifficulty(60);
 }
