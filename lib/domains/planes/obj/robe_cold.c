/* Robe of cold resistance
 *  simply doesn't deteriorate to cold
 *
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
  SetKeyName("fluffy white robe");
  SetShort("a fluffy white robe");
  SetLong("This robe is made of thick white whool. Extra fur around "
    "the neck and hands provides protection from the elements."
  );
  SetAdjectives( ({ "fluffy", "white"  }) );
  SetArmourClass(ARMOUR_CLOTH); 
  SetArmourType(A_BODY_ARMOUR);
  SetDamagePoints(2000);  
  SetMaterials( ({ "textile" }) ); 
  SetProperty("history",
    "This robe shares a similiar design with several other garments "
    "produced by a number of now-defunct magical schools, where "
    "they were often worn by students as uniforms."
  );
  SetProperty("magic",
    "This garment has been enchanted to provide protection from "
    "ice storms and other similiar magical attacks."
  );
  SetSize(SIZE_MEDIUM);
  SetValue(1000);
  SetWarmth(30);
  SetWear("The robe feels extremely warm, almost stiffling.");
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
  if(!(DamageType & COLD)) {
    armour::eventDeteriorate(DamageType);
    return;
  }

  // shield is held, send message to room and wielder
  if (room) {
    room->eventPrint(possessive_noun(env) + " " + GetKeyName() +
      " %^BOLD%^WHITE%^resists%^RESET%^ the frost.", ({env}) );
    env->eventPrint("Your " + GetKeyName() + 
      " %^BOLD%^WHITE%^resists%^RESET%^ the frost.");
  } else {
    // shield is not held. send message to room
    env->eventPrint(capitalize(GetShort()) + 
      " %^BOLD%^WHITE%^resists%^RESET%^ the frost.");
  }
}

