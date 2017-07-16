//
//  Summon Familiar
//  Thoin@haven
//

#include <lib.h>
#include <magic.h>
#include <dirs.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("summon familiar");
  SetRules("");
  SetSpellType(SPELL_OTHER);
  SetRecoveryTime(25);
  SetMagicCost(300, 200);
  SetDifficulty(275);
  SetSkills( ([
               "conjuring" : 250,
               "enchantment" : 250
             ]) );
  SetHelp("This allows the mage to call forth a powerful "
          "familiar from the aether. The pet the caster summons is "
          "dependent on the alignment of the caster. Only one pet can "
          "be summoned at a time."
         );
}

varargs int CanCast(object who, int level, mixed q, object *t) {
  object scales;
  foreach(object ob in filter(livings(), (: environment($1) :))) {
    if (ob->GetOwner() == who->GetKeyName()) {
      who->eventPrint("You already have a summoned familiar.");
      return 0;
    }
  }

  return ::CanCast(who, level, q, t);
}

int eventCast(object who, int level, mixed limb, object array targets) {
  object scales;
  int damage;

  switch (level) {
     case 1..50 :
       if ( who->GetMorality() < 0 ) {
         scales = new(DIR_SPELLS "/obj/sumfam_garg_ob");
         break;
       } 
       else {
         scales = new(DIR_SPELLS "/obj/sumfam_griff_ob");
         break;
       }
     case 51..100 :
       if ( who->GetMorality() < 0 ) {
         scales = new(DIR_SPELLS "/obj/sumfam_garg2_ob");
         break;
       } 
       else {
         scales = new(DIR_SPELLS "/obj/sumfam_griff2_ob");
         break;
       }
   }
   scales->SetLevel(scales->GetLevel() + who->GetLevel()/5);
   scales->eventMove(environment(who));
   send_messages( "start",
                          "$agent_name $agent_verb %^BOLD%^%^BLACK%^chanting%^RESET%^, "

                          "a large %^MAGENTA%^rift%^RESET%^ begins to form in the "
                          "%^CYAN%^aether%^RESET%^.  Claws slowly form from the "
                          "mists as " + scales->GetShort() + 
                          " materalizes.",
                           who, scales, environment(who) 
                );
   scales->eventForce("emote roars with such might the ground itself trembles.");
   scales->AddFriend(who->GetKeyName());
   scales->SetOwner(who->GetKeyName());
   damage = scales->GetLevel() + random(10);
   scales->SetDamageAmount(damage);
   foreach(object sucker in who->GetEnemies()) {
       scales->AddEnemy(sucker);
   }
   scales->eventForce("follow " + who->GetKeyName());
   who->eventForce("lead " + scales->GetKeyName());
   return 1;
}

