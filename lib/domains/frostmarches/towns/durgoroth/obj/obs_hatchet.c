// mahkefel 2010
//  sword for black night captain
//  preeettty much good against him and his boarders.
//  i am once again copying mel's runed katana

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("hatchet");
  SetId( ({ "hatchet" }) );
  SetAdjectives( ({ "obsidian"}) );
  SetShort("an obsidian hatchet");
  SetLong(
    "The most primitive of weapons still capable of being "
    "called an axe, this is little more than a carefully "
    "sharpened chunk of obsidian nested into a handle of "
    "rough wood tied with sinew. Stains along the blade, "
    "rust colored or not, attest to its effectiveness."
  );
  SetHands(1);
  SetClass(30);
  SetWeaponType("hack");
  SetDamageType(SLASH | MAGIC);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(4000);
  SetValue(1000);
  SetMass(500);
  SetMaterials( ({ "natural" }) );
  SetRepairDifficulty(30);
  SetProperty("history",
    "Though you don't know this items exact history, weapons like "
    "this were common in the primitive stages of all races that "
    "were ever uncivilized, and can still be found in backwater "
    "realms such as Baria or Gwonish, with little design variation."
  );
  SetProperty("magic",
    "This hatchet is suspiciously effective, as if someone had "
    "searched through hundreds or thousands of merely servicable "
    "weapons until finding one of exceptional lethality."
  );

}

int eventStrike(object who) {
  int amount = random(10);

  if (!random(5)) {
    if (1) {
        message("action", "The hatchet opens a vicious wound!",
          environment(environment()) );
        who->AddBleeding(amount);
        return (item::eventStrike(who));
    }
  }
  return (item::eventStrike(who));
}

