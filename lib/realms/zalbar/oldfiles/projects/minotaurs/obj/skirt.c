#include <lib.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("skirt");
  SetId( ({ "skirt"}) );
  SetAdjectives( ({ "leather" }) );
  SetShort("a leather skirt");
  SetLong("This leather skirt is no more than belt with leather straps hanging from "
          "it. Each strap is reinforced with a line of metal studded going down the "
          "middle of strap. The straps would hang right above the knee of the wearer. ");
  SetVendorType(VT_ARMOUR);
  SetMass(60);
  SetValue(800);
  SetDamagePoints(1500);
  SetArmourClass(ARMOUR_REINFORCED);
  SetArmourType(A_PANTS);
  SetMaterial( ({"leather","metal"}) );
  SetWarmth(10);
  SetSize(SIZE_LARGE);
  SetRepairSkills( ([
     "armour smithing" : 25,
     "leather working" : 25,
     "metal working"   : 10,
     ]) );
  SetRepairDifficulty(25);
}