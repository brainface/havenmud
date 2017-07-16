/*
 * Conjured ARmour for the frost armour spell
 * frost armour spell declared armour type, class adjectives blahblah
 * this file only contains functions and magic id property

 */
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

int eventMelt();

static void create() {
  armour::create();
  SetKeyName("frost armour");
  // will be overridden
  SetShort("a bit of frost");

  SetLong("A thick coating of frost and ice. It seems unnaturally flexible "
    "for the material involved, yet it gathers and hardens when struck.");

  SetId( ({ "frost_armour" }) );

  //SetAdjectives( ({ "dragon", "dragonscale", "large", "scale" }) );
  //SetArmourClass(ARMOUR_NATURAL);
  //SetArmourType(A_SHIELD);
  //SetDamagePoints(1500);
  SetMass(500);
  SetMaterial( ({ "natural" }) );
  SetProperty("history",
  "This smells like necromancy, and recent at that. While moderately "
  "uncomfortable it's probably not harmful, nor worth anything.");
  SetProperty("magic",
  "Magically forged by a necromancer directly upon the skin of the wearer, "
  "this conjured armour will face once removed. It will resist frost and "
  "fear fire."
  );
  SetProtectionBonus(COLD,5);
  SetRepairDifficulty(10);
  SetSize(SIZE_MEDIUM);
  SetValue(0);
  // MaxDamagePoints, DamagePoints?
  // hopefully this "just works" ^^
  AddSave( ({"ArmourClass",  "ArmourType", "Size", "ExternalDesc", "Short" }) );
}

// resist frost deterioriation
// should maybe heal some when taking frost damage.
void eventDeteriorate(int DamageType) {
  object env = environment();
  object room;

  if (!env) {
    // there really should be an environment, but
    // torch code has this
    return;
  }
  room = environment(env);

  // TODO: something bad with fire.

  //deteroirate normally and ignore my bullcrap.
  if(!(DamageType & COLD)) {
    armour::eventDeteriorate(DamageType);
    return;
  }

  // shield is held, send message to room and wielder
  if (room) {
    room->eventPrint(possessive_noun(env) + " " + GetKeyName()
      + " %^RED%^resists%^RESET%^ the frigid attack.", ({env}) );
    env->eventPrint("Your " + GetKeyName() +
      " %^RED%^resists%^RESET%^ the frigid attack.");
  } else {
    // shield is not held. send message to room
    env->eventPrint(capitalize(GetShort()) +
      "  %^RED%^resists%^RESET%^ the frigid attack.");
  }
}

varargs mixed eventUnequip(object who) {
    mixed tmp = ::eventUnequip(who);
    if( tmp != 1 ) {
        return tmp;
    }
    call_out( (: eventMelt :), 0);
    return 1;
}

int eventMelt() {
  object wearer;
  object env;
  if (environment()) {
    wearer = environment();
    if (environment(wearer)) {
      env = environment(wearer);
    }
    send_messages("", "$agent_possessive_noun " + GetKeyName() +
    "melts away!", wearer, this_object(), env);    
  }
  eventDestruct();
}

