// area effect anteky hate spell       
#include <lib.h>                                                          
#include <magic.h>                                                        
#include <damage_types.h>                                                 

inherit LIB_SPELL;

static void create() {
  spell::create();    
  SetSpell("rain of fire");
  SetRules("");            

  SetEnhanceSkills( ({ "fire magic" }) );
  SetSkills( ([                          
    "faith" : 80,                        
    "evokation" : 80,                  
  ]) );                                  
  SetDamageType(HEAT);                   
  SetStaminaCost(50, 25);                
  SetAutoDamage(0);                      
  SetAreaSpell(1);                       
  SetSpellType(SPELL_COMBAT);            
  SetDifficulty(100);                    
  SetMessages( ({                        
    ({"evade", "$target_name %^GREEN%^$target_verb%^RESET%^ $agent_possessive_noun rain of fire!" }),           
    ({"pelt", "$agent_name %^ORANGE%^$agent_verb%^RESET%^ $target_name with $agent_possessive rain of fire!" }),                                                   
    ({"", "$agent_possessive_noun rain of fire %^RED%^BOLD%^slams%^RESET%^ into $target_name, %^RED%^roasting%^RESET%^ $target_objective! " }),                                                               
    }) );                                                                                     
  SetHelp(                                                                                    
    "The fervent adherant of Anteky can call upon the wrath of "                              
    "their god, showering an area in flame. Such an act is known "                            
    "to demoralize any enemy priests that survive the fire. "                                 
    "The faithful are unharmed by these flames."                                              
  );                                                                                          
}                                                                                             

// broadcast a message to the room
int eventCast(object who, int level, string limb, object array targets) {
   int result;
   int pro,con;                                      
                                                               
   send_messages( "chant",                                                    
     "$agent_name $agent_verb an angry plea to $agent_possessive god, and a horrible "
     "%^BOLD%^BLACK%^cloud of fire%^RESET%^ begins to form overhead.",            
     who, 0, environment(who));                                               

   result = spell::eventCast(who, level, limb, targets);

   if (result) {
     foreach(object target in targets) {
       if (!target) continue;           
       if (target->GetSkillLevel("faith") && !(target->GetReligion()=="Kylin")) { // anteky's don't even burn.
         //debug("trying to demoralize");
         pro = random( who->GetStatLevel("wisdom") + who->GetSkillLevel("faith") );
         con = random(target->GetStatLevel("wisdom")+target->GetStatLevel("faith") )+ 20;
         //debug("pro: " + pro + " con: " + con);
         if( pro > con ) {
           //debug("should work!");                                    
           send_messages("are","$target_name $target_verb %^MAGENTA%^demoralized%^RESET%^ by the righteous flames!",
             who, target, environment(target));
         }
         target->AddMagicPoints(random(who->GetWisdom()/2)+5);
       }
     }
  }

  return result;
}


// override GetTargets to remove summoned animals from the list
// god, i do not know if this will work or randomly throw errors.
varargs object *GetTargets(object who, mixed args...) {
  object array targets = ({ });

  foreach(mixed arg in args) {
    debug(arg);
  }

  // damned spell shouldn't have args anyway
  targets = spell::GetTargets(who);
  if (!sizeof(targets)) return targets;

  // let's go ahead and not rain lightning down on the druid's pets?
  foreach(object target in targets) {
    if (!target) continue;
    if (target->GetOwner() == who->GetKeyName() || target->GetReligion() == "Anteky") {
      who->eventPrint("Your god's power refuses to harm " + target->GetKeyName() + ".");
      targets = targets - ({target});
    }
  }
  return targets;
}

