#include <lib.h>
#include <magic.h>
#include <std.h>
#include <daemons.h>
inherit LIB_SPELL;

void OpenGate();

static void create() {
  spell::create();
  SetSpell("exodus");
  SetRules("",);
  SetSpellType(SPELL_OTHER);
  SetSkills( ([
    "faith" : 60,
    "enchantment" : 60,
  ]) );
  SetMagicCost(175, 175);
  SetDifficulty(30);
  SetGlobalSpell(1);
  SetReligions("Anteky");
  SetHelp(
    "The righteous follower of Anteky, tiring of the ceaseless toil in "
    "the lands of Xandria, can divide the waters separating the lands "
    "of her birth and the promised lands. Casting the spell "
    "elsewhere will allow her to return home and lead others to freedom."
  );
}

varargs int CanCast(object who, int level, string limb, object array targets) {
        //object target = targets[0];
        object env  = environment(who);
        object envT;
        int distance;

        // note this doesn't actually really for reals set the target
       // this just makes sure target is valid
        if (env->GetDomain() != "Xandria") {
          envT = get_object("/domains/xandria/virtual/river/0,-4");
        } else {
          //random from a list would be best. this amuses me the most.
          envT = get_object("/domains/southern_coast/areas/meadow/rooms/meadow11");
        }

        if( envT->GetProperty("no teleport") ) {
                message("fail", "Strange magics prevent you from dividing the waters to your destination!", who);
                return 0;
                }
        if( environment(who)->GetProperty("no teleport") ) {
                message("fail", "Strange magics prevent you from dividing the waters here.", who);
                return 0;
                }
        if( environment(who)->GetProperty("ocean") ) {
                message("fail", "The waters here are too deep to divide!", who);
                return 0;
                }
        if( !environment(who)->GetProperty("coastal") ) {
                message("fail", "There are no waters to divide here!", who);
                return 0;
                }
        if( present("mosestunnel", environment(who)) ) {
                message("fail", "The waters here are already divided!",      who);
                return 0;
                }
        if( present("tunnel", environment(who)) ) {
                message("fail", "There is already a tunnel here!",      who);
                return 0;
                }
        if( present("tunnel", environment(who)) ) {
                message("fail", "It appears some other prophet is at work, complicating your task!",      who);
                return 0;
                }
        SetDifficulty(100); // ?

        return spell::CanCast(who, level, limb,targets );
}

varargs int eventCast(object who, int level, string limb, object array targets) {
        object target = targets[0];
        object gate;

        if (environment(who)->GetDomain() != "Xandria") {
          target = get_object("/domains/xandria/virtual/river/-1,-4");
        } else {
          //random from a list would be best. this amuses me the most.
          target = get_object("/domains/southern_coast/areas/meadow/rooms/meadow11");
        }

  send_messages( ({"stretch"}), "$agent_name $agent_verb out "
    "$agent_possessive hand %^BLUE%^over the waters %^BOLD%^and they divide, "
    "%^RESET%^forming a tunnel underneath the waves!",
    who, 0, environment(who));
  message("system",
    "%^BOLD%^BLUE%^Strong winds blow and waves crash, and tunnel forms "
    "from underneath the waters!%^RESET%^",
    target);

  gate = new(STD_SPELLS "obj/mosestunnel");
  gate->eventMove(environment(who));
  gate->SetLifeSpan(10 + level + random(30));
  gate->SetGateTarget(file_name(target));

  gate = new(STD_SPELLS "obj/mosestunnel");
  gate->eventMove(target);
  gate->SetLifeSpan(10 + level + random(30));
  gate->SetGateTarget(file_name(environment(who)));

  return 1;
}

