#include <lib.h>
#include <magic.h>
#include <std.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("summon animal");
  SetRules("");
  SetMagicCost(50, 20);
  SetDifficulty(15);
  SetSpellType(SPELL_OTHER);
  SetSkills( ([
       "natural magic" : 8,
       "evokation" : 8,
       ]) );
  SetHelp(
          "Summons an animal to assist the caster.");
  }

int canCast(object who, int level, mixed limb, object array targets) {
  foreach (object ob in filter(all_inventory(environment(who)), 
               (: (int)$1->is_living() :) )) {
    if (ob->GetKeyName() == "squirrel" || ob->GetKeyName() == "dog" || 
        ob->GetKeyName() == "bear"     || ob->GetKeyName() == "wolf") {
      who->eventPrint("There are already too many animals in the area!");
      return 0;
    }
  }
  return spell::CanCast(who, level, limb, targets);
}
int eventCast(object who, int level, mixed limb, object array targets) {
  object furry;
  foreach (object ob in filter(all_inventory(environment(who)), 
               (: (int)$1->is_living() :) )) {
    if (ob->GetKeyName() == "squirrel" || ob->GetKeyName() == "dog" || 
        ob->GetKeyName() == "bear"     || ob->GetKeyName() == "wolf") {
      who->eventPrint("There are already too many animals in the area!");
      return 1;
    }
  }
  switch(level) {
     case 0..10 :
        furry = new(STD_NPC "squirrel");
        break;
     case 11..20 : 
        furry = new(STD_NPC "dog");
         break;
     case 21..30 :
        furry = new(STD_NPC "bear");
         break;
     case 31..100 :
        furry = new(STD_NPC "wolf");
          break;
     default :
        furry = new(STD_NPC "dog");
           break;
      }
     furry->eventMove(environment(who));
     furry->AddFriend(who->GetKeyName());
   foreach(object sucker in who->GetEnemies()) {
       furry->AddEnemy(sucker);
     }
     furry->eventForce("follow " + who->GetKeyName());
     who->eventForce("lead first " + furry->GetKeyName());
     who->AddMagicPoints(-GetMagicCost(who));
     who->AddMagicPoints(-GetMagicCost(who));
    send_messages("summon",
       "$agent_name $agent_verb a $target_name to help $agent_objective.",
        who, furry, environment(who) );
     return 1;
  message("system", "You already have a summoned creature!", who);
  return 1;
  }


/* Approved by Duuktsaryth on Tue Sep  9 02:02:00 1997. */
