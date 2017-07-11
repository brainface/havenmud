//
// Creeping Doom
// Thoin
// 12-17-05
//

#include <lib.h>
#include <magic.h>
#define SNAKE "/std/spells/obj/snake"
#define MSNAKE "/std/spells/obj/msnake"
#define LSNAKE "/std/spells/obj/lsnake"

inherit LIB_SPELL;
void SnakeKill(object target);

static void create() {
  spell::create();
  SetSpell("creeping doom");
  SetRules("","LIV");
  SetMagicCost(120, 140);
  SetDifficulty(125);
  SetSpellType(SPELL_COMBAT);
  SetReligions("Enniae");
  SetSkills( ([
     "evokation" : 150,
     "faith"  : 150,
    ]) );
  SetHelp("Summons a horde of snakes to attack the designated target.\n"
          "Once the target is dead, the snakes vanish. This spell is "
          "one of the most powerful Enniae spells and such it requires the "
          "caster to have full knowledge of the summon asp spell.");
  }


int CanCast(object who, int level, mixed limb, object *targets) {

  if(who->GetSpellLevel("summon asp") < 99) {
        message("system","You have not mastered the summon asp spell. ",who);
      return 0;
      }
   return spell::CanCast(who, level, limb, targets);
}

varargs int eventCast(object who,int level, mixed n, object *targets) {
  object target = targets[0];
  int snakes;
  object snakefetish;
  int i;
  foreach (object ob in filter(all_inventory(environment(who)),
               (: (int)$1->is_living() :) )) {
    if (ob->GetKeyName() == "serpent") {
      who->eventPrint("There are already too many animals in the area!");
      return 1;
    }
  }
  snakes = 1 + level/3;
  snakes += who->GetSkillLevel("evokation")/20;
  if(snakes > 15) snakes = 15;
  send_messages("summon",
    "$agent_name%^BLUE%^ $agent_verb%^RESET%^ a horde of snakes "
    "to attack $target_name!",
    who, target, environment(who) );
    who->eventForce("muah");

  switch(level){
     case 1..35 :
       for (i = 0;i<snakes;i++) {
        snakefetish = new(SNAKE);
        snakefetish->SetLevel(snakefetish->GetLevel() + who->GetLevel()/10);
        snakefetish->eventMove(environment(target));
       }
      break;
     case 36..85 :
       for (i = 0;i<snakes;i++) {
        snakefetish = new(MSNAKE);
        snakefetish->SetLevel(snakefetish->GetLevel() + who->GetLevel()/10);
        snakefetish->eventMove(environment(target));
       }
      break;
     case 86..100 :
       for (i = 0;i<snakes;i++) {
        snakefetish = new(LSNAKE);
        snakefetish->SetLevel(snakefetish->GetLevel() + who->GetLevel()/10);
        snakefetish->eventMove(environment(target));
       }
      break;
    }
  snakefetish->AddFriend(who);
  snakefetish->SetOwner(who);
  return 1;
}

