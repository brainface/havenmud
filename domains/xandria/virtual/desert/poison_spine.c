/*
// poisonous spine for xandrian manticore
*/
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("a barbed spine");
  SetId( ({ "spine" }) );
  SetAdjectives( ({ "barbed" }) );
  SetShort("a barbed spine");
  SetLong(
    "This is a thin black spine, similiar to a porcupine's but nearly the "
    "length of an ogre's hand. Tiny barbs line the length of the spine, and "
    "a clear viscous liquid drips from the tip. It looks safe to hold from "
    "the base."
  );
  SetClass(25);
  SetDamagePoints(2000);
  SetValue(1500);
  SetWeaponType("knife");
  SetDamageType(PIERCE);
  SetMass(100);
  SetMaterial( ({ "natural" }) );
  SetProperty("history",
    "This is a discarded spine from a manticore's tail."
    "It still contains some of the creature's poison."
  );
  SetRepairDifficulty(40);
  SetVendorType(VT_WEAPON);
}

// has a chance to poison the target
int eventStrike(object who) {
  // a fairly low chance, as poison counters can add up fast.
  if (!random(10)) {
    send_messages("sting",
      "$agent_name%^GREEN%^ $agent_verb%^RESET%^ $target_name viciously "
      "with $agent_possessive barbed spine!", environment(), who,
      environment(environment())
    );
    who->AddPoison(10+random(20));
  }
  return (item::eventStrike(who));
}
