// mahkefel 2011
// shuggoth tooth
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   ::create();
   SetKeyName("tooth");
   SetShort("a cracked yellow tooth");
   SetId( ({ "tooth" }) );
   SetAdjectives( ({ "cracked", "yellow"}) );
   SetLong(
     "Apparently the tooth of a large beast, the root is "
     "covered in dried black ichor and greenish stains. "
     "The enamel is chipped and yellow, with nasty cracks "
     "leaking yet more of the inkish ichor."
   );
   SetMass(30);
   SetValue(200);
   SetVendorType(VT_TREASURE);
   SetMaterial( ({ "natural" }) );
   SetWeaponType("knife");
   SetDamageType(PIERCE);
   SetDamagePoints(1000);
 
   SetProperty("history",
     "You're gazing at a tooth from the many-mawed shuggoth, "
     "a fearsome beast of the nearly unknown god tulu."
   );

   SetProperty("history",
     "You're gazing at a tooth from the many-mawed shuggoth, "
     "a fearsome beast of the nearly unknown god tulu."
   );

   SetProperty("magic",
     "Though not precisely magical, the fang quivers in your "
     "hand as if alive. Contamination with the substance covering "
     "it is likely unhealthy to nearly anything that originated in "
     "Kailee, alive or undead."
   );
}

int eventStrike(object who) {
  int amount = random(250);

  if (!random(20)) {
    SetDamageType(POISON|MAGIC);
    message("action", "Putrescent tumors bubble and pop around "
      "the gash created by the cracked fang!",
      environment(environment()) );
      return (item::eventStrike(who) + amount);
  }

  SetDamageType(PIERCE);
  return (item::eventStrike(who));
}

