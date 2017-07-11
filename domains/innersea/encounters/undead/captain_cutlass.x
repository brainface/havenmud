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
  SetKeyName("cutlass");
  SetId( ({ "cutlass" }) );
  SetAdjectives( ({ "ancient","shimmering" }) );
  SetShort("an ancient, shimmering cutlass");
  SetLong(
    "This cutlass has a long, curved blade with a "
    "razor sharp edge. Dried bloodstains and unidentifiable "
    "ichor mar the surface of sword and attest its use in countless "
    "battles. Despite its evident age, the blade still shimmers "
    "in the light and shows no signs of wear."
  );
  SetHands(1);
  SetClass(30);
  SetWeaponType("slash");
  SetDamageType(SLASH | MAGIC);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(2000);
  SetValue(1600);
  SetMass(300);
  SetMaterials( ({ "metal" }) );
  SetRepairDifficulty(75);
  SetProperty("history",
    "This blade was recovered from the murderous captain "
    "of The Black Night, a notorious ghost ship that prowls "
    "the ruined sea."
  );
  SetProperty("magic",
    "Long used in the company of violent undead, "
    "this sword seems to have developed some antipathy "
    "towards the creatures."
  );
}

int eventStrike(object who) {
  int nolive = who->GetUndead();
  int amount = random(60);
  if (!random(5)) {
    if (nolive == 1) {
        message("action", "Brilliant light shines from the "
        "wound created by " + environment()->GetCapName() + "'s cutlass.",
        environment(environment()) );
        return (item::eventStrike(who) + amount);
    }
  }
  return (item::eventStrike(who));
}

