// mahkefel 2010
// supa throwing weapon for havenwood.

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("chakram");
  SetId( ({ "chakram" }) );
  SetAdjectives( ({ "razor-sharp", "razor", "sharp" }) );
  SetShort("a razor-sharp chakram");
  SetLong(
    "This is a chakram, a metal hoop with a sharp blade around the "
    "circumference. The interior handle is made of polished wood "
    "and decorated with a tree-like sigil. The exterior blade is "
    "gleaming, paper thin mithril with wicked barbs. Though a "
    "difficult weapon to use, it is a deadly instrument in the right "
    "hands."
  );
  SetClass(30);
  SetDamagePoints(1500);
  SetValue(3000);
  SetProperty( "magic",
    "This weapon is layered with enchantments to improve sharpness "
    "and enhance bleeding."
  );
  SetWeaponType("projectile");
  SetDamageType(SLASH);
  SetRepairDifficulty(90);
  SetMass(50);
  SetMaterial( ({ "mithril"}) );
  SetVendorType(VT_WEAPON);
}

int eventStrike(object who) {
  if (!random(30)) {
  send_messages( "rip",
    "%^RED%^ $agent_possessive_noun" + "'s chakram $agent_verb "
    "into $target_possessive_noun flesh, leaving a gaping wound.%^RESET%^",
    environment(), who, environment(who) );
    who->AddBleeding(random(15)+10);
  }
  return (item::eventStrike(who));
}

