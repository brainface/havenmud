#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("reveal rainbow");
   SetRules("");
   SetSkills( ([ 
                 "divination" : 6,
                 "faith"      : 6,
            ]) );
   SetMagicCost(10,3);
   SetRequiredMagic(15);
   SetHelp("Syntax:  <cast reveal rainbow>\n\n"
           "The caster makes the natural water prisms in the air "
           "visible.");
}

varargs int eventCast(object who, int level, mixed n, object *targets) {
   object rainbow = new("/realms/amelia/spells/obj/rainbow");
   if(environment(who)->GetClimate("arid") ||
      environment(who)->GetClimate("arctic") ||
      environment(who)->GetClimate("indoors") ||
      environment(who)->GetTown() != "wilderness" ) {
      send_messages( ({ "" }),"This is an inappropriate area to "
                        "find rainbows in.",who,0,environment(who));
      return 1;
   }
   rainbow->eventMove(environment(who));
   send_messages( ({ "reveal" }), "$agent_name $agent_verb a "
                     "rainbow!",who,0,environment(who));
}