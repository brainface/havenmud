/* Divine Elemental Resistance
 * Enchantment spell, determines "elemental"
 * resistances in target.
 * SHOCK|COLD|POISON|HEAT|MAGIC
 */
#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;

string GetWeakness(object,int);

mapping ResistancesToCheck = ([
  SHOCK : " lightning.",
  COLD : " cold and ice.",
  HEAT : " fire.",
  MAGIC : " pure magic.",
  POISON : " venom.",
]);

static void create()
{
  spell::create();
  SetSpell("divine elemental resistance");
  SetSpellType(SPELL_OTHER);
  SetRules("LIV");
  SetSkills(  ([
    "enchantment" : 100,
  ])  );
  SetMagicCost(75,75);
  SetDifficulty(100);
  SetHelp(
    "Enables a talented enchanter to divine the "
    "elemental resistances of a creature."
  );

}

int eventCast(object who, int level, mixed limbs, object array targets) {

   object target = targets[0];
  send_messages( ({"call", "gaze"}),
      "$agent_name $agent_verb upon the power of the elements and $agent_verb "
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
  } else if (resistance == "medium") {
    output += " is somewhat resistant to";
  } else if (resistance == "high") {
    output += " is highly resistant to";
  } else if (resistance == "immune") {
    output += " is completely immune to";
  }

  // add human readable description of
  // damage type.
  //output += ResistancesToCheck(damageType);
  return output;
}


