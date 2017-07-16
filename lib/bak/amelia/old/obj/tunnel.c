//  A tunnel for marn faith
//  Takes you back home
//  Not it towns
//  

#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("tunnel");
   SetSkills( ([
                 "faith" : 30,
                 "evokation" : 30,
            ]) );
   SetDifficulty(45);
   SetRules("");
   SetSpellType(SPELL_OTHER);
   SetRequiredMagic(110);
   SetMagicCost(80,30);
   SetRequiredStamina(10);
   SetStaminaCost(8,2);
   SetHelp("Syntax:  <cast tunnel>\n\n"
           "When cast, the spell forms a tunnel in the "
           "ground that lasts for a short period of time.  "
           "The tunnel leads from wherever the caster is "
           "to Ditmar.");
}

int CanCast(object who, int level, string limb, object array targets) {
   if(environment(who)->GetProperty("no teleport")) {
      message("spell","A mystical force prevents the spell.",who);
      return 0;
   }
   return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, mixed limb, object array targets) {
   object ob;
   int values;

   message("spell","PortalOpens",environment(who),who);
   message("spell","PortalOpens",who);
   values = who->GetSkillLevel("evokation") + who->GetSkillLevel("faith");
   ob = new("/spells/obj/marntunnel");
   ob->eventMove(environment(who));
   ob->SetDestTime(values);
   return 1;
}
