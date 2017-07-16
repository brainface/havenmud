#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("whip");
  SetId( ({ "whip" }) );
  SetAdjectives( ({ "silver" }) );
  SetShort("a silver whip");
  SetLong(
    "The length of this whip is inlaid with silver.  "
    "Little silver claws have been braided into its "
    "tip for adding effect."
  );
  SetHands(1);
  SetClass(17);
  SetWeaponType("projectile");
  SetDamageType(PIERCE | MAGIC);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1000);
  SetValue(1600);
  SetMass(200);
  SetMaterials( ({ "metal" }) );
  SetRepairDifficulty(5);
  SetProperty("magic", "This whip has been empowered with"
              " the ability to inflict greater damage on lycanthropic"
              " foes.");
 }

int eventStrike(object who) {
  int nolive = who->GetProperty("lycanthrope");
  int amount = random(25) +100;
  if (nolive == 1) {
      message("action", 
      "%^MAGENTA%^Smoke rises from the wound created by " 
      + environment()->GetCapName() + "'s whip.%^RESET%^", 
      environment(environment()) );
      return (item::eventStrike(who) + amount);
   
  }
      return (item::eventStrike(who));
}
