//
// Summon Asp of Enniae
// Thoin@haven
//

#include <lib.h>
#include <magic.h>
#include <std.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("summon asp");
  SetRules("");
  SetMagicCost(70, 20);
  SetDifficulty(70);
  SetReligions("Enniae");
  SetSpellType(SPELL_OTHER);
  SetSkills( ([
      "faith" : 45,
      "evokation" : 45,
       ]) );
  SetHelp(
          "Summons an asp to assist the caster.");
  }

int eventCast(object who, int level, mixed limb, object array targets) {
  object furry;
  foreach (object ob in filter(all_inventory(environment(who)), 
               (: (int)$1->is_living() :) )) {
    if (ob->GetOwner() == who->GetKeyName()) {
      who->eventPrint("You already have a snake friend!");
      return 1;
    }
  }
  switch(level) {
     case 0..50 :
        furry = new(STD_NPC "asp1");
        break;
     case 51..90 : 
        furry = new(STD_NPC "asp2");
         break;
     case 91..100 :
        furry = new(STD_NPC "asp3");
         break;
      }
     furry->SetLevel(furry->GetLevel() + who->GetLevel()/5);
     furry->SetOwner(who->GetKeyName());
     furry->eventMove(environment(who));
     furry->AddFriend(who->GetKeyName());
   foreach(object sucker in who->GetEnemies()) {
       furry->AddEnemy(sucker);
     }
     furry->eventForce("follow " + who->GetKeyName());
     who->eventForce("lead first " + furry->GetKeyName());
    send_messages("summon",
       "$agent_name $agent_verb a $target_name to help $agent_objective.",
        who, furry, environment(who) );
     return 1;
  message("system", "You already have a summoned creature!", who);
  return 1;
  }
