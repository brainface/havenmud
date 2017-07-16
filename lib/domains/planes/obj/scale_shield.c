/*  shield for abashai */
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("dragonscale shield");
  SetShort("a large dragonscale shield");
  SetLong("This is a large shield made from the harvested scales of "
          "a slain dragon. A leather strap on the inside allows it "
          "to be held easily in combat, and its great size would "
          "provide protection from any sort of attack.");

  SetId( ({ "shield", "dragonscale shield" }) );

  SetAdjectives( ({ "dragon", "dragonscale", "large", "scale" }) );
  SetArmourClass(ARMOUR_NATURAL);
  SetArmourType(A_SHIELD);
  SetDamagePoints(1500); 
  SetMass(400);
  SetMaterial( ({ "natural" }) );
  SetProperty("magic",
    "Crafted from the scales of a great black dragon, this shield "
    "is impervious to acidic substances."
  );
  SetRepairDifficulty(50);
  SetSize(SIZE_LARGE);
  SetValue(1000);
}

// dragonshield will not corrode from acid.
// this effectively affected limb near immune to acid,
// without me figured out immunities.
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
  if(!(DamageType & ACID)) {
    armour::eventDeteriorate(DamageType);
    return;
  }

  // shield is held, send message to room and wielder
  if (room) {
    room->eventPrint(possessive_noun(env) + " " + GetKeyName() 
      + " %^RED%^resists%^RESET%^ the caustic attack.", ({env}) );
    env->eventPrint("Your " + GetKeyName() + 
      " %^RED%^resists%^RESET%^ the caustic attack.");
  } else {
    // shield is not held. send message to room
    env->eventPrint(capitalize(GetShort()) + 
      "  %^RED%^resists%^RESET%^ the caustic attack.");
  }
}

