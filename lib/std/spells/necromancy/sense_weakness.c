/* Sense Weakness
 * Necromancy spell, returns weakness/lack of resistance
 * to elements.
 */
#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;

string GetWeakness(object,int);

mapping ResistancesToCheck = ([
  BLUNT : " blunt trauma.",
  SLASH : " slashing weapons.", 
  PIERCE : " piercing weapons.",
  WATER : " flowing water.",
  SHOCK : " lightning.",
  COLD : " cold and ice.",
  HEAT : " fire.",
  GAS : " deadly vapors.",
  ACID : " vitriol.",
  MAGIC : " pure magic.",
  POISON : " venom.",
  SOUND : " loud noises.",
]);

static void create()
{
  spell::create();
  SetSpell("sense weakness");
  SetSpellType(SPELL_OTHER);
  SetRules("LIV");
  SetSkills(  ([
"necromancy" : 50,
  ])  );
  SetMagicCost(75,75);
  SetDifficulty(100);
  SetHelp(
    "Enables a talented master of necromancy to sense the "
    "inherent weaknesses in a creature."
  );

}

int eventCast(object who, int level, mixed limbs, object array targets) {

   object target = targets[0];
  send_messages( ({"call", "gaze"}),
      "$agent_name $agent_verb upon the power of the death and $agent_verb "
      "at $target_name.",
   who, target, environment(who)  );

  //foreach obj resistance in ResistancesToCheck
  foreach(int resistance in keys(ResistancesToCheck)) {
    string weakness = GetWeakness(target,resistance);
   
    if (weakness != "") {
      message("system",
        "You sense that " 
        + target->GetName()                 // bob
        + weakness                          // is weak to
        + ResistancesToCheck[resistance],  // burning alive
        who);
    }

  }
}

// valid resistances
// * string level "none", "low", "medium", "high", and "immune"
// "weakness" should be valid, but isn't.

string GetWeakness(object creature, int damageType) {
  string resistance, output = "";
  resistance = creature->GetResistance(damageType);

  // "weakness" currently doesn't
  // actually work.
  if (resistance == "weakness") {
    output += " is vulnerable to";
  } else if (resistance == "none") {
    output += " has no resistance to";
  } else if (resistance == "low") {
    output += " has little resistance to";
  }

  // add human readable description of
  // damage type.
  //output += ResistancesToCheck(damageType);
  return output;
}


