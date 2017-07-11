//
// Summon vermin horde
// by Ranquest@Haven
// A Natural Evokation spell
// started 5th December 1998
//
// COPIED WHOLE HOG^H^H^H FROG by Mahkefel, 2013

#include <lib.h>
#include <dirs.h>
#include <magic.h>
#define FROG DIR_SPELLS "/obj/plague_frog"
inherit LIB_SPELL;
void FrogKill(object target);

static void create() {
  spell::create();
  SetSpell("plague of frogs");
  SetRules("","LIV");
  SetDifficulty(15);
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([
     "faith" : 5,
     "evokation" : 5,
    ]) );
  SetReligions("Anteky");
  SetHelp("Summons a plague of frogs to pester and annoy your enemy.\n"
          "Once the target is dead, the frogs vanish.");
}

varargs int eventCast(object who,int level, mixed n, object *targets) {
  object target = targets[0];
  object frog;
  int frogs;
  int i;
  foreach (object ob in filter(all_inventory(environment(who)),
               (: (int)$1->is_living() :) )) {
    if (ob->GetKeyName() == "frog") {
      who->eventPrint("There are already too many animals in the area!");
      return 1;
    }
  }
  frogs = 1 + level/5;
  if(frogs > 8) frogs = 8;
  send_messages("summon",
    "$agent_name%^BLUE%^ $agent_verb%^RESET%^ a plague of frogs to overwhelm $target_name!",
    who, target, environment(who) );
  for (i = 0;i<frogs;i++) {
    frog = new(FROG);
    frog->AddFriend(who->GetKeyName());
    frog->SetOwner(who->GetKeyName());
    frog->eventMove(environment(target));
    }
  return 1;
}

