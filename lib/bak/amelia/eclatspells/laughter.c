#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("laughter");
   SetRules("","LIV");
   SetSpellType(SPELL_COMBAT);
   SetSkills( ([
                 "faith"       : 15,
                 "enchantment" :  5,
            ]) );
   SetMagicCost(15,10);
   SetRequiredMagic(25);
   SetDifficulty(25);
   SetMorality(5);
   SetDamage(1,0,0);
   SetHelp("Syntax:  <cast laughter>\n"
           "         <cast laughter on LIV>\n\n"
           "This spell causing the target to suddenly start laughing, "
           "making the target tired.");
}

varargs int eventCast(object who, int level, mixed limb, object *targets) {
   object target = targets[0];
   int blah = 0;
   blah += who->GetSkillLevel("faith");
   blah += who->GetStatLevel("wisdom");
   blah = blah*3;
   blah -= random(target->GetLevel());
   if(blah <= 0) {
      blah = -1;
      send_messages( ({ "sputter" }),"$agent_name $agent_name at the "
                        "end of the spell, causing it to fail.",
                        who,target,environment(who));
   }
   if(target->GetStaminaPoints() < blah) {
      blah = target->GetStaminaPoints();
   }
   if(blah > 500) {
      blah = 500;
   }
   switch(blah) {
      case 0..80:
      send_messages( ({ "cause" }), "$agent_name $agent_verb "
                        "$target_name to laugh for a little bit, "
                        "tiring him slightly.",who,target,
                        environment(who));
      break;
      case 81..200:
      send_messages( ({ "start" }),"$target_name $target_verb to "
                        "laugh hysterically for while, tiring $target_reflexive "
                        "out, because of $agent_possessive_noun spell.",
                        who,target,environment(who));
      break;
      case 201..400:
      send_messages( ({ "cause" }),"$agent_name $agent_verb "
                        "$target_name to get a bad case of the "
                        "giggles, exhausting $target_reflexive.",
                        who,target,environment(who));
      break;
      case 401..500:
      send_messages( ({ "burst","watch" }),"$target_name $target_verb into "
                        "laughter while $agent_name $agent_verb, "
                        "amused.",who,target,environment(who));
      break;
   }
   target->AddStaminaPoints(-blah);
   return 1;
}