// mahkefel 2010
// another copy of the tairi runed weapons
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("wooden stake");
  SetId( ({ "stake" }) );
  SetAdjectives( ({ "wooden" }) );
  SetShort("a wooden stake");
  SetLong("This is a simple wooden stake, carved into a"
    " taper at one end with a very sharp point. Etched"
    " along the length of the stake are holy symbols"
    " of the magildan faith.");
  SetHands(1);
  SetClass(12);
  SetWeaponType("pierce");
  SetDamageType(PIERCE | MAGIC);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(800);
  SetValue(40);
  SetMass(200);
  SetMaterials( ({ "wood" }) );
  SetRepairDifficulty(5);
  SetRepairSkills( ([
    "wood working" : 1,
    "weapon smithing" : 1,
  ]) );
  SetProperty("history", "Stakes such as these have been used for centuries"
    "to assault vampires.");
 }

int eventStrike(object who) {
  int vampire = who->GetUndeadType() == "vampire";
  int amount = random(25);

  if (vampire) {
      message("action", "%^RED%^Thick blood oozes%^RESET%^ from the wound"
      " created by " + environment()->GetCapName() + "'s wooden stake.", 
      environment(environment()) );
      return (item::eventStrike(who) + amount);
  
  }
      return (item::eventStrike(who));
}


