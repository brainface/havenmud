// mahkefel 2011
// just junk for smith trainer to wear
#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("leather glove");
  SetId( ({ "glove" }) );
  SetAdjectives( ({ "thick", "leather" }) );
  SetShort("a thick leather glove");
  SetLong(
    "This glove is made of thick hardened leather, capable of insulating "
    "the hands from great heat at the cost of dexterity. The palm and wrist "
    "is rigid and probably reinforced with metal."
  );
  SetMass(20);
  SetValue(200);
  SetMaterial( ({ "leather", "metal" }) );
  SetArmourClass(ARMOUR_REINFORCED);
  SetWarmth(5);
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_GLOVE);
  SetSize(SIZE_SMALL);
  SetDamagePoints(2500);
  SetProperty("history",
    "Though not enchanted, these blacksmith's gloves are insulated well "
    "enough to resist even magefire."
  );
}

// these gloves don't burn.
void eventDeteriorate(int DamageType) {
  object env = environment();
  object room;

  if (!env) {
    // there really should be an environment, but
    // torch code has this
    return;
  }
  room = environment(env);
  //deteroirate normally and ignore my bullcrap.
  if(!(DamageType & HEAT)) {
    armour::eventDeteriorate(DamageType);
    return;
  }

  // shield is held, send message to room and wielder

  if (room) {
    room->eventPrint(possessive_noun(env) + " " + GetKeyName() +
      " %^RED%^resists%^RESET%^ the heat.", ({env}) );
    env->eventPrint("Your " + GetKeyName() +
      " %^RED%^resists%^RESET%^ the heat.");
  } else {
    // shield is not held. send message to room
    env->eventPrint(capitalize(GetShort()) +
      " %^RED%^resists%^RESET%^ the heat.");
  }
}

