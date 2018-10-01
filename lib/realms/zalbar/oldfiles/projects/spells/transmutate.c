/*  Transmutate
 * Thoin@Haven
 */
#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("transmutate");
  SetRules("OBJ");
  SetMagicCost(175, 100);
  SetSpellType(SPELL_OTHER);
  SetDifficulty(200);
  SetSkills( ([
      "natural magic" : 350,
      "enchantment" : 350,
    ]) );
  SetHelp("A powerful druid can transmutate an object into wood using this spell. "
      "No matter what the previous material was of the target it is turned into "
      "wood. Though this spell may not seem powerful at first, combined with "
      "other spells it shows its true power.");
  }

int CanCast(object who, int level, mixed blah, object *targets){
    object thing;
    thing = targets[0];    

    if(!sizeof(targets)){
        message("", "Cast enchant armour on what?", who);
        return 0;
    }
    
    if (member_array("wood", thing->GetMaterials()) == 0) {
        message("system", "You cannot cast this on something that is already wood.", who);
        return 0;
    }
  
    return spell::CanCast(who, level, blah, targets);
}

varargs int eventCast(object who, int level, mixed blah, object *targets) {
  int chance;

  chance = level/10 + (who->GetSkillLevel("enchantment")-350);
  
  if (chance < 15) {
  send_messages( ({}),
       "Vines sprout forth from $agent_possessive_noun hand and they wrap themselves around "
       "$target_name completely. As the vines begin to dissolve into $target_name nothing happens.",
        who, targets[0], environment(who));
  return 1;
 } {
  send_messages( ({}),
       "Vines sprout forth from $agent_possessive_noun hand and they wrap themselves around "
       "$target_name completely. As the vines begin to dissolve into $target_name, $target_nominative "
       "turns into wood.",
        who, targets[0], environment(who));
  targets[0]->SetMaterials("wood");
  return 1; 
 }
  }

