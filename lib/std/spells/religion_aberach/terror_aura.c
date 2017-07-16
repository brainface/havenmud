/* Updated to only be castable in one room at a time
   -Melchezide 20110902
*/
#include <lib.h>
#include <magic.h>
#include <dirs.h>
#include <damage_types.h>

inherit LIB_SPELL;
void killit(object ob,object who);

static void create() {
  spell::create();
  SetSpell("aura of terror");
  SetRules("");
  SetSpellType(SPELL_OTHER);
  SetRequiredMagic(175);
  SetSkills( ([
     "faith" : 55,
     "necromancy" : 55,
              ]) );
  SetReligions( ({ "Aberach" }) );
  SetMagicCost(150, 90);
  SetMaximumMorality(-400);
  SetDifficulty(25);
  SetMorality(0);
  SetHelp(
    "Aura of Terror is used by skilled clerics of Aberach to invoke fear "
    "in those who enter the area in which it is cast."
  );
}

int CanCast(object who, int level, mixed limb, object array targets) {
  if (present("fearmaker", environment(who))) {
    message("message", "This area has already been filled with terror.", who);
    return 0;
  }
  return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, string limb, object array targets) {
  object ob;           
  if (who->GetProperty("hasAura")) {
     who->eventPrint("You already have an aura.");
     return 0; 
 } else { 
     who->SetProperty("hasAura", 1);
     ob = new(DIR_SPELLS "/obj/aura_terror_ob");
     ob->SetCaster(who);
     ob->SetFearType("horror of " + who->GetCapName() + "'s magic");
     ob->SetResistLevel(to_int(who->GetLevel() * 0.75));
     ob->SetFearLength(5 + (to_int(level/4)));
     send_messages("fill", "$agent_name $agent_verb the area with terrifying "
                "magic.", who, 0, environment(who));
    ob->eventMove(environment(who));
    call_out( (: killit :), random(level) + level, ob, who);
  }
}

void killit(object ob, object who) {
  who->RemoveProperty("hasAura");
  message("message", "The horrible magic leaves the area.", environment(ob));
  ob->eventDestruct();
}

