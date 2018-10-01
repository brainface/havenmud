#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("blood kris");
  SetId( ({ "kris" }) );
  SetAdjectives( ({ "blood" }) );
  SetShort("a blood kris");
  SetLong("This eight inch blade waves like willow branches"
          " in the wind. A blood hole has been made towards"
          " the base of the knife. The dark crimson appearance"
          " of what was once a steel blade gives the"
          " impression the blood hole has been used on"
          " more than one occasion.");
  SetHands(1);
  SetClass(18);
  SetWeaponType("knife");
  SetDamageType(PIERCE | MAGIC);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1000);
  SetValue(550);
  SetMass(150);
  SetMaterials( ({ "metal" }) );
  SetRepairDifficulty(5);
  SetRepairSkills( ([
    "metal working" : 1,
    "weapon smithing" : 1,
     ]) );
  SetProperty("magic", "This knife has the ability to"
              " draw blood when plunged into an opponent.");
 }

int eventStrike(object who) {
  int hit = random(5);
  int amt = random(10);

  if (hit == 3) {
  send_messages( ({ "plunge" }),
      "%^RED%^" + "$agent_possessive_name blood kris $agent_verb deep, drawing blood.
      %^RESET%^", this_player(), this_object(), environment(this_player()) );
  who->AddBleeding(2);
  return (item::eventStrike(who) + amt);
  }
  return (item::eventStrike(who));
}
