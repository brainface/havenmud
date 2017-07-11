// mahkefel 2011
// MAN FUCK ELVES
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("lash");
  SetId( ({"lash"}) );
  SetAdjectives( ({ "vicious" }) );
  SetShort("a vicious lash");
  SetLong(
    "This lash of corded rope is entiwed around "
    "broken shards of glass and tarnished bronze. "
    "More than an instrument of corporal punishment, "
    "it looks designed to inflict crippling pain on the "
    "target, and an aura of sadistic cruelty seems to "
    "surround it."
  );
  SetClass(25);
  SetDamagePoints(2000);
  SetValue(2500);
  SetWeaponType("projectile");
  SetDamageType(SLASH);
  SetMass(300);
  SetMaterial( ({ "textile" }) );
  SetVendorType(VT_WEAPON);
  SetHands(1);
  SetProperty("history",
    "This weapon seems similiar to others found among the "
    "worshippers of the Enniae religion from Lisht. They are "
    "now common among any number of groups with a grudge against "
    "the elves of Haven Town.");
  SetProperty("magic",
    "This weapon is enchanted to be particularly dehabilitating "
    "against those of elvin blood.");

}

int eventStrike(object who) {
  int bane = 0;
  int amount = random(10);

  if (who->GetRace() == "elf" || 
      who->GetRace() == "wild-elf" ||
      who->GetRace() == "dark-elf" ||
      who->GetRace() == "half-elf" )
  {
    bane = 1;
  }

  if (!random(5)) {
    if (bane == 1) {
      send_messages("", "The lash coils around $target_name and "
        "%^GREEN%^bites%^RESET%^ into $target_possessive flesh like "
        "a striking snake!",
        this_object(), who, environment(environment()) );
      return (item::eventStrike(who) + amount);
      who->AddPoison(amount);
    }
  }
  return (item::eventStrike(who));
}

