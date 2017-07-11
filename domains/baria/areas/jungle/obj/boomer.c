/*  A boomerang */
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("boomerang");
  SetShort("a small curved boomerang");
  SetId( ({ "boomerang" }) );
  SetAdjectives( ({ "small", "curved" }) );
  SetLong("This small, curved piece of wood is a boomerang. "
          "It is used as a projectile weapon that can be used "
          "only by a skilled wielder.");
  SetClass(13);
  SetValue(80);
  SetMass(75);
  SetWeaponType("projectile");
  SetDamagePoints(1200);
  SetMaterial( ({ "wood" }) );
  SetVendorType(VT_WEAPON);
  SetDamageType(BLUNT);
  SetRepairDifficulty(10);
  SetRepairSkills( ([
                     "wood working" : 1,
                     "weapon smithing" : 1,
                 ]) ); 
}

int eventStrike(object target) {
  send_messages("", "$agent_possessive_noun boomerang flies towards "
                    "$target_name...",this_player(),target,
                     environment(this_player())
               );
  if (!random(100)) {
    send_messages("are",
       "$agent_name $agent_verb stunned by the sudden hit of the boomerang!",
       target, 0, environment(this_player()));
    target->SetParalyzed(random(4) + 1);
  }
  return item::eventStrike(target);
}
