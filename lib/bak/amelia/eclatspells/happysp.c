#include <lib.h>
#include <magic.h>
#include <damage_types.h>
#include <magic_protection.h>
inherit LIB_SPELL;

int hitCallback(object who, object agent, int x, class MagicProtection cl);
void endCallback(object who);

static void create() {
   spell::create();
   SetSpell("sphere of happiness");
   SetRules("", "LIV");
   SetSpellType(SPELL_DEFENSE);
   SetSkills( ([
                 "faith" : 10,
                 "enchantment" : 10,
            ]) );
   SetMagicCost(50,10);
   SetRequiredMagic(30);
   SetDifficulty(25);
   SetHelp("syntax: <cast sphere of happiness>\n"
           "        <cast sphere of happiness on LIVING>\n\n"
           "This spell creates a sphere around you that helps "
           "protection against external damage.");
}

int eventCast(object who, int level, mixed limbs, object array targets) {
   class MagicProtection protection;
   object target = targets[0];
   protection = new(class MagicProtection);
   protection->name = "happy sphere";
   protection->bits = ALL_DAMAGE;
   protection->caster = who;
   protection->time = level-(random(level)/2);
   protection->protect = level + random(level)/2;
   if( target == who ) {
      protection->protect = protection->protect/4;
   }
   protection->args = level;
   protection->hit = (: hitCallback :);
   protection->end = (: endCallback :);
   if(target->AddMagicProtection(protection)) {
      send_messages( ({ "smile" }), "$target_name $target_verb "
                           "as a sphere of happiness surrounds "
                           "$target_reflexive.", who, target, 
                           environment(target));
   }
   else {
      send_messages( ({ "" }), "The spell fails.",who);
   }
   return 1;
}

int hitCallback(object who, object agent, int x, class MagicProtection cl) {
   if(who == cl->caster) {
      who->eventTrainSkill("enchantment", cl->args, 0, 1);
   }
   send_messages( ({ "" }), "The sphere of happiness around "
                     "$agent_name caves in "
                     "slightly, but bounces back.",who, 0,
                     environment(who));
   return random(x);
}

void endCallback(object who) {
   if(who) {
      send_messages( ({ "" }), "The world dampens slightly as the "
                        "aura around $agent_name scatters into the "
                        "air.",who,0,environment(who));
   }
}