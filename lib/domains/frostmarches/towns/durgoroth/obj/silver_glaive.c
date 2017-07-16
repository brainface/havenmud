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
  SetKeyName("glaive");
  SetId( ({ "glaive" }) );
  SetAdjectives( ({ "strange","silver"}) );
  SetShort("a strange silver glaive");
  SetLong(
    "At first glance an ordinary glaive, further inspection "
    "reveals a strange weight to the weapon, and the grip seems "
    "unsuited to any race you know. The shaft of the weapon is "
    "made of something not quite wood, inscribed with many symbols "
    "of a foreign tongue. The axehead itself seems straightforward enough, "
    "solid mithril sharpened to a razor's fine edge, curving to a point at the "
    "tip of the polearm."
  );
  SetHands(2);
  SetClass(40);
  SetWeaponType("hack");
  SetDamageType(SLASH | MAGIC);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(4000);
  SetValue(5000);
  SetMass(500);
  SetMaterials( ({ "mithril" }) );
  SetRepairDifficulty(75);
  SetProperty("history",
    "Strangely, you can recall no details of this history "
    "of this object upon the continent of Kaillie or the "
    "known planes."
  );
  SetProperty("magic",
    "This weapon has been enchanted with many runes vicious "
    "to creatures of otherplanar origins. The forms are foriegn "
    "and unfamiliar, however. It's possible some daemon dragged "
    "it back from a far plane."
  );
}

int eventStrike(object who) {
  int nolive = 0;
  int amount = random(60);
  string race = who->GetRace();

  if(race == "daemon" ||
     race == "demon"  ||
     race == "devil"  ||
     race == "angel"  ||
     race == "elemental"  ||  
     race == "thing") {
    nolive = 1;
  }

  if (!random(5)) {
    if (nolive == 1) {
        message("action", "Violent sky-blue runes %^BOLD%^CYAN%^ignite%^RESET%^ "
           "along the entire length of the glaive!",
        environment(environment()) );
        return (item::eventStrike(who) + amount);
    }
  }
  return (item::eventStrike(who));
}


