// HOODed travellers cloak
// for acro trainer
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("cloak");
  SetShort("a hooded traveling cloak");
  SetLong("This is a long cloak of supple dark leather, complete with a hood. "
    "Though a bit heavy, there's not much better to keep the rain off."
  );
  SetId( ({ "cloak" }) );
  SetAdjectives( ({ "hooded","travelling","traveling" }) );
  SetArmourClass(ARMOUR_LEATHER);
  SetArmourType(A_CLOAK);
  SetDamagePoints(2000);
  SetMass(300);
  SetMaterial( ({ "leather" }) );
  SetProperty("history",
    "Though not magical, the leather has been treated thoroughly with some "
    "waterproofing and weatherizing alchemy, and will protect the wearer "
    "somewhat from water and extreme temperatures."
  );
  SetRepairDifficulty(100);
  SetSize(SIZE_SMALL);
  SetValue(1500);
  SetProtectionBonus(HEAT|COLD|WATER,10);
}


