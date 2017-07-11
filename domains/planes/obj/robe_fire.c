/*
 * robe of fire resistance
 * instead of granting an ability to the player
 * it simply refuses to deteriorate vs. fire
 * effectively giving some resistance
 */
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
::create(); 
  SetId( ({ "robe" }) );
  SetKeyName("thin red robe");
  SetShort("a thin red robe");
  SetLong(
    "This robe is made of a thin layer of coarse, translucent fabric. "
    "It completely covers the torso and arms, though it would give "
    "little defense against a sword or axe. The interior is lined "
    "with red silk."
  );
  SetAdjectives( ({ "thin", "red"  }) );
  SetArmourClass(ARMOUR_CLOTH); 
  SetArmourType(A_BODY_ARMOUR);
  SetDamagePoints(2000);
  SetMaterials( ({"natural" }) ); 
  SetProperty("history",
    "This robe shares a similiar design with several other garments "
    "produced by a number of now-defunct magical schools, where "
    "they were often worn by students as uniforms. This particular "
    "robe is woven from a naturally occuring fibrous mineral that "
    "is extremely resistant to heat. "
  );
  SetSize(SIZE_MEDIUM);
  SetValue(1000);
  SetWarmth(0); // negative warmth is bad
  SetWear("The robe feels strangely cool.");
}

// magical robe ignores electrical deterioration
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

