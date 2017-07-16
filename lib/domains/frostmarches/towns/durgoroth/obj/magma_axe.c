// mahkefel 2011

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("axe");
  SetId( ({ "axe" }) );
  SetAdjectives( ({ "molten","battle"}) );
  SetShort("a molten battle axe");
  SetLong(
    "A half-moon axehead of flowing igneous rock wrapped "
    "around a charred steel handle, the enchantments and "
    "effects of this weapon are glaringly obvious and lacking "
    "in all subtlety."
  );
  SetHands(1);
  SetClass(30);
  SetWeaponType("hack");
  SetDamageType(HEAT);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(4000);
  SetValue(3000);
  SetMass(500);
  SetMaterials( ({ "natural" }) );
  SetRepairDifficulty(80);
  SetProperty("history",
    "An armament favored by elementals, this one likely given "
    "to a respected lieutenant or even general of some planar "
    "army."
  );
  SetProperty("magic",
    "The molten rock is rather a dead giveaway."
  );

}

int eventStrike(object who) {
  int amount = random(60);

  if (!random(10)) {
    if (1) {
        message("action", "Magma %^BOLD%^RED%^spews and sputters%^RESET%^ into the "
          "wound created by the molten axe!",
          environment(environment()) );
        return (item::eventStrike(who)+amount);
    }
  }
  return (item::eventStrike(who));
}

