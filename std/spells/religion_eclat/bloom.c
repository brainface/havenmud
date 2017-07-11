#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

void MakeFlower(object dude);

static void create() {
   spell::create();
   SetSpell("bloom");
  SetReligions("Eclat");   
   SetConjure("/std/spells/obj/eclatbloom");
   SetRules("");
   SetSkills( ([
     "enchantment" : 40,
    "natural magic" : 40,
            ]) );
  SetMagicCost(60,20);
   SetRequiredMagic(30);
   SetHelp(""
           "Makes the surrounding area bloom with joyous "
           "flowers.");
}

varargs int CanCast(object who, int level, string limb, object array targets) {
   if(1+member_array(environment(who)->GetClimate(),({ "indoors", 
         "arid","arctic","underground" }))) {
      message("spell","This is the wrong climate for blooming "
              "flowers.",who);
      return 0;
   }
   return ::CanCast(who, level, limb, targets);
}

varargs int eventCast(object who, int level, mixed n, object *T) {
   int flowers;
   int i;
   flowers = level;
   flowers += who->GetStatLevel("wisdom")/10;
   flowers += who->GetSkillLevel("natural magic")/10;
   if(flowers > 25) flowers = 20+random(5);
   for(i = 0;i<flowers;i++) {
      MakeFlower(who);
   }
   return 1;
}

void MakeFlower(object dude) {
   object flower = new(GetConjure());
   if(!flower) { dude->eventPrint("Error in Flower Object");
      return;
   }
   flower->eventMove(environment(dude));
   send_messages( ({ "" }),"" + capitalize(flower->GetShort()) +
                     " blooms at $agent_possessive_noun request.",
                     dude,0,environment(dude));
   return;
}
