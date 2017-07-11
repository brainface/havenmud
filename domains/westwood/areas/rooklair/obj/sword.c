#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("sword");
  SetRepairDifficulty(22);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([
    "metal working" : 15,
   "weapon smithing" : 10,
     ]) );
  SetShort("a dazzling longsword");
  SetAdjectives( ({ "dazzling" }) );
  SetId( ({ "longsword", "dazzling longsword" }) );
  SetLong("The longsword seems to radiate a slight glow, "
    "lighting the area slightly.  The edge looks very "
    "sharp and the blade very heavy.  Etched into the "
    "blade is a set of runes that roughly translate "
    "to 'LifeGiver.'");
  SetClass(30);
  SetDamagePoints(2500);
  SetValue(5000);
  SetMass(250);
  SetVendorType(VT_WEAPON);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetRadiantLight(15);
  SetProperty("magic","The sword seems adept at drawing opponents "
    "life force into the user.");
  }

int eventStrike(object ob) {
  int amount = random(10) + 10;
  if (!random(15)) {
    ob->AddHealthPoints(-amount);
    environment()->AddHealthPoints(amount);
    message("weapon", "%^RED%^The sword seems to be making "
      "slurping noises as it hits.%^RESET%^",
                      environment(environment()));
  }
  return item::eventStrike(ob);
}
