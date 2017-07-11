// Artanis@Haven (August 07, 2004)

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("longbow");
  SetShort("a hand-crafted longbow");
  SetId( ({ "longbow", "bow" }) );
  SetAdjectives( ({ "hand", "crafted" }) );
  SetLong(
     "This weapon has been made out of the local variety of jungle bamboo "
     "and has been formed into the shape of a bow. The string looks to "
     "have been cured in animal fat to give it added strength and ease "
     "of use. "
  );
  SetClass(14);
  SetHands(2);
  SetValue(150);
  SetMass(125);
  SetWeaponType("projectile");
  SetDamagePoints(1450);
  SetMaterial( ({ "wood" }) );
  SetVendorType(VT_WEAPON);
  SetDamageType(PIERCE);
  SetRepairDifficulty(18);
  SetRepairSkills( ([
     "wood working" : 3,
     "weapon smithing" : 3,
  ]) );
}

int eventStrike(object target) {
  send_messages("fire", "$agent_name $agent_verb an arrow towards "
                        "$target_name...",this_player(),target,
                        environment(this_player()));
  return item::eventStrike(target) + random(40);
}
