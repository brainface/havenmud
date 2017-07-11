/*  A full suit of laced leather/metal/cloth armour */
#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
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
          "battle honors won and is nearly an art form in itself.");
  SetMaterials( ({ "metal", "leather", "textile" }) );
  SetWarmth(20);
  SetRepairSkills( ([
      "metal working" : 15,
      "leather working" : 15,
      "textile working" : 15,
     "armour smithing" : 15,
    ]) );
  SetRepairDifficulty(65);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_REINFORCED);
  SetValue(2500);
  SetMass(1200);
  // SetProtection(SLASH, 25);
  SetDamagePoints(2500);
  // SetProtection(PIERCE, 25);
  // SetProtection(BLUNT, 25);
  // SetProtection(COLD, 15);
  // SetProtection(HEAT, 10);
  SetArmourType(A_BODY_ARMOUR);
 }
