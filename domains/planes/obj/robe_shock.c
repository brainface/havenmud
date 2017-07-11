/* robe of electrical resistance
 * doesn't degrade to shock
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
  SetKeyName("padded blue robe");
  SetShort("a padded blue robe");
  SetLong("This robe is decorated with alternating blue and white "
    "vertical stripes. Ivory buttons line the chest and wrists. A "
    "thin layer of soft leather pads the interior of the robe."
  );
  SetAdjectives( ({ "padded", "blue"  }) );
  SetArmourClass(ARMOUR_CLOTH); 
  SetArmourType(A_SHIRT);
  SetDamagePoints(2000);
  SetMaterials( ({ "textile", "leather" }) ); 
  SetProperty("history",
    "This robe shares a similiar design with several other garments "
    "produced by a number of now-defunct magical schools, where "
    "they were often worn by students as uniforms."
  );
  SetProperty("magic",
    "This garment has been enchanted to provide protection from "
    "lightning bolts and other similiar magical attacks."
  );
  SetSize(SIZE_MEDIUM);
  SetWarmth(15);
  SetWear("The robe clings to you uncomfortably.");
  SetValue(1000);
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
  if(!(DamageType & SHOCK)) {
    armour::eventDeteriorate(DamageType);
    return;
  }

  // shield is held, send message to room and wielder
  if (room) {
    room->eventPrint(possessive_noun(env) + " " + GetKeyName() 
      + " %^BLUE%^resists%^RESET%^ the shock.", ({env}) );
    env->eventPrint("Your " + GetKeyName() + 
      " %^BLUE%^resists%^RESET%^ the shock.");
  } else {
    // shield is not held. send message to room
    env->eventPrint(capitalize(GetShort()) + 
      " %^BLUE%^resists%^RESET%^ the shock.");
  }
}

