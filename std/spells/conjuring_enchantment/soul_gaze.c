// mahkefel 2011
// reveals history
// boring spell is boring.
#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create()
{
  spell::create();
  SetSpell("soul gaze");
  SetSpellType(SPELL_OTHER);
  SetRules("LIV");
  SetSkills(  ([
    "conjuring" : 150,
    "enchantment" : 150,
  ])  );
  SetMagicCost(100,100);
  SetDifficulty(20);
  SetHelp(
    "A master conjurer can gaze into the eyes of a stranger, seeing "
    "through to their very soul. Meddling in the domain of the Gods "
    "is not without cost to the mage, however!");
}

int eventCast(object who, int level, mixed limbs, object array targets) {
   object person = targets[0];
   int pro, con, result;

   pro = who->GetStatLevel("charisma") + who->GetSkillLevel("conjuring");
   con = person->GetStatLevel("charisma") + person->GetStatLevel("luck") 
     + person->GetSkillLevel("conjuring") / 2 + person->GetSkillLevel("faith") / 2
     + person->GetSkillLevel("dodge") / 2;
   //enchanters are hard to soulgaze. rogues can physically look away.
   // priests can resist the effect, blahblah rp.

   result = random(pro) - random(con);

   if (who->GetTestChar()) debug("soul gaze pro: " + pro + " con: " + con);
   if (result < 0) {
     send_messages( ({"try","avoid"}),
        "$agent_name $agent_verb to lock eyes with $target_name, but "
        "$target_nominative quickly $target_verb the ensaring "
        "gaze!",
        who, person, environment(who)  );
     who->eventPrint("You are startled by the resistance to your arcane power!");
     who->AddParalyzed(3);
     return 0;
   }

   send_messages( ({"lock","ensare"}),
      "$agent_name $agent_verb eyes with $target_name and $agent_verb "
      "$target_objective with $agent_possessive powerful gaze!",
      who, person, environment(who)  );
   if (!(who->GetStory())) {
     who->eventPrint("You have to have a soul yourself to gaze at "
       "anothers!");
   }
   if (!(person->GetStory())) {
        message("system",
          "Due to all your many years of experience as a master "
          "conjurer, you feel you can conclusively say that "
          + capitalize(person->GetKeyName()) + " is a boring lout.",
        who);
   } else {
     message("system",
       "Thousands of images of "+capitalize(person->GetKeyName()) + "'s "
       "memories and deeds flash before your eyes.",
        who);
     message("system",
       "Thousands of images of "+capitalize(who->GetKeyName()) + "'s "
       "memories and deeds flash before your eyes.",
        person);
     who->eventPrint(person->GetStory());
     person->eventPrint(who->GetStory());

     send_messages("are", "$agent_name $agent_verb %^BOLD%^YELLOW%^stunned%^RESET%^ "
       "by something only $agent_nominative can see!",
       who, person, environment(who));
     send_messages("are", "$agent_name $agent_verb %^BOLD%^YELLOW%^stunned%^RESET%^ "
       "by something only $agent_nominative can see!",
       person, who, environment(person));
     //HAHHAH
     who->AddParalyzed(random(5)+5);
     person->AddParalyzed(random(2)+1);
   }
}


