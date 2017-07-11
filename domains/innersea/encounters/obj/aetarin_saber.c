// mahkefel 2011
//  sword for averath patrollman dude
//  deals a bit more damage and reduces mp on a proc
//  against conjurer/necro/practical magic users

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("saber");
  SetId( ({ "saber" }) );
  SetAdjectives( ({ "military" }) );
  SetShort("a military saber");
  SetLong(
    "This steel saber bears a razor-sharp edge. The steel shines "
    "and glimmers in the light, and the golden hilt gives "
    "comfortable grip." 
  );
  SetHands(1);
  SetClass(25);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1000);
  SetValue(600);
  SetMass(100);
  SetMaterials( ({ "metal" }) );
  SetRepairDifficulty(25);
  SetProperty("history",
    "This blade was obviously forged in the Duchy of Averath. "
    "Symbols of the Aetarin religion decorate the hilt."
  );
  SetProperty("magic",
    "This blade has been enchanted to disrupt the minds of conjurers "
    "and necromancers--all witches to the intolerant Aetarin faith."
  );
}

int eventStrike(object who) {
  int nolive = who->GetSkillLevel("conjuring")
    +who->GetSkillLevel("necromancy")
    +who->GetSkillLevel("practical magic");
  int amount = random(20)+5;
  if (!random(5)) {
    if (nolive) {
      message("action", "Eerie flame %^MAGENTA%^%^BOLD%^billows%^RESET%^ from "
        "the wound created by " + environment()->GetCapName() + "'s saber.",
        environment(environment()) );
      who->AddMagicPoints(-2*amount);
      who->eventPrint("You feel the unnatural flame burning through your mind!");
      return (item::eventStrike(who) + amount);
    }
  }
  return (item::eventStrike(who));
}


