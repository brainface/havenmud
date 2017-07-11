/* Hat Trick
 * Shameless copy of vermin horde
 *
 */
#include <lib.h>
#include <dirs.h>
#include <magic.h>
#define RABBIT DIR_SPELLS "/obj/hat_rabbit"
#define PIGEON DIR_SPELLS "/obj/hat_pigeon"
#define SNAKE DIR_SPELLS "/obj/hat_snake"
inherit LIB_SPELL;
void RatKill(object target);

static void create() {
  spell::create();
  SetSpell("hat trick");
  SetRules("","LIV");
  SetDifficulty(15);
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([
      "conjuring" : 10,
    "illusion" : 10,
  ]) );
  SetHelp("The apprentice illusionist always has a few tricks up their sleeves.\n"
          "This one, in particular, summons a handful of mostly harmless animals\n"
          "to attack an enemy.");
}

varargs int eventCast(object who,int level, mixed n, object *targets) {
  object target = targets[0];
  object rat;
  string creature_type;
  int rats;
  int i;
  foreach (object ob in filter(all_inventory(environment(who)),
               (: (int)$1->is_living() :) )) {
    if (ob->GetProperty("hat_trick")) {
      who->eventPrint("Search as hard as you might, you can't seem to find "
        "more rabbits in there.");
      return 1;
    }
  }
  // mostly summon rabbit/pigeon
  switch(random(5)) {
    case 0: creature_type = RABBIT;break;
    case 1: creature_type = RABBIT;break;
    case 2: creature_type = PIGEON;break;
    case 3: creature_type = PIGEON;break;
    case 4: creature_type = SNAKE;break;
  }
  rats = 1 + level/5;
  if(rats > 3) rats = 3;
  send_messages( ({"pull", "fling"}),
    "With a shout of triumph, $agent_name $agent_verb a handful "
    "of struggling creatures from $agent_possessive hat and%^BOLD%^GREEN%^ "
    "$agent_verb%^RESET%^ them at $target_name!",
    who, target, environment(who) );

  for (i = 0;i<rats;i++) {
    rat = new(creature_type);
    rat->AddFriend(who->GetKeyName());
    rat->SetOwner(who->GetKeyName());
    rat->eventMove(environment(target));
    rat->SetLevel(who->GetLevel());
//    rat->SetAttack(target);  /*Edited out so that all the rats don't die on spawn vs
                               /*larger creatures, also reduntant since AddFriend will
                               /*force the rats to attack    -Melchezidek 9/10/09  */
    }
  return 1;
}

