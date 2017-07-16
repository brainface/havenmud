#include <lib.h>
#include <magic.h>
#define DIR "/realms/amelia/spells/obj"
inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("create iron fist");
   SetRules("");
   SetSkills( ([ 
                 "enchantment" : 10,
                 "faith"       : 10,
            ]) );
   SetMagicCost(25,5);
   SetRequiredMagic(30);
   SetHelp("Syntax:  <cast create iron fist>\n\n"
           "The spell creates a temporary iron fist for the caster "
           "to use.");
}

varargs int eventCast(object who, int level, mixed n, object *targets) {
   object blah;
   int z;
   z = (who->GetSkillLevel("faith")) + (who->GetStatLevel("wisdom"));
   if(z>100) z = 101;
   switch(z) {
      case 0..50:
      blah = new(DIR + "/fist1");
      blah->SetLife(z*2);
      break;
      case 50..65:
      blah = new(DIR + "/fist1");
      blah->SetLife(z*3);
      break;
      case 65..85:
      blah = new(DIR + "/fist2");
      blah->SetLife(z*4);
      break;
      case 85..100:
      blah = new(DIR + "/fist2");
      blah->SetLife(z*6);
      break;
      case 101:
      blah = new(DIR + "/fist3");
      blah->SetLife(z*10);
      break;
   }
   blah->eventMove(who);
   send_messages( ({ "create" }), "$agent_name $agent_verb an "
                     "iron fist!",who,0,environment(who));
}