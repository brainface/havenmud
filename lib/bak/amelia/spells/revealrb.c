#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpellType(SPELL_OTHER);
   SetSpell("reveal rainbow");
   SetRules("");
   SetSkills( ([ 
                 "natural magic" : 25,
                 "enchantment"      : 25,
            ]) );
   SetMagicCost(50,10);
   SetRequiredMagic(60);
   SetDifficulty(20);
   SetMorality(0);
   SetMessages( ([
	({ "reveal" }):"$agent_name $agent_verb a rainbow!" ]) );
   SetHelp("Syntax:  <cast reveal rainbow>\n\n"
           "The caster makes the natural water prisms in the air "
           "visible.");
}

varargs int CanCast(object who, int level, mixed limb, object *targets) {
   if(environment(who)->GetClimate() == "arid" ||
      environment(who)->GetClimate() == "indoors" ) {
      send_messages( ({ "" }),"This is an inappropriate area to "
                        "find rainbows in.",who,0,environment(who));
      return 0;
   }

  return ::CanCast(who, level, limb, targets);
}

varargs int eventCast(object who, int level, mixed limb, object array targets) {
   object ob;
   ob = new("/std/spells/obj/rainbow.c");
   ob->eventMove(environment(who));
   send_messages( ({ "reveal" }), "$agent_name $agent_verb a "
                     "rainbow!",who,0,environment(who));
   return ::eventCast(who, level, limb, targets);
}
