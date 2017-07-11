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
  SetKeyName("leather goggles");
  SetId( ({ "goggles" }) );
  SetAdjectives( ({ "leather","pair","of" }) );
  SetShort("a pair of leather goggles");
  SetLong(
    "These goggles are made of hardened leather, treated to resist "
    "flame. The tinted glass of the eyepieces would protect the eyes against "
    "smoke and ash and are thick enough to withstand a casual blow."
  );
  SetMass(20);
  SetValue(200);
  SetMaterial( ({ "leather", "natural" }) );
  SetArmourClass(ARMOUR_REINFORCED);
  SetWarmth(5);
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_VISOR);
  SetSize(SIZE_SMALL);
  SetDamagePoints(2000);
  SetProperty("history",
    "Though not enchanted, these blacksmith's goggles are insulated well "
    "enough to resist even magefire."
  );
}

// these goggles don't care bout no fire
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

