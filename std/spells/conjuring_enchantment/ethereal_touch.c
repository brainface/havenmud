/*  ethereal form
 * Lightens mass of objects
 */
 
// mahkfel 2015
// updated a bit. made not apply if already cast on an object
// made use short suffixes because goddamned if i didn't make that
// for a reason.
#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("ethereal touch");
  SetRules("OBJ");
  SetSkills( ([
     "enchantment" : 20,
     "conjuring" : 20,
     ]) );
  SetRequiredMagic(20);
  SetMagicCost(10, 10);
  SetSpellType(SPELL_OTHER);
  SetDifficulty(15);
  SetHelp(
         "This spell makes the target item lighter, the amount it is decresed "
         "is dependent on the level the caster has the spell at.");
  }

int eventCast(object who, int level, mixed useless, object *targets) {
  object thing = targets[0];
  int new_mass;

  send_messages("summon",
     "$agent_name $agent_verb a wispy phantasm of air to touch $target_name.",
      who, thing, environment(who));

  if (!thing->GetProperty("ethereal_touch")){    
    new_mass = level/5;
    new_mass = new_mass * -1;
    thing->AddMass(new_mass);
    if (thing->GetMass() < 1) thing->SetMass(1);
    thing->AddShortSuffix("(ethereal)");
    thing->AddProperty("ethereal_touch",1);
    return 1;
  } else {
    send_messages("tap",
      "$agent_name $agent_verb " + thing->GetName() + " lightly to no effect.",
      who,0,environment(who)
    );
    who->eventPrint("That object is already bespelled!");
    return 0;
  }

}

