#include <lib.h>
#include "../master.h"

#define SEVERED  0
#define FREE     1
#define GRAPPLED 2
#define NUM_TENTACLES 10

inherit LIB_NPC;
inherit LIB_FEAR;

mixed tentacle = ({0,0,0,0,0,0,0,0,0,0,0});

int CheckEncounter();
void AttemptGrapple();
void DoGrapple(object target,int which_tentacle);
void DoConstrict(object target,int which_tentacle);


static void create()
{
  int i;

  npc::create();
  SetKeyName("giant squid");
  SetId(({"squid","giant squid","monster"}) );
  SetShort("an enormous squid");
  SetLong("Tentacles wave everywhere from the leviathan before you as "
          "it seeks to grapple and drag anything within reach to its "
          "gaping maw.");
  SetRace("squid");
  SetClass("animal");
  SetLevel(75);
  
  SetMorality(-800);
  SetGender("neuter");
  SetEncounter( (:CheckEncounter:) );
 
  
  SetResistLevel(15);
  SetFearType("beastly terror");
  SetFearLength(10);

  SetCombatAction(35, (: AttemptGrapple :) );

  for(i=0;i<NUM_TENTACLES;i++)
  {
    tentacle[i+1] = FREE;
  }
}


void init()
{
  npc::init();
  fear::init();
}



int CheckEncounter()
{
  return 1;
}


void AttemptGrapple()
{
  int i,this_tentacle;
  object target;

  if(tentacle[(this_tentacle = random(NUM_TENTACLES)+1)-1] != FREE) return;

  i = random(sizeof(all_inventory(environment(this_player()))));
  if(living(target = all_inventory(environment(this_player()))[i]) &&
     target != this_player()  &&
     !creatorp(target))
  {
    if(random(100) < (15 + (
      (this_player()->GetBaseStatLevel("agility") -
        target->GetBaseStatLevel("agility"))*2 +
      (this_player()->GetBaseStatLevel("speed") -
        target->GetBaseStatLevel("speed")) +
      (this_player()->GetBaseStatLevel("luck") -
        target->GetBaseStatLevel("luck")) ) ) )
    {
      DoGrapple(target,this_tentacle);
    }

    else
    {
      message("environment",
            "%^BOLD%^%^YELLOW%^"
            "One of the beast's enormous tentacles snakes out toward "
            "you, attempting a grapple, but you nimbly dodge out of "
            "the way."
            "%^RESET%^",
            target);
      message("environment",
          "%^BOLD%^%^YELLOW%^"
          "One of the beast's enormous tentacles snakes out toward " +
          target->GetName() + ", attempting to grapple "+ objective(target) +
          ".%^RESET%^",environment(this_player()),target);
    }
  }
}

void DoGrapple(object target,int which_tentacle)
{
  target->SetProperty("grappled",which_tentacle);
  tentacle[which_tentacle] = GRAPPLED;
  AddEnemy(target);
  message("environment",
        "%^BOLD%^%^YELLOW%^"
        "One of the beast's enormous tentacles snakes out toward "
        "you, attempting a grapple, and snags you securely in its "
        "powerful grasp."
        "%^RESET%^",
        target);
  message("environment",
      "%^BOLD%^%^YELLOW%^"
      "One of the beast's enormous tentacles snakes out toward " +
      target->GetName() + ", grappling " + objective(target) + " in its "
      "powerful grasp.%^RESET%^",environment(this_player()),target);
  call_out( (: DoConstrict :), random(10)+8, target, which_tentacle);
}


void DoConstrict(object target,int which_tentacle)
{
  string tentacle_name;

  switch(which_tentacle)
  {
    case 1 : tentacle_name = "first tentacle";
      break;
    case 2 : tentacle_name = "second tentacle";
      break;
    case 3 : tentacle_name = "third tentacle";
      break;
    case 4 : tentacle_name = "fourth tentacle";
      break;
    case 5 : tentacle_name = "fifth tentacle";
      break;
    case 6 : tentacle_name = "sixth tentacle";
      break;
    case 7 : tentacle_name = "seventh tentacle";
      break;
    case 8 : tentacle_name = "eighth tentacle";
      break;
    case 9 : tentacle_name = "ninth tentacle";
      break;
    case 10 : tentacle_name = "tenth tentacle";
      break;
  }
  if(!present(target, environment())) return;
  if(GetLimb(tentacle_name))
  {
    target->eventReceiveDamage(0,0,random(25)+10);
    message("environment",
            "The tentacle constricts around you cutting off your air.",
            target);
    target->eventForce("groan painfully");
    call_out("DoConstrict",random(10)+8,target,which_tentacle);
  }
  else
  {
    target->SetProperty("grappled",0);
    tentacle[which_tentacle] = SEVERED;
    message("environment",
            "%^BOLD%^%^YELLOW%^"
            "The severed tentacle falls away from you.%^RESET%^",
            target);
    message("environment",
            "%^BOLD%^%^YELLOW%^" +
            target->GetName() + " is released by the squid when the "
            "tentacle holding " + target->objective() + "is severed."
            "%^RESET%^",
            environment(this_player()),target);
  }
}


varargs int eventDie(object target)
{
  remove_call_out(0);
  write_file("/realms/balishae/SQUID",this_player()->GetKeyName() + 
             " :  " + ctime(time()) + "\n");
  npc::eventDie(target);
}


void eventCauseFear(object victim, int Time)
{
  message("other_action",
    "The emergence of the great leviathan is too much for you.  Unable to "
    "stop yourself, you run from the room in terror!", victim);
  message("other_action",
    victim->GetCapName() + " flees the room in terror.",
    environment(victim),victim);
  victim->eventForce("go out");
}

