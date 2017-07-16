#include <lib.h>
#include <magic.h>
#include <std.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
    spell::create();
    SetSpell("call firefly");
    SetRules("");
    SetSpellType(SPELL_OTHER);
    SetRequiredMagic(40);
  SetSkills( ([
    "natural magic" : 1,
    ]) );
    SetMagicCost(20, 20);
    SetDifficulty(15);
    SetMorality(0);
  SetMessages( ({ 
       ({ "call", "$agent_name $agent_verb a firefly." }),
         }) );
   SetHelp(
          "This spell allows natural magic users to call a firefly "
	  "out of the wilderness.  The firefly emits a small amount of "
	  "light.  See <minor tame> for information on controlling it.");
}

varargs int eventCast(object who, int level, mixed limb, object array targets) {
   object ob;
   ob = new("/std/spells/obj/firefly");
   ob->SetLife(who->GetSkillLevel("natural magic")*50);
   ob->SetCreator(who->GetKeyName());
   ob->eventMove(environment(who));
   send_messages( ({ "call" }), "$agent_name $agent_verb a firefly out of the wilderness.",
	this_player(),0,environment(this_player()));
   return 1;
}
