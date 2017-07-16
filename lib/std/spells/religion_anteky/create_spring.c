// mahkefel 2011
// 0 proof copy of tainted spring 
#include <lib.h>       
#include <std.h>       
#include <magic.h>     
inherit LIB_SPELL;     

static void create() {
  ::create();         
  SetSpell("create spring");
  SetRules("");                     
  SetMagicCost(50, 100);            
  SetDifficulty(25);               
  SetSkills( ([                     
    "faith" : 30,           
    "enchantment"   : 30,           
    ]) );
  SetReligions( "Anteky" );
  SetHelp(                          
    "Using this spell, the caster strikes the ground with her staff, "
    "causing a spring of pure water to rise up from barren land."    
    );
}

varargs int CanCast(object who, int level, string bleh, object *t) {
  object room = environment(who);

  if ((room->GetClimate() == "indoors") &&
          !present("natural_charge", who)) {
    send_messages( ({ "strike", "realize", "are", }),
        "$agent_name%^GREEN%^BOLD%^ $agent_verb %^RESET%^the ground angrily, "
        "only to $agent_verb that $agent_objective $agent_verb indoors!", who, 0, room);
    return 0;
  }
  return ::CanCast(who, level, bleh, t);
}

varargs int eventCast(object who, int level, string bleh, object *t) {
  object room = environment(who);
  object spring = new(STD_SPELLS "obj/anteky_spring_ob");

  if (!spring) {
    who->eventPrint("Error with obj/anteky_spring_ob.c");
    return 0;
    }
  send_messages( ({ "strike", }),
    "$agent_name $agent_verb the ground, and %^BLUE%^a spring of water%^RESET%^ "
    "wells up from the barren ground.",
    who, 0, room);
  spring->eventMove(room);
  spring->SetPortions(level/5 + 1);
  return 1;
}

