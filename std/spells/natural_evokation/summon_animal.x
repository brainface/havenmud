#include <lib.h>
#include <daemons.h>
#include <magic.h>
#include <std.h>
inherit LIB_SPELL;

void CrumbleCorpse(object corpse);

static void create() {
  ::create();
  SetSpell("summon animal");
  SetSpellType(SPELL_OTHER);
  SetRules("");
  SetSkills( ([
    "natural magic" : 20,
    "evokation"     : 20,
     ]) );
  SetMagicCost(  100, 100);
  SetStaminaCost(100, 100);
  SetDifficulty(50);
  SetHelp(
    "Using this spell the natural magic user summons a woodland creature "
    "to act as companion on the travels of the caster. This creature may "
    "look like any normal animal but is a much more effective version ("
    "depending, of course, on the skill of the caster)."
    );
}

int CanCast(object who, int level, mixed limb, object *targets) {
  if( (environment(who)->GetClimate() == "indoors") || (environment(who)->GetClimate() == "underground") ){
    if (!present("natural_charge", who)) {
      who->eventPrint("Your spell fizzles and refuses to work in these types of environmental settings.");
      return 0;
     }
  }
  return spell::CanCast(who, level, limb, targets);
}

varargs int eventCast(object who, int level, mixed x, object *targets) {
  object animal;
  int animallevel;
  
   switch(level) {
     case 0..10 :
        animal = new(STD_NPC "squirrel");
        break;
     case 11..20 : 
        animal = new(STD_NPC "dog");
         break;
     case 21..30 :
        animal = new(STD_NPC "bear");
         break;
     case 31..100 :
        animal = new(STD_NPC "wolf");
          break;
     default :
        animal = new(STD_NPC "dog");
        break;
      }
   switch(level) {
      case 0..20:
        animallevel = who->GetLevel() - 10;
        break;
      case 21..50:
        animallevel = who->GetLevel() - 8;
        break;
      case 51..100:
        animallevel = who->GetLevel() - 5;
        break;
      }
   if (animallevel < 1) animallevel = 1;
   animal->SetLevel(animallevel);
   animal->AddFriend(who->GetKeyName());
   animal->SetOwner(who->GetKeyName());
   send_messages( ({ "summon", }),
     "$agent_name $agent_verb %^BOLD%^GREEN%^" + animal->GetShort() + "%^RESET%^ to aid $agent_objective.",
      who, animal, environment(who) );
   animal->eventMove(environment(who));
   animal->eventForce("purr happily");
   animal->eventForce("follow "+ who->GetKeyName());
   who->eventForce("lead "+ animal->GetKeyName());
   
   if (animallevel > 49) animal->SetSkill("dodge", ((animal->GetLevel() * 2) + 4));
   if (animallevel > 99) animal->SetSkill("accuracy", ((animal->GetLevel() * 2) + 4));
   if (animallevel > 149) animal->SetSkill("combat rage", ((animal->GetLevel() * 2) + 4));
   return 1;
}
