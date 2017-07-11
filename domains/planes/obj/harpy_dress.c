/* Robe of MAAAHHGIC resistance
 *  simply doesn't deteriorate to magic
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
  SetId( ({ "dress" }) );
  SetKeyName("fur dress");
  SetShort("a crude fur dress");
  SetLong(
    "This fluffy garment appears to be fashioned from several furry thing hides "
    "in the approximate shape of what an apprentice tailor would imagine a dress "
    "to be. Two wide, gaping holes exist in the back for whatever reason, and "
    "several feathers and various teeth are entangled throughout, whether as "
    "decoration or stain is unclear."
  );
  SetAdjectives( ({ "crude", "fur"  }) );
  SetArmourClass(ARMOUR_LEATHER);
  SetArmourType(A_BODY_ARMOUR);
  SetDamagePoints(10000);
  SetMaterials( ({ "leather" }) );
  SetProperty("history",
    "Some creatures of the forest planes use the hide and hair of "
    "furry things for garments. Some magical nature of the creatures "
    "may still exist in the woven fabric."
  );
  SetProperty("magic",
    "This crude garment possesses a bit of magical resistance "
    "due to absolute innocence of the creatures composing it."
  );
  SetSize(SIZE_LARGE);
  SetValue(500);
  SetWarmth(10);
  SetWear("You have the horrible, inexplicable feeling that the dress "
    "wants to be your friend.");
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
  if(!(DamageType & MAGIC)) {
    armour::eventDeteriorate(DamageType);
    return;
  }

  // shield is held, send message to room and wielder
  if (room) {
    room->eventPrint(possessive_noun(env) + " " + GetKeyName() +
      " %^BOLD%^YELLOW%^resists%^RESET%^ the malevolent magic.", ({env}) );
    env->eventPrint("Your " + GetKeyName() +
      " %^BOLD%^YELLOW%^resists%^RESET%^ the malevolent magic.");
  } else {
    // shield is not held. send message to room
    env->eventPrint(capitalize(GetShort()) +
      " %^BOLD%^YELLOW%^resists%^RESET%^ the malevolent magic.");
  }
}

