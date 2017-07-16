// thoin@Haven
// 02-15-06

#include <lib.h>
#include <magic.h>

inherit LIB_SPELL;

static void create() 
{
  spell::create();
  SetSpell("nature's lament");
  SetRecoveryTime(60);
  SetRules("LIV");
  SetSpellType(SPELL_OTHER);
  SetSkills( ([ 
    "healing"       : 550,
    "natural magic" : 550,
  ]) );
  SetDifficulty(100);
  SetHelp(
    "By using the powers of nature a extremely powerful druid can "
    "attempt to restore life into the target without any great cost "
    "to the target but because of this spells power it takes a great "
    "toll on the caster.");
}

int CanCast(object who, int level, mixed limb, object array targets) {

   if( (environment(who)->GetClimate() == "indoors") ||
       (environment(who)->GetClimate() == "underground") ){
      message("system","Your spell fizzles and refuses to work "
              "in these types of environmental settings.",who);
      return 0;
   }
  if(who->GetSpellLevel("nature's gift") < 99) { 
        message("system","You have not mastered the nature's gift spell. ",who);
      return 0;
      }

   foreach(object target in targets) {
      if ( (target == who) && !target->GetUndead()) {
          message("system", "But you are not undead!",who);
          return 0;
      }
      else if(!target->GetUndead()) {
         message("system","But "+target->GetName()+" is not "
                 "undead!.",who);
         return 0;
      }
   }
   return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, string limb, object array targets) {
  foreach(object target in targets) 
  {
    send_messages( ({ "lay" }),"$agent_name $agent_verb $agent_possessive "
      "on the ground and a vine crawls out from the earth and wraps itself "
      "around $target_name.",
      who,target,environment(who));
    send_messages( ({ "" }),"The vine begins to bud and then blooms into "
      "thousands of flowers completely covering $target_possessive_noun body.",
      who,target,environment(who));
    send_messages( ({ "" }),"The flowers send their pollen into the air "
      "and then begin to wilt. As the petals fall from the vine, the wind "
      "catches them causing them to dance in the air. As the wind stops "
      "$target_name is visible again restored to life by nature.",
      who,target,environment(who));
    who->AddHealthPoints( -(who->GetHealthPoints() - 10) );
    who->AddMagicPoints( -who->GetMagicPoints() );
    who->AddStaminaPoints( -who->GetStaminaPoints() );
    target->SetUndead(0);
   }
   return 1;
}
