/*  A full suit of laced leather/metal/cloth armour */
/* modified as newbie style */
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("oyoroi");
  SetShort("a suit of laced armour");
  SetId( ({ "armour", "suit", "oyoroi" }) );
  SetAdjectives( ({ "suit of", "laced" }) );
  SetLong("The oyoroi is a full suit of decorative laced armour which "
          "covers the full body of the wearer.  It is often inlaid with "
          "battle honors won and is nearly an art form in itself. "
          "This set obviously belonged to a young warrior with few battle "
          "honors.");
  SetMaterials( ({ "metal", "leather", "textile" }) );
  SetWarmth(15);
  SetRepairSkills( ([
      "metal working" : 15,
      "leather working" : 15,
      "textile working" : 15,
     "armour smithing" : 15,
    ]) );
  SetRepairDifficulty(65);
  SetArmourClass(ARMOUR_REINFORCED);
  SetSize(SIZE_MEDIUM);
  SetValue(250);
  SetMass(1200);
  // SetProtection(SLASH, 10);
  SetDamagePoints(2500);
  // SetProtection(PIERCE, 10);
  // SetProtection(BLUNT, 10);
  // SetProtection(COLD, 5);
  // SetProtection(HEAT, 3);
  SetArmourType(A_BODY_ARMOUR);
 }
